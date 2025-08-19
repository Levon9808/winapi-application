#include <iostream>
#include <windows.h>
#include "basewindow.h"


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow){
    BaseWindow MyWindow(L"MyWindowClass", L"BaseWindow", hInstance);
    if(!MyWindow.RegisterMyClass()){
        return 1;
    }
    if(!MyWindow.CreateMyWindowEx()){
        return 1;
    }

    ShowWindow(MyWindow.GetHwnd(), nCmdShow);

    MSG msg = {};

    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
