#include <iostream>
#include <cstdio>
using namespace std;
int d[11][11], f[111][111];

int main(void)
{
    int A, B, ok = 1;
    scanf("%d %d", &A, &B);
    for(int i = 1; i <= A; i++)
        for(int j = 1; j <= B; j++)
            scanf("%d", &d[i][j]);
    for(int x = 1; x <= A; x++)
    for(int y = 1; y <= B; y++)
    for(int a = 0; a <= 100; a++)
    for(int b = 0; b <= 100; b++)
    f[a][b] = max(f[a][b], d[x][y] - x * a - y * b);
    for(int x = 1; x <= A; x++)
    for(int y = 1; y <= B; y++)
    {
        int tmp = 1111;
        for(int a = 0; a <= 100; a++)
        for(int b = 0; b <= 100; b++)
            tmp = min(x * a + y * b + f[a][b], tmp);
        if(tmp != d[x][y]) ok = 0;
    }
    if(!ok) puts("Impossible");
    else
    {
        puts("Possible");
        printf("202 10401\n");
        for(int i = 1; i <= 100; i++) printf("%d %d X\n", i, i + 1);
        for(int i = 102; i <= 201; i++) printf("%d %d Y\n", i, i + 1);
        for(int i = 1; i <= 101; i++)
            for(int j = 102; j <= 202; j++)
                printf("%d %d %d\n", i, j, f[i-1][202-j]);
        printf("1 202\n");
    }
    return 0;
}
