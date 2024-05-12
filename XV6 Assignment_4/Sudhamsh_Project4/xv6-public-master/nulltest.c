#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
    char *nullPointer = 0;

    // Demonstrating a null pointer dereference using a char pointer
    printf(1, "Testing Null Pointer Dereference: %c\n", *nullPointer);

    exit();
}