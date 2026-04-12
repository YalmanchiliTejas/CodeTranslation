#include <bits/stdc++.h>

#define rep(x, y) for (int i = (x); i < (y); i++)

typedef long long ll;

using namespace std;

int graph[9][9];

int dfs(int now, int nodes, vector<bool> visited) {
    visited[now] = true;

    int count = 0;
    bool found = false;
    rep(1, nodes) {
        if (graph[now][i] && !visited[i]) {
            found = true;
            count += dfs(i, nodes, visited);
        }
    }

    if (!found) {
        return all_of(visited.begin(), visited.end(), [](bool v) { return v; }) ? 1 : 0;
    } else {
        return count;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int a, b;
    bzero(graph, sizeof(graph));
    rep(0, m) {
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1;
    }

    vector<bool> visited(n + 1, false);
    visited[0] = true;
    int ans = dfs(1, n + 1, visited);

    cout << ans << endl;

    return 0;
}