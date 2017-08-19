// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "EBAA.generated.h"


UCLASS()
class TUBITAKPROJE_API AEBAA : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEBAA();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*EBAAnaliz Fonksyonu*/
	UFUNCTION(BlueprintCallable, Category = "EBA")
		void EBAAnaliz(FString SetUrl, bool Completed, int32 &basari);

	FHttpModule* Http;

	/* The actual HTTP call */
	UFUNCTION(BlueprintCallable, Category = "MyHttpCall")
		void MyHttpCall(FString URL);

	/*Assign this function to call when the GET request processes sucessfully*/
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	// Sets default values for this actor's properties
	AEBAA(const class FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EBA")
		FString Export;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EBA")
		FString SetURL;
};
