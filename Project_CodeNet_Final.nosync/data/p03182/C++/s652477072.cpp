#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)
#define repa(i,n) for (auto& i: n)

template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}

#ifdef DEBUG
template <class T, class N> void verr(const T& a, const N& n) { rep(i, n) cerr << a[i] << " "; cerr << "\n" << flush; }
ll dbgt = 1; void err() { cerr << "passed " << dbgt++ << "\n" << flush; }
template<class H, class... T> void err(H&& h,T&&... t){ cerr<< h << (sizeof...(t)?" ":"\n") << flush; if(sizeof...(t)>0) err(forward<T>(t)...); }
#endif

const ll INF = 4e18;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
//--------------------------------------------------------------------------------//
template <class T, class U = T>
struct LazySegTree {
    int n, height;
    // 値配列, 値の単位元
    vector<T> data;
    T dataId;
    // 遅延配列, 遅延値の単位元
    vector<U> lazy;
    U lazyId;

    function<T(T, T)> fOperate;
    function<T(T, U)> fAct;
    function<U(U, U)> fMerge;

    LazySegTree(
        int _n, T _did = INF, U _lid = INF,
        function<T(T, T)> _op = [](T t1, T t2) { return min(t1, t2); },
        function<T(T, U)> _ac = [](T t1, U u1) { return u1; },
        function<U(U, U)> _me = [](U u1, U a) { return a; }
    )
        : dataId(_did), lazyId(_lid), fOperate(_op), fAct(_ac), fMerge(_me) {
        n = 1, height = 0;
        while (n < _n) n *= 2, height++;
        data = vector<T>(2 * n, dataId);
        lazy = vector<U>(2 * n, lazyId);
    }

    inline T act(int k){
        return lazy[k] == lazyId ? data[k] : fAct(data[k], lazy[k]);
    }

    inline void propagate(int k){
        if (lazy[k] == lazyId) return;
        lazy[2 * k + 0] = fMerge(lazy[2 * k + 0], lazy[k]);
        lazy[2 * k + 1] = fMerge(lazy[2 * k + 1], lazy[k]);
        data[k] = act(k), lazy[k] = lazyId;
    }


    // [a, b)を更新
    inline void update(int a, int b, U x) {
        a += n, b += n - 1;
        for (int i = height; i > 0; i--) propagate(a >> i), propagate(b >> i);
        for (int l = a, r = b + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) lazy[l] = fMerge(lazy[l], x), l++;
            if (r & 1) r--, lazy[r] = fMerge(lazy[r], x);
        }
        for (int l = a / 2, r = b / 2; l > 0; l /= 2, r /= 2) {
            data[l] = fOperate(act(2 * l + 0), act(2 * l + 1));
            data[r] = fOperate(act(2 * r + 0), act(2 * r + 1));
        }
    }

    // [l, r)の区間クエリ
    inline T query(int a, int b){
        a += n, b += n - 1;
        for (int i = height; i > 0; i--) propagate(a >> i), propagate(b >> i);
        T Lret = dataId, Rret = dataId;
        for (int l = a, r = b + 1; l < r; l /= 2, r /= 2){
            if (l & 1) Lret = fOperate(Lret, act(l++));
            if (r & 1) Rret = fOperate(act(--r), Rret);
        }
        return fOperate(Lret, Rret);
    }

    inline void build(vector<T> vec){
        for (int i = 0; i < vec.size(); i++) data[i + n] = vec[i];
        for (int i = n - 1; i > 0; i--) data[i] = fOperate(data[2 * i + 0], data[2 * i + 1]);
    }

    // 添字でアクセス
    inline T& operator[](int i) {
        return data[i + n];
    }
};
// LazySegTree<T, U = T> seg(N, dataId, lazyId, fOp, fMe, fAc)
// 要素数, 要素単位元, 遅延値単位元, 要素ｘ要素, 要素ｘ作用素, 作用素ｘ作用素
// デフォルト引数　dataId = INF, lazyId = INF, fOp : min, fAct : update, fMerge : update

using P = pair<ll, ll>;
int main() {
    init();
    ll N, M;
    cin >> N >> M;

    auto f = [](ll a, ll b) { return max(a, b); };
    auto g = [](ll a, ll b) { return a + b; };
    LazySegTree<ll> seg(N, 0, 0, f, g, g);

    vvc<P> A(N);
    rep(i, M){
        ll l, r, c;
        cin >> l >> r >> c;
        l--, r--;
        A[r].eb(l, c);
    }

    rep(i, N){
        seg.update(i, i + 1, seg.query(0, i + 1));
        for (auto [l, c] : A[i]) seg.update(l, i + 1, c);
    }
    cout << seg.query(0, N) << endl;
}   