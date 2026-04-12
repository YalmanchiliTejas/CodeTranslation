#include <algorithm>
#include <cstdio>

const int N = 11;

int a, b, d[N][N], delta[101][101];
bool ok[N][N];

int main()
{
    scanf("%d%d", &a, &b);
    int cnt = 0, left = a * b;
    for (int i = 1; i <= a; ++ i) {
        for (int j = 1; j <= b; ++ j) {
            scanf("%d", d[i] + j);
            cnt = std::max(cnt, d[i][j]);
        }
    }
    for (int i = 0; i <= cnt; ++ i) {
        for (int j = 0; j <= cnt; ++ j) {
            int& dt = delta[i][j];
            dt = 0;
            for (int x = 1; x <= a; ++ x) {
                for (int y = 1; y <= b; ++ y) {
                    dt = std::max(dt, d[x][y] - i * x - j * y);
                }
            }
            for (int x = 1; x <= a; ++ x) {
                for (int y = 1; y <= b; ++ y) {
                    if (dt + i * x + j * y == d[x][y]) {
                        left -= !ok[x][y];
                        ok[x][y] = true;
                    }
                }
            }
        }
    }
    if (left) {
        puts("Impossible");
    } else {
        puts("Possible");
        printf("%d %d\n", 2 * (cnt + 1), 2 * cnt + (cnt + 1) * (cnt + 1));

        for (int i = 0; i < cnt; ++ i) {
            printf("%d %d X\n", i + 1, i + 2);
            printf("%d %d Y\n", i + cnt + 3, i + cnt + 2);
        }
        for (int i = 0; i <= cnt; ++ i) {
            for (int j = 0; j <= cnt; ++ j) {
                printf("%d %d %d\n", i + 1, j + cnt + 2, delta[i][j]);
            }
        }
        printf("%d %d\n", 1, cnt + 2);
    }
}
