#include <windows.h>
#include <stdio.h>

int main () {
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    printf("Page size: %lu\n", si.dwPageSize);
    
    return 0;
}
