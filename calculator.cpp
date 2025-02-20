#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include<cstdlib>
#include<stdio.h>
#include<cstdio>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

HWND textfield, textbox1, textbox2, button1, button2, button3, button4;
char textSaved1[20], textSaved2[20];

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("My Calculator"),       /* Title Text */
           WS_SYSMENU,          /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           250,                 /* The programs width */
           200,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:

            textfield = CreateWindow("STATIC",
                                     "Please input two number",
                                     WS_VISIBLE | WS_CHILD | WS_BORDER,
                                     20, 20, 200, 25,
                                     hwnd, NULL, NULL, NULL);
            textbox1 = CreateWindow("EDIT",
                                     "",
                                     WS_VISIBLE | WS_CHILD | WS_BORDER,
                                     20, 50, 200, 25,
                                     hwnd, NULL, NULL, NULL);
            textbox2 = CreateWindow("EDIT",
                                     "",
                                     WS_VISIBLE | WS_CHILD | WS_BORDER,
                                     20, 80, 200, 25,
                                     hwnd, NULL, NULL, NULL);
            button1 = CreateWindow("BUTTON",
                                  "+",
                                  WS_VISIBLE | WS_CHILD | WS_BORDER,
                                  40, 110, 30, 25,
                                  hwnd, (HMENU) 1, NULL, NULL);
            button2 = CreateWindow("BUTTON",
                                  "-",
                                  WS_VISIBLE | WS_CHILD | WS_BORDER,
                                  80, 110, 30, 25,
                                  hwnd, (HMENU) 2, NULL, NULL);
            button3 = CreateWindow("BUTTON",
                                  "*",
                                  WS_VISIBLE | WS_CHILD | WS_BORDER,
                                  120, 110, 30, 25,
                                  hwnd, (HMENU) 3, NULL, NULL);
            button4 = CreateWindow("BUTTON",
                                  "*",
                                  WS_VISIBLE | WS_CHILD | WS_BORDER,
                                  160, 110, 30, 25,
                                  hwnd, (HMENU) 4, NULL, NULL);

            break;
        case WM_ERASEBKGND:
            {
                HDC hdc = (HDC)wParam;
                RECT rect;
                GetClientRect(hwnd, &rect);

                HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 400));
                FillRect(hdc, &rect, hBrush);
                DeleteObject(hBrush);
                return 1;
            }
        case WM_COMMAND:

            if(LOWORD(wParam) == 1)
            {
                    int gwtstat1 = 0, gwtstat2 = 0;
                    gwtstat1 = GetWindowText(textbox1, &textSaved1[0], 20);
                    gwtstat2 = GetWindowText(textbox2, &textSaved2[0], 20);
                    double x = atof(textSaved1) + atof(textSaved2);
                    char t[100];
                    sprintf(t, "%f", x);
                    ::MessageBox(hwnd, t, "result", MB_OK);

            }
            else if(LOWORD(wParam) == 2)
            {
                    int gwtstat1 = 0, gwtstat2 = 0;
                    gwtstat1 = GetWindowText(textbox1, &textSaved1[0], 20);
                    gwtstat2 = GetWindowText(textbox2, &textSaved2[0], 20);
                    double x = atof(textSaved1) - atof(textSaved2);
                    char t[100];
                    sprintf(t, "%f", x);
                    ::MessageBox(hwnd, t, "result", MB_OK);
            }
            else if(LOWORD(wParam) == 3)
            {
                    int gwtstat1 = 0, gwtstat2 = 0;
                    gwtstat1 = GetWindowText(textbox1, &textSaved1[0], 20);
                    gwtstat2 = GetWindowText(textbox2, &textSaved2[0], 20);
                    double x = atof(textSaved1) * atof(textSaved2);
                    char t[100];
                    sprintf(t, "%f", x);
                    ::MessageBox(hwnd, t, "result", MB_OK);
            }
            else if(LOWORD(wParam) == 4)
            {
                    int gwtstat1 = 0, gwtstat2 = 0;
                    gwtstat1 = GetWindowText(textbox1, &textSaved1[0], 20);
                    gwtstat2 = GetWindowText(textbox2, &textSaved2[0], 20);
                    double x = atof(textSaved1) / atof(textSaved2);
                    char t[100];
                    sprintf(t, "%f", x);
                    ::MessageBox(hwnd, t, "result", MB_OK);
            }

            break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
