#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<vector<int> > g;
int n, m;
vector<bool> v;

void dfs(int curr, int ver){
    if(ver == n){
        ans++;
        return;
    }
    v[curr] = true;
    for(int i=0 ; i<g[curr].size() ; i++){
        if(v[g[curr][i]] == true){
            continue;
        }
        dfs(g[curr][i], ver+1);
    }
    v[curr] = false;
}

int main(){
    cin >> n >> m;
    g.resize(n+1);
    for(int i=0 ; i< m ;i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    v.resize(n+1, 0);
    dfs(1, 1);
    cout << ans << '\n';
    return 0;
}
