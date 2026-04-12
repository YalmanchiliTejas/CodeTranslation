#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define log(x,b) (log(b)/log(x))
#define rep(i,x,y) for(int i=(x);i<(y);i++)
using namespace std;

vi graph[8];
bool vis[8];
int res,n,m;
void dfs(int u,int cnt){
    if(cnt==n){
        res++;
        return;
    }
    vis[u]=1;
    for(auto v:graph[u]){
        if(!vis[v]){
            vis[v]=1;
            dfs(v,cnt+1);
            vis[v]=0;
        }
    }
}

int32_t main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(1,1);
    cout<<res<<endl;

    return 0;
}
