#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <tr1/unordered_set>
#include <tr1/unordered_map>
#include <bitset>
#include <cassert>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define inf 1e9
#define debug(a) cout << #a" = " << (a) << endl;
#define debugarry(a, n) for (int i = 0; i < (n); i++) { cout << #a"[" << i << "] = " << (a)[i] << endl; }
#define clr(x, y) memset(x, y, sizeof x)
#define LL long long
#define uLL unsigned LL

using namespace std;

const int maxn = 300;

int sub[maxn*10],len;

int X1[maxn], Y1[maxn], X2[maxn], Y2[maxn];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int TT[maxn][maxn], par[maxn*maxn];
int vis[maxn*maxn];
int n;

int id(int x,int y)
{
    return x * 250 + y;
}
void init()
{
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
            par[id(i, j)] = id(i, j);
}
int Find(int x)
{
    if(x==par[x]) return x;
    return par[x] = Find(par[x]);
}
void unite(int u,int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v) return ;
    par[u] = v;
}
bool in(int x, int y)
{
    if (x < 0 || x >= len) return false;
    if (y < 0 || y >= len) return false;
    return true;
}

int solve()
{
    init();
    for (int x = 0; x < len; x++)
        for (int y = 0; y < len; y++)
            for (int k = 0; k < 4; k++)
            {
                if ((TT[x][y]>>k)&1) continue;
                int nx = x + dx[k], ny = y + dy[k];
                if (in(nx, ny))
                {
                    if ((TT[nx][ny]>>(k^1))&1) continue;
                    unite(id(x, y), id(nx, ny));
                }
            }
    clr(vis, 0);
    for (int x = 0; x < len; x++)
        for (int y = 0; y < len; y++)
        {
            vis[Find(id(x, y))] = 1;
        }
    int ans = 0;
    for (int i = 0; i <= id(len,len); i++)
     {
        if (vis[i]) ans++;
     }
    return ans;
}

int main()
{
   // freopen("input.txt", "r", stdin);
    int ta;
    while(scanf("%d", &n) == 1, n)
    {
        ta = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&X1[i],&Y1[i],&X2[i],&Y2[i]);
            sub[ta++] = X1[i];
            sub[ta++] = X2[i];
            sub[ta++] = Y1[i];
            sub[ta++] = Y2[i];
            if( X1[i] > X2[i] ) swap(X1[i],X2[i]);
            if( Y1[i] > Y2[i] ) swap(Y1[i],Y2[i]);
        }
        sub[ta++] = -1;
        sub[ta++] = 1e6 + 10;
        sort(sub,sub+ta);
        len = unique(sub,sub+ta) - sub;
        for(int i=0;i<n;i++)
        {
            //printf(">>%d %d %d %d\n",X1[i],X2[i],Y1[i],Y2[i]);
            X1[i] = lower_bound(sub,sub+len,X1[i]) - sub;
            X2[i] = lower_bound(sub,sub+len,X2[i]) - sub;
            Y1[i] = lower_bound(sub,sub+len,Y1[i]) - sub;
            Y2[i] = lower_bound(sub,sub+len,Y2[i]) - sub;
        }
        clr(TT, 0);
        for (int i = 0; i < n; i++)
        {
            for (int y = Y1[i]; y < Y2[i]; y++)
                TT[X1[i]][y] |= 1;
            for (int y = Y1[i]; y < Y2[i]; y++)
                TT[X2[i]-1][y] |= (1<<1);
            for (int x = X1[i]; x < X2[i]; x++)
                TT[x][Y1[i]] |= (1<<2);
            for (int x = X1[i]; x < X2[i]; x++)
                TT[x][Y2[i]-1] |= (1<<3);
        }
//    for (int x = 0; x < len; x++)
//    {
//        for (int y = 0; y < len; y++)
//            printf("%c", TT[x][y] > 0 ? '*':'.');
//        printf("\n");
//    }

        printf("%d\n",solve());
//    for (int x = 0; x < len; x++)
//    {
//        for (int y = 0; y < len; y++)
//            printf("%6d", Find(id(x,y)));
//        printf("\n");
//    }

    }
    return 0;
}