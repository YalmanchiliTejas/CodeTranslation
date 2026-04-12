#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int n,m,ans=0;
Graph g;
vector<bool>seen;
void dfs(int x){
    seen[x]=true;
    bool flag=true;
    rep(i,n){
        if(!seen[i]){
            flag=false;
        }
    }
    if(flag){
        ans++;
        return;
    }


    for(int next_x:g[x]){
        if(seen[next_x])continue;
        seen[next_x]=true;
        dfs(next_x);
        seen[next_x]=false;
    }
    return;
}
int main(int argc, const char * argv[]) {

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    int a,b;
    g.resize(n);
    seen.resize(n);
    rep(i,m){
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    seen[0]=true;
    dfs(0);
    cout<<ans<<endl;


    return 0;
}

