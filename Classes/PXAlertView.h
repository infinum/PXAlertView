//
//  PXAlertView.h
//  PXAlertViewDemo
//
//  Created by Alex Jarvis on 25/09/2013.
//  Copyright (c) 2013 Panaxiom Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PXAlertView;

typedef void(^PXAlertViewCompletionBlock)(BOOL cancelled, NSInteger buttonIndex, PXAlertView *alert);

@protocol PXAlertViewDelegate <NSObject>

- (void)alertViewDidSelectLinkWithURL:(NSURL *)url;

@end

@interface PXAlertWindow: UIWindow
@end

@interface PXAlertView : UIViewController

@property (nonatomic, getter = isVisible) BOOL visible;
@property (nonatomic) UIView *contentView;
@property (nonatomic, strong) NSString *message;
@property (nonatomic, weak) id<PXAlertViewDelegate> delegate;

@property (nonatomic) UIWindow *mainWindow;
@property (nonatomic) PXAlertWindow *alertWindow;

+ (instancetype)showAlertWithTitle:(NSString *)title;

+ (instancetype)showAlertWithTitle:(NSString *)title
                           message:(NSString *)message;

+ (instancetype)showAlertWithTitle:(NSString *)title
                           message:(NSString *)message
                        completion:(PXAlertViewCompletionBlock)completion;

+ (instancetype)showAlertWithTitle:(NSString *)title
                           message:(NSString *)message
                       cancelTitle:(NSString *)cancelTitle
                        completion:(PXAlertViewCompletionBlock)completion;

+ (instancetype)showAlertWithTitle:(NSString *)title
                           message:(NSString *)message
                       cancelTitle:(NSString *)cancelTitle
                        otherTitle:(NSString *)otherTitle
                        completion:(PXAlertViewCompletionBlock)completion;

+ (instancetype)showAlertWithTitle:(NSString *)title
                           message:(NSString *)message
                       cancelTitle:(NSString *)cancelTitle
                        otherTitle:(NSString *)otherTitle
                buttonsShouldStack:(BOOL)shouldStack
                        completion:(PXAlertViewCompletionBlock)completion;

/**
 * @param otherTitles Must be a NSArray containing type NSString, or set to nil for no otherTitles.
 */
+ (instancetype)showAlertWithTitle:(NSString *)title
                           message:(NSString *)message
                       cancelTitle:(NSString *)cancelTitle
                       otherTitles:(NSArray *)otherTitles
                buttonsShouldStack:(BOOL)shouldStack
                        completion:(PXAlertViewCompletionBlock)completion;


+ (instancetype)showAlertWithTitle:(NSString *)title
                           message:(NSString *)message
                       cancelTitle:(NSString *)cancelTitle
                        otherTitle:(NSString *)otherTitle
                       contentView:(UIView *)view
                        completion:(PXAlertViewCompletionBlock)completion;

+ (instancetype)showAlertWithTitle:(NSString *)title
                           message:(NSString *)message
                       cancelTitle:(NSString *)cancelTitle
                        otherTitle:(NSString *)otherTitle
                buttonsShouldStack:(BOOL)shouldStack
                       contentView:(UIView *)view
                        completion:(PXAlertViewCompletionBlock)completion;

/**
 * @param otherTitles Must be a NSArray containing type NSString, or set to nil for no otherTitles.
 */
+ (instancetype)showAlertWithTitle:(NSString *)title
                           message:(NSString *)message
                       cancelTitle:(NSString *)cancelTitle
                       otherTitles:(NSArray *)otherTitles
                buttonsShouldStack:(BOOL)shouldStack
                       contentView:(UIView *)view
                        completion:(PXAlertViewCompletionBlock)completion;

/**
 * Adds a button to the receiver with the given title.
 * @param title The title of the new button
 * @return The index of the new button. Button indices start at 0 and increase in the order they are added.
 */
- (NSInteger)addButtonWithTitle:(NSString *)title;

/**
 * Dismisses the receiver, optionally with animation.
 */
- (void)dismissWithClickedButtonIndex:(NSInteger)buttonIndex animated:(BOOL)animated;

/**
 * By default the alert allows you to tap anywhere around the alert to dismiss it.
 * This method enables or disables this feature.
 */
- (void)setTapToDismissEnabled:(BOOL)enabled;

- (id)initWithTitle:(NSString *)title
            message:(NSString *)message
        cancelTitle:(NSString *)cancelTitle
        otherTitles:(NSArray *)otherTitles
 buttonsShouldStack:(BOOL)shouldstack
        contentView:(UIView *)contentView
         completion:(PXAlertViewCompletionBlock)completion;

- (void)addLinkToStringInMessage:(NSString *)string URL:(NSURL *)URL;

- (void)show;
- (void)dismiss;

- (void)fixTTTAttributedLabelFormat;

@end
