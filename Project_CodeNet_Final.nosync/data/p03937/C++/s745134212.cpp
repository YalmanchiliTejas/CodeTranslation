#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define MAXN 15
using namespace std;
char malt[MAXN][MAXN];
int n, m;
bool inMap(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    else
        return true;
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%s", malt[i]);
    int num = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(malt[i][j] == '#') num++;
        }
    }
    bool flag = true;
    int x = 0, y = 0, tmp = 1;
    if(malt[0][0] != '#' || malt[n - 1][m - 1] != '#') flag = false;
    while(x != n - 1 || y != m - 1)
    {
        //cout << x << " " << y << endl;
        if(inMap(x + 1, y) && malt[x + 1][y] == '#')
        {
            tmp++;
            x = x + 1, y = y;
        }
        else if(inMap(x, y + 1) && malt[x][y + 1] == '#')
        {
            tmp++;
            x = x, y = y + 1;
        }
        else
        {
            flag = false;
            break;
        }
    }
    if(flag && tmp == num) puts("Possible");
    else
        puts("Impossible");
    return 0;
}
