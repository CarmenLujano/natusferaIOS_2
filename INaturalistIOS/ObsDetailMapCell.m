//
//  ObsDetailMapCell.m
//  iNaturalist
//
//  Created by Alex Shepard on 12/8/15.
//  Copyright © 2015 iNaturalist. All rights reserved.
//

#import "ObsDetailMapCell.h"
#import "FAKINaturalist.h"

@implementation ObsDetailMapCell

- (void)awakeFromNib {
    // Initialization code
    
    self.locationNameLabel.layer.cornerRadius = 5.0f;
    self.locationNameLabel.clipsToBounds = YES;
    
    self.noLocationLabel.attributedText = ({
        FAKIcon *noLocation = [FAKINaturalist noLocationIconWithSize:80];
        [noLocation addAttribute:NSForegroundColorAttributeName
                           value:[UIColor whiteColor]];
        
        noLocation.attributedString;
    });
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

- (void)prepareForReuse {
    self.locationNameLabel.text = nil;
    self.mapView.hidden = NO;
    self.noLocationLabel.hidden = YES;
    [self.mapView removeAnnotations:self.mapView.annotations];
}

@end