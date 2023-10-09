#ifndef _APPWINDOW_H
#define _APPWINDOW_H

#ifndef _STDIO_DEFINED
#include <stdio.h>
#endif // _STDIO_DEFINED

#ifndef _WINDOWS_
#include <windows.h>
#endif // _WINDOWS_

#ifndef _DISPLAYMONITOR_H
#include "DisplayMonitor.h"
#endif // _DISPLAY_MONITOR_H

#ifndef MAX_TITLE_LENGTH
#define MAX_TITLE_LENGTH 256
#endif // MAX_TITLE

#define APPWND_OOB_POSITION (0x1)
#define APPWND_OOB_SIZE (0x2)


// Represents a Windows process application with a visible rectangle.
typedef struct {

	HWND handle;
	DWORD processId;

	DisplayMonitor monitor;

	TCHAR title[MAX_TITLE_LENGTH];

	int width;
	int height;
	int x;
	int y;

} AppWindow;


BOOL GetAppWindow (HWND hWnd, AppWindow* window);
BOOL IsValidAppWindow (const HWND hWnd);
BOOL IsWindowMaximized (const AppWindow* window);
BOOL IsWindowFullScreen (const AppWindow* window);
BOOL IsWindowOutOfBounds (const AppWindow* window, UINT flags);
BOOL GetAppWindowExecutable (const AppWindow* window, TCHAR exeName[], DWORD maxSize);
BOOL CenterWindow (const AppWindow* window, const BOOL useWorkArea);


#endif // _APPWINDOW_H
