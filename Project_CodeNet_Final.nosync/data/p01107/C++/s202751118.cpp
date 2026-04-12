#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define rep(i, n) FOR(i, 0, n)

using flow_type = int;

struct dinic {
    struct edge {
        int s, d;
        flow_type c, f;
        int r;
        bool is_r;
    };
    int n, s, t;
    std::vector<std::vector<edge>> g;
    std::vector<int> level, prog, que;
    std::vector<std::pair<std::pair<int, int>, flow_type>> edges;

    dinic(int n_ = 0) : n(n_) {}

    flow_type maximum_flow(int s_, int t_) {
        s = s_;
        t = t_;
        if (g.size()) {
            init();
        } else {
            make_graph();
        }
        que.resize(n);
        flow_type res = 0;
        while (levelize()) {
            prog.assign(n, 0);
            res += augment(s, std::numeric_limits<flow_type>::max());
        }
        return res;
    }

    void add_edge(int u, int v, flow_type c) {
        if (u != v && c != 0) {
            edges.emplace_back(std::make_pair(u, v), c);
        }
    }

    void make_graph() {
        g.assign(n, {});
        std::sort(edges.begin(), edges.end());
        for (auto it = edges.begin(); it != edges.end();) {
            flow_type c = 0;
            auto uv = it->first;
            while (it != edges.end() && it->first == uv) {
                c += it->second;
                ++it;
            }
            int u = uv.first, v = uv.second;
            g[u].push_back({u, v, c, 0, (int)g[v].size(), false});
            g[v].push_back({v, u, c, c, (int)g[u].size() - 1, true});
        }
    }

    void init() {
        for (auto &es : g) {
            for (auto &e : es) {
                e.f = e.is_r ? e.c : 0;
            }
        }
    }

    bool levelize() {
        int fst = 0, lst = 0;
        que[lst++] = s;
        level.assign(n, -1);
        level[s] = 0;
        while (fst != lst) {
            int v = que[fst++];
            if (v == t) break;
            for (auto &e : g[v]) {
                if (level[e.d] == -1 && residue(e) != 0) {
                    level[e.d] = level[v] + 1;
                    que[lst++] = e.d;
                }
            }
        }
        return level[t] != -1;
    }

    flow_type augment(int v, flow_type lim) {
        flow_type res = 0;
        if (v == t) return lim;
        for (int &i = prog[v]; i < (int)g[v].size(); ++i) {
            if (lim == 0) break;
            auto &e = g[v][i];
            if (level[v] < level[e.d] && residue(e) != 0) {
                flow_type aug = augment(e.d, std::min(lim, residue(e)));
                if (aug == 0) continue;
                e.f += aug;
                reverse(e).f -= aug;
                res += aug;
                lim -= aug;
            }
        }
        return res;
    }

    flow_type residue(const edge &e) { return e.c - e.f; }

    edge &reverse(const edge &e) { return g[e.d][e.r]; }
};

using namespace std;
int h, w;
char g[55][55];
const int di[] = {0,1,0,-1};
const int dj[] = {1,0,-1,0};

bool inner(int i, int j) {
    return 0 <= i && 0 <= j && i < h && j < w;
}

int f(int i, int j) {
    return i*w + j;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    while (cin >> h >> w && h) {
        dinic dn(h*w*2);
        rep(i, h) cin >> g[i];
        rep(i, h) rep(j ,w) {
            if (g[i][j] != '#') {
                rep(d, 4) {
                    int ni = i + di[d], nj = j + dj[d];
                    if (inner(ni, nj) && g[ni][nj] != '#') {
                        dn.add_edge(f(i,j), f(ni,nj) + h*w, 1);
                    }
                }
            }
            dn.add_edge(f(i,j) + h*w, f(i,j), 1);
        }

        bool res = 
            dn.maximum_flow(f(0,0),     f(0,w-1) + h*w) == 2 &&
            dn.maximum_flow(f(0,w-1),   f(h-1,w-1) + h*w) == 2 &&
            dn.maximum_flow(f(h-1,w-1), f(h-1,0) + h*w) == 2 &&
            dn.maximum_flow(f(h-1,0),   f(0,0) + h*w) == 2;
        cout << (res ? "YES" : "NO") << '\n';
    }
}