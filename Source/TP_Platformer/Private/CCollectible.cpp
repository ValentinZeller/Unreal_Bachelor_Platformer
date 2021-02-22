// Fill out your copyright notice in the Description page of Project Settings.


#include "CCollectible.h"
#include "CCharacter.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

// Sets default values for this component's properties
UCCollectible::UCCollectible()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	flt_rotation = 2.5f;
	n_scoreadd = 10;
	// ...
}


// Called when the game starts
void UCCollectible::BeginPlay()
{
	Super::BeginPlay();
	actor = GetOwner();
	cylinder = actor->FindComponentByClass<UStaticMeshComponent>();
	// ...
	
}


// Called every frame
void UCCollectible::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	if (cylinder) {
		cylinder->AddLocalRotation(FRotator(flt_rotation, 0.0, 0.0));
	}

	CollectOnOverlap();

	
	
	// ...
}

void UCCollectible::CollectOnOverlap()
{
	bool bl_isOverlap = actor->IsOverlappingActor(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (bl_isOverlap) {

		ACCharacter* player = Cast<ACCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());


		if (player) {
			player->SetScores(player->GetScores() + n_scoreadd);

		}
		UGameplayStatics::PlaySound2D(this, sound);
		actor->Destroy();
	}
}

