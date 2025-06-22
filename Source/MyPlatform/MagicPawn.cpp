// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicPawn.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMagicPawn::AMagicPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	    // 카메라 생성 및 루트에 붙이기
    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    CameraComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMagicPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMagicPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMagicPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

