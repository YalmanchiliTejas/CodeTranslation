#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int src, dst, rev;
    bool in;
    Edge(int s, int d, bool in, int rev = 0) :
        src(s), dst(d), rev(rev), in(in) {}
};

class GiftExchangeParty {
public:
    GiftExchangeParty(int n, int m) : n(n), m(m), g(n), deg(n) {}

    // src から dst へ向き付けを行う
    void add_edge(const int src, const int dst, const bool in) {
        g[src].emplace_back(Edge(src, dst, in, g[dst].size()));
        g[dst].emplace_back(Edge(dst, src, !in, g[src].size() - 1));
        ++deg[dst];
    }

    pair<int, int> MinimumDiff() {
        vector<bool> visited(n, false);

        while (true) {
            int min_idx = distance(deg.begin(), min_element(deg.begin(), deg.end()));
            int max_idx = distance(deg.begin(), max_element(deg.begin(), deg.end()));

            fill(visited.begin(), visited.end(), false);
            if (Dfs(min_idx, deg[min_idx] + 2, -1, true, visited)) continue;

            min_idx = distance(deg.begin(), min_element(deg.begin(), deg.end()));
            max_idx = distance(deg.begin(), max_element(deg.begin(), deg.end()));

            fill(visited.begin(), visited.end(), false);
            if (!Dfs(max_idx, -1, deg[max_idx] - 2, false, visited)) break;
        }

        return {*min_element(deg.begin(), deg.end()), *max_element(deg.begin(), deg.end())};
    }

private:
    int n, m;
    vector<vector<Edge>> g;
    vector<int> deg; // 入次数

    bool Dfs(const int cur, const int lb, const int ub, bool dir, vector<bool> &visited) {
        if (visited[cur]) return false;
        if ((!dir && deg[cur] <= ub) || (dir && lb <= deg[cur])) return true;

        visited[cur] = true;
        for (auto &e : g[cur]) {
            if (e.in == dir && Dfs(e.dst, lb, ub, dir, visited)) {
                if (dir) { // min
                    ++deg[e.src]; --deg[e.dst];
                    e.in = false; g[e.dst][e.rev].in = true;
                }
                else { // max
                    --deg[e.src]; ++deg[e.dst];
                    e.in = true; g[e.dst][e.rev].in = false;
                }
                return true;
            }
        }

        return false;
    }
};


int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int n, m, u, v;

    while (cin >> n >> m, n) {
        GiftExchangeParty prob(n, m);

        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            prob.add_edge(u - 1, v - 1, true);
        }

        auto ans = prob.MinimumDiff();
        cout << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}

