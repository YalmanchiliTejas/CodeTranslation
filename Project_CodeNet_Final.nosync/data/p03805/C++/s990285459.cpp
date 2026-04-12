/**
 *    author:  FromDihPout
 *    created: 2020-06-25
**/

#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> adj;

int dfs(int u, vector<bool> seen) {
    int paths = 0;
    seen[u] = true;
    bool all = true;
    for (bool s : seen) {
        if (!s) {
            all = false;
            break;
        }
    }
    if (all) {
        return 1;
    }
    
    for (int v : adj[u]) {
        if (seen[v]) continue;
        paths += dfs(v, seen);
    }
    return paths;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> seen(n);
    cout << dfs(0, seen) << endl;
    return 0;
}