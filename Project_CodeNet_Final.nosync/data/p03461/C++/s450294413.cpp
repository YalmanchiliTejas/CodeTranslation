#include <bits/stdc++.h>
using namespace std;

const int N = 200 + 5;

int n, m, d[N][N], f[N][N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &d[i][j]);
    for (int i = 0; i <= 100; ++i)
        for (int j = 0; j <= 100; ++j)
            for (int x = 1; x <= n; ++x)
                for (int y = 1; y <= m; ++y)
                    f[i][j] = max(f[i][j], d[x][y] - i * x - j * y);
    for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= m; ++y) {
            int tmp = INT_MAX;
            for (int i = 0; i <= 100; ++i)
                for (int j = 0; j <= 100; ++j)
                    tmp = min(tmp, i * x + j * y + f[i][j]);
            if (tmp != d[x][y]) { puts("Impossible"); return 0; }
        }
    printf("Possible\n%d %d\n", 202, 10401);
    for (int i = 0; i < 100; ++i) printf("%d %d X\n%d %d Y\n", i + 1, i + 2, 103 + i, 102 + i);
    for (int i = 0; i <= 100; ++i)
        for (int j = 0; j <= 100; ++j) printf("%d %d %d\n", 1 + i, 102 + j, f[i][j]);
    puts("1 102");
    return 0;
}

