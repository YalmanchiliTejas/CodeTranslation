#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int x;
    scanf("%d", &x);
    if (x >= 30) {
        printf("Yes");
        return 0;
    } else {
        printf("No");
        return 0;
    }

    return 0;
}