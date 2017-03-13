#include "WinMain.h"

//Additional include files
#include "Engine.h"

#ifndef _STRING_H
	#include "string.h"
#endif // !_SRING_H
#ifndef _IOSTREAM_H
	#include "iostream.h"
#endif // !_IOSTREAM_H
#ifndef _DELETEMACRO_H
	#include "deletemacros.h"
#endif // !_DELETEMACRO_H



#if defined (DEBUG) | defined (_DEBUG)
int _tmain(int argc, char* argv[])
{
	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	//Logger::Log("Starting the Program");

	//Run Main Function
	WinMain((HINSTANCE)GetModuleHandle(NULL), 0, 0, SW_SHOW);
}
#endif // debug

int WINAPI WinMain(HINSTANCE hInctance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hInctance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);

#if defined (DEBUG) | defined(_DEBUG)
	HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);
/*
	//Runtime memory leak check for dbg builds
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(0);
*/
#endif //debug check
	
	//Create Engine
	Engine* pEngine = new Engine();

	//Kick off the Game
	int result = pEngine->RunLoop();

	//Delete the engine
	SafeDelete (pEngine);
	
	return result;
}