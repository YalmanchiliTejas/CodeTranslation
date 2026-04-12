#include "bits/stdc++.h"
#define _overload3(_1,_2,_3,name,...)name
#define _rep(i,n)repi(i,0,n)
#define repi(i,a,b)for(int i=int(a),i##_len=(b);i<i##_len;++i)
#define MSVC_UNKO(x)x
#define rep(...)MSVC_UNKO(_overload3(__VA_ARGS__,repi,_rep,_rep)(__VA_ARGS__))
#define all(c)c.begin(),c.end()
#define write(x)cout<<(x)<<'\n'
using namespace std; typedef long long ll; template<class T>using vv = vector<vector<T>>;
template<class T>auto vvec(int n, int m, T v) { return vv<T>(n, vector<T>(m, v)); }
template<class T, class U>bool chmax(T& a, U&& b) { return a < b ? a = b, 1 : 0; }
template<class T, class U>bool chmin(T& a, U&& b) { return b < a ? a = b, 1 : 0; }
constexpr int INF = 1 << 29, MOD = int(1e9) + 7; constexpr ll LINF = 1LL << 60;
struct aaa { aaa() { cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10); }; }aaaa;

template<typename T, typename E, class F>
struct LazyEvaluationSegmentTree {
    const F op = F();
    int n, height; vector<T> dat; vector<E> laz;
    void init(int n_) {
        n = 1; height = 0; while (n < n_) n *= 2, height++;
        dat.assign(2 * n, op.I_T); laz.assign(2 * n, op.I_E);
    }
    void build(const vector<T>& v) {
        int n_ = v.size();  init(n_);
        for (int i = 0; i < n_; ++i) dat[n + i] = v[i];
        for (int i = n - 1; i; --i) dat[i] = op.f(dat[i << 1], dat[(i << 1) | 1]);
    }
    T reflect(int k) { return laz[k] == op.I_E ? dat[k] : op.g(dat[k], laz[k]); }
    void eval(int k) {
        if (laz[k] == op.I_E) return;
        laz[(k << 1)] = op.h(laz[k << 1], laz[k]); laz[(k << 1) | 1] = op.h(laz[(k << 1) | 1], laz[k]);
        dat[k] = reflect(k); laz[k] = op.I_E;
    }
    void thrust(int k) { for (int i = height; i; i--) eval(k >> i); }
    void thrust(int l, int r) {
        if (l == r) { thrust(l); return; } int x = l ^ r, i = height;
        for (; !(x >> i); i--) { eval(l >> i); } for (; i; i--) { eval(l >> i); eval(r >> i); }
    }
    void recalc(int k) { while (k >>= 1) dat[k] = op.f(reflect(k << 1), reflect((k << 1) | 1)); }
    void recalc(int l, int r) {
        for (int x = l ^ r; x > 1; ) {
            x >>= 1; l >>= 1; r >>= 1;
            dat[l] = op.f(reflect(l << 1), reflect((l << 1) | 1)); dat[r] = op.f(reflect(r << 1), reflect((r << 1) | 1));
        }
        while (l > 1) { l >>= 1; dat[l] = op.f(reflect(l << 1), reflect((l << 1) | 1)); }
    }
    void update(int a, int b, E v) {
        thrust(a += n, b += n - 1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) laz[l] = op.h(laz[l], v), l++; if (r & 1) --r, laz[r] = op.h(laz[r], v);
        } recalc(a, b);
    }
    void set_val(int a, T v) { thrust(a += n); dat[a] = v; laz[a] = op.I_E; recalc(a); }
    T query(int a, int b) {
        thrust(a += n, b += n - 1); T vl = op.I_T, vr = op.I_T;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = op.f(vl, reflect(l++)); if (r & 1) vr = op.f(reflect(--r), vr);
        } return op.f(vl, vr);
    }
};

template<typename T = ll, typename E = ll>
struct LESTOperator_RMRA {
    static constexpr T I_T = -LINF;
    static constexpr E I_E = 0;
    template<typename T_L = T, typename T_R = T> constexpr T f(T_L&& lhs, T_R&& rhs) const {
        static_assert(std::is_same<std::remove_reference_t<T_L>, T>::value, "");
        static_assert(std::is_same<std::remove_reference_t<T_R>, T>::value, "");
        return max<T>(lhs, rhs);
    }
    constexpr T g(T& lhs, E& rhs) const { return lhs + (T)rhs; }
    constexpr E h(E& lhs, E& rhs) const { return lhs + rhs; }
};
template<typename T, typename E> constexpr T LESTOperator_RMRA<T, E>::I_T;
template<typename T, typename E> constexpr E LESTOperator_RMRA<T, E>::I_E;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> L(M), R(M), A(M);
    rep(i, M) {
        cin >> L[i] >> R[i] >> A[i];
        R[i]++;
    }

    vector<int> lsort(M), rsort(M);
    iota(all(lsort), 0);
    iota(all(rsort), 0);
    sort(all(lsort), [&](auto&& l, auto&& r) { return L[l] < L[r]; });
    sort(all(rsort), [&](auto&& l, auto&& r) { return R[l] < R[r]; });

    LazyEvaluationSegmentTree<ll, ll, LESTOperator_RMRA<ll, ll>> lest;
    lest.build(vector<ll>(N + 1, 0));

    ll local = 0;
    ll ans = 0;
    for (int i = 1, l = 0, r = 0; i <= N; ++i) {
        ll sub = 0;
        if (r < M && R[rsort[r]] == i) {
            int j = r;
            for (; j < M; ++j) {
                if (R[rsort[j]] == i) {
                    sub += A[rsort[j]];
                    lest.update(L[rsort[j]], R[rsort[j]], A[rsort[j]]);
                }
                else break;
            }
            r = j;
        }
        local -= sub;

        ll add = 0;
        if (l < M && L[lsort[l]] == i) {
            int j = l;
            for (; j < M; ++j) {
                if (L[lsort[j]] == i) {
                    add += A[lsort[j]];
                }
                else break;
            }
            l = j;
        }

        ll premax = lest.query(0, i);
        lest.update(i, i + 1, premax);
        local += add;

        ans = max(ans, premax + local);
    }

    write(ans);
}