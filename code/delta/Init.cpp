
// Copyright (C) 2019 Force67

#ifdef _WIN32
#include <Windows.h>
#endif

#include <cstdio>
#include <Delta.h>

static bool ValidateCPU()
{
	return true;
}

int DeltaMain()
{
	// we need all cpu features
	if (!ValidateCPU()) {
		std::puts("Error: your cpu does not support all amd jaguar features");
		return -1;
	}

	const std::wstring game(LR"(C:\Users\vince\Desktop\.nomad\JOURNEY_HD\CUSA02172\eboot.bin)");
	/*
	//dt.Boot(LR"(C:\Users\vince\Desktop\.nomad\JOURNEY_HD\CUSA02172\Journey\Journey.elf)");
	//dt.Boot(LR"(C:\Users\vince\Desktop\pup\PS4UPDATE1.PUP.dec)");
	dt.Boot(LR"(C:\Users\vince\Desktop\.nomad\JOURNEY_HD\CUSA02172\eboot.bin)");
	//dt.Boot(LR"(C:\Users\vince\Desktop\.nomad\Angry_Birds_Star_Wars_1_01_PS4-LFC\CUSA00184\eboot.bin)");*/

	// create a delta instance
	auto& dt = Delta::Get();
	
	// boot the title
	dt.Boot(game);

	getchar();
	return 0;
}

#ifdef _WIN32

// windows platform init
int wmain()
{
	// raise a win console
	::AllocConsole();
	::AttachConsole(GetCurrentProcessId());
	::SetConsoleTitleW(L"Dev Console");

	FILE* file = nullptr;
	freopen_s(&file, "CON", "w", stdout);
	freopen_s(&file, "CONIN$", "r", stdin);

	// todo: lock app mutex


	//void* m = VirtualAlloc(nullptr, 0x7fffffff, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	//std::printf("test %p\n", m);

	return DeltaMain();
}
#endif