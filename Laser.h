#pragma once
#using <System.dll>
#include "SMObjects.h"
#include "NetworkedModule.h"

using namespace System;
using namespace System::Threading;
using namespace System::Diagnostics;

ref class Laser : public NetworkedModule
{
public:

    Laser(SM_ThreadManagement^ SM_TM, SM_Laser^ SM_Laser);

    error_state setupSharedMemory();  
    void threadFunction() override;
    error_state processHeartbeats();
    void shutdownModules() override;
    bool getShutdownFlag() override;
    error_state communicate() override;
    error_state checkData();
    error_state processSharedMemory() override;
    error_state connect(String^ hostName, int portNumber) override;
    
    

    ~Laser() {};

private:
    SM_ThreadManagement^ SM_TM_;
    SM_Laser^ SM_Laser_;
    Stopwatch^ Watch;
};