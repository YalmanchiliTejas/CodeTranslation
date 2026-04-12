#include <bits/stdc++.h>
using namespace std;

struct edge {
    int to, cap, rev;
};

using edges = std::vector<edge>;
using graph = std::vector<edges>;

void add_edge(graph& g, int from, int to, int cap) {
    g[from].push_back(edge{to, cap, static_cast<int>(g[to].size())});
    g[to].push_back(edge{from, 0, static_cast<int>(g[from].size()-1)});
}

int dfs(graph& g, std::vector<bool>& used, int v, int t, int f) {
    if(v == t) {
        return f;
    }
    used[v] = true;
    for(int i=0; i<g[v].size(); ++i) {
        edge& e = g[v][i];
        if(!used[e.to] && e.cap > 0) {
            int d = dfs(g, used, e.to, t, std::min(f, e.cap));
            if(d > 0) {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(graph& g, int s, int t) {
    int flow = 0;
    int INF = 1e9;
    std::vector<bool> used(g.size(), false);
    while(true) {
        std::fill(used.begin(), used.end(), false);
        int f = dfs(g, used, s, t, INF);
        if(f == 0) {
            return flow;
        }
        flow += f;
    }

}

int calc_max(int n, vector<int> const& u, vector<int> const& v) {
    const int m = u.size();
    graph g(n + m + 2);
    const int source = n + m;
    const int dest = n + m + 1;
    for(int i=0; i<m; ++i) {
        add_edge(g, u[i], n + i, 1);
        add_edge(g, v[i], n + i, 1);
        add_edge(g, n + i, dest, 1);
    }
    for(int i=0; i<n; ++i) {
        add_edge(g, source, i, 0);
    }
    int flow = 0;
    int res = 1;
    for(; ; ++res) {
        for(auto& e : g[source]) {
            e.cap += 1;
        }
        flow += max_flow(g, source, dest);
        if(flow == m) {
            break;
        }
    }
    return res;
}

int calc_min(int n, vector<int> const& u, vector<int> const& v) {
    const int m = u.size();
    graph g(n + m + 2);
    const int source = n + m;
    const int dest = n + m + 1;
    for(int i=0; i<m; ++i) {
        add_edge(g, u[i], n + i, 1);
        add_edge(g, v[i], n + i, 1);
        add_edge(g, n + i, dest, 1);
    }
    for(int i=0; i<n; ++i) {
        add_edge(g, source, i, 0);
    }
    int res = 0;
    int flow = 0;
    for(int i = 1; i <= 100; ++i) {
        for(auto& e : g[source]) {
            e.cap += 1;
        }
        flow += max_flow(g, source, dest);
        if(flow == n * i) {
            res = i;
        }
    }
    return res;
}

int main() {
    int n, m;
    while(cin >> n >> m, n) {
        vector<int> u(m), v(m);
        for(int i=0; i<m; ++i) {
            cin >> u[i] >> v[i];
            u[i]--;
            v[i]--;
        }
        int ma = calc_max(n, u, v);
        int mi = calc_min(n, u, v);
        cout << mi << ' ' << ma << endl;
    }
}
