#ifndef _WINMAIN_H
#define _WINMAIN_H

//C Runtime Header Files
#ifndef _WINDOW_
	#include <Windows.h>
#endif // !_WINDOW_

int _tmain(int argc, char* argv[]);
int CALLBACK WinMain(HINSTANCE hInctance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);


#endif //_WINMAIN_H