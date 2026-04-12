// Created by sz
#include <bits/stdc++.h>
using namespace std;

const int N = 9;
int n,m, cnt = 0, vis[N];

vector<int> g[N];

void dfs(int node, int pre){
    vis[node] = 1;
    
    int ok = 1;
    for (int i = 0; i < n; i++){
        if(vis[i] ==0)ok = 0;
    }
    if(ok == 1) cnt++;
    
    for(auto i: g[node]){
        if (i == pre) continue;
        if (vis[i])continue;
        dfs(i, node);
    }
    
    vis[node] = 0;
    
}

int main(){
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    int a, b;
    for (int i = 1; i <= m; i++){
        cin>>a>>b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    dfs(0,-1);
    
    cout<<cnt<<endl;
    
    return 0;
}

