/*
 * iSENSE Project - isenseproject.org
 * This file is part of the iSENSE iOS API and applications.
 *
 * Copyright (c) 2015, University of Massachusetts Lowell. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer. Redistributions in binary
 * form must reproduce the above copyright notice, this list of conditions and
 * the following disclaimer in the documentation and/or other materials
 * provided with the distribution. Neither the name of the University of
 * Massachusetts Lowell nor the names of its contributors may be used to
 * endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 *
 * BSD 3-Clause License
 * http://opensource.org/licenses/BSD-3-Clause
 *
 * Our work is supported by grants DRL-0735597, DRL-0735592, DRL-0546513, IIS-1123998,
 * and IIS-1123972 from the National Science Foundation and a gift from Google Inc.
 *
 */

//
// FieldMatchingViewController.h
// iSENSE_API
//
// Created by Michael Stowell on 11/14/13.
//

#import <UIKit/UIKit.h>
#import "FieldMatchCell.h"
#import "FieldEntry.h"
#import "DataContainer.h"

#define kFIELD_MATCHED_ARRAY @"field_matched_array"

@interface FieldMatchingViewController : UIViewController <UIPickerViewDelegate, UIAlertViewDelegate> {
    // bundle for resource files in the iSENSE_API_Bundle
    NSBundle *isenseBundle;
    
    // to hold FieldEntry objects
    NSMutableArray *entries;
    
    // last clicked cell
    NSIndexPath *lastClickedCellIndex;
    
    // pickerview for changing fields
    BOOL isShowingPickerView;
    UIPickerView *fieldPickerView;
    int fieldTag;
    NSString *fieldName;
    UITextField *alertText;
}

- (id) initWithMatchedFields:(NSArray *)mf andProjectFields:(NSArray *)pf;

- (IBAction) okOnClick:(id)sender;

@property (nonatomic, assign) IBOutlet UITableView *mTableView;
@property (nonatomic, assign) IBOutlet UIButton *back;
@property (nonatomic, assign) IBOutlet UIButton *ok;
@property (nonatomic, strong) NSMutableArray *matchFields;
@property (nonatomic, strong) NSMutableArray *projFields;

@end
