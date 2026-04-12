#include <bits/stdc++.h>
using namespace std;
using Int = long long;
using Graph = vector<vector<pair<int, int>>>;
template <class T>
using priority_queue_min = priority_queue<T, vector<T>, greater<T>>;
Graph minimum_spanning_tree(const Graph &g) {
    Graph ans(g.size());
    priority_queue_min<tuple<int, int, int>> Q;
    vector<bool> used(g.size());
    int cnt = 0;
    used[0] = true;
    cnt++;
    for (auto &e : g[0]) {
        Q.emplace(e.second, 0, e.first);
    }
    while (cnt < g.size()) {
        int cost, src, dst;
        tie(cost, src, dst) = Q.top();
        Q.pop();
        if (!used[dst]) {
            used[dst] = true;
            cnt++;
            ans[src].emplace_back(dst, cost);
            ans[dst].emplace_back(src, cost);
            for (auto &e : g[dst]) {
                if (!used[e.first]) Q.emplace(e.second, dst, e.first);
            }
        }
    }
    return ans;
}
Int sum_edge(const Graph &g) {
    Int ans = 0;
    for (auto &es : g) for (auto &e : es) ans += e.second;
    return ans / 2;
}
vector<vector<int>> max_edge(const Graph &g) {
    vector<vector<int>> ans(g.size(), vector<int>(g.size()));
    stack<pair<int, int>> S;
    for (int i = 0; i < g.size(); i++) {
        S.emplace(i, -1);
        while (!S.empty()) {
            int curr, prev;
            tie(curr, prev) = S.top();
            S.pop();
            for (auto &e : g[curr]) if (prev != e.first) {
                S.emplace(e.first, curr);
                ans[i][e.first] = max(ans[i][curr], e.second);
            }
        }
    }
    return ans;
}
int main() {
    int N, M; cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c; a--, b--;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }
    G = minimum_spanning_tree(G);
    auto sum = sum_edge(G);
    auto maxE = max_edge(G);
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int s, t; cin >> s >> t; s--, t--;
        cout << sum - maxE[s][t] << '\n';
    }
    return 0;
}
