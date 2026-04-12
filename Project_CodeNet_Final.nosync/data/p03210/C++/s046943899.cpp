#include<stdio.h>
int a;
int main() {
    scanf("%d", &a);
    printf("%s", (a == 3 || a == 5 || a == 7) ? "YES" : "NO");
    return 00;
}