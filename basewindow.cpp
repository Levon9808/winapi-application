#include "basewindow.h"

BaseWindow::BaseWindow(const wchar_t* class_name, const wchar_t* window_text, HINSTANCE hInst) : m_hInstance(hInst) {
    M_CLASS_NAME = class_name;
    m_window_text = window_text;
}


bool BaseWindow::RegisterMyClass(){
    m_window_class_description.lpfnWndProc = WindowProc;
    m_window_class_description.hInstance = m_hInstance;
    m_window_class_description.lpszClassName = M_CLASS_NAME;

    return RegisterClass(&m_window_class_description) != 0;
}

bool BaseWindow::CreateMyWindowEx(){
    m_hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        M_CLASS_NAME,                     // Window class
        m_window_text,                  // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window
        NULL,       // Menu
        m_hInstance,  // Instance handle
        NULL        // Additional application data
    );
    return m_hwnd != NULL;
}

LRESULT CALLBACK BaseWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);  // <- вот это важно!
        return 0;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}


HWND BaseWindow::GetHwnd(){
    return m_hwnd;
}
