#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <functional>
#include <utility>
#include <cstring>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

struct node
{
    int x, y;
};

const int inf = 0x3f3f3f3f;

char s[60][60];
int l[60][60];
int k[60][60];
int g[60][60];
int rx[1010], ry[1010];
int vis[60][60];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int r, c, m;
int mx, my;
vector <node> a;
vector <node> z;

int dfs(int x, int y, int fx, int fy)
{
    if(x == mx && y == my)
        return 1;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c || s[nx][ny] == '#')
            continue;
        if(nx == fx && ny == fy)
            continue;
        if(dfs(nx, ny, x, y) == 1)
        {
            node xin;
            xin.x = nx, xin.y = ny;
            a.push_back(xin);
            return 1;
        }
    }
    return 0;
}

int main()
{
    while(~scanf("%d%d%d", &r, &c, &m))
    {
        memset(vis, -1, sizeof(vis));
        for(int i = 0; i < r; i++)
            scanf("%s", s[i]);
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                scanf("%d", &l[i][j]);
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                scanf("%d", &k[i][j]);
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                scanf("%d", &g[i][j]);
        for(int i = 0; i < m; i++)
            scanf("%d%d", &rx[i], &ry[i]);
        z.clear();
        node qi;
        qi.x = rx[0], qi.y = ry[0];
        z.push_back(qi);
        for(int i = 1; i < m; i++)
        {
            a.clear();
            if(rx[i] == rx[i - 1] && ry[i] == ry[i - 1])
                continue;
            mx = rx[i], my = ry[i];
            dfs(rx[i - 1], ry[i - 1], -1, -1);
            for(int j = a.size() - 1; j >= 0; j--)
            {
                node aa = a[j];
                z.push_back(aa);
            }
        }
//        printf("\n\n");
//        for(int i = 0; i < z.size(); i++)
//        {
//            printf("%d %d\n", z[i].x, z[i].y);
//        }
        long long sum = 0;
        int i;
        for(i = 0; i < z.size(); i++)
        {
            int nx = z[i].x;
            int ny = z[i].y;
            sum += k[nx][ny] + g[nx][ny];
            //cout << sum << endl;
            if(vis[nx][ny] == -1)
            {
                vis[nx][ny] = i;
                continue;
            }
            if((long long)(i - vis[nx][ny]) * l[nx][ny] <  k[nx][ny] + g[nx][ny])
            {
               // printf("%d\n", (k[nx][ny] + g[nx][ny]) - (i - vis[nx][ny) * l[nx][ny]);
                sum -= (k[nx][ny] + g[nx][ny]) - (i - vis[nx][ny]) * l[nx][ny];
            }
            //printf("\n");
            vis[nx][ny] = i;
        }
        //sum += g[rx[i]][ry[i]];
        cout << sum << endl;
    }
    return 0;
}