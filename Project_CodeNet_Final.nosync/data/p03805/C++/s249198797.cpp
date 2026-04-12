#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> graph;

int dfs(int from, vector<bool> visited, int cnt) {
    if (cnt == N - 1) return 1;

    visited[from] = true;
    int res = 0;
    for (int to : graph[from]) {
        if (visited[to]) continue;
        res += dfs(to, visited, cnt + 1);
    }
    visited[from] = false;

    return res;
}

int main() {
    cin >> N >> M;
    graph.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> visited(N, false);
    cout << dfs(0, visited, 0) << endl;
    return 0;
}