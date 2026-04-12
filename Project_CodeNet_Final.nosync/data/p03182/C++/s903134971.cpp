#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
const long long INF = 1LL<<60;

// 抽象化した遅延評価付きセグメント木
template<class Monoid, class Action> struct SegTree {
    using FuncMonoid = function< Monoid(Monoid, Monoid) >;
    using FuncAction = function< void(Monoid&, Action) >;
    using FuncLazy = function< void(Action&, Action) >;
    FuncMonoid FM;
    FuncAction FA;
    FuncLazy FL;
    Monoid UNITY_MONOID;
    Action UNITY_LAZY;
    int SIZE, HEIGHT;
    vector<Monoid> dat;
    vector<Action> lazy;

    SegTree() { }
    SegTree(int n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
            const Monoid &unity_monoid, const Action &unity_lazy)
    : FM(fm), FA(fa), FL(fl), UNITY_MONOID(unity_monoid), UNITY_LAZY(unity_lazy) {
        SIZE = 1; HEIGHT = 0;
        while (SIZE < n) SIZE <<= 1, ++HEIGHT;
        dat.assign(SIZE * 2, UNITY_MONOID);
        lazy.assign(SIZE * 2, UNITY_LAZY);
    }
    void init(int n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
              const Monoid &unity_monoid, const Action &unity_lazy) {
        FM = fm; FA = fa; FL = fl;
        UNITY_MONOID = unity_monoid; UNITY_LAZY = unity_lazy;
        SIZE = 1; HEIGHT = 0;
        while (SIZE < n) SIZE <<= 1, ++HEIGHT;
        dat.assign(SIZE * 2, UNITY_MONOID);
        lazy.assign(SIZE * 2, UNITY_LAZY);
    }

    /* set, a is 0-indexed */
    void set(int a, const Monoid &v) { dat[a + SIZE] = v; }
    void build() {
        for (int k = SIZE - 1; k > 0; --k)
            dat[k] = FM(dat[k*2], dat[k*2+1]);
    }

    /* update [a, b) */
    inline void evaluate(int k) {
        if (lazy[k] == UNITY_LAZY) return;
        if (k < SIZE) FL(lazy[k*2], lazy[k]), FL(lazy[k*2+1], lazy[k]);
        FA(dat[k], lazy[k]);
        lazy[k] = UNITY_LAZY;
    }
    inline void update(int a, int b, const Action &v, int k, int l, int r) {
        evaluate(k);
        if (a <= l && r <= b)  FL(lazy[k], v), evaluate(k);
        else if (a < r && l < b) {
            update(a, b, v, k*2, l, (l+r)>>1), update(a, b, v, k*2+1, (l+r)>>1, r);
            dat[k] = FM(dat[k*2], dat[k*2+1]);
        }
    }
    inline void update(int a, int b, const Action &v) { update(a, b, v, 1, 0, SIZE); }

    /* get [a, b) */
    inline Monoid get(int a, int b, int k, int l, int r) {
        evaluate(k);
        if (a <= l && r <= b)
            return dat[k];
        else if (a < r && l < b)
            return FM(get(a, b, k*2, l, (l+r)>>1), get(a, b, k*2+1, (l+r)>>1, r));
        else
            return UNITY_MONOID;
    }
    inline Monoid get(int a, int b) { return get(a, b, 1, 0, SIZE); }
    inline Monoid operator [] (int a) { return get(a, a+1); }

    /* debug */
    void print() {
        for (int i = 0; i < SIZE; ++i) { cout << (*this)[i]; if (i != SIZE) cout << ","; }
        cout << endl;
    }
};

using pll = pair<int, long long>;
int main() {
    int N, M;
    cin >> N >> M;

    // 右端が i であるような区間の左端
    vector<vector<pll>> lefts(N+1);
    for (int i = 0; i < M; ++i) {
        int l, r;
        long long a;
        cin >> l >> r >> a;
        --l, --r; // 0-indexed に
        ++r;      // 右側を開区間に
        lefts[r].push_back({l, a});
    }

    // DP in Starry Sky Tree
    auto fm = [&](long long a, long long b) { return max(a, b); };
    auto fa = [&](long long &a, long long d) { a += d; };
    auto fl = [&](long long &d, long long e) { d += e; };
    SegTree<long long, long long> dp(N+2, fm, fa, fl, -INF, 0);

    dp.update(0, 1, -dp.get(0, 1)); // dp[0] = 0 の状態にします
    for (int i = 1; i <= N; ++i) {
        long long A = 0;
        for (auto p : lefts[i]) A += p.second;
        long long ma = dp.get(0, i);

        // ma + A - dp.get(i, i+1) を加算すれば ma + A になる
        dp.update(i, i+1, ma + A - dp.get(i, i+1));

        for (auto p : lefts[i]) {
            int l = p.first;
            long long a = p.second;
            dp.update(l+1, i, a);
        }
    }

    // 答えは dp[0], ..., dp[N] の最大値
    cout << dp.get(0, N+1) << endl;
}
