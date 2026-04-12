#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int A, B, D[11][11], O[111][111], Nw[11][11];

int main() {
    scanf("%d%d", &A, &B);
    for(int i = 1; i <= A; i++)
        for(int j = 1; j <= B; j++)
            scanf("%d", &D[i][j]);
    memset(Nw, 63, sizeof Nw);
    for(int i = 0; i <= 100; i++)
        for(int j = 0; j <= 100; j++) {
            int c = 0;
            for(int a = 1; a <= A; a++)
                for(int b = 1; b <= B; b++)
                    c = max(c, D[a][b] - i * a - j * b);
            O[i][j] = c;
            for(int a = 1; a <= A; a++)
                for(int b = 1; b <= B; b++)
                    Nw[a][b] = min(Nw[a][b], i * a + j * b + c);
        }
    for(int i = 1; i <= A; i++)
        for(int j = 1; j <= B; j++)
            if(D[i][j] != Nw[i][j]) {
                puts("Impossible");
                return 0;
            }
    puts("Possible\n204 10401\n");
    for(int i = 1; i <= 100; i++) printf("%d %d X\n", i, i + 1);
    for(int i = 1; i <= 101; i++)
        for(int j = 102; j <= 202; j++)
            printf("%d %d %d\n", i, j, O[i - 1][202 - j]);
    for(int i = 102; i <= 201; i++) printf("%d %d Y\n", i, i + 1);
    puts("1 202");
    return 0;
}