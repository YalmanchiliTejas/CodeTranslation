#include <cstdio>

int r, g, b;
int main(){
    scanf("%d %d %d", &r, &g, &b);
    int n = r * 100 + g * 10 + b;

    printf("%s\n", n % 4 == 0 ? "YES" : "NO");

    return 0;
}
