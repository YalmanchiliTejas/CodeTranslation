#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G(8,vector<int>(8));
vector<bool> visited(8,false);
int ans;
int n, m;

/*
目的: 頂点を受け取り, 条件を満たすかどうかを探索する. 何も返さない.
*/

void dfs(int v){
    
    bool allVisited = true;
    for (int i = 0; i < n; i++) if (i != v && visited[i] == false) allVisited = false;
    
    if (allVisited){
        ans++;
        return;
    }
    
    visited[v] = true;
    
    for (auto p : G[v]){
        if (!visited[p]) dfs(p);
    }
    
    visited[v] = false;
}

int main(void){
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    ans = 0;
    visited[0] = true;
    dfs(0);
    
    cout << ans << endl;
    return 0;
    
}
