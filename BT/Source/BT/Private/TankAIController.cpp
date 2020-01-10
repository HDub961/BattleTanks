// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#define OUT

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController doesn't see Player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO MKove towards player

		AimTowardsPlayer();

		// TODO Fire at player
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	APlayerController* PlayerPC = GetWorld()->GetFirstPlayerController();

	return Cast<ATank>(PlayerPC->GetPawn());
}

void ATankAIController::AimTowardsPlayer()
{
	if (!GetControlledTank()) { return; }

	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

}