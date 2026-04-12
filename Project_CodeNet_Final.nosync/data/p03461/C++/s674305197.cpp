#include <iostream>
#include <cstdio>
#include <cstring>

const int INF = 999999999;

int n, m, d[55][55], f[550][550], tmp[55][55];

void Read(int &x)
{
    x = 0; int p = 0; char st = getchar();
    while (st < '0' || st > '9') p = (st == '-'), st = getchar();
    while (st >= '0' && st <= '9') x = (x << 1) + (x << 3) + st - '0', st = getchar();
    x = p ? -x : x;
    return;
}

int Max(int a, int b)
{
    return a > b ? a : b;
}

int Min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &d[i][j]);

    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++) 
            for (int x = 1; x <= n; x++)
                for (int y = 1; y <= m; y++)
                    f[i][j] = Max(f[i][j], d[x][y] - i * x - j * y);

    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= m; y++)
        {
            tmp[x][y] = INF;
            for (int i = 0; i <= 100; i++)
                for (int j = 0; j <= 100; j++)
                    tmp[x][y] = Min(tmp[x][y], i * x + j * y + f[i][j]);
        }


    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if(tmp[i][j] != d[i][j])
            {
                puts("Impossible"); return 0;
            }

    puts("Possible");
    printf("%d %d\n", 202, 10401);
    for (int i = 1; i <= 100; i++) printf("%d %d X\n", i, i + 1);
    for (int i = 102; i <= 201; i++) printf("%d %d Y\n", i, i + 1);
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++)
            printf("%d %d %d\n", i + 1, 202 - j, f[i][j]);
    puts("1 202");
    return 0;
}