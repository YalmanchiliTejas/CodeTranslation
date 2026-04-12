#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<vector<bool>> adj;

int dfs(int now, vector<bool> visited) {
    bool all_visited = true;
    for (int i = 0; i < N; i++) {
        all_visited &= visited[i];
    }
    if (all_visited) return 1;

    int cnt = 0;
    for (int nxt = 0; nxt < N; nxt++) {
        if (!adj[now][nxt]) continue;
        if (visited[nxt]) continue;

        visited[nxt] = true;
        cnt += dfs(nxt, visited);
        visited[nxt] = false;
    }
    return cnt;
}

int main() {
    cin >> N >> M;
    adj = vector<vector<bool>>(N, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        adj[u - 1][v - 1] = adj[v - 1][u - 1] = true;
    }
    vector<bool> visited(N, false);
    visited[0] = true;
    cout << dfs(0, visited) << endl;
    return 0;
}