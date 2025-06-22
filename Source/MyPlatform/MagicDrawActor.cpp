#include "MagicDrawActor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

AMagicDrawActor::AMagicDrawActor()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMagicDrawActor::BeginPlay()
{
    Super::BeginPlay();

    // 입력 활성화
    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (PC)
    {
        EnableInput(PC);
        UE_LOG(LogTemp, Warning, TEXT("✅ Input enabled!"));
    }
}

void AMagicDrawActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (!PC) return;

    if (PC->IsInputKeyDown(EKeys::LeftMouseButton))
    {
        if (!bWasMouseDown)
        {
            bWasMouseDown = true;

            float X, Y;
            if (PC->GetMousePosition(X, Y))
            {
                UE_LOG(LogTemp, Warning, TEXT("🖱️ Mouse clicked at: X = %f, Y = %f"), X, Y);
            }

            // 커서 숨김
            PC->bShowMouseCursor = false;
        }
    }
    else
    {
        if (bWasMouseDown)
        {
            // 마우스를 뗐을 때 커서 다시 보이게
            PC->bShowMouseCursor = true;
        }
        bWasMouseDown = false;
    }
}

