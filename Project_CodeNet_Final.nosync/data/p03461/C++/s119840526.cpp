#include <stdio.h>
#include <algorithm>

int A, B, d[11][11], f[101][101];

int main() {
    scanf("%d %d", &A, &B);
    for (int i = 1; i <= A; ++i) {
        for (int j = 1; j <= B; ++j) {
            scanf("%d", &d[i][j]);
        }
    }

    for (int a = 0; a <= 100; ++a) {
        for (int b = 0; b <= 100; ++b) {
            f[a][b] = 0;
            for (int x = 1; x <= A; ++x) {
                for (int y = 1; y <= B; ++y) {
                    f[a][b] = std::max(f[a][b], d[x][y] - x * a - y * b);
                }
            }
        }
    }
    for (int x = 1; x <= A; ++x) {
        for (int y = 1; y <= B; ++y) {
            int D = 1e9;
            for (int a = 0; a <= 100; ++a) {
                for (int b = 0; b <= 100; ++b) {
                    D = std::min(D, a * x + b * y + f[a][b]);
                }
            }
            if (D != d[x][y]) {
                printf("Impossible\n");
                return 0;
            }

        }
    }

    puts("Possible");
    printf("%d %d\n", 202, 101 * 101 + 200);
    for(int i = 1; i <= 100; ++i) {
        printf("%d %d X\n", i, i + 1);
    }
    for(int i = 102; i <= 201; ++i) {
        printf("%d %d Y\n", i, i + 1);
    }
    for(int a = 0; a <= 100; ++a) {
        for(int b = 0; b <= 100; ++b) {
            printf("%d %d %d\n", a + 1, 202 - b, f[a][b]);
        }
    }
    printf("1 202\n");

    return 0;
}