// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle TimerHandler;
	


	FTimerHandle FPSTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(FPSTimerHandle, this, &AMyCharacter::ShowFrameRate, 1.f, true);
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FPS++;

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyCharacter::ShowFrameRate()
{
	GEngine->AddOnScreenDebugMessage(0, 1.f, FColor::Yellow, "FPS: " + FString::FromInt(FPS) + " ms: " + FString::SanitizeFloat(FApp::GetDeltaTime() * 1000));
	FPS = 0;
}


