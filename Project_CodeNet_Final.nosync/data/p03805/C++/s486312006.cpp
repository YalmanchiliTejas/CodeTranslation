#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const long long MOD = 1e9 + 7;
const int INF = 1e9 + 7;

int dfs(const auto& graph, int v, auto is_visit) {
    is_visit[v] = true;
    bool ok = true;
    for (bool b : is_visit) ok &= b;
    if (ok) return 1;
    
    int res = 0;
    for (int u : graph[v]) {
        if (is_visit[u]) continue;
        res += dfs(graph, u, is_visit);
        is_visit[u] = false;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> is_visit(N, false);
    cout << dfs(graph, 0, is_visit) << endl;
}