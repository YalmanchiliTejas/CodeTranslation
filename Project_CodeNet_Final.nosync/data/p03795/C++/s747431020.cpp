#include <cstdio>


int main() {
    int n;
    scanf("%d", &n);
    int d = n / 15;
    int rez = 800 * n;
    rez = rez - d * 200;
    printf("%d", rez);
    return 0;
}
