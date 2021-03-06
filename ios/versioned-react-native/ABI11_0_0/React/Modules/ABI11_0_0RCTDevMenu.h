/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <UIKit/UIKit.h>

#import "ABI11_0_0RCTBridge.h"
#import "ABI11_0_0RCTBridgeModule.h"

@class ABI11_0_0RCTDevMenuItem;

/**
 * Developer menu, useful for exposing extra functionality when debugging.
 */
@interface ABI11_0_0RCTDevMenu : NSObject

/**
 * Is the menu enabled. The menu is enabled by default if ABI11_0_0RCT_DEV=1, but
 * you may wish to disable it so that you can provide your own shake handler.
 */
@property (nonatomic, assign) BOOL shakeToShow;

/**
 * Enables performance profiling.
 */
@property (nonatomic, assign) BOOL profilingEnabled;

/**
 * Enables automatic polling for JS code changes. Only applicable when
 * running the app from a server.
 */
@property (nonatomic, assign) BOOL liveReloadEnabled;

/**
 * Enables hot loading. Currently not supported in open source.
 */
@property (nonatomic, assign) BOOL hotLoadingEnabled;

/**
 * Shows the FPS monitor for the JS and Main threads.
 */
@property (nonatomic, assign) BOOL showFPS;

/**
 * Manually show the dev menu (can be called from JS).
 */
- (void)show;

/**
 * Manually reload the application. Equivalent to calling [bridge reload]
 * directly, but can be called from JS.
 */
- (void)reload;

/**
 * Deprecated. Use the `-addItem:` method instead.
 */
- (void)addItem:(NSString *)title
        handler:(void(^)(void))handler DEPRECATED_ATTRIBUTE;

/**
 * Add custom item to the development menu. The handler will be called
 * when user selects the item.
 */
- (void)addItem:(ABI11_0_0RCTDevMenuItem *)item;

@end

/**
 * Developer menu item, used to expose additional functionality via the menu.
 */
@interface ABI11_0_0RCTDevMenuItem : NSObject

/**
 * This creates an item with a simple push-button interface, used to trigger an
 * action.
 */
+ (instancetype)buttonItemWithTitle:(NSString *)title
                            handler:(void(^)(void))handler;

/**
 * This creates an item with a toggle behavior. The key is used to store the
 * state of the toggle. For toggle items, the handler will be called immediately
 * after the item is added if the item was already selected when the module was
 * last loaded.
 */
+ (instancetype)toggleItemWithKey:(NSString *)key
                            title:(NSString *)title
                    selectedTitle:(NSString *)selectedTitle
                          handler:(void(^)(BOOL selected))handler;
@end

/**
 * This category makes the developer menu instance available via the
 * ABI11_0_0RCTBridge, which is useful for any class that needs to access the menu.
 */
@interface ABI11_0_0RCTBridge (ABI11_0_0RCTDevMenu)

@property (nonatomic, readonly) ABI11_0_0RCTDevMenu *devMenu;

@end
