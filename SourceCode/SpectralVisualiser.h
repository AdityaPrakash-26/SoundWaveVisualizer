// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpectralVisualiser.generated.h"

UCLASS()
class MYPROJECT3_API ASpectralVisualiser : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpectralVisualiser();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
    
    void Refresh();
    
    UPROPERTY(EditAnywhere, Category = "Audio")
    class UTimeSynthComponent* TimeSynthComponent;
    
    UPROPERTY(EditAnywhere, Category = "Audio")
    class UTimeSynthClip* TimeSynthClip;
    
    UPROPERTY(EditAnywhere, Category = "Audio")
    TArray<UStaticMeshComponent*> SpectrumBars;
    
    UPROPERTY(EditAnywhere, Category = "Audio")
    float SpectrumBarSpacing;       //this is the distance between two bars
    
    UPROPERTY(EditAnywhere, Category = "Audio")
    UStaticMesh* SpectrumBarMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
