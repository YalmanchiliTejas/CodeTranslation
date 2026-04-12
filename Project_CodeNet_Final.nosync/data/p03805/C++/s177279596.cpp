#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define FOR(i,k,n) for(int i=k;i<n;i++)
#define FORR(i,k,n) for(int i=k;i<=n;i++)
#define scan(a) scanf("%d",&a)
#define scann(a,b) scanf("%d%d",&a,&b)
#define scannn(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define mst(a,n)  memset(a,n,sizeof(a))
#define ll long long
#define N 10
#define mod 1000000007
#define INF 0x3f3f3f3f

const double eps=1e-8;
const double pi=acos(-1.0);

int n,m;
vector<int> g[N];
int vis[N];
int ans;

void Dfs(int u)
{
    int j=1;
    for(;j<=n;j++)
    {
        if(!vis[j]) break;
    }
    if(j>n)
    {
        ans++;
        return ;
    }
    for(int i=0;i<g[u].size();i++)
    {
        if(!vis[g[u][i]])
        {
            vis[g[u][i]]=1;
            Dfs(g[u][i]);
            vis[g[u][i]]=0;
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scann(n,m);
    int u,v;
    for(int i=0;i<m;i++)
    {
        scann(u,v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis[1]=1;
    Dfs(1);
    printf("%d\n",ans);
    return 0;
}
