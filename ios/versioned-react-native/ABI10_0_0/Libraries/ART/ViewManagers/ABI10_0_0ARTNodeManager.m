/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import "ABI10_0_0ARTNodeManager.h"

#import "ABI10_0_0ARTNode.h"

@implementation ABI10_0_0ARTNodeManager

ABI10_0_0RCT_EXPORT_MODULE()

- (ABI10_0_0ARTNode *)node
{
  return [ABI10_0_0ARTNode new];
}

- (UIView *)view
{
  return [self node];
}

- (ABI10_0_0RCTShadowView *)shadowView
{
  return nil;
}

ABI10_0_0RCT_EXPORT_VIEW_PROPERTY(opacity, CGFloat)
ABI10_0_0RCT_EXPORT_VIEW_PROPERTY(transform, CGAffineTransform)

@end
