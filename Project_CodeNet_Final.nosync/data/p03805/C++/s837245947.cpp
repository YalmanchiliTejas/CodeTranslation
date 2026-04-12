#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#define SS(i) scanf("%s",i)
#define SC(i) scanf("%d",&i)
#define SCC(i,j) scanf("%d%d",&i,&j)
#define SCCC(i,j,z) scanf("%d%d%d",&i,&j,&z)
#define PR(i) printf("%d\n",i)
#define LL long long
#define FF(i,a,b) for(int i=a;i<=b;++i)
#define RR(i,a,b) for(int i=a;i>=b;--i)
#define CL(i,x) memset(i,x,sizeof(i))
#define IN freopen("in.txt","r",stdin)
#define OUT  freopen("out.txt","w",stdout)
#define PB(i) push_back(i)
#define min(x,y) ((x>y)?(y):(x))
#define max(x,y) ((x<y)?(y):(x))
#define abs(i) (i<0?(-i):i)
#define lson x,m,rt<<1
#define rson m+1,y,rt<<1|1
using namespace std;
const int N=200000+10;

vector<int>g[10];

int ans;
int vis[10];
int n, m;

void dfs(int u)
{
    int ok = 1;
    FF(i, 1, n) if(vis[i]==0){
        ok = 0;
        break;
    }
    if(ok){
        ans += 1; return;
    }
    int sz = g[u].size();
    FF(i, 0, sz-1)
    {
        int v = g[u][i];
        if(!vis[v]){
            vis[v] = 1;
            dfs(v);
            vis[v] = 0;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
   
#endif


    SCC(n, m);
    FF(i, 1, m)
    {
        int x, y; SCC(x, y);
        g[x].PB(y); g[y].PB(x);
    }
    ans = 0;
    vis[1] = 1;
    dfs(1);
    PR(ans);
    return 0;
}
