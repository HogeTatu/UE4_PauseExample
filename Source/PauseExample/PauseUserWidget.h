#pragma once

#include "Blueprint/UserWidget.h"
#include "PauseUserWidget.generated.h"

UCLASS(Abstract, editinlinenew, BlueprintType, Blueprintable, meta=( Category="User Controls", DontUseGenericSpawnObject="True" ) )
class PAUSEEXAMPLE_API UPauseUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPauseUserWidget(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category="Utilities")
	bool GetTickableWhenPaused();

	UFUNCTION(BlueprintCallable, Category="Utilities")
	void SetTickableWhenPaused(bool bTickableWhenPaused);

protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

public:
	UPROPERTY(EditDefaultsOnly, Category="Tick", AdvancedDisplay)
	bool bTickEvenWhenPaused;
};
