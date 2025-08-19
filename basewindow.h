#ifndef BASEWINDOW_H
#define BASEWINDOW_H
#include <windows.h>
class BaseWindow
{
public:
    BaseWindow(const wchar_t* class_name, const wchar_t* window_text, HINSTANCE hInst);
    bool RegisterMyClass();
    bool CreateMyWindowEx();
    HWND GetHwnd();

    LRESULT static CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
    const wchar_t* M_CLASS_NAME = nullptr;
    const wchar_t* m_window_text = nullptr;
    HINSTANCE m_hInstance = nullptr;
    HWND m_hwnd = nullptr;
    WNDCLASS m_window_class_description = {};

};

#endif // BASEWINDOW_H
