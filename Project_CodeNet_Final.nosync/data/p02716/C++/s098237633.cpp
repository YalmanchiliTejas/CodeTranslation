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

// map, um, set 出力
template <class T> ostream &out_iter(ostream &os, T &map_var) {
    os << "{";
    REPI(itr, map_var) {
        os << *itr;
        auto itrcp = itr;
        if (++itrcp != map_var.end()) os << ", ";
    }
    os << "}";
    return os;
}
template <typename T, typename U> ostream &operator<<(ostream &os, map<T, U> &map_var) { return out_iter(os, map_var); }
template <typename T, typename U> ostream &operator<<(ostream &os, um<T, U> &map_var) { return out_iter(os, map_var); }
template <typename T> ostream &operator<<(ostream &os, set<T> &set_var) { return out_iter(os, set_var); }

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

    if (n % 2 == 0) {
        ll c = n / 2;
        // とりあえず n 偶数とする
        vll la(c), ra(c);
        la[0] = a[0], ra[c - 1] = a[n - 1];
        REP(i, 1, c) la[i] = la[i - 1] + a[2 * i];
        REP(i, 1, c) ra[c - 1 - i] = ra[c - 1 - i + 1] + a[n - 1 - 2 * i];
        // dump(la, ra);
        ll ret = max(la[c - 1], ra[0]);
        REP(i, 0, c - 1) chmax(ret, la[i] + ra[i + 1]);
        cout << ret << endl;

        // vvll dp(n, vll(2, -INF));
        // dp[0][0] = a[0]; // max(0LL, a[0]);
        // dp[1][0] = a[1]; // max(0LL, a[1]);
        // if (n >= 3) dp[2][0] = a[2] + a[0], dp[2][2] = a[2];
        // REP(i, 3, n) {
        //     // j == 0..2
        //     dp[i][0] = dp[i - 2][0] + a[i];
        //     dp[i][1] = dp[i - 2][1] + a[i];
        //     dp[i][2] = dp[i - 2][2] + a[i];
        //     chmax(dp[i][1], dp[i - 3][0] + a[i]);
        //     chmax(dp[i][2], dp[i - 3][1] + a[i]);
        //     if (i >= 4) chmax(dp[i][2], dp[i - 4][0] + a[i]);
        // }
        // cout << max({dp[n - 1][2], dp[n - 2][1], dp[n - 3][0]}) << endl;
    } else {
        // ll c = n / 2;
        // vll la0(c + 1), la1(c), ra0(c + 1), ra1(c);
        // la0[0] = a[0], ra0[c] = a[n - 1];
        // la1[0] = a[1], ra1[c - 1] = a[n - 2];
        // REPM(i, 1, c) la0[i] = la0[i - 1] + a[2 * i];
        // REPM(i, 1, c) ra0[c - i] = ra0[c - i + 1] + a[n - 1 - 2 * i];
        // // dump(la1);
        // REP(i, 1, c) la1[i] = la1[i - 1] + a[1 + 2 * i];
        // // dump(la1);
        // REP(i, 1, c) ra1[c - 1 - i] = ra1[c - 1 - i + 1] + a[n - 2 - 2 * i];
        // // dump(la0, la1, ra0, ra1);
        // ll ret = max(la1[c - 1], ra1[0]);
        // chmax(ret, ra0[1]);
        // chmax(ret, la0[c - 1]);
        // REP(i, 0, c - 1) chmax(ret, la0[i] + ra1[i + 1]);
        // REP(i, 0, c - 1) chmax(ret, la1[i] + ra1[i + 1]);
        // REP(i, 0, c - 2) chmax(ret, la0[i] + ra0[i + 2]);
        // REP(i, 0, c - 2) chmax(ret, la1[i] + ra0[i + 2]);
        // cout << ret << endl;

        // n >= 3
        // dp[i][j] = i 番目の要素までを使って，そのうち余分なスキップを j 回使用したときの和の最大値
        vvll dp(n, vll(3, -INF));
        dp[0][0] = a[0]; // max(0LL, a[0]);
        dp[1][1] = a[1]; // max(0LL, a[1]);
        if (n >= 3) dp[2][0] = a[2] + a[0], dp[2][2] = a[2];
        REP(i, 3, n) {
            // j == 0..2
            dp[i][0] = dp[i - 2][0] + a[i];
            dp[i][1] = dp[i - 2][1] + a[i];
            dp[i][2] = dp[i - 2][2] + a[i];
            chmax(dp[i][1], dp[i - 3][0] + a[i]);
            chmax(dp[i][2], dp[i - 3][1] + a[i]);
            if (i >= 4) chmax(dp[i][2], dp[i - 4][0] + a[i]);
        }
        cout << max({dp[n - 1][2], dp[n - 2][1], dp[n - 3][0]}) << endl;
    }
}

// entry point
int main() {
    solve();
    return 0;
}
