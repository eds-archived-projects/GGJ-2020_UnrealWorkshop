// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

// Unreal Engine
#include "CoreMinimal.h"
#include "GameFramework/Character.h"

// Unreal Header Tool
#include "UE_AdvancedWorkshopCharacter.generated.h"



UCLASS(config=Game)
class AUE_AdvancedWorkshopCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	AUE_AdvancedWorkshopCharacter();

	FORCEINLINE class USpringArmComponent* GetCameraBoom  () const { return CameraBoom  ; }   /** Returns CameraBoom subobject **/
	FORCEINLINE class UCameraComponent*    GetFollowCamera() const { return FollowCamera; }   /** Returns FollowCamera subobject **/

	
protected:

	/**
		 * Called via input to turn look up/down at a given rate.
		 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
		 */
	void LookUpAtRate(float Rate);

	void MoveForward(float Value);   /** Called for forwards/backward input */
	void MoveRight  (float Value);   /** Called for side to side input */

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);   /** Handler for when a touch input begins. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);   /** Handler for when a touch input stops. */
	
	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);


	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface


// Declares

public:

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;


private:

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;
};

