/* #region Head */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pll = pair<ll, ll>;
template <class T> using vc = vector<T>;
template <class T> using vvc = vc<vc<T>>;
using vll = vc<ll>;
using vvll = vvc<ll>;
using vld = vc<ld>;
using vvld = vvc<ld>;
using vs = vc<string>;
using vvs = vvc<string>;
template <class T, class U> using um = unordered_map<T, U>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqa = priority_queue<T, vc<T>, greater<T>>;
template <class T> using us = unordered_set<T>;

#define REP(i, m, n) for (ll i = (m), i##_len = (ll)(n); i < i##_len; ++(i))
#define REPM(i, m, n) for (ll i = (m), i##_max = (ll)(n); i <= i##_max; ++(i))
#define REPR(i, m, n) for (ll i = (m), i##_min = (ll)(n); i >= i##_min; --(i))
#define REPD(i, m, n, d) for (ll i = (m), i##_len = (ll)(n); i < i##_len; i += (d))
#define REPMD(i, m, n, d) for (ll i = (m), i##_max = (ll)(n); i <= i##_max; i += (d))
#define REPI(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
#define ALL(x) begin(x), end(x)
#define SIZE(x) ((ll)(x).size())
#define PERM(c)                                                                                                        \
    sort(ALL(c));                                                                                                      \
    for (bool c##p = 1; c##p; c##p = next_permutation(ALL(c)))
#define UNIQ(v) v.erase(unique(ALL(v)), v.end());

#define endl '\n'
#define sqrt sqrtl
#define floor floorl
#define log2 log2l

constexpr ll INF = 1'010'000'000'000'000'017LL;
constexpr ll MOD = 1'000'000'007LL; // 1e9 + 7
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.14159265358979323846;

template <typename T> istream &operator>>(istream &is, vc<T> &vec) { // vector 入力
    for (T &x : vec) is >> x;
    return is;
}
template <typename T> ostream &operator<<(ostream &os, vc<T> &vec) { // vector 出力 (for dump)
    os << "{";
    REP(i, 0, SIZE(vec)) os << vec[i] << (i == i_len - 1 ? "" : ", ");
    os << "}";
    return os;
}
template <typename T> ostream &operator>>(ostream &os, vc<T> &vec) { // vector 出力 (inline)
    REP(i, 0, SIZE(vec)) os << vec[i] << (i == i_len - 1 ? "\n" : " ");
    return os;
}

template <typename T, typename U> istream &operator>>(istream &is, pair<T, U> &pair_var) { // pair 入力
    is >> pair_var.first >> pair_var.second;
    return is;
}
template <typename T, typename U> ostream &operator<<(ostream &os, pair<T, U> &pair_var) { // pair 出力
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}

// map, um, set, us 出力
template <class T> ostream &out_iter(ostream &os, T &map_var) {
    os << "{";
    REPI(itr, map_var) {
        os << *itr;
        auto itrcp = itr;
        if (++itrcp != map_var.end()) os << ", ";
    }
    return os << "}";
}
template <typename T, typename U> ostream &operator<<(ostream &os, map<T, U> &map_var) { return out_iter(os, map_var); }
template <typename T, typename U> ostream &operator<<(ostream &os, um<T, U> &map_var) { return out_iter(os, map_var); }
template <typename T> ostream &operator<<(ostream &os, set<T> &set_var) { return out_iter(os, set_var); }
template <typename T> ostream &operator<<(ostream &os, us<T> &set_var) { return out_iter(os, set_var); }
template <typename T> ostream &operator<<(ostream &os, pq<T> &pq_var) {
    pq<T> pq_cp(pq_var);
    os << "{";
    if (!pq_cp.empty()) {
        os << pq_cp.top(), pq_cp.pop();
        while (!pq_cp.empty()) os << ", " << pq_cp.top(), pq_cp.pop();
    }
    return os << "}";
}

// dump
#define DUMPOUT cerr
void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) DUMPOUT << ", ";
    dump_func(move(tail)...);
}

// chmax (更新「される」かもしれない値が前)
template <typename T, typename U, typename Comp = less<>> bool chmax(T &xmax, const U &x, Comp comp = {}) {
    if (comp(xmax, x)) {
        xmax = x;
        return true;
    }
    return false;
}

// chmin (更新「される」かもしれない値が前)
template <typename T, typename U, typename Comp = less<>> bool chmin(T &xmin, const U &x, Comp comp = {}) {
    if (comp(x, xmin)) {
        xmin = x;
        return true;
    }
    return false;
}

// ローカル用
#define DEBUG_

#ifdef DEBUG_
#define DEB
#define dump(...)                                                                                                      \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                                                                    \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]" << endl                                        \
            << "    ",                                                                                                 \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif

struct AtCoderInitialize {
    static constexpr int IOS_PREC = 15;
    static constexpr bool AUTOFLUSH = false;
    AtCoderInitialize() {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        cout << fixed << setprecision(IOS_PREC);
        if (AUTOFLUSH) cout << unitbuf;
    }
} ATCODER_INITIALIZE;

string yes = "Yes", no = "No";
// string yes = "YES", no = "NO";
void yn(bool p) { cout << (p ? yes : no) << endl; }

/* #endregion */

/* #region Graph */

// エッジ（本来エッジは双方向だが，ここでは単方向で管理）
template <class weight_t, class flow_t> struct Edge {
    ll src;          // エッジ始点となる頂点
    ll dst;          // エッジ終点となる頂点
    weight_t weight; // 重み
    flow_t cap;
    Edge() : src(0), dst(0), weight(0) {}
    Edge(ll src, ll dst, weight_t weight) : src(src), dst(dst), weight(weight) {}
    Edge(ll src, ll dst, weight_t weight, flow_t cap) : src(src), dst(dst), weight(weight), cap(cap) {}
    // Edge 標準出力
    friend ostream &operator<<(ostream &os, Edge &edge) {
        os << "(" << edge.src << " -> " << edge.dst << ", " << edge.weight << ")";
        return os;
    }
};
// 同じ頂点を始点とするエッジ集合
template <class weight_t, class flow_t> class Node : public vc<Edge<weight_t, flow_t>> {
  public:
    ll idx;
    Node() : vc<Edge<weight_t, flow_t>>() {}
    // void add(int a, int b, weight_t w, flow_t cap) { this->emplace_back(a, b, w, cap); };
};
// graph[i] := 頂点 i を始点とするエッジ集合
template <class weight_t, class flow_t> class Graph : public vc<Node<weight_t, flow_t>> {
  public:
    Graph() : vc<Node<weight_t, flow_t>>() {}
    Graph(int n) : vc<Node<weight_t, flow_t>>(n) {}
    // 単方向
    void add_arc(int a, int b, weight_t w, flow_t cap) { (*this)[a].emplace_back(a, b, w, cap); }
    // 双方向
    void add_edge(int a, int b, weight_t w, flow_t cap) { add_arc(a, b, w, cap), add_arc(b, a, w, cap); }
};
// using Array = vc<Weight>;
// using Matrix = vc<Array>;

/* #endregion */

/* #region Dinic */

// 最大流 (Dinic) | libalgo https://tubo28.me/compprog/algorithm/dinic/
template <class weight_t, class flow_t> struct dinic {
    int n, s, t;
    vc<int> level, prog, que;
    vc<vc<flow_t>> cap, flow;
    vc<vc<int>> g;
    flow_t inf;

    dinic(const int n)
        : n(n), cap(n, vc<flow_t>(n)), flow(n, vc<flow_t>(n)), g(n, vc<int>()),
          inf(std::numeric_limits<flow_t>::max() / 8) {}
    dinic(const Graph<weight_t, flow_t> &graph)
        : n(graph.size()), cap(n, vc<flow_t>(n)), flow(n, vc<flow_t>(n)), g(n, vc<int>()),
          inf(std::numeric_limits<flow_t>::max() / 8) {
        build(graph);
    }
    void build(const Graph<weight_t, flow_t> &graph) {
        for (int i = 0; i < n; i++) {
            for (auto &e : graph[i]) {
                int u = e.src, v = e.dst;
                flow_t c = e.cap;
                cap[u][v] += c;
                cap[v][u] += c;
                flow[v][u] += c;
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
    }
    inline flow_t residue(int u, int v) { return cap[u][v] - flow[u][v]; }
    flow_t solve(int s_, int t_) {
        this->t = t_, this->s = s_;
        que.resize(n + 1);
        flow_t res = 0;
        while (levelize()) {
            prog.assign(n, 0);
            res += augment(s, inf);
        }
        return res;
    }
    bool levelize() {
        int l = 0, r = 0;
        level.assign(n, -1);
        level[s] = 0;
        que[r++] = s;
        while (l != r) {
            int v = que[l++];
            if (v == t) break;
            for (const int &d : g[v])
                if (level[d] == -1 && residue(v, d) != 0) {
                    level[d] = level[v] + 1;
                    que[r++] = d;
                }
        }
        return level[t] != -1;
    }
    flow_t augment(int v, flow_t lim) {
        flow_t res = 0;
        if (v == t) return lim;
        for (int &i = prog[v]; i < (int)g[v].size(); i++) {
            const int &d = g[v][i];
            if (residue(v, d) == 0 || level[v] >= level[d]) continue;
            const flow_t aug = augment(d, std::min(lim, residue(v, d)));
            flow[v][d] += aug;
            flow[d][v] -= aug;
            res += aug;
            lim -= aug;
            if (lim == 0) break;
        }
        return res;
    }
};

/* #endregion */

template <class flow_t> struct flow_bounded {
    using weight_t = int;

    int n;
    int S, T; // super-start, super-sink
    flow_t sum_flow_of_mi;
    vc<vc<flow_t>> min_flows;
    Graph<weight_t, flow_t> g;
    dinic<weight_t, flow_t> dn;

    flow_bounded() {}
    flow_bounded(int n)
        : n(n), S(n), T(n + 1), g(n + 2), dn(n + 2), sum_flow_of_mi(0), min_flows(n, vc<flow_t>(n, flow_t(0))) {}

    void add_arc_minmax(ll src, ll dst, ll cap_mi, ll cap_ma) {
        int w = 0;
        if (src == dst || cap_ma == 0) return;
        if (cap_mi == 0) {
            g.add_arc(src, dst, w, cap_ma);
        } else if (cap_mi == cap_ma) {
            g.add_arc(S, dst, w, cap_ma);
            g.add_arc(src, T, w, cap_ma);
        } else {
            g.add_arc(S, dst, w, cap_mi);
            g.add_arc(src, T, w, cap_mi);
            g.add_arc(src, dst, w, cap_ma - cap_mi);
        }
        sum_flow_of_mi += cap_mi;
        min_flows[src][dst] += cap_mi;
    };

    flow_t maximum_flow(int s, int t) {
        dn.build(g);
        flow_t a = dn.solve(S, T);
        flow_t b = dn.solve(s, T);
        flow_t c = dn.solve(S, t);
        flow_t d = dn.solve(s, t);
        return (a + b == sum_flow_of_mi && a + c == sum_flow_of_mi) ? b + d : -1;
    }

    flow_t get(int a, int b) { return min_flows[a][b] + dn.flow[a][b]; }
};

// Problem
void solve() {
    ll n;
    cin >> n;

    vll s(n), t(n); // 0, 1
    vc<ull> u(n), v(n);
    cin >> s >> t >> u >> v;

    ull whole = 0;
    REP(i, 0, n) whole |= u[i] | v[i];
    ll maxdigit = 64 - __builtin_clzll(whole);

    vc<vc<ull>> ret(n, vc<ull>(n, 0));

    REP(digit, 0, maxdigit) {
        flow_bounded<ll> mf(2 * n + 2);
        ll start = 2 * n, sink = start + 1;
        auto line = [](ll linenum) { return linenum; };
        auto row = [&n](ll rownum) { return rownum + n; };

        REP(i, 0, n) REP(j, 0, n) mf.add_arc_minmax(line(i), row(j), 0, 1);

        REP(i, 0, n) {
            if (s[i] == 0) { // i 行目の AND が u[i]
                if (u[i] & (1ULL << digit))
                    mf.add_arc_minmax(start, line(i), n, n); // n bit 全て立っていてほしい
                else
                    mf.add_arc_minmax(start, line(i), 0, n - 1); // n bit 全て立っていたら駄目
            } else {                                             // i 行目の OR が u[i]
                if (u[i] & (1ULL << digit)) mf.add_arc_minmax(start, line(i), 1, n); // 1 bit は立っていてほしい
                // else add_arc_minmax(start, line(i), 0, 0); // 1 bit も立っていたら駄目
            }
        }
        REP(j, 0, n) {
            if (t[j] == 0) { // j 列目の AND が v[j]
                if (v[j] & (1ULL << digit))
                    mf.add_arc_minmax(row(j), sink, n, n); // n bit 全て立っていてほしい
                else
                    mf.add_arc_minmax(row(j), sink, 0, n - 1); // n bit 全て立っていたら駄目
            } else {                                           // j 列目の OR が v[j]
                if (v[j] & (1ULL << digit)) mf.add_arc_minmax(row(j), sink, 1, n); // 1 bit は立っていてほしい
                // else // 1 bit も立っていたら駄目
            }
        }

        if (mf.maximum_flow(start, sink) == -1) {
            cout << -1 << endl;
            exit(0);
        }

        REP(i, 0, n) REP(j, 0, n) if (mf.get(line(i), row(j)) == 1) ret[i][j] += 1ULL << digit;
    }
    // dump(ret);

    bool ok = true;
    // ull and_init = 0;
    // REP(i, 0, maxdigit) and_init |= 1ULL << i;
    ull and_init = -1;
    // dump(and_init);

    REP(i, 0, n) {
        if (s[i] == 0) { // i 行目の AND が u[i]
            ull acc = and_init;
            REP(j, 0, n) acc &= ret[i][j];
            if (acc != u[i]) {
                ok = false;
                // dump(i, acc, u[i]);
                break;
            }
        } else { // i 行目の OR が u[i]
            ull acc = 0;
            REP(j, 0, n) acc |= ret[i][j];
            if (acc != u[i]) {
                ok = false;
                // dump(i, acc, u[i]);
                break;
            }
        }
    }
    REP(j, 0, n) {
        if (t[j] == 0) { // j 列目の AND が v[j]
            ull acc = and_init;
            REP(i, 0, n) acc &= ret[i][j];
            if (acc != v[j]) {
                ok = false;
                // dump(j, acc, v[j]);
                break;
            }
        } else { // j 列目の OR が v[j]
            ull acc = 0;
            REP(i, 0, n) acc |= ret[i][j];
            if (acc != v[j]) {
                ok = false;
                // dump(j, acc, v[j]);
                break;
            }
        }
    }
    if (!ok) {
        cout << -1 << endl;
        return;
    }
    REP(i, 0, n) cout >> ret[i];
}

// entry point
int main() {
    solve();
    return 0;
}
