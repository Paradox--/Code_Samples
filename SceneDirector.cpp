// Fill out your copyright notice in the Description page of Project Settings.

#include "AI_Simulator.h"
#include "SceneDirector.h"


//---------------------------------------------------------------------------------------------------------------------------------------
// Constructors																															-
//---------------------------------------------------------------------------------------------------------------------------------------
ASceneDirector::ASceneDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// -- Scene Master Setting Defaults
	bIsStaticScene = true; 
	bWantChangeOfScene = false; 
	bWantRandomScene = false; 
	bWantDeveloperScene = false; 
	bWantCustomTimeForHours = false;
	bWantOverrideForWeatherCycle = false; 
	bWantSimulateDays = false; 

	// -- Scene Time Settings
	bWantEvenDayNight = false; 
	bWantLongerDaysThanNights = false; 
	bWantLongerNightsThanDays = false; 
	numberOfHoursPerDay = 24; 
	timeScalePerHour_EvenSplit = 14.f; 
	timeScalePerHour_LongerDay = 0.f;
	timeScalePerHour_LongerNight = 0.f; 


	// -- Scene Weather Settings
	bIsModerateClimate = true; 
	bIsWarmClimate = false; 
	bIsColdClimate = false;
	bIsTropicClimate = false; 
	bIsDesertClimate = false;
	bIsMountainClimate = false; 
	bIsHighAltitude = false;
	bIsLowAltittude = false;
}

//---------------------------------------------------------------------------------------------------------------------------------------
// Engine Events																														-
//---------------------------------------------------------------------------------------------------------------------------------------
void ASceneDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASceneDirector::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


void ASceneDirector::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

}

