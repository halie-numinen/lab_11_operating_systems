#include <windows.h>
#include <stdio.h>

int main () {
    SYSTEM_INFO si;
    MEMORY_BASIC_INFORMATION memoryInformation;
    SIZE_T size = 1048576; //2^20

    GetSystemInfo(&si);
    printf("1. Page size: %lu\n", si.dwPageSize);
    void* ptr = VirtualAlloc(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (ptr == NULL) {
        printf("Allocation failed\n");
        return 1;
    }
    printf("2. Memory allocated for a size of %zu bytes\n", size);
    if (VirtualQuery(ptr, &memoryInformation, sizeof(memoryInformation))) {
        printf("3. System Queried to determine the state of the allocated memory.\n");
        printf("4. The state of the alocated memory: ");
        if (memoryInformation.State == MEM_COMMIT) {
            printf("Committed\n");
        }
        else if (memoryInformation.State == MEM_RESERVE) {
            printf("Reserved\n");
        }
        else if (memoryInformation.State == MEM_FREE) {
            printf("Freed\n");
        }
    }
    else {
        printf("VirtualQuery failed\n");
    }
    if (!VirtualFree(ptr, 0, MEM_RELEASE)) {
        printf("Release failed.\n");
    }
    else {
        printf("5. De-allocating memory\n");
    }
    return 0;
}
