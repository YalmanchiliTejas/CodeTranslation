// >>> TEMPLATES
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define rep1(i,n) for (int i = 1; i <= int(n); i++)
#define repR(i,n) for (int i = int(n)-1; i >= 0; i--)
#define rep1R(i,n) for (int i = int(n); i >= 1; i--)
#define loop(i,a,B) for (int i = a; i B; i++)
#define loopR(i,a,B) for (int i = a; i B; i--)
#define all(x) (x).begin(), (x).end()
#define allR(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
#ifdef LOCAL
#define dump(...) cerr << "[" << __LINE__ << ":" << __FUNCTION__ << "] ", dump_impl(#__VA_ARGS__, __VA_ARGS__)
#define say(x) cerr << "[" << __LINE__ << ":" << __FUNCTION__ << "] " << x << endl;
#define debug if (1)
void dump_impl(const char*) { cerr << endl; }
template <class T, class... U> void dump_impl(const char *s, T const& x, U const& ...y) { const char *o = "({[", *e = "]})"; for (int i = 0; *s != '\0'; cerr << *s++) { if (count(o,o+3,*s)) i++; if (count(e,e+3,*s)) i--; if (!i && *s == ',') break; } cerr << " = " << x; if (*s == ',') cerr << ", ", s++; dump_impl(s, y...); }
#else
#define dump(...)
#define say(x)
#define debug if (0)
#endif
using ll = long long;
using ld = long double;
#define int ll
#define double ld
template <class T> using pque_max = priority_queue<T>;
template <class T> using pque_min = priority_queue<T, vector<T>, greater<T> >;
template <class T, class = typename T::iterator, class = typename enable_if<!is_same<T, string>::value>::type>
ostream& operator<<(ostream& os, T const& v) { os << "{"; for (auto const& x : v) os << " " << x; return os << " }"; }
template <class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template <class T, class S> ostream& operator<<(ostream& os, pair<T,S> const& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <class T, class S> istream& operator>>(istream& is, pair<T,S>& p) { return is >> p.first >> p.second; }
template <size_t i, class T> typename enable_if<i >= tuple_size<T>::value>::type output_tuple(ostream&, T const&) { }
template <size_t i = 0, class T> typename enable_if<i < tuple_size<T>::value>::type
output_tuple(ostream& os, T const& t) { os << (i ? " " : "") << get<i>(t); output_tuple<i+1,T>(os,t); }
template <class... T> ostream& operator<<(ostream& os, tuple<T...> const& t) { return output_tuple(os,t), os; }
struct IOSetup { IOSetup() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } iosetup;
template <class T, size_t d> struct vec_impl {
    using type = vector<typename vec_impl<T,d-1>::type>;
    template <class... U> static type make_v(size_t n, U&&... x) { return type(n, vec_impl<T,d-1>::make_v(forward<U>(x)...)); }
};
template <class T> struct vec_impl<T,0> { using type = T; static type make_v(T const& x = {}) { return x; } };
template <class T, size_t d = 1> using vec = typename vec_impl<T,d>::type;
template <class T, size_t d = 1, class... Args> auto make_v(Args&&... args) { return vec_impl<T,d>::make_v(forward<Args>(args)...); }
template <class T> void quit(T const& x) { cout << x << endl; exit(0); }
template <class T> constexpr bool chmin(T& x, T const& y) { if (x > y) { x = y; return true; } return false; }
template <class T> constexpr bool chmax(T& x, T const& y) { if (x < y) { x = y; return true; } return false; }
template <class It> constexpr auto sumof(It b, It e) { return accumulate(b,e,typename iterator_traits<It>::value_type{}); }
template <class T> int sz(T const& x) { return x.size(); }
const ll INF = (1LL<<62)-1; // ~ 4.6e18
// <<<
struct edge { int cost,to; };
int dst(edge const& e) { return e.to; }
int cost(edge const& e) { return e.cost; }
// >>> dijkstra
vector<int> dijkstra(vector<vector<edge> > const& g, int s) {
    vector<int> d(g.size(),-1);
    pque_min<pair<int,int> > q;
    d[s] = 0;
    q.emplace(0,s);
    while (!q.empty()) {
        auto p = q.top(); q.pop();
        const int x = p.snd;
        if (d[x] < p.fst) continue;
        for (edge const& e : g[x]) {
            const int y = dst(e);
            if (d[y] < 0 || d[y] > d[x] + cost(e)) {
                d[y] = d[x] + cost(e);
                q.emplace(d[y], y);
            }
        }
    }
    return d;
}
// <<<
// >>> modint
using ll = long long;
template <ll M> // m : prime
class modint {
    static_assert(M > 0, "");
    ll x;
public:
    modint(ll x = 0) : x((x%=M) < 0 ? x+M : x) { }
    ll val() const { return x; }
    bool operator==(modint rhs) const { return x == rhs.x; }
    bool operator!=(modint rhs) const { return x != rhs.x; }
    modint operator+() const { return *this; }
    modint operator-() const { return {M-x}; }
    modint& operator+=(modint rhs) { if ((x += rhs.x) >= M) x -= M; return *this; }
    modint& operator-=(modint rhs) { if ((x += M-rhs.x) >= M) x -= M; return *this; }
    modint& operator*=(modint rhs) { (x *= rhs.x) %= M; return *this; }
    modint operator+(modint rhs) const { return modint(*this) += rhs; }
    modint operator-(modint rhs) const { return modint(*this) -= rhs; }
    modint operator*(modint rhs) const { return modint(*this) *= rhs; }
    modint& operator/=(modint rhs) { return *this *= rhs.inv(); }
    modint operator/(modint rhs) const { return *this * rhs.inv(); }
    modint pow(ll n) const {
        if (n < 0) return inv().pow(-n);
        modint v = *this, r = 1;
        for (; n > 0; n >>= 1, v *= v) if (n&1) r *= v;
        return r;
    }
    modint inv() const {
        assert(x != 0);
        ll t = 1, v = x, q, r;
        while (v != 1) {
            q = M / v; r = M % v;
            if (r * 2 < v) {
                t *= -q; t %= M; v = r;
            } else {
                t *= q + 1; t %= M; v -= r;
            }
        }
        return t;
    }
};
template <ll M> ostream& operator<<(ostream& os, modint<M> rhs) { return os << rhs.val(); }
template <ll M> istream& operator>>(istream& is, modint<M> &rhs) { ll x; is >> x; rhs = x; return is; }

//constexpr ll MOD = 998244353;
constexpr ll MOD = 1e9+7;
using mint = modint<MOD>;
// <<<

vector<mint> f(vector<vector<edge> > const& g, int s, vector<int> const& d) {
    int n = sz(g);
    vector<mint> c(n);
    vector<int> idx(n); iota(all(idx),0);
    c[s] = 1;
    sort(all(idx), [&](int i, int j) { return d[i] < d[j]; });
    rep (i,n) {
        int x = idx[i];
        for (auto e : g[x]) {
            int y = e.to;
            if (d[x] + e.cost == d[y]) {
                c[y] += c[x];
            }
        }
    }
    return c;
}

int32_t main() {
    int n,m; cin >> n >> m;
    int s,t; cin >> s >> t; s--,t--;
    vector<int> xs(m),ys(m),Ds(m);
    vector<vector<edge> > g(n);
    rep (i,m) {
        int x,y,d; cin >> x >> y >> d; x--,y--;
        xs[i] = x; ys[i] = y; Ds[i] = d;
        g[x].eb(edge{d,y});
        g[y].eb(edge{d,x});
    }

    vector<int> ds = dijkstra(g,s);
    vector<int> dt = dijkstra(g,t);
    vector<mint> cs = f(g,s,ds);
    vector<mint> ct = f(g,t,dt);

    dump(ds);
    dump(cs);
    dump(dt);
    dump(ct);

    auto sq = [](auto x) { return x*x; };

    assert(ds[t] == dt[s]);
    assert(cs[t] == ct[s]);
    int total = ds[t];
    mint cnt = sq(cs[t]);
    dump(cnt);

    rep (x,n) {
        if (ds[x]*2 == total && dt[x]*2 == total) {
            cnt -= sq(cs[x]*ct[x]);
        }
    }

    rep (i,m) rep (dir,2) {
        int x = xs[i], y = ys[i], d = Ds[i];
        if (dir) swap(x,y);

        if (ds[x] + d + dt[y] == total &&
            ds[x]*2 < total && dt[y]*2 < total) {
            cnt -= sq(cs[x]*ct[y]);
        }
    }

    cout << cnt << endl;
}
