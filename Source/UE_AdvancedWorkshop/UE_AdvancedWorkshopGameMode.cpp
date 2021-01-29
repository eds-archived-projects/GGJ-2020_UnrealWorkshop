// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

// Parent Header
#include "UE_AdvancedWorkshopGameMode.h"

// Unreal
#include "UObject/ConstructorHelpers.h"

// Advanced Workshop
#include "UE_AdvancedWorkshopCharacter.h"



AUE_AdvancedWorkshopGameMode::AUE_AdvancedWorkshopGameMode()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	//if (PlayerPawnBPClass.Class != NULL)
	//{
		//DefaultPawnClass = PlayerPawnBPClass.Class;
	//}
}
