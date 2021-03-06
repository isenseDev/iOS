//
//  StepOneSetup.h
//  iOS Data Collector
//
//  Created by Mike Stowell on 06/21/13.
//  Copyright 2013 iSENSE Development Team. All rights reserved.
//  Engaging Computing Lab, Advisor: Fred Martin
//

#import <UIKit/UIKit.h>
#import <iSENSE_API/SensorCompatibility.h>
#import <iSENSE_API/SensorEnums.h>
#import <iSENSE_API/DataFieldManager.h>
#import <iSENSE_API/FieldMatchingViewController.h>
#import <ProjectBrowserViewController.h>

#import "Data_CollectorAppDelegate.h"
#import <AVFoundation/AVFoundation.h>
#import <AVFoundation/AVCaptureDevice.h>

@interface StepOneSetup : UIViewController <UITextFieldDelegate, ProjectBrowserDelegate> {
    
    API *api;
    int projNumInteger;
    bool sensorsSelected;
    bool displaySensorSelectFromBrowse;
    NSMutableArray *returnFields;
    
}

- (IBAction)rememberMeToggled:(UISwitch *)switcher;
- (IBAction)selectLaterToggled:(UISwitch *)switcher;
- (IBAction)projectOnClick:(UIButton *)projButton;
- (IBAction)okOnClick:(UIButton *)okButton;

@property (nonatomic, strong) IBOutlet UITextField *sessionName;
@property (nonatomic, strong) IBOutlet UITextField *sampleInterval;
@property (nonatomic, strong) IBOutlet UITextField *testLength;
@property (nonatomic, strong) IBOutlet UILabel     *projNumLabel;
@property (nonatomic, strong) IBOutlet UISwitch    *rememberMe;
@property (nonatomic, strong) IBOutlet UIButton    *selectProj;
@property (nonatomic, strong) IBOutlet UISwitch    *selectLater;
@property (nonatomic, strong) IBOutlet UIButton    *ok;

@end