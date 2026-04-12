#include<bits/stdc++.h>
#include<numeric>
using namespace std;
#define ll  long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<ll,ll>
#define pb push_back
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define what_is(x) cerr << #x << " is " << x << endl;
#define mod 1000000007
int edge[8][8];int ans=0;
int vis[8];int n,m;
void dfs(int v,int count)
{
    if(count==n-1)
    {
        int temp=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i])
            temp++;
        }
        if(temp==n)
        ans++;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i]&&edge[v][i])
        {
            vis[i]=1;
            dfs(i,count+1);
            vis[i]=0;
        }
    }
}
int main()
{
    int u,v;
    cin >> n >> m ;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        u--;
        v--;
        edge[u][v]=1;
        edge[v][u]=1;
    }
    vis[0]=1;
    dfs(0,0);
    cout << ans;
}