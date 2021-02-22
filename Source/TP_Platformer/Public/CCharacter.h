// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CCharacter.generated.h"

UCLASS()
class TP_PLATFORMER_API ACCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	int32 scores = 0;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	int32 live = 3;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	int32 GetScores();

	UFUNCTION(BlueprintCallable)
	void SetScores(int32 value);

	//Movement

	void MoveForwarBackward(float flt_scale);


	void MoveLeftRight(float flt_scale);


	void Turn(float flt_scale);


	void LookUp(float flt_scale);


	void Jump()override;
};
