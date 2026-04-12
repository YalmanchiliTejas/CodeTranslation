/* #region Head */

// #define _GLIBCXX_DEBUG
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
constexpr int IINF = 1'000'000'007LL;
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
template <typename T, typename U> ostream &operator<<(ostream &os, um<T, U> &map_var) {
    os << "{";
    REPI(itr, map_var) {
        auto [key, value] = *itr;
        os << "(" << key << ", " << value << ")";
        auto itrcp = itr;
        if (++itrcp != map_var.end()) os << ", ";
    }
    os << "}";
    return os;
}
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

#define VAR(type, ...)                                                                                                 \
    type __VA_ARGS__;                                                                                                  \
    cin >> __VA_ARGS__;

template <typename T> istream &operator,(istream &is, T &rhs) { return is >> rhs; }
template <typename T> ostream &operator,(ostream &os, const T &rhs) { return os << ' ' << rhs; }

struct AtCoderInitialize {
    static constexpr int IOS_PREC = 15;
    static constexpr bool AUTOFLUSH = false;
    AtCoderInitialize() {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        cout << fixed << setprecision(IOS_PREC);
        if (AUTOFLUSH) cout << unitbuf;
    }
} ATCODER_INITIALIZE;

void Yn(bool p) { cout << (p ? "Yes" : "No") << endl; }
void YN(bool p) { cout << (p ? "YES" : "NO") << endl; }

/* #endregion */

/* #region DoublingStepVal */

// ダブリングで，k ステップ先の要素を log(k) で得るためのクラス
// データも載せる
template <typename T> class DoublingStepVal {
    using Data = pair<ll, T>;
    using FNext = function<Data(ll)>; //  (i) -> (次の要素の番号, 追加情報)
    using FMerge = function<T(T, T)>; // (追加情報1, 追加情報2) -> マージした追加情報

    ll n;
    ll log_n;
    T ti;
    FNext fNext;
    FMerge fMerge;
    vc<vc<Data>> next; // (ある回数次のインデックス，追加情報)

  public:
    // コンストラクタ（要素数を指定）
    DoublingStepVal(const ll n, const T ti, FNext fNext, FMerge fMerge)
        : n(n), log_n((ll)floorl(log2l(n))), ti(ti), fNext(fNext), fMerge(fMerge),
          next(log_n + 1, vc<Data>(n, {0, ti})) {
        init();
    }

    // コンストラクタ（要素数，最大距離（n より大きい時は必ずそれを指定））
    DoublingStepVal(const ll n, const T ti, FNext fNext, FMerge fMerge, const ll max_step)
        : n(n), log_n((ll)floorl(log2l(max_step))), ti(ti), fNext(fNext), fMerge(fMerge),
          next(log_n + 1, vc<Data>(n, {0, ti})) {
        init();
    }

    // O(n * log_n)
    void init() {
        REP(i, 0, n) next[0][i] = fNext(i); // i の次の要素のインデックスを返す関数，次がない場合は -1
        REP(e, 0, log_n) REP(i, 0, n) {
            if (next[e][i].first == -1)
                next[e + 1][i] = {-1, ti}; // 2^e 個次の要素がない -> 2^(e+1) 個次の要素もない
            else {
                auto [nxt, info] = next[e][i];
                next[e + 1][i] = {
                    next[e][nxt].first,
                    fMerge(info, next[e][nxt].second)}; // 「2^e 個次の要素」の 2^e 個次の要素 = 2^(e+1) 個次の要素
            }
        }
    }

    // cur の k 個先の要素を返す, O(log k)
    Data step(ll _cur, const ll k) {
        Data cur = {_cur, ti};
        REPR(e, log_n, 0) {
            if (cur.first == -1)
                break; // cur が既に存在しない要素を指している -> それ以降で存在する要素を指すことはない
            if ((k >> e) & 1)
                // k を二進展開した際、e 番目のビットが立っていたら、cur の位置を 2^e だけ次にずらす
                cur = {next[e][cur.first].first, fMerge(cur.second, next[e][cur.first].second)};
        }
        return cur;
    }
};

/* #endregion */

// Problem
void solve() {
    VAR(ll, n, x, m); //

    using T = ll;
    // (あるインデックス) -> (次のインデックス，追加情報)
    auto fNext = [&m](ll i) -> pair<ll, T> {
        ll x = (i * i) % m;
        return {x, x};
    };
    // (追加情報1, 追加情報2) -> マージした追加情報
    auto fMerge = [](T data1, T data2) -> T {
        return data1 + data2; //
    };
    T ti = 0;
    DoublingStepVal<T> ds(m, ti, fNext, fMerge, n); // 最大 n ステップ

    auto data = ds.step(x, n - 1);
    // // dump(nxt, ov);
    auto ov = data.second;
    cout << (x + ov) << endl;
    // REP(i, 0, 3) {
    //     //
    //     dump(ds.step(x, i));
    // }
}

// entry point
int main() {
    solve();
    return 0;
}
