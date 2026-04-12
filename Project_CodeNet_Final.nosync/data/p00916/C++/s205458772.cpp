// >>> TEMPLATES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define int ll
#define double ld
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define repR(i,n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep1R(i,n) for (int i = (int)(n); i >= 1; i--)
#define loop(i,a,B) for (int i = a; i B; i++)
#define loopR(i,a,B) for (int i = a; i B; i--)
#define all(x) (x).begin(), (x).end()
#define allR(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
template <class Int> auto constexpr inf = numeric_limits<Int>::max()/2-1;
auto constexpr INF32 = inf<int32_t>;
auto constexpr INF64 = inf<int64_t>;
auto constexpr INF   = inf<int>;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dump(...) (void)(0)
#define say(x) (void)(0)
#define debug if (0)
#endif
template <class T> using pque_max = priority_queue<T>;
template <class T> using pque_min = priority_queue<T, vector<T>, greater<T> >;
template <class T, class = typename T::iterator, class = typename enable_if<!is_same<T, string>::value>::type>
ostream& operator<<(ostream& os, T const& v) { bool f = true; for (auto const& x : v) os << (f ? "" : " ") << x, f = false; return os; }
template <class T, class = typename T::iterator, class = typename enable_if<!is_same<T, string>::value>::type>
istream& operator>>(istream& is, T &v) { for (auto& x : v) is >> x; return is; }
template <class T, class S> ostream& operator<<(ostream& os, pair<T,S> const& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <class T, class S> istream& operator>>(istream& is, pair<T,S>& p) { return is >> p.first >> p.second; }
struct IOSetup { IOSetup() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } iosetup;
template <class F> struct FixPoint : private F {
    constexpr FixPoint(F&& f) : F(forward<F>(f)) {}
    template <class... T> constexpr auto operator()(T&&... x) const { return F::operator()(*this, forward<T>(x)...); }
};
struct MakeFixPoint {
    template <class F> constexpr auto operator|(F&& f) const { return FixPoint<F>(forward<F>(f)); }
};
#define MFP MakeFixPoint()|
#define def(name, ...) auto name = MFP [&](auto &&name, __VA_ARGS__)
template <class T, size_t d> struct vec_impl {
    using type = vector<typename vec_impl<T,d-1>::type>;
    template <class... U> static type make_v(size_t n, U&&... x) { return type(n, vec_impl<T,d-1>::make_v(forward<U>(x)...)); }
};
template <class T> struct vec_impl<T,0> { using type = T; static type make_v(T const& x = {}) { return x; } };
template <class T, size_t d = 1> using vec = typename vec_impl<T,d>::type;
template <class T, size_t d = 1, class... Args> auto make_v(Args&&... args) { return vec_impl<T,d>::make_v(forward<Args>(args)...); }
template <class T> void quit(T const& x) { cout << x << endl; exit(0); }
template <class T, class U> constexpr bool chmin(T& x, U const& y) { if (x > y) { x = y; return true; } return false; }
template <class T, class U> constexpr bool chmax(T& x, U const& y) { if (x < y) { x = y; return true; } return false; }
template <class It> constexpr auto sumof(It b, It e) { return accumulate(b,e,typename iterator_traits<It>::value_type{}); }
template <class T> int sz(T const& x) { return x.size(); }
template <class C, class T> int lbd(C const& v, T const& x) {
    return lower_bound(v.begin(), v.end(), x)-v.begin();
}
template <class C, class T> int ubd(C const& v, T const& x) {
    return upper_bound(v.begin(), v.end(), x)-v.begin();
}
template <class C, class F> int ppt(C const& v, F f) {
    return partition_point(v.begin(), v.end(), f)-v.begin();
}
template <class Int> struct Random {
    mt19937_64 mt{random_device{}()};
    //mt19937_64 mt{(unsigned)time(0)};
    Int a,b; // [a,b]
    Random(Int a, Int b) : a(a), b(b) {}
    Int operator()() { return uniform_int_distribution<Int>(a,b)(mt); }
};
// <<<
// >>> coordinate compression
template <class T>
struct Compress {
    vector<T> v;
    bool ok = false;
    void add(T const& x) { ok = false; v.push_back(x); }
    template <class V>
    void add(V const& u) { ok = false; copy(all(u), back_inserter(v)); }
    template <class... Ts>
    void add(Ts const&... xs) { (int[]){(add(xs),0)...}; }
    void init() { sort(all(v)); v.erase(unique(all(v)), v.end()); ok = true; }
    int size() const { return v.size(); }
    T operator[](int i) const { assert(ok); return v[i]; }
    int find(T const& x) const { assert(ok); auto it = lower_bound(all(v),x); assert(*it == x); return it-v.begin(); }
    void set(T& x) const { x = find(x); }
    template <class V>
    void set(V& u) const { for (auto &x : u) x = find(x); }
    template <class... Ts>
    void set(Ts&... xs) const { (int[]){(set(xs),0)...}; }
};
// <<<
// >>> union find
struct UnionFind {
    int n, sz; // id : 0...n-1
    vector<int> par;

    UnionFind(int n = 0) : n(n), sz(n), par(n,-1) { }
    int root(int x) {
        assert(0 <= x); assert(x < n);
        return par[x] < 0 ? x : par[x] = root(par[x]);
    }
    bool unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return false;
        sz--;
        if (par[x] < par[y]) swap(x,y);
        par[y] += par[x];
        par[x] = y;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -par[root(x)]; }
    int size() const { return sz; }
    struct groups_t {
        vector<vector<int> > grp;
        vector<pair<int,int> > id;
    };
    groups_t groups() {
        vector<vector<int> > g(n);
        rep (i,n) if (par[i] < 0) g[i].reserve(-par[i]);
        rep (i,n) g[root(i)].push_back(i);
        vector<vector<int> > grp; grp.reserve(size());
        rep (i,n) if (g[i].size()) grp.emplace_back(move(g[i]));
        vector<pair<int,int> > id(n);
        rep (i,grp.size()) rep (j,grp[i].size()) {
            id[grp[i][j]] = make_pair(i,j);
        }
        return { grp, id };
    }
};
// <<<

void solve(int n) {
    vector<int> y0(n),x1(n),y1(n),x0(n);
    rep (i,n) cin >> y0[i] >> x1[i] >> y1[i] >> x0[i];
    assert(cin);

    Compress<int> Z;
    Z.add(x0,y0,x1,y1,INF,-INF);
    Z.init();
    Z.set(x0,y0,x1,y1);

    const int m = Z.size();
    auto ver = make_v<int,2>(m,m);
    auto hol = make_v<int,2>(m,m);
    rep (i,n) {
        ver[x0[i]][y0[i]]++; ver[x0[i]][y1[i]]++;
        ver[x1[i]][y0[i]]--; ver[x1[i]][y1[i]]--;

        hol[x0[i]][y0[i]]++; hol[x0[i]][y1[i]]--;
        hol[x1[i]][y0[i]]++; hol[x1[i]][y1[i]]--;
    }
    rep (i,m-1) rep (j,m) ver[i+1][j] += ver[i][j];
    rep (i,m) rep (j,m-1) hol[i][j+1] += hol[i][j];

    auto id = [&](int i, int j) { return i*m+j; };
    UnionFind uf(m*m);
    rep (i,m) rep (j,m-1) {
        if (ver[i][j+1] == 0) uf.unite(id(i,j),id(i,j+1));
    }
    rep (i,m-1) rep (j,m) {
        if (hol[i+1][j] == 0) uf.unite(id(i,j),id(i+1,j));
    }

    cout << uf.size() << "\n";

}

int32_t main() {
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        solve(n);
    }
}

