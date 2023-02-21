"use strict";(self.webpackChunkdocs=self.webpackChunkdocs||[]).push([[629],{3905:(e,t,n)=>{n.d(t,{Zo:()=>m,kt:()=>f});var r=n(7294);function o(e,t,n){return t in e?Object.defineProperty(e,t,{value:n,enumerable:!0,configurable:!0,writable:!0}):e[t]=n,e}function a(e,t){var n=Object.keys(e);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);t&&(r=r.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),n.push.apply(n,r)}return n}function i(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{};t%2?a(Object(n),!0).forEach((function(t){o(e,t,n[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(n)):a(Object(n)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(n,t))}))}return e}function l(e,t){if(null==e)return{};var n,r,o=function(e,t){if(null==e)return{};var n,r,o={},a=Object.keys(e);for(r=0;r<a.length;r++)n=a[r],t.indexOf(n)>=0||(o[n]=e[n]);return o}(e,t);if(Object.getOwnPropertySymbols){var a=Object.getOwnPropertySymbols(e);for(r=0;r<a.length;r++)n=a[r],t.indexOf(n)>=0||Object.prototype.propertyIsEnumerable.call(e,n)&&(o[n]=e[n])}return o}var p=r.createContext({}),s=function(e){var t=r.useContext(p),n=t;return e&&(n="function"==typeof e?e(t):i(i({},t),e)),n},m=function(e){var t=s(e.components);return r.createElement(p.Provider,{value:t},e.children)},d="mdxType",u={inlineCode:"code",wrapper:function(e){var t=e.children;return r.createElement(r.Fragment,{},t)}},c=r.forwardRef((function(e,t){var n=e.components,o=e.mdxType,a=e.originalType,p=e.parentName,m=l(e,["components","mdxType","originalType","parentName"]),d=s(n),c=o,f=d["".concat(p,".").concat(c)]||d[c]||u[c]||a;return n?r.createElement(f,i(i({ref:t},m),{},{components:n})):r.createElement(f,i({ref:t},m))}));function f(e,t){var n=arguments,o=t&&t.mdxType;if("string"==typeof e||o){var a=n.length,i=new Array(a);i[0]=c;var l={};for(var p in t)hasOwnProperty.call(t,p)&&(l[p]=t[p]);l.originalType=e,l[d]="string"==typeof e?e:o,i[1]=l;for(var s=2;s<a;s++)i[s]=n[s];return r.createElement.apply(null,i)}return r.createElement.apply(null,n)}c.displayName="MDXCreateElement"},9095:(e,t,n)=>{n.r(t),n.d(t,{assets:()=>p,contentTitle:()=>i,default:()=>u,frontMatter:()=>a,metadata:()=>l,toc:()=>s});var r=n(7462),o=(n(7294),n(3905));const a={sidebar_position:1},i="Sophus Style Guide",l={unversionedId:"Developer Guide/style-guide",id:"Developer Guide/style-guide",title:"Sophus Style Guide",description:"Sophus is following the farm-ng style guide.",source:"@site/docs/Developer Guide/style-guide.md",sourceDirName:"Developer Guide",slug:"/Developer Guide/style-guide",permalink:"/sophus2/docs/Developer Guide/style-guide",draft:!1,tags:[],version:"current",sidebarPosition:1,frontMatter:{sidebar_position:1},sidebar:"tutorialSidebar",previous:{title:"Contributor Guide",permalink:"/sophus2/docs/category/contributor-guide"}},p={},s=[{value:"Transformations, points, velocities",id:"transformations-points-velocities",level:2},{value:"Rigid body transform and points convention",id:"rigid-body-transform-and-points-convention",level:2},{value:"Some details",id:"some-details",level:3}],m={toc:s},d="wrapper";function u(e){let{components:t,...n}=e;return(0,o.kt)(d,(0,r.Z)({},m,n,{components:t,mdxType:"MDXLayout"}),(0,o.kt)("h1",{id:"sophus-style-guide"},"Sophus Style Guide"),(0,o.kt)("p",null,"Sophus is following the ",(0,o.kt)("a",{parentName:"p",href:"https://farm-ng.github.io/farm-ng-core/docs/Developer%20Guide/style-guide"},"farm-ng style guide"),"."),(0,o.kt)("h2",{id:"transformations-points-velocities"},"Transformations, points, velocities"),(0,o.kt)("h2",{id:"rigid-body-transform-and-points-convention"},"Rigid body transform and points convention"),(0,o.kt)("p",null,"Given a point in frame ",(0,o.kt)("inlineCode",{parentName:"p"},"foo"),", ",(0,o.kt)("inlineCode",{parentName:"p"},"bar_from_foo")," is the rigid body\ntransform which maps the point to frame ",(0,o.kt)("inlineCode",{parentName:"p"},"bar"),":"),(0,o.kt)("pre",null,(0,o.kt)("code",{parentName:"pre",className:"language-cpp"},"    point_in_bar = bar_from_foo * point_in_foo\n")),(0,o.kt)("p",null,"Note that the frame names line up: ",(0,o.kt)("inlineCode",{parentName:"p"},"bar")," - ",(0,o.kt)("inlineCode",{parentName:"p"},"bar"),", ",(0,o.kt)("inlineCode",{parentName:"p"},"foo")," - ",(0,o.kt)("inlineCode",{parentName:"p"},"foo"),"."),(0,o.kt)("h3",{id:"some-details"},"Some details"),(0,o.kt)("ul",null,(0,o.kt)("li",{parentName:"ul"},(0,o.kt)("p",{parentName:"li"},"If necessary to resolved ambiguities, e.g. between rotations and rigid\nbody transforms, we use a corresponding notation, e.g.\n",(0,o.kt)("inlineCode",{parentName:"p"},"bar_form_foo_rotation"),", ",(0,o.kt)("inlineCode",{parentName:"p"},"bar_form_foo_se3s")," etc.")),(0,o.kt)("li",{parentName:"ul"},(0,o.kt)("p",{parentName:"li"},"If we have a list (or vector, or map) of transforms we write:, e.g.:"),(0,o.kt)("p",{parentName:"li"},"   bar_from_foo_rotations")),(0,o.kt)("li",{parentName:"ul"},(0,o.kt)("p",{parentName:"li"},"Transforms with compound frame names, such as ",(0,o.kt)("inlineCode",{parentName:"p"},"robot_base")," or\n",(0,o.kt)("inlineCode",{parentName:"p"},"left_camera"),", are written as follows::"),(0,o.kt)("p",{parentName:"li"},"   robot_base_from_left_camera")),(0,o.kt)("li",{parentName:"ul"},(0,o.kt)("p",{parentName:"li"},"For functions and methods we use ",(0,o.kt)("inlineCode",{parentName:"p"},"camelCase"),". Examples::"),(0,o.kt)("p",{parentName:"li"},"   this->calcRobotBaseFromLeftCamera();"),(0,o.kt)("p",{parentName:"li"},"   other->setBarFromFoo(bar_from_foo);")),(0,o.kt)("li",{parentName:"ul"},(0,o.kt)("p",{parentName:"li"},"We use the ",(0,o.kt)("inlineCode",{parentName:"p"},"entity_in_frame")," conventions for points and other entities\nwhich have one frame attached to it. Examples:"),(0,o.kt)("ul",{parentName:"li"},(0,o.kt)("li",{parentName:"ul"},(0,o.kt)("inlineCode",{parentName:"li"},"point_in_camera")),(0,o.kt)("li",{parentName:"ul"},(0,o.kt)("inlineCode",{parentName:"li"},"circle_in_image")),(0,o.kt)("li",{parentName:"ul"},(0,o.kt)("inlineCode",{parentName:"li"},"camera_position_in_world")," (or short ",(0,o.kt)("inlineCode",{parentName:"li"},"camera_in_world"),")"),(0,o.kt)("li",{parentName:"ul"},"..."))),(0,o.kt)("li",{parentName:"ul"},(0,o.kt)("p",{parentName:"li"},"When storing transforms / using them in interfaces, prefer the\n",(0,o.kt)("inlineCode",{parentName:"p"},"parent_from_child")," convention."),(0,o.kt)("p",{parentName:"li"},"E.g. ",(0,o.kt)("inlineCode",{parentName:"p"},"world_from_sensor_rig"),", ",(0,o.kt)("inlineCode",{parentName:"p"},"sensor_rig_from_camera"),",\n",(0,o.kt)("inlineCode",{parentName:"p"},"robot_from_imu")," (and not ",(0,o.kt)("inlineCode",{parentName:"p"},"sensor_rig_from_world")," etc.)."),(0,o.kt)("p",{parentName:"li"},"It is easier to reason about the pose of camera in the world frame, then\nthe pose of the world origin in the camera frame."))))}u.isMDXComponent=!0}}]);