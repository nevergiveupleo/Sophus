// Copyright (c) 2011, Hauke Strasdat
// Copyright (c) 2012, Steven Lovegrove
// Copyright (c) 2021, farm-ng, inc.
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#pragma once

#include "sophus/core/types.h"

namespace sophus {

/// Projects 3-point (x,y,z) through the origin (0,0,0) onto the plane z=1.
/// Hence it returns (x/z, y/z).
///
/// Precondition: z must not be close to 0.
template <class PointT>
Eigen::Vector2<typename PointT::Scalar> proj(
    const Eigen::MatrixBase<PointT>& p) {
  using Scalar = typename PointT::Scalar;

  static_assert(PointT::ColsAtCompileTime == 1, "p must be a column-vector");
  static_assert(
      PointT::RowsAtCompileTime == 3, "p must have exactly 3 columns");
  return Eigen::Vector2<Scalar>(p.x() / p.z(), p.y() / p.z());
}

/// Maps point on the z=1 plane (a,b) to homogeneous representation of the same
/// point: (z*a, z*b, z). Z defaults to 1.
template <class PointT>
Eigen::Vector3<typename PointT::Scalar> unproj(
    const Eigen::MatrixBase<PointT>& p,
    const typename PointT::Scalar& z = 1.0) {
  using Scalar = typename PointT::Scalar;
  static_assert(PointT::ColsAtCompileTime == 1, "p must be a column-vector");
  static_assert(
      PointT::RowsAtCompileTime == 2, "p must have exactly 3 columns");
  return Eigen::Vector3<Scalar>(z * p.x(), z * p.y(), z);
}

}  // namespace sophus