//
//  DWMasterViewController.h
//  Data_Walk
//
//  Created by Michael Stowell on 8/22/13.
//  Copyright (c) 2013 iSENSE. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>
#import <AudioToolbox/AudioToolbox.h>
#import <CoreMotion/CoreMotion.h>
#import <CoreLocation/CoreLocation.h>
#import <iSENSE_API/Waffle.h>
#import <iSENSE_API/API.h>
#import <RPerson.h>
#import <iSENSE_API/ProjectBrowseViewController.h>
#import "DWAppDelegate.h"
#import <iSENSE_API/headers/DataSaver.h>
#import <iSENSE_API/QueueUploaderView.h>
#import <iSENSE_API/ISKeys.h>

typedef void (^APIBlock)(void);

@interface MainViewController : UIViewController <UINavigationControllerDelegate, UIAlertViewDelegate, CLLocationManagerDelegate, UITextFieldDelegate, UIPickerViewDelegate, UIActionSheetDelegate, ProjectBrowseViewControllerDelegate> {
    
    // iSENSE API
    API *api;
    
    // Variables for the recording interval picker view
    BOOL isShowingPickerView;
    UIPickerView *intervalPickerView;
    BOOL comingBackFromQueueUploader;
    
    // User settings/other variables
    int recordingInterval;
    NSString *name;
    int projectID;
    int elapsedTime;
    int dataPointCount;
    NSMutableArray *data;
}

// UI functions
- (void) onResetClick:(id)sender;
- (void) onAboutClick:(id)sender;

- (IBAction) onRecordingIntervalClick:(id)sender;
- (IBAction) onLoggedInClick:(id)sender;
- (IBAction) onUploadClick:(id)sender;
- (IBAction) onSelectProjectClick:(id)sender;

// Non-UI functions
- (void)showLoadingDialogWithMessage:(NSString *)message andExecuteInBackground:(APIBlock)backgroundBlock finishingOnMainThreadWith:(APIBlock)mainBlock;

// UI properties
@property (nonatomic, strong) UIBarButtonItem *reset;
@property (nonatomic, strong) UIBarButtonItem *about;

@property (nonatomic, strong) IBOutlet UILabel *latitudeLabel;
@property (nonatomic, strong) IBOutlet UILabel *longitudeLabel;
@property (nonatomic, strong) IBOutlet UIButton *recordData;
@property (nonatomic, strong) IBOutlet UIButton *recordingIntervalButton;
@property (nonatomic, strong) IBOutlet UITextField *nameTextField;
@property (nonatomic, strong) IBOutlet UIButton *loggedInAs;
@property (nonatomic, strong) IBOutlet UIButton *upload;
@property (nonatomic, strong) IBOutlet UIButton *selectProject;
@property (nonatomic, strong) IBOutlet UILabel *topBar;
@property (nonatomic, strong) IBOutlet UILabel *timeElapsedLabel;
@property (nonatomic, strong) IBOutlet UILabel *dataPointCountLabel;
@property (nonatomic, strong) IBOutlet UILabel *gpsLockLabel;
@property (nonatomic, strong) IBOutlet UIImageView *gpsLockImage;

// Other properties
@property (nonatomic) BOOL isRecording;
@property (nonatomic, strong) CMMotionManager *motionManager;
@property (nonatomic, strong) CLLocationManager *locationManager;
@property (nonatomic, strong) UITextField *activeField;
@property (nonatomic, strong) UITextField *passwordField;
@property (nonatomic, strong) NSTimer *elapsedTimeTimer;
@property (nonatomic, strong) NSTimer *recordDataTimer;
@property (nonatomic, strong) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, strong) DataSaver *dataSaver;
@property (nonatomic, strong) CLLocation *lastLocation;

@end
