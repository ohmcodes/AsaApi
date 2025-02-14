#pragma once

#include "../../IApiUtils.h"

// Actor extensions

FORCEINLINE FVector ActorExtensions::GetActorForwardVector()
{
    AActor* _this = static_cast<AActor*>(this);
    USceneComponent* RootComponent = _this->RootComponentField().Get();
    if (RootComponent)
    {
        return RootComponent->ComponentToWorldField().GetUnitAxis(EAxis::X);
    }

    //return FVector::ZeroVector;
    return FVector(0, 0, 0);
}

FORCEINLINE bool ActorExtensions::IsA(UClass* SomeBase)
{
    return static_cast<AActor*>(this)->ClassPrivateField()->IsChildOf(SomeBase);
}

FORCEINLINE FVector ActorExtensions::GetLocation()
{
    AActor* _this = static_cast<AActor*>(this);
    auto* root = _this->RootComponentField().Get();
    if (root)
    {
        UE::Math::TTransform<double> transform = root->ComponentToWorldField();
        return transform.GetLocation();
    }
    return FVector();
}

// Player Controller Extensions

FORCEINLINE FString PlayerControllerExtensions::GetEOSId()
{
    AShooterPlayerController* _this = static_cast<AShooterPlayerController*>(this);
    FString eos_id = "";
    
    _this->GetUniqueNetIdAsString(&eos_id);

    return eos_id;
}

FORCEINLINE FString PlayerControllerExtensions::GetCharacterName()
{
    AShooterPlayerController* _this = static_cast<AShooterPlayerController*>(this);
    FString characterName = "";
    _this->GetPlayerCharacterName(&characterName);
    return characterName;
}


FORCEINLINE FString PlayerControllerExtensions::GetTribeName()
{
	AShooterPlayerController* _this = static_cast<AShooterPlayerController*>(this);
	FString tribeName = "";
    if (_this->IsInTribe())
        tribeName = ((AShooterPlayerState*)_this->PlayerStateField().Get())->MyTribeDataField().TribeNameField();

    return tribeName;
}