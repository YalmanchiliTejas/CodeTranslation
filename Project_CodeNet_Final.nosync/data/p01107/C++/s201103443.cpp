#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

//
// Maximum flow (Dinic)
//
// Complexity:
//     O(V^2 E) time
//

template <typename T> class Dinic {
    struct edge {
        int to, rev;
        T cap;
        bool isrev;
        edge(int t, T c, int r, bool i) : to(t), cap(c), rev(r), isrev(i) {}
    };

    void bfs(int s, int t) {
        lev.assign(g.size(), -1);
        queue<int> que;
        lev[s] = 0;
        que.emplace(s);
        while (!que.empty() && lev[t] == -1) {
            int v = que.front();
            que.pop();
            for (edge& e : g[v]) {
                if (lev[e.to] == -1 && e.cap > 0) {
                    lev[e.to] = lev[v] + 1;
                    que.emplace(e.to);
                }
            }
        }
    }

    T dfs(int v, int t, T f) {
        if (v == t) return f;
        for (int& i = ite[v]; i < g[v].size(); ++i) {
            edge& e = g[v][i];
            if (e.cap > 0 && lev[v] < lev[e.to]) {
                T d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

public:

    const T INF;
    vector<int> lev, ite;
    vector<vector<edge>> g;

    Dinic(int n) : INF(numeric_limits<T>::max()), g(n) {}

    void reset() {
        for (auto& es : g) for (auto& e : es) if (!e.isrev) {
            e.cap = e.cap + g[e.to][e.rev].cap;
            g[e.to][e.rev].cap = 0;
        }
    }

    void add_edge(int f, int t, T c = numeric_limits<T>::max()) {
        g[f].emplace_back(t, c, g[t].size(), false);
        g[t].emplace_back(f, 0, g[f].size() - 1, true);
    }

    T max_flow(int s, int t) {
        T res = 0;
        while (1) {
            bfs(s, t);
            if (lev[t] < 0) break;
            ite.assign(g.size(), 0);
            T f = 0;
            while ((f = dfs(s, t, INF)) > 0) {
                res += f;
            }
        }
        return res;
    }

    void print() {
        for (int i = 0; i < g.size(); ++i) for (auto& e : g[i]) if (!e.isrev) {
            auto& rev_e = g[e.to][e.rev];
            cout << i << " -> " << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
        }
    }
};

const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};
int N, M;
string c[50];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> N >> M, N) {
        REP (i, N) cin >> c[i];
        Dinic<int> g(2 * N * M);
        REP (i, N) REP (j, M) if (c[i][j] == '.') {
            int v = 2 * (i * M + j);
            g.add_edge(v, v + 1, 1);
            REP (k, 4) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                int u = 2 * (ny * M + nx);
                if (ny >= 0 && ny < N && nx >= 0 && nx < M && c[ny][nx] == '.') {
                    g.add_edge(v + 1, u);
                }
            }
        }
        int no = 0;
        if (g.max_flow(1, 2 * (M - 1)) < 2) no = 1;
        g.reset();
        if (g.max_flow(1, 2 * ((N - 1) * M)) < 2) no = 1;
        g.reset();
        if (g.max_flow(1, 2 * ((N - 1) * M + (M - 1))) < 2) no = 1;
        cout << (no ? "NO" : "YES") << endl;
    }
}
