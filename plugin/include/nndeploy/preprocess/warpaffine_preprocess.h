#ifndef _NNDEPLOY_PREPROCESS_WARPAFFINE_PREPROCESS_H_
#define _NNDEPLOY_PREPROCESS_WARPAFFINE_PREPROCESS_H_

#include "nndeploy/base/any.h"
#include "nndeploy/base/common.h"
#include "nndeploy/base/glic_stl_include.h"
#include "nndeploy/base/log.h"
#include "nndeploy/base/macro.h"
#include "nndeploy/base/object.h"
#include "nndeploy/base/opencv_include.h"
#include "nndeploy/base/status.h"
#include "nndeploy/base/string.h"
#include "nndeploy/dag/edge.h"
#include "nndeploy/dag/node.h"
#include "nndeploy/device/buffer.h"
#include "nndeploy/device/device.h"
#include "nndeploy/device/memory_pool.h"
#include "nndeploy/device/tensor.h"
#include "nndeploy/preprocess/opencv_convert.h"
#include "nndeploy/preprocess/params.h"

namespace nndeploy {
namespace preprocess {

class NNDEPLOY_CC_API WarpaffinePreprocess : public dag::Node {
 public:
  // WarpaffinePreprocess(const std::string &name, dag::Edge *input,
  //                      dag::Edge *output)
  //     : dag::Node(name, {input}, {output}) {
  //   param_ = std::make_shared<WarpAffineParam>();
  // }
  WarpaffinePreprocess(const std::string &name) : dag::Node(name) {
    key_ = "nndeploy::preprocess::WarpaffinePreprocess";
    param_ = std::make_shared<WarpAffineParam>();
    this->setInputTypeInfo<cv::Mat>();
    this->setOutputTypeInfo<device::Tensor>();
  }
  WarpaffinePreprocess(const std::string &name,
                       std::initializer_list<dag::Edge *> inputs,
                       std::initializer_list<dag::Edge *> outputs)
      : dag::Node(name, inputs, outputs) {
    key_ = "nndeploy::preprocess::WarpaffinePreprocess";
    param_ = std::make_shared<WarpAffineParam>();
    this->setInputTypeInfo<cv::Mat>();
    this->setOutputTypeInfo<device::Tensor>();
  }
  WarpaffinePreprocess(const std::string &name, std::vector<dag::Edge *> inputs,
                       std::vector<dag::Edge *> outputs)
      : dag::Node(name, inputs, outputs) {
    key_ = "nndeploy::preprocess::WarpaffinePreprocess";
    param_ = std::make_shared<WarpAffineParam>();
    this->setInputTypeInfo<cv::Mat>();
    this->setOutputTypeInfo<device::Tensor>();
  }
  virtual ~WarpaffinePreprocess() {}

  virtual base::Status run();
};

}  // namespace preprocess
}  // namespace nndeploy

#endif /* _NNDEPLOY_PREPROCESS_WARPAFFINE_PREPROCESS_H_ */