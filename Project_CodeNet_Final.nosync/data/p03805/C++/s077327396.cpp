#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>pa;
map<int,int>mp;
const int N=1e7+100;
int n,m;
vector<int>ve[10];
int vis[10];
int ans;
void dfs(int v,int step)
{
    if(step==n){
        ans++;
        return ;
    }
    for(auto k:ve[v]){
        if(!vis[k]){
            vis[k]=1;
            dfs(k,step+1);
            vis[k]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        ve[x].push_back(y);
        ve[y].push_back(x);
    }
    vis[1]=1;
    dfs(1,1);
    cout<<ans<<endl;
    return 0;
}
