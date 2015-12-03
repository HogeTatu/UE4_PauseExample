#include "PauseExample.h"
#include "PauseUserWidget.h"

UPauseUserWidget::UPauseUserWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UPauseUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	UWorld* World = GEngine->GameViewport->GetWorld();

	if (World == nullptr)
	{
		return;
	}

	if (World->IsPaused() && !bTickEvenWhenPaused)
	{
		return;
	}

	UUserWidget::NativeTick(MyGeometry, InDeltaTime);
}

bool UPauseUserWidget::GetTickableWhenPaused()
{
	return bTickEvenWhenPaused;
}

void UPauseUserWidget::SetTickableWhenPaused(bool bTickableWhenPaused)
{
	bTickEvenWhenPaused = bTickableWhenPaused;
}
