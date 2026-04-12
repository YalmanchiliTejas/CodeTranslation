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
// constexpr ll MOD = 998244353;
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

/* #region SegTree */

template <typename T> // T: 要素
struct SegmentTree {
    using F = function<T(T, T)>; // 要素と要素をマージする関数．max とか．

    ll n;  // 木のノード数
    ll nn; // 外から見た要素数
    F f; // 区間クエリで使う演算，結合法則を満たす演算．区間最大値のクエリを投げたいなら max 演算．
    T ti; // 値配列の初期値．演算 f に関する単位元．区間最大値なら単位元は 0. (a>0 なら max(a,0)=max(0,a)=a)
    vc<T> dat; // 1-indexed 値配列 (index は木の根から順に 1 | 2 3 | 4 5 6 7 | 8 9 10 11 12 13 14 15 | ...)

    // コンストラクタ．
    SegmentTree() {}
    // コンストラクタ．
    SegmentTree(F f, T ti) : f(f), ti(ti) {}

    // 指定要素数のセグメント木を初期化する
    void init(ll n_) {
        nn = n_;
        n = 1;
        while (n < n_) n <<= 1;
        dat.assign(n << 1, ti);
    }

    // ベクトルからセグメント木を構築する
    void build(const vc<T> &v) {
        ll n_ = v.size();
        init(n_);
        REP(i, 0, n_) dat[n + i] = v[i];
        REPR(i, n - 1, 1) dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
    }

    // インデックス k の要素の値を x にする．
    void set_val(ll k, T x) {
        dat[k += n] = x;
        while (k >>= 1) dat[k] = f(dat[(k << 1) | 0], dat[(k << 1) | 1]); // 上へ登って更新していく
    }

    // インデックス k の要素の値を取得する．
    T get_val(ll k) { return dat[k + n]; }

    // 半開区間 [a, b) に対するクエリを実行する
    T query(ll a, ll b) {
        if (a >= b) return ti;
        // assert(a<b)

        T vl = ti, vr = ti;
        for (ll l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = f(vl, dat[l++]);
            if (r & 1) vr = f(dat[--r], vr);
        }
        return f(vl, vr);
    }

    // セグメント木上の二分探索
    template <typename C> int find(ll st, C &check, T &acc, ll k, ll l, ll r) {
        if (l + 1 == r) {
            acc = f(acc, dat[k]);
            return check(acc) ? k - n : -1;
        }
        ll m = (l + r) >> 1;
        if (m <= st) return find(st, check, acc, (k << 1) | 1, m, r);
        if (st <= l && !check(f(acc, dat[k]))) {
            acc = f(acc, dat[k]);
            return -1;
        }
        ll vl = find(st, check, acc, (k << 1) | 0, l, m);
        if (~vl) return vl;
        return find(st, check, acc, (k << 1) | 1, m, r);
    }

    // セグメント木上の二分探索．check(query(st, idx)) が真となる idx を返す．
    template <typename C> int find(ll st, C &check) {
        T acc = ti;
        return find(st, check, acc, 1, 0, n);
    }

    void _dump() {
        REP(k, 0, nn) {
            T val = dat[k + n];
            cout << val << (k == nn - 1 ? '\n' : ' ');
        }
    }
};
/* #endregion */

// Problem
void solve() {
    VAR(ll, n, q); //
    vll a(n);
    cin >> a;

    auto f = [](ll a, ll b) { return max(a, b); };
    SegmentTree<ll> seg(f, -INF);
    seg.build(a);

    REP(i, 0, q) {
        VAR(ll, t, u, v); //
        --u;
        if (t == 1) {
            // set
            seg.set_val(u, v);
        } else if (t == 2) {
            // max
            cout << seg.query(u, v) << endl;
        } else {
            // search
            auto ch = [&v](ll acc) -> bool { return acc >= v; };
            ll r = seg.find(u, ch);
            if (r == -1) r = n;
            cout << (r + 1) << endl;
        }
    }
}

// entry point
int main() {
    solve();
    return 0;
}
