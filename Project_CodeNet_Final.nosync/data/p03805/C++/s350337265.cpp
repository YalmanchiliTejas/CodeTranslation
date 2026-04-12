#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;
int N, M;
vector<vector<int>> g;
vector<bool> visited;

int dfs(int u){
    bool visited_all = true;
    for (int i=0;i<N;i++){
        if (!visited[i]) visited_all = false;
    }
    if (visited_all){
        return 1;
    }
    int res = 0;
    for (int v: g[u]){
        if (visited[v]) continue;
        visited[v] = true;
        res += dfs(v);
        visited[v] = false;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    g = vector<vector<int>>(N);
    visited = vector<bool>(N,false);
    for (int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    visited[0] = true;
    int ans = dfs(0);
    cout << ans << "\n";
}