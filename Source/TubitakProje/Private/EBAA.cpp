// Fill out your copyright notice in the Description page of Project Settings.

#include "EBAA.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"

// Sets default values
AEBAA::AEBAA()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Taným
	Export = 0;
	SetURL = "https://www.google.com";


}

// Called every frame
void AEBAA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//
/*EBAAnaliz Fonksyonu*/
void AEBAA::EBAAnaliz(FString SetUrl, bool Completed, int32 & basari)
{
}


// Sets default values
AEBAA::AEBAA(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//When the object is constructed, Get the HTTP module
	Http = &FHttpModule::Get();
}

// Called when the game starts or when spawned
void AEBAA::BeginPlay()
{
	//MyHttpCall();
	//Super::BeginPlay();
}

/*Http call*/
void AEBAA::MyHttpCall(FString URL)
{
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &AEBAA::OnResponseReceived);
	//This is the url on which to process the request
	Request->SetURL(URL);
	Request->SetVerb("GET");
	Request->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");
	Request->SetHeader("Content-Type", TEXT("text/html"));
	Request->ProcessRequest();
}

/*Assigned function on successfull http call*/
void AEBAA::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	Export = Response->GetContentAsString();
	//const FString htmlResult = Response->GetContentAsString();
	//Create a pointer to hold the json serialized data
	//TSharedPtr<FJsonObject> JsonObject;

	//Create a reader pointer to read the json data
	//TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	//Deserialize the json data given Reader and the actual object to deserialize
	//if (FJsonSerializer::Deserialize(Reader, JsonObject))
	//{
		//Get the value of the json object by field name
		//int32 recievedInt = JsonObject->GetIntegerField("customInt");

		//Output it to the engine
		//GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, FString::FromInt(recievedInt));
		//GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, TEXT(htmlResult));
	//}
}