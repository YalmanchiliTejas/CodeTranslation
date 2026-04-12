#include <stdio.h>

int main(void) {
    char a, b, c;
    a = getchar();
    b = getchar();
    c = getchar();

    if ((a == b) && (a == c) && (b = c)){
        printf("No\n");
    }
    else {
        printf("Yes\n");
    }
    return 0;
}