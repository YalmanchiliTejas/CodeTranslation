#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define int long long
using namespace std;
typedef vector<int>   vint;
typedef pair<int,int> pint;

int N,M,ans;
vint G[10];
bool vis[10];

bool dfs(int v,int c){
    vis[v]=1;
    if(c==N) ans++;
    for(int u:G[v]){ 
        if(!vis[u]) dfs(u,c+1);
    }
    vis[v]=0;
}

signed main()
{
    cin>>N>>M;
    REP(i,M){
        int a,b; cin>>a>>b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0,1);
    cout<<ans<<endl;
}
