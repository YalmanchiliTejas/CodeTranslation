#include <bits/stdc++.h>

using namespace std;

template<typename Weight>
class Dinic {
public:
    Dinic(const int n) : n(n), g(n), INF(numeric_limits<Weight>::max()) {}

    void add_edge(const int src, const int dst, const Weight cap) {
        g[src].emplace_back(Edge(src, dst, cap, g[dst].size()));
        g[dst].emplace_back(Edge(dst, src, 0, g[src].size() - 1));
    }

    // O(|E||V|^2)
    Weight MaximumFlow(const int s, const int t) {
        Weight flow = 0;

        while(true) {
            vector<int> level(n, -1), iter(n);
            Bfs(s, level);
            if(level[t] == -1) break;
            for (Weight f = 0; (f = Dfs(s, t, INF, level, iter)) > 0; )
                flow += f;
        }

        return flow;
    }

private:
    struct Edge {
        int src, dst, rev;
        Weight weight;
        Edge(int f, int t, Weight cap, int rev = 0) :
            src(f), dst(t), rev(rev), weight(cap) {}
    };

    int n;
    vector<vector<Edge>> g;
    const Weight INF;

    void Bfs(const int s, vector<int> &level){
        queue<int> que;
        for (level[s] = 0, que.push(s); !que.empty(); ) {
            const int v = que.front(); que.pop();
            for (auto &e : g[v])
                if(0 < e.weight && level[e.dst] == -1){
                    level[e.dst] = level[v] + 1;
                    que.push(e.dst);
                }
        }
    }

    Weight Dfs(int v, int t, Weight flow, vector<int> &level, vector<int> &iter) {
        if(v == t) return flow;
        for ( ; iter[v] < (int)g[v].size(); ++iter[v]) {
            Edge &e = g[v][iter[v]];

            if(0 < e.weight && level[v] < level[e.dst]){
                Weight d = Dfs(e.dst, t, min(flow, e.weight), level, iter);
                if(0 < d){
                    e.weight -= d;
                    g[e.dst][e.rev].weight += d;
                    return d;
                }
            }
        }
        return 0;
    }
};

template<class Weight>
class DinicWithLowerBound {
public:
    DinicWithLowerBound(int n) : dinic(n + 2), n(n), S(n), T(n + 1), sum_lb(0) {}

    void add_edge(const int src, const int dst, const int lb, const int ub) {
        if (src == dst || ub == 0) return ;
        dinic.add_edge(src, dst, ub - lb);
        dinic.add_edge(S, dst, lb);
        dinic.add_edge(src, T, lb);
        sum_lb += lb;
    }
    Weight MaximumFlow(const int s, const int t) {
        const Weight f1 = dinic.MaximumFlow(S, T);
        const Weight f2 = dinic.MaximumFlow(s, T);
        const Weight f3 = dinic.MaximumFlow(S, t);
        const Weight f4 = dinic.MaximumFlow(s, t);
        return (f1 + f3 == sum_lb && f1 + f2 == sum_lb) ? f2 + f4 : -1;
    }

private:
    Dinic<Weight> dinic;
    int n, S, T;
    Weight sum_lb;
};

bool Feasible(const int lb, const int ub, const int n, const int m,
              const int s, const int t, auto dinic) {
    for (int v = 0; v < n; ++v)
        dinic.add_edge(s, v, lb, ub);

    return dinic.MaximumFlow(s, t) == m;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int n, m, u, v;

    while (cin >> n >> m, n) {
        // [0, n) : 頂点集合，[n, n + m) : 辺集合, n + m : ソース，n + m + 1 : シンク
        DinicWithLowerBound<int> dinic(n + m + 2);
        const int s = n + m, t = n + m + 1;

        for (int i = n; i < n + m; ++i)
            dinic.add_edge(i, t, 0, 1);
        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            dinic.add_edge(u - 1, n + i, 0, 1);
            dinic.add_edge(v - 1, n + i, 0, 1);
        }

        pair<int, int> ans(0, n);
        int ub = 1;
        for (int lb = 0; lb <= ub && ub < n; ++lb) {
            while (ub < n && !Feasible(lb, ub, n, m, s, t, dinic)) ++ub;

            if (ub - lb < ans.second - ans.first)
                ans = make_pair(lb, ub);
        }

        cout << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}

