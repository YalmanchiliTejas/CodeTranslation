#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define MOD 1000000007
#define INF 1e7
#define LINF 1e15
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
// 'a' = 97 'z' = 122 => 'a' = 0 'z' = 25

int dfs(int v, vector<bool> visited, Graph G){
    bool all_visited = true;
    rep(i, visited.size()){
        if(!visited[i]) all_visited = false;
    }
    if(all_visited) return 1;
    
    int ret = 0;
    
    rep(i, visited.size()){
        if(G[i][v] == 0) continue;
        if(visited[i]) continue;
        
        visited[i] = true;
        ret += dfs(i, visited, G);
        visited[i] = false;
    }
    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;
    Graph G(n, vector<int>(n));
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a][b] = 1; G[b][a] = 1;
    }
    vector<bool> visited(n);
    
    visited[0] = true;
    
    cout << dfs(0, visited, G) << endl;
    return 0;
}


