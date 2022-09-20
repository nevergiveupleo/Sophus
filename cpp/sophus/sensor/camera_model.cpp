// Copyright (c) 2011, Hauke Strasdat
// Copyright (c) 2012, Steven Lovegrove
// Copyright (c) 2021, farm-ng, inc.
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include "sophus/sensor/camera_model.h"

#include <farm_ng/core/misc/variant_utils.h>

namespace sophus {

namespace {
CameraTransformVariant getModelFromType(
    CameraTransformType projection_type,
    ImageSize image_size,
    const Eigen::VectorXd& params) {
  switch (projection_type) {
    case CameraTransformType::pinhole: {
      return PinholeModel(image_size, params);
      break;
    }
    case CameraTransformType::brown_conrady: {
      return BrownConradyModel(image_size, params);
      break;
    }
    case CameraTransformType::kannala_brandt_k3: {
      return KannalaBrandtK3Model(image_size, params);
      break;
    }
  }
  FARM_FATAL("logic error");
}
}  // namespace

CameraModel::CameraModel(
    std::string frame_name,
    ImageSize image_size,
    CameraTransformType projection_type,
    const Eigen::VectorXd& params)
    : frame_name_(std::move(frame_name)),
      model_(getModelFromType(projection_type, image_size, params)) {}

std::string_view CameraModel::cameraTransformName() const {
  return std::visit(
      [](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        return T::kProjectionModel;
      },
      model_);
}

Eigen::VectorXd CameraModel::params() const {
  return std::visit(
      [](auto&& arg) -> Eigen::VectorXd { return arg.params(); }, model_);
}

Eigen::Vector2d CameraModel::focalLength() const {
  return std::visit(
      [](auto&& arg) -> Eigen::Vector2d { return arg.focalLength(); }, model_);
}

void CameraModel::setFocalLength(Eigen::Vector2d const& focal_length) {
  std::visit(
      [&focal_length](auto&& arg) { return arg.setFocalLength(focal_length); },
      model_);
}

Eigen::Vector2d CameraModel::principalPoint() const {
  return std::visit(
      [](auto&& arg) -> Eigen::Vector2d { return arg.principalPoint(); },
      model_);
}

void CameraModel::setPrincipalPoint(Eigen::Vector2d const& principal_point) {
  std::visit(
      [&principal_point](auto&& arg) {
        return arg.setPrincipalPoint(principal_point);
      },
      model_);
}

Eigen::VectorXd CameraModel::distortionParams() const {
  return std::visit(
      [](auto&& arg) -> Eigen::VectorXd { return arg.distortionParams(); },
      model_);
}

void CameraModel::setParams(const Eigen::VectorXd& params) {
  std::visit([&params](auto&& arg) { arg.mutParams() = params; }, model_);
}

Eigen::Vector2d CameraModel::camProj(
    const Eigen::Vector3d& point_camera) const {
  return std::visit(
      [&](auto&& arg) -> Eigen::Vector2d { return arg.camProj(point_camera); },
      model_);
}

Eigen::Vector3d CameraModel::camUnproj(
    const Eigen::Vector2d& pixel_image, double depth_z) const {
  return std::visit(
      [&](auto&& arg) -> Eigen::Vector3d {
        return arg.camUnproj(pixel_image, depth_z);
      },
      model_);
}

Eigen::Vector2d CameraModel::warp(
    const Eigen::Vector2d& point2_in_camera_z1_plane) const {
  return std::visit(
      [&](auto&& arg) -> Eigen::Vector2d {
        return arg.warp(point2_in_camera_z1_plane);
      },
      model_);
}

Eigen::Matrix2d CameraModel::dxWarp(
    const Eigen::Vector2d& point2_in_camera_z1_plane) const {
  return std::visit(
      [&](auto&& arg) -> Eigen::Matrix2d {
        return arg.dxWarp(point2_in_camera_z1_plane);
      },
      model_);
}

Eigen::Vector2d CameraModel::unwarp(const Eigen::Vector2d& pixel_image) const {
  return std::visit(
      [&](auto&& arg) -> Eigen::Vector2d { return arg.unwarp(pixel_image); },
      model_);
}

[[nodiscard]] MutImage<Eigen::Vector2f> CameraModel::unwarpTable() const {
  return std::visit(
      [](auto&& arg) -> MutImage<Eigen::Vector2f> { return arg.unwarpTable(); },
      model_);
}

Eigen::Matrix<double, 2, 3> CameraModel::dxCamProjX(
    const Eigen::Vector3d& point_in_camera) const {
  return std::visit(
      [&](auto&& arg) -> Eigen::Matrix<double, 2, 3> {
        return arg.dxCamProjX(point_in_camera);
      },
      model_);
}

Eigen::Matrix<double, 2, 6> CameraModel::dxCamProjExpXPointAt0(
    const Eigen::Vector3d& point_in_camera) const {
  return std::visit(
      [&](auto&& arg) -> Eigen::Matrix<double, 2, 6> {
        auto dx2 = Se3F64::dxExpXTimesPointAt0(point_in_camera);

        return arg.dxCamProjX(point_in_camera) * dx2;
      },
      model_);
}

CameraModel CameraModel::subsampleDown() const {
  return CameraModel(
      this->frame_name_,
      std::visit(
          [](auto&& arg) -> CameraTransformVariant {
            return arg.subsampleDown();
          },
          this->model_));
}

CameraModel CameraModel::subsampleUp() const {
  return CameraModel(
      this->frame_name_,
      std::visit(
          [](auto&& arg) -> CameraTransformVariant {
            return arg.subsampleUp();
          },
          this->model_));
}

CameraModel CameraModel::binDown() const {
  return CameraModel(
      this->frame_name_,
      std::visit(
          [](auto&& arg) -> CameraTransformVariant { return arg.binDown(); },
          this->model_));
}

CameraModel CameraModel::binUp() const {
  return CameraModel(
      this->frame_name_,
      std::visit(
          [](auto&& arg) -> CameraTransformVariant { return arg.binUp(); },
          this->model_));
}

CameraModel CameraModel::roi(
    const Eigen::Vector2i& top_left, ImageSize roi_size) const {
  FARM_CHECK_LE(top_left.x() + roi_size.width, imageSize().width);
  FARM_CHECK_LE(top_left.y() + roi_size.height, imageSize().height);
  return CameraModel(
      this->frame_name_,
      std::visit(
          [&](auto&& arg) -> CameraTransformVariant {
            return arg.roi(top_left, roi_size);
          },
          this->model_));
}

bool CameraModel::contains(const Eigen::Vector2i& obs, int border) const {
  return std::visit(
      [&](auto&& arg) -> bool { return arg.contains(obs, border); },
      this->model_);
}

const ImageSize& CameraModel::imageSize() const {
  return std::visit(
      [](auto&& arg) -> const ImageSize& { return arg.imageSize(); },
      this->model_);
}

bool CameraModel::contains(const Eigen::Vector2d& obs, double border) const {
  return std::visit(
      [&](auto&& arg) -> bool { return arg.contains(obs, border); },
      this->model_);
}

CameraTransformType CameraModel::transformType() const {
  return std::visit(
      [](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, PinholeModel>) {
          return CameraTransformType::pinhole;
        } else if constexpr (std::is_same_v<T, BrownConradyModel>) {
          return CameraTransformType::brown_conrady;
        } else if constexpr (std::is_same_v<T, KannalaBrandtK3Model>) {
          return CameraTransformType::kannala_brandt_k3;
        } else {
          static_assert(farm_ng::AlwaysFalse<T>, "non-exhaustive visitor!");
        }
      },
      this->modelVariant());
}

CameraModel CameraModel::createDefaultPinholeModel(
    std::string frame_name, ImageSize image_size) {
  return CameraModel(
      frame_name, ::sophus::createDefaultPinholeModel(image_size));
}

PinholeModel createDefaultPinholeModel(ImageSize image_size) {
  double fx = image_size.width * 0.5;
  double fy = fx;
  double cx = (image_size.width - 1.0) * 0.5;
  double cy = (image_size.height - 1.0) * 0.5;

  return PinholeModel(image_size, {fx, fy, cx, cy});
}

CameraModel CameraModel::scale(ImageSize image_size) const {
  return CameraModel(
      this->frame_name_,
      std::visit(
          [&image_size](auto&& arg) -> CameraTransformVariant {
            return arg.scale(image_size);
          },
          this->model_));
}

}  // namespace sophus