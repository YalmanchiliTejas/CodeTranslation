#include <bits/stdc++.h>
using namespace std;
using unWeightedGraph = vector<vector<int>>;

int N, M;

int dfs(unWeightedGraph graph, vector<bool> visited, int v) {
    bool all_visited = true;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) all_visited = false;
    }
    if (all_visited) return 1;

    int ret = 0;
    for (int i = 0; i < N; i++) {
        if (graph[v][i] == 0) continue;
        if (visited[i]) continue;

        visited[i] = true;
        ret += dfs(graph, visited, i);
        visited[i] = false;
    }
    return ret;
}

int solve() {
    unWeightedGraph graph(N, vector<int>(N));
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--, b--;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    vector<bool> visited(N, false);
    visited[0] = true;
    return dfs(graph, visited, 0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    cout << solve() << endl;
}