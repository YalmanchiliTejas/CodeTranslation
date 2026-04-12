#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const long long MOD = 1e9 + 7;
const int INF = 1e9 + 7;

void dfs(const vector<vector<int>>& graph, int v, vector<bool> is_visit, int& cnt) {
    is_visit[v] = true;
    bool ok = true;
    for (bool b : is_visit) ok &= b;
    if (ok) {
        ++cnt;
        return;
    }
    for (auto u : graph[v]) {
        if (is_visit[u]) continue;
        dfs(graph, u, is_visit, cnt);
    }
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
    int ans = 0;
    dfs(graph, 0, is_visit, ans);
    cout << ans << endl;
}