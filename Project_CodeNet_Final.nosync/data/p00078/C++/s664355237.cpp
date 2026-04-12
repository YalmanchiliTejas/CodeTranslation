#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n), n) {
        int a[15][15] = {}, x = n / 2, y = x + 1;
        a[y][x] = 1;

        for (int i = 2; i <= n * n; i++) {
           y = (y + 1) % n, x = (x + 1) % n;
           if (a[y][x]) y = (y + 1 + n) % n, x = (x - 1 + n) % n;
           a[y][x] = i; 
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%4d", a[i][j]);
            printf("\n");
        }
    }

    return 0;
}
