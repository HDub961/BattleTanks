// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward Declaration
class UTankBarrel;
class AProjectile;

UCLASS()
class BT_API ATank : public APawn
{
	GENERATED_BODY()

public:

	/*void AimAt(FVector HitLocation);*/

	UFUNCTION(BlueprintCallable)
	void Fire();


private:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	// Local barrel reference for spawning projectiles
	UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;
};
