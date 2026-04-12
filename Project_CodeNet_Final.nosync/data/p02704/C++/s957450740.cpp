#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define FORI(i,v) for (auto i = v.begin(); i != v.end(); i++)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)
#define YES(b) cout << ((b) ? "YES" : "NO") << endl
#define Yes(b) cout << ((b) ? "Yes" : "No") << endl
#define DOUBLE(d) cout << fixed << setprecision(15) << (d) << endl

template<typename T, bool directed, T inf> class Dinic {
private:
    struct Edge {
        int to; T cap; int rev;
        Edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}
    };

    vector<int> level, iter;

    void init(int n) {
        G = vector<vector<Edge>>(n);
        level = vector<int>(n);
        iter = vector<int>(n);
    }

    void bfs(int s) {
        fill(ALL(level), -1);
        level[s] = 0;
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int n = que.front(); que.pop();
            for (auto &&e : G[n]) if (e.cap > T(0) && level[e.to] < 0) {
                level[e.to] = level[n] + 1;
                que.push(e.to);
            }
        }
    }

    T dfs(int s, int t, T f) {
        if (s == t) return f;
        for (int &i = iter[s]; i < G[s].size(); i++) {
            Edge& e = G[s][i];
            if (e.cap > T(0) && level[s] < level[e.to]) {
                T d = dfs(e.to, t, min(f, e.cap));
                if (d == T(0)) continue;
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
        return T(0);
    }

public:
    Dinic() {}
    Dinic(int n) { init(n); }

    vector<vector<Edge>> G;
    void add(int from, int to, T cap) {
        if (!cap) return;
        G[from].push_back(Edge(to, cap, G[to].size()));
        G[to].push_back(Edge(from, (directed ? 0 : cap), G[from].size()-1));
    }

    T solve(int s, int t, T lim = inf) {
        T ret(0);
        while (1) {
            bfs(s);
            if (level[t] < 0 || lim == 0) return ret;
            fill(ALL(iter), 0);
            while (1) {
                T f = dfs(s, t, lim);
                if (f == T(0)) break;
                ret += f;
                lim -= f;
            }
        }
    }
};

const int MAX = 505;
const int DIGIT = 64;

int N;
bool S[MAX], T[MAX];
uint64_t U[MAX], V[MAX];

void solve() {
    vector<vector<uint64_t>> ans(N, vector<uint64_t>(N));
    REP (k, DIGIT) {
        Dinic<int, true, (int)2e9> dinic(2*N+4);
        // 行/列の必要量/余剰量に対応する頂点
        int row_required = 2*N,
            row_extra = 2*N+1,
            col_required = 2*N+2,
            col_extra = 2*N+3;
        // 行/列の必要量の和
        int row_lb = 0,
            col_lb = 0;

        auto add_row = [&](int r, int lb, int ub) {
            dinic.add(row_required, r, lb);
            dinic.add(row_extra, r, ub-lb);
            row_lb += lb;
        };
        auto add_col = [&](int c, int lb, int ub) {
            dinic.add(c+N, col_required, lb);
            dinic.add(c+N, col_extra, ub-lb);
            col_lb += lb;
        };

        REP (i, N) {
            // 全部1
            if (S[i] == 0 && (U[i]&1) == 1) add_row(i, N, N);
            if (T[i] == 0 && (V[i]&1) == 1) add_col(i, N, N);

            // 1が1つ以上
            if (S[i] == 1 && (U[i]&1) == 1) add_row(i, 1, N);
            if (T[i] == 1 && (V[i]&1) == 1) add_col(i, 1, N);

            // 1がN個未満
            if (S[i] == 0 && (U[i]&1) == 0) add_row(i, 0, N-1);
            if (T[i] == 0 && (V[i]&1) == 0) add_col(i, 0, N-1);

            // 全部0のところは辺がないとみなす
        }
        // 任意の行から列へ容量1の辺
        REP (i, N) REP (j, N) dinic.add(i, j+N, 1);

        int r_r = dinic.solve(row_required, col_required);
        int r_e = dinic.solve(row_required, col_extra);
        int e_r = dinic.solve(row_extra, col_required);

        if (r_r + r_e == row_lb && r_r + e_r == col_lb) {
            REP (i, N) {
                FORE (n, dinic.G[i]) if (n.to >= N && n.to < 2*N) {
                    int j = n.to - N;
                    if (n.cap == 0) ans[i][j] |= (1ull << k);
                }
            }
        } else {
            cout << -1 << endl;
            return;
        }
        REP (i, N) { U[i] >>= 1; V[i] >>=1; }
    }

    REP (i, N) {
        REP (j, N) cout << ans[i][j] << " ";
        cout << endl;
    }
}

int main() {
    cin >> N;
    REP (i, N) cin >> S[i];
    REP (i, N) cin >> T[i];
    REP (i, N) cin >> U[i];
    REP (i, N) cin >> V[i];
    solve();
}