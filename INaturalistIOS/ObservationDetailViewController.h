//
//  INObservationFormViewController.h
//  INaturalistIOS
//
//  Created by Ken-ichi Ueda on 2/13/12.
//  Copyright (c) 2012 iNaturalist. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TapkuLibrary/TapkuLibrary.h>
#import "PhotoViewController.h"

@class Observation;
@class ObservationPhoto;
@class ObservationDetailViewController;

@protocol ObservationDetailViewControllerDelegate <NSObject>
- (void)observationDetailViewControllerDidSave:(ObservationDetailViewController *)controller;
- (void)observationDetailViewControllerDidCancel:(ObservationDetailViewController *)controller;
@end

@interface ObservationDetailViewController : UITableViewController <UITextFieldDelegate, UITextViewDelegate, UIActionSheetDelegate, UINavigationControllerDelegate, UIImagePickerControllerDelegate, TKCoverflowViewDelegate, TKCoverflowViewDataSource,PhotoViewControllerDelegate, CLLocationManagerDelegate>

@property (nonatomic, weak) id <ObservationDetailViewControllerDelegate> delegate;
@property (nonatomic, strong) Observation *observation;
@property (nonatomic, strong) NSMutableArray *observationPhotos;
@property (nonatomic, strong) TKCoverflowView *coverflowView;
@property (weak, nonatomic) IBOutlet UITextField *speciesGuessTextField;
@property (weak, nonatomic) IBOutlet UITextView *descriptionTextView;
@property (weak, nonatomic) IBOutlet UILabel *observedAtLabel;
@property (weak, nonatomic) IBOutlet UILabel *latitudeLabel;
@property (weak, nonatomic) IBOutlet UILabel *longitudeLabel;
@property (weak, nonatomic) IBOutlet UILabel *positionalAccuracyLabel;
@property (weak, nonatomic) IBOutlet UITextField *placeGuessField;
@property (strong, nonatomic) UIToolbar *keyboardToolbar;
@property (strong, nonatomic) UIBarButtonItem *saveButton;
@property (nonatomic, strong) CLLocationManager *locationManager;
@property (nonatomic, strong) NSTimer *locationTimer;
@property (nonatomic, strong) CLGeocoder *geocoder;


- (IBAction)clickedClear:(id)sender;
- (IBAction)keyboardDone:(id)sender;
- (IBAction)clickedSave:(id)sender;
- (IBAction)clickedCancel:(id)sender;
- (IBAction)clickedAddPhoto:(id)sender;
- (void)save;
- (void)observationToUI;
- (void)uiToObservation;

- (void)addPhoto:(ObservationPhoto *)op;
- (void)removePhoto:(ObservationPhoto *)op;
- (void)initCoverflowView;
- (void)refreshCoverflowView;
- (void)resizeHeaderView;

- (void)startUpdatingLocation;
- (void)stopUpdatingLocation;

- (void)photoActionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex;
- (void)locationActionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex;

@end