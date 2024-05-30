#include "stdio.h"
#include "windows.h"

int main()
{
    printf("Process 1:\n"); //comments
    PROCESS_INFORMATION pi; //another comment
    STARTUPINFO si;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    if (!CreateProcessA(NULL, "\"C:/Windows/write.exe\"", NULL, NULL, FALSE, 8, NULL, NULL, &si, &pi))
    {
        printf("�Process Creation Error\n");
    }

    SetPriorityClass(pi.hProcess, HIGH_PRIORITY_CLASS);

    printf("Process id: %d\n", pi.dwProcessId);
    printf("hProcess: %x\n", pi.hProcess);
    printf("dwThreadID: %d\n", pi.dwThreadId);
    printf("hProcess: %x\n", pi.hProcess);
    printf("Priority class: %d\n", GetPriorityClass(pi.hProcess));

    
    system("pause");
    printf("Process 2:\n");

    if (!TerminateProcess(pi.hProcess, 0)) {
        printf("Process ShutDown Error\n");
        //return 0;
    }

    PROCESS_INFORMATION pi1;
    STARTUPINFO si1;
    ZeroMemory(&si1, sizeof(si1));
    si.cb = sizeof(si1);

    if (!CreateProcessA(NULL, "cmd", NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si1, &pi1))
    {
        printf("�Process Creation Error\n");
    }

    SetPriorityClass(pi1.hProcess, IDLE_PRIORITY_CLASS);

    printf("Process id: %d\n", pi1.dwProcessId);
    printf("hProcess: %x\n", pi1.hProcess);
    printf("dwThreadID: %d\n", pi1.dwThreadId);
    printf("hProcess: %x\n", pi1.hProcess);
    printf("Priority class: %d\n", GetPriorityClass(pi1.hProcess));


    system("pause");

    if (!TerminateProcess(pi1.hProcess, 0)) {
        printf("Process ShutDown Error\n");
        return 0;
    }

    return 0;
}
