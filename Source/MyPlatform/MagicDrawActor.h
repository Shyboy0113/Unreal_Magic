#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MagicDrawActor.generated.h"

UCLASS()
class MYPLATFORM_API AMagicDrawActor : public AActor
{
    GENERATED_BODY()

public:
    AMagicDrawActor();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    bool bWasMouseDown = false;
};
