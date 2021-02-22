// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CCollectible.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TP_PLATFORMER_API UCCollectible : public UActorComponent
{
	GENERATED_BODY()

	float flt_rotation;
	int32 n_scoreadd;
	AActor* actor;
	UStaticMeshComponent* cylinder;

public:	
	// Sets default values for this component's properties
	UCCollectible();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* sound;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void CollectOnOverlap();
		
};
