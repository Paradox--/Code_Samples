//---------------------------------------------------------------------------------------------------------------------------------------
// This is the scene director class. It Controls the Scenes weather elements.															-
// Nicholas Mallonee																													-
//---------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------
// Pragma's and defines																													-
//---------------------------------------------------------------------------------------------------------------------------------------
#pragma once

//---------------------------------------------------------------------------------------------------------------------------------------
// Libraries and Includes																												-
//---------------------------------------------------------------------------------------------------------------------------------------
#include "GameFramework/Actor.h"
#include "SceneDirector.generated.h"

//---------------------------------------------------------------------------------------------------------------------------------------
// Scene Control Enums																													-
//---------------------------------------------------------------------------------------------------------------------------------------
UENUM(BlueprintType)
enum class ESceneSettingDefine												// -- Defines if we need to overwrite any settings on run -- // 
{
	Random_NoChange,														// Random Generation of scene, will not change over time
	Random_Change,															// Random Generation of Scene, will not change over time
	Developer_Set_NoChange,													// Start at Developer Setting, do not change anything in the scene
	Developer_Set_Change,													// Start at Developer Setting, Change over time
	Static																	// Static Settings, No change over time nor generation
};

UENUM(BlueprintType)
enum class ESceneWeather : uint8											// -- How the Scenes Weather Will be -- //
{
	Cloudy,																	// Overcast
	Sunny_NoClouds,															// Sun with no clouds
	Sunny_WithClouds,														// Sun with Some Clouds
	Rain_Light,																// Overcast with drizzle
	Rain_Medium,															// Overcast with a moderate Rain
	Rain_Heavy,																// Overcast with a heavy rain 
	Override																// Developer Can set their own pattern
};

UENUM(BlueprintType)
enum class ESceneTime : uint8												// -- Effects What time of day the scene will be -- // 
{
	Midnight,																// Midnight  -- 0:00 till 3:59am
	Early_Morning,															// Early MRN -- 4:00 till 5:59am
	Morning,																// Morning   -- 6:00 till 9:59am 
	Late_Morning,															// LTE MRN   -- 10   till Noon
	Afternoon,																// AFTNOON   -- 12   till 4:59pm
	Early_Evening,															// Early EVN -- 5:00 till 6:59pm
	Evening,																// Evening   -- 7:00 till 9:59pm
	Late_Evening,															// Late EVN  -- 10   till 11:59pm
	Static_Midnight,														// Always Midnight
	Static_Morning,															// Always Morning
	Static_Afternoon,														// Always Afternoon
	Static_Evening,															// Always Evening, 
	Static_Night															// Always Night
};

UENUM(BlueprintType)
enum class EScenePopulation : uint8											// -- Population of the Scene -- // 
{
	No_Population,															// No Pop -- No People other than the required amount
	Low_Population,															// Low	  -- Few People in the Scene other than the required                   -- Simulates a small town
	Med_Population,															// Med	  -- More than a few people 3 to 5 people extra per required person	   -- Simulates a med town
	High_Population															// HGH    -- A large number of peoople 7 to 10 people per required person	   -- Simulates a large town 	
};

UENUM(BlueprintType)
enum class ESceneMood : uint8												// -- Scenes Overall Vibe or Feeling -- // 
{
	Busy,																	// People going from place to place
	Calm,																	// No one starting fights, calm but busy
	Chaos,																	// Fighting or Violence
	Peaceful,																// No sudden movements now...
	Static																	// Scene's Mood Does not Change
};

//---------------------------------------------------------------------------------------------------------------------------------------
// Scene Control Enums																													-
//---------------------------------------------------------------------------------------------------------------------------------------
USTRUCT(BlueprintType)
struct FSceneInformation
{
	GENERATED_USTRUCT_BODY()

		// -- Private -- Settings for Scene -- // 
private:
	ESceneSettingDefine sceneMasterSetting;

	ESceneMood sceneMood;

	ESceneTime sceneTime;

	EScenePopulation scenePop;

	ESceneWeather sceneWeather;

	// -- Public -- Accessors and Mutators -- // 
public:
	void setSceneMood(ESceneMood newMood)
	{
		sceneMood = newMood;
	}

	void setSceneTime(ESceneTime newTime)
	{
		sceneTime = newTime;
	}

	void setScenePop(EScenePopulation newPop)
	{
		scenePop = newPop;
	}

	void setSceneWeather(ESceneWeather newWeather)
	{
		sceneWeather = newWeather;
	}

	ESceneSettingDefine getSceneDefine()
	{
		return sceneMasterSetting;
	}

	ESceneMood getSceneMood()
	{
		return sceneMood;
	}

	ESceneTime getSceneTime()
	{
		return sceneTime;
	}

	EScenePopulation getScenePopulation()
	{
		return scenePop;
	}

	ESceneWeather getSceneWeather()
	{
		return sceneWeather;
	}
	
	// -- Public --  Constructor -- // 
public:
	FSceneInformation()
	{
		sceneMasterSetting = ESceneSettingDefine::Static;
		sceneMood = ESceneMood::Static;
		sceneTime = ESceneTime::Static_Afternoon;
		scenePop = EScenePopulation::No_Population;
		sceneWeather = ESceneWeather::Sunny_WithClouds;
	}
};


UCLASS()
class ASceneDirector : public AActor
{
	GENERATED_BODY()
	
	// -- Public Information -- Constructor and Engine Events -- // 
public:	
	ASceneDirector();

	virtual void BeginPlay() override;
	
	virtual void Tick( float DeltaSeconds ) override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// -- Private Information -- Scene Setting Struct -- //
private:
	FSceneInformation sceneInfo; 	

	// -- Public Information -- Scene Master Variables -- // 
public:
	UPROPERTY(EditDefaultsOnly, Category = "Scene Master Settings")
	bool bIsStaticScene;

	UPROPERTY(EditDefaultsOnly, Category = "Scene Master Settings")
	bool bWantChangeOfScene;

	UPROPERTY(EditDefaultsOnly, Category = "Scene Master Settings")
	bool bWantRandomScene;

	UPROPERTY(EditDefaultsOnly, Category = "Scene Master Settings")
	bool bWantDeveloperScene; 

	UPROPERTY(EditDefaultsOnly, Category = "Scene Master Settings")
	bool bWantCustomTimeForHours;

	UPROPERTY(EditDefaultsOnly, Category = "Scene Master Settings")
	bool bWantOverrideForWeatherCycle;

	UPROPERTY(EditDefaultsOnly, Category = "Scene Master Settings")
	bool bWantSimulateDays;

	// -- Public Information -- Scene Time Scale Settings -- //
public:
	UPROPERTY(EditDefaultsOnly, Category = "Scene Time Scale Settings")
	bool bWantEvenDayNight;													/* Click True if you want Even Days and Nights.
																			   This Will override longer days and Nights 
																			 */

	UPROPERTY(EditDefaultsOnly, Category = "Scene Time Scale Settings")
	bool bWantLongerDaysThanNights;											/* Click True If you want longer Days than nights */

	UPROPERTY(EditDefaultsOnly, Category = "Scene Time Scale Settings")
	bool bWantLongerNightsThanDays;											/* Click True If you want longer nights than Days */

	UPROPERTY(EditDefaultsOnly, Category = "Scene Time Scale Settings")
	int32 numberOfHoursPerDay;												/* Number of In Game Hours Than Equals One In Game Day */

	UPROPERTY(EditDefaultsOnly, Category = "Scene Time Scale Settings")
	float timeScalePerHour_EvenSplit;										/* Number of Real World Minutes Per In Game Hour 
																			   This Only Applies to if Want Even Day Night is True 
																			 */

	UPROPERTY(EditDefaultsOnly, Category = "Scene Time Scale Settings")
	float timeScalePerHour_LongerDay;										/* Number of Real World Minutes Per In Game Hour */

	UPROPERTY(EditDefaultsOnly, Category = "Scene Time Scale Settings")
	float timeScalePerHour_LongerNight;										/* Number of Real World Minutes Per In Game Hour */

	// -- Public Information -- Scene Weather Settings -- //
public: 
	UPROPERTY(EditDefaultsOnly, Category = "Scene Weather Settings")
	bool bIsModerateClimate;

	UPROPERTY(EditDefaultsOnly, Category = "Scene Weather Settings")
	bool bIsWarmClimate;

	UPROPERTY(EditDefaultsOnly, Category = "Scene Weather Settings")
	bool bIsColdClimate;

	UPROPERTY(EditDefaultsOnly, Category = "Scene Weather Settings")
	bool bIsTropicClimate;

	UPROPERTY(EditDefaultsOnly, Category = "Scene Weather Settings")
	bool bIsDesertClimate;

	UPROPERTY(EditDefaultsOnly, Category = "Scene Weather Settings")
	bool bIsMountainClimate; 

	UPROPERTY(EditDefaultsOnly, Category = "Scene Weather Settings")
	bool bIsHighAltitude; 

	UPROPERTY(EditDefaultsOnly, Category = "Scene Weather Settings")
	bool bIsLowAltittude;

	UPROPERTY(EditDefaultsOnly, Category = "Scene Weather Settings")
	TArray<ESceneWeather> customWeatherCycle; 


};
