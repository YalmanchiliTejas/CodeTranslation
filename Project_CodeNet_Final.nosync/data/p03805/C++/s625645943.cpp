// Created by sz
#include <bits/stdc++.h>
using namespace std;

const int N = 8;
int n,m, ans = 0, vis[N];
vector<int> g[N];

void dfs(int u, int p){
    vis[u] = 1;
    int allvis = 1;
    for (int i = 0; i < n; i++){
        if(vis[i] == 0) allvis = 0;
    }
    if(allvis) {
        ans++;
        vis[u] = 0;
        return;
    }
    for (auto  v: g[u]) {
        if(!vis[v]&&v!=p) dfs(v, u);
    }
    vis[u] = 0;
}



int main(){
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    cin>>n>>m;
    int u,v;
    for (int i = 0; i < m; i++){
        cin>>u>>v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(0, -1);
    cout<<ans<<endl;
    
    return 0;
}
