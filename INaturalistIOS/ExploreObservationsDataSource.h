//
//  ExploreObservationsDataSource.h
//  Explore Prototype
//
//  Created by Alex Shepard on 10/3/14.
//  Copyright (c) 2014 iNaturalist. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

#import "ExploreSearchPredicate.h"
#import "ExploreRegion.h"

typedef void(^FetchCompletionHandler)(NSArray *results, NSError *error);
typedef void(^PostCompletionHandler)(RKResponse *response, NSError *error);


@class ExploreObservation;

@protocol ExploreObservationsDataSource <NSObject>

@property NSOrderedSet *observations;
@property (readonly) NSArray *mappableObservations;
@property NSArray *activeSearchPredicates;
@property ExploreRegion *limitingRegion;

- (void)addSearchPredicate:(ExploreSearchPredicate *)predicate;
- (void)removeSearchPredicate:(ExploreSearchPredicate *)predicate;
- (void)removeAllSearchPredicates;
- (void)removeAllSearchPredicatesUpdatingObservations:(BOOL)update;
- (void)reload;

- (NSString *)combinedColloquialSearchPhrase;
- (BOOL)activeSearchLimitedBySearchedLocation;
- (BOOL)activeSearchLimitedByCurrentMapRegion;
- (void)expandActiveSearchToNextPageOfResults;

- (void)addComment:(NSString *)commentBody forObservation:(ExploreObservation *)observation completionHandler:(PostCompletionHandler)handler;
- (void)addIdentificationTaxonId:(NSInteger)taxonId forObservation:(ExploreObservation *)observation completionHandler:(PostCompletionHandler)handler;
- (void)loadCommentsAndIdentificationsForObservation:(ExploreObservation *)observation completionHandler:(FetchCompletionHandler)handler;

@end