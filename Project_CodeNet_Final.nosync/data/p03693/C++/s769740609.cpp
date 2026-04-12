#include <stdio.h>

int main() {
    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);
    printf("%s\n", (100*r+10*g+b) % 4 == 0 ? "YES" : "NO");
}