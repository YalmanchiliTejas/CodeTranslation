#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int> > G, int n, bool *visited, int u) {
    bool all_visited = true;
    for (int i = 0; i < n; i++) {
        if (visited[i] == false)
            all_visited = false;
    }

    if (all_visited) {
        return 1;
    }

    int ret = 0;

    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (visited[v])
            continue;
        
        visited[v] = true;
        ret += dfs(G, n, visited, v);
        visited[v] = false;
    }

    return ret;
}

int main() {
    int n, m;   cin >> n >> m;
    vector<vector<int> > G(n);
    int a, b;   
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    visited[0] = true;

    int ans = dfs(G, n, visited, 0);

    cout << ans << endl;

    return 0;
}