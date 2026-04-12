#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
const int N=15;
const int mod=1e9+7;
const double eps=1e-8;
const double PI = acos(-1.0);
#define lowbit(x) (x&(-x))
vector<int> g[N];
ll ans=0,n,m;
int vis[N];
void dfs(int u)
{
    int num=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])
            num++;
    }
    if(num==n)
        ans++;
    for(int i:g[u])
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs(i);
            vis[i]=0;
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis[1]=1;
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
