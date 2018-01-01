//
//  ISAlertView.h
//  ISAlertView
//
//  Copyright (c) 2014-2015 Ilya Stepanov
//
//  Based on CustomIOS7AlertView
//  Copyright (c) 2013 Wimagguc.
//
//  Lincesed under The MIT License (MIT)
//  http://opensource.org/licenses/MIT
//

#import <UIKit/UIKit.h>

@protocol ISAlertViewDelegate

- (void)customIOS7dialogButtonTouchUpInside:(id)alertView clickedButtonAtIndex:(NSInteger)buttonIndex;
- (void)didTapOnOutside;

@end

@interface ISAlertView : UIView <UIGestureRecognizerDelegate>

@property (nonatomic, retain) UIView *parentView;    // The parent view this 'dialog' is attached to
@property (nonatomic, retain) UIView *dialogView;    // Dialog's container view
@property (nonatomic, retain) UIView *containerView; // Container within the dialog (place your ui elements here)

@property (nonatomic, assign) id<ISAlertViewDelegate> delegate;
@property (nonatomic, retain) NSArray *buttonTitles;
@property (nonatomic, assign) BOOL useMotionEffects;
@property (nonatomic, assign) BOOL useBorder;
@property (nonatomic, assign) BOOL clipToBounds;

@property (copy) void (^onButtonTouchUpInside)(ISAlertView *alertView, int buttonIndex) ;

- (instancetype)init NS_DESIGNATED_INITIALIZER;

- (void)show;
- (void)close;

- (IBAction)customIOS7dialogButtonTouchUpInside:(id)sender;
- (void)setOnButtonTouchUpInside:(void (^)(ISAlertView *alertView, int buttonIndex))onButtonTouchUpInside;

- (void)deviceOrientationDidChange: (NSNotification *)notification;
- (void)dealloc;

@end
