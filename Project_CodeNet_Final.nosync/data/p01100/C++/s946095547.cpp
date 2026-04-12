#include <bits/stdc++.h>
using ll = long long;
// #define int ll
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= int(a); --i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, int(n) + 1)
#define rrep(i, n) RFOR(i, 0, n)
#define rrep1(i, n) RFOR(i, 1, int(n) + 1)
#define all(c) begin(c), end(c)
// const int MOD = 1000000007;

template <typename T>
void __print__(std::ostream &os, const char *, const char *tail, const T &fst) {
    os << fst << tail;
}
template <typename Fst, typename... Rst>
void __print__(std::ostream &os, const char *del, const char *tail, const Fst &fst,
               const Rst &... rst) {
    os << fst << del;
    __print__(os, del, tail, rst...);
}

#ifdef LOCAL
#define dump(...)                                         \
    do {                                                  \
        std::ostringstream os;                            \
        os << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; \
        __print__(os, ", ", "\n", __VA_ARGS__);           \
        std::cerr << os.str();                            \
    } while (0)
#else
#define dump(...)
#endif

template <typename Fst, typename... Rst>
void println(const Fst &fst, const Rst &... rst) {
    __print__(std::cout, "\n", "\n", fst, rst...);
}
template <typename Fst, typename... Rst>
void print(const Fst &fst, const Rst &... rst) {
    __print__(std::cout, " ", "\n", fst, rst...);
}

template <typename iter>
void println_(iter bgn, iter end) {
    while (bgn != end) println(*bgn++);
}

template <typename iter>
void print_(iter bgn, iter end) {
    while (bgn != end) {
        std::cout << *bgn++;
        std::cout << (bgn == end ? "\n" : " ");
    }
}

int _ = (std::cout.precision(10), std::cout.setf(std::ios::fixed), std::cin.tie(0),
         std::ios::sync_with_stdio(0), 0);

template <typename T>
std::vector<T> ndarray(int n, T v) {
    return std::vector<T>(n, v);
}
template <typename... Args>
auto ndarray(int n, Args... args) {
    auto val = ndarray(args...);
    return std::vector<decltype(val)>(n, move(val));
}

template <typename T>
bool umax(T &a, const T &b) {
    return a < b ? a = b, true : false;
}

template <typename T>
bool umin(T &a, const T &b) {
    return a > b ? a = b, true : false;
}

using namespace std;
using flow_type = int;

struct dinic {
    struct edge {
        int s, d;
        flow_type c, f;
        int r;
    };
    int n, s, t;
    std::vector<std::vector<edge>> g;
    std::vector<int> level, prog, que;

    dinic(int n_ = 0) : n(n_), g(n_) {}

    flow_type maximum_flow(int s_, int t_) {
        s = s_;
        t = t_;
        que.resize(n);
        flow_type res = 0;
        while (levelize()) {
            prog.assign(n, 0);
            res += augment(s, std::numeric_limits<flow_type>::max());
        }
        return res;
    }

    void add_edge(int u, int v, flow_type c) {
        if (u == v || c == 0) return;
        g[u].push_back({u, v, c, 0, (int)g[v].size()});
        g[v].push_back({v, u, c, c, (int)g[u].size() - 1});
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

template <class F>
struct maximum_flow_lr {
    F flow;
    int S, T;
    flow_type sum_lb;

    maximum_flow_lr() { }

    maximum_flow_lr(int n) : flow(n + 2), S(n), T(n + 1), sum_lb(0) { }

    void add_edge(int u, int v, int lb, int ub) {
        assert(0 <= lb);
        assert(lb <= ub);
        if (u == v || ub == 0) return;
        flow.add_edge(u, v, ub - lb);
        // Three lines below should have no effect if lb == 0.
        flow.add_edge(S, v, lb);
        flow.add_edge(u, T, lb);
        sum_lb += lb;
    }

    flow_type maximum_flow(int s, int t) {
        int S = flow.n - 2, T = flow.n - 1;
        flow_type a = flow.maximum_flow(S, T);
        flow_type b = flow.maximum_flow(s, T);
        flow_type c = flow.maximum_flow(S, t);
        flow_type d = flow.maximum_flow(s, t);
        return (a + c == sum_lb && a + b == sum_lb) ? b + d : -1;
    }
};

vector<pair<int,int>> es;
int n, m;

bool ok(int l, int r, maximum_flow_lr<dinic> dn) {
    int S = m + n;
    int T = S + 1;
    rep(i, n) dn.add_edge(m + i, T, l, r);
    int f = dn.maximum_flow(S, T);
    return f == m;
}

int main() {
    while (cin >> n >> m && n) {
        es.resize(m);
        maximum_flow_lr<dinic> dn(m + n + 2);
        int S = m + n;
        rep(i, m) dn.add_edge(S, i, 1, 1);
        rep(i, m) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            dn.add_edge(i, m + u, 0, 1);
            dn.add_edge(i, m + v, 0, 1);
        }
        int ansl = 0, ansr = n;
        int l = 0;
        for (int r = 0; r <= n; ++r) {
            while (l <= r && ok(l, r, dn)){
                ansl = l, ansr = r;
                ++l;
            }
        }
        print(ansl, ansr);
    }
}