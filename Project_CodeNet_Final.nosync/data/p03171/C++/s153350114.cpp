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

// Problem
void solve() {
    ll n;
    cin >> n;
    vll a(n);
    cin >> a;

    // 自分が最小化したいもの = 相手が最小化したいもの，なので，交互に - をかけることで，
    // 最大化に統一して書くことができる
    vvll dp(n, vll(n, -INF));
    auto dfs = [&](auto &&dfs, ll left, ll right) -> ll {
        if (dp[left][right] != -INF) return dp[left][right];
        // 残っている区間が[left, right]
        if (left == right) return dp[left][right] = a[left];
        return dp[left][right] = max(a[left] - dfs(dfs, left + 1, right), a[right] - dfs(dfs, left, right - 1));
    };
    cout << dfs(dfs, 0, n - 1) << endl;
}

// entry point
int main() {
    solve();
    return 0;
}
