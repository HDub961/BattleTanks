#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/*** 
This controls the tanks movement
*/

// Forward Declaration
class ATank;
class UTankTrack;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BT_API UTankMovementComponent : public UNavMovementComponent
{	
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMoveForward(float Throw);

private:

	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;

};
