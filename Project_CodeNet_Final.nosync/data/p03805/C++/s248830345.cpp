#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define pi pair<int,int>
#define all(v) v.begin(),v.end()
const int MOD = 1e9+7;
template <typename A>istream& operator>>(istream& input,vector<A>& x) {for(auto& i:x)input>>i;return input;}
template<typename A>ostream& operator<<(ostream& output,vector<A>& x) {for(auto& i:x)output<<i<<' ';return output;}
vector<int> g[10];
vector<bool> vis;
int n,m,ans=0;
void dfs(int u,int cnt)
{
  if(cnt==n){
    ans++;
    return;
  }
  vis[u]=true;
  for(auto it:g[u])
    if(!vis[it])dfs(it,cnt+1);
  vis[u]=false;
}
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int T=1;
    //cin>>T;
    vis.assign(10,false);
    while(T--)
    {
        
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
          int x,y;
          cin>>x>>y;
          g[x].pb(y);
          g[y].pb(x);

        }
        dfs(1,1);
        cout<<ans<<"\n";
    }

}
