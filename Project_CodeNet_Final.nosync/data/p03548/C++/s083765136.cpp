#include <stdio.h>

int main() {
    int X, Y, Z;
    scanf("%d %d %d", &X, &Y, &Z);
    int n = X / (Y + Z);
    if (X % (Y + Z) < Z) {
        printf("%d\n", n - 1);
    } else {
        printf("%d\n", n);
    }
    return 0;
}
