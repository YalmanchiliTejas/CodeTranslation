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

/* #region LazySegTree */

// 遅延評価セグメント木，区間更新したいときに使うやつ
// 遅延伝播セグメント木について（旧：遅延評価セグメント木について） - beet's soil
// http://beet-aizu.hatenablog.com/entry/2017/12/01/225955
template <typename T, typename E> // T: 要素，E: 作用素
struct LazySegmentTree {
    using F = function<T(T, T)>; // 要素と要素をマージする関数．max とか．
    using G = function<T(T, E)>; // 要素に作用素を作用させる関数．加算とか．
    using H = function<E(E, E)>; // 作用素と作用素をマージする関数．

    ll n, height; // 木のノード数と高さ
    F f; // 区間クエリで使う演算，結合法則を満たす演算．区間最大値のクエリを投げたいなら max 演算．
    G g; // 要素更新で使う演算，たとえば加算など．g(更新前，加算値) の形で使う．
    H h; // 遅延評価をまとめる際に使う演算，たとえば加算など．
    T ti; // 値配列の初期値．演算 f, h に関する単位元．区間最大値なら単位元は 0. (a>0 なら max(a,0)=max(0,a)=a)
    E ei; // 遅延配列の初期値．演算 f, h に関する単位元．区間最大値なら単位元は 0.
    vc<T> dat; // 1-indexed 値配列 (index は木の根から順に 1 | 2 3 | 4 5 6 7 | 8 9 10 11 12 13 14 15 | ...)
    vc<E> laz; // 1-indexed 遅延配列

    // コンストラクタ．
    LazySegmentTree(F f, G g, H h, T ti, E ei) : f(f), g(g), h(h), ti(ti), ei(ei) {}

    // 指定要素数の遅延セグメント木を初期化する
    void init(ll n_) {
        n = 1;
        height = 0;
        while (n < n_) n <<= 1, height++;
        dat.assign(2 * n, ti);
        laz.assign(2 * n, ei);
    }

    // ベクトルから遅延セグメント木を構築する
    void build(const vc<T> &v) {
        ll n_ = SIZE(v);
        init(n_);
        REP(i, 0, n_) dat[n + i] = v[i];
        REPR(i, n - 1, 1) dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
    }

    // 木のノード k のみに遅延評価を反映する
    inline T reflect(ll k) { return laz[k] == ei ? dat[k] : g(dat[k], laz[k]); }

    // 木のノード k について遅延伝搬処理を行う．
    // これにより dat[k] は更新を反映した状態になる．
    inline void propagate(ll k) {
        if (laz[k] == ei) return;

        // 直接の子ノードに遅延配列内容を伝搬
        laz[(k << 1) | 0] = h(laz[(k << 1) | 0], laz[k]); // 子，左側
        laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]); // 子，右側
        dat[k] = reflect(k);
        laz[k] = ei;
    }

    // 木のノード k に関して，親から順に伝搬処理を行う
    // これにより dat[k] とその全ての親ノード dat[k>>1], dat[k>>2], ..., dat[1] が更新される．
    // 更新は根 dat[1] 側から順に行う．
    inline void thrust(ll k) { REPR(i, height, 1) propagate(k >> i); }

    // 木のノード k に関して，子から順に値配列の再計算を行う
    inline void recalc(ll k) {
        while (k >>= 1) dat[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));
    }

    // 半開区間 [a, b) を更新する
    void update(ll a, ll b, E x) {
        if (a >= b) return;
        // assert(a < b)

        thrust(a += n);     // インデックス a の更新
        thrust(b += n - 1); // インデックス b-1 の更新
        // 以降では l, r は木のノード
        for (ll l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) laz[l] = h(laz[l], x), l++; // 木のノード l が，親から見て右側の子である場合
            if (r & 1) --r, laz[r] = h(laz[r], x); // 木のノード r が，親から見て右側の子である場合
        }
        recalc(a);
        recalc(b);
    }

    // インデックス a の要素の値を x にする．
    void set_val(ll a, T x) {
        thrust(a += n);
        dat[a] = x;
        laz[a] = ei;
        recalc(a);
    }

    // 半開区間 [a, b) に対するクエリを実行する
    T query(ll a, ll b) {
        if (a >= b) return ti;
        // assert(a<b)

        thrust(a += n);     // インデックス a の更新
        thrust(b += n - 1); // インデックス b-1 の更新
        T vl = ti, vr = ti;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = f(vl, reflect(l++));
            if (r & 1) vr = f(reflect(--r), vr);
        }
        return f(vl, vr);
    }

    template <typename C> ll find(ll st, C &check, T &acc, ll k, ll l, ll r) {
        if (l + 1 == r) {
            acc = f(acc, reflect(k));
            return check(acc) ? k - n : -1;
        }
        propagate(k);
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

    // check が真となる要素を探して，そのインデックスを返す．
    template <typename C> ll find(ll st, C &check) {
        T acc = ti;
        return find(st, check, acc, 1, 0, n);
    }
};

/* #endregion */

struct Entity {
    ll l, r, a;

    // Entity() {} // これがあるとリスト初期化ができないっぽい
    // Entity(ll x) : x(x) {}
    bool operator<(const Entity &another) const { return r < another.r; }
    bool operator==(const Entity &another) const { return r == another.r; }
    friend istream &operator>>(istream &is, Entity &entity) {
        is >> entity.l >> entity.r >> entity.a;
        // --entity.l, --entity.r;
        return is;
    }
    friend ostream &operator<<(ostream &os, const Entity &entity) {
        os << "(" << entity.l << ", " << entity.r << ", " << entity.a << ")";
        return os;
    }
};

// Problem
void solve() {
    ll n, m;
    cin >> n >> m;
    vc<Entity> lra(m);
    cin >> lra;
    sort(ALL(lra));

    auto f = [](ll a, ll b) { return max(a, b); };
    auto g = [](ll a, ll b) { return a + b; };
    ll ti = 0, ei = 0;
    LazySegmentTree<ll, ll> seg(f, g, g, ti, ei);
    seg.init(n + 1);

    ll cur = 0;
    REPM(i, 1, n) {
        // i 番目は [0, i-1] の最大を入れる
        ll ma = seg.query(0, i);
        seg.update(i, i + 1, ma);
        while (cur < m && lra[cur].r == i) {
            // 区間 [l, r] にスコア加算
            seg.update(lra[cur].l, lra[cur].r + 1, lra[cur].a);
            cur++;
        }
    }
    cout << seg.query(0, n + 2) << endl;
}

// entry point
int main() {
    solve();
    return 0;
}
