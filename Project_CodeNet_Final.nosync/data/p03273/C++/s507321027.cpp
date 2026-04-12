#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define writeln printf("\n")
using namespace std;
typedef long long LL;
typedef double DB;
const int MAXN = 20;
const DB eps = 1e-7;
int len;
LL n, m;
int a[1000][1000];
bool val[1000][2];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        bool row = true;
        for (int j = 1; j <= m; j ++)
        {
            char ch;
            cin >> ch;
            if (ch == '#') a[i][j] = 1;
            else if (ch == '.') a[i][j] = 2;
            if (a[i][j] == 1) row = false;
        }
        val[i][0] = row;
//        printf("val[%d][0]=%d\n", i, val[i][0]);
    }
    for (int i = 1; i <= m; i ++)
    {
        bool col = true;
        for (int j = 1; j <= n; j ++) if (a[j][i] == 1) col = false;
        val[i][1] = col;
    }
    for (int i = 1; i <= n; i ++)
    {
        if (val[i][0]) continue;
        for (int j = 1; j <= m; j ++)
        {
            if (val[j][1]) continue;
            if (a[i][j] == 1) printf("#");
            else printf(".");
        }
        printf("\n");
    }
}
/*
*/