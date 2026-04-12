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
#define dump(...) cerr << "[" << __LINE__ << ":" << __FUNCTION__ << "] ", my_dmp(#__VA_ARGS__, __VA_ARGS__)
#define say(x) cerr << "[" << __LINE__ << ":" << __FUNCTION__ << "] " << x << endl;
void my_dmp(const char*) { cerr << endl; }
template <class T, class... U> void my_dmp(const char *s, T const& x, U const& ...y) { const char *o = "({[", *e = "]})"; for (int i = 0; *s != '\0'; cerr << *s++) { if (count(o,o+3,*s)) i++; if (count(e,e+3,*s)) i--; if (!i && *s == ',') break; } cerr << " = " << x; if (*s == ',') cerr << ", ", s++; my_dmp(s, y...); }
#else
#define dump(...)
#define say(x)
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
struct my_Init { my_Init() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } my_init;
template <class T, size_t d> struct vec_impl {
    using type = vector<typename vec_impl<T,d-1>::type>;
    template <class... U> static type make_v(size_t n, U&&... x) { return type(n, vec_impl<T,d-1>::make_v(forward<U>(x)...)); }
};
template <class T> struct vec_impl<T,0> { using type = T; static type make_v(T const& x = {}) { return x; } };
template <class T, size_t d> using vec = typename vec_impl<T,d>::type;
template <class T, size_t d, class... Args> auto make_v(Args&&... args) { return vec_impl<T,d>::make_v(forward<Args>(args)...); }
template <class T> void quit(T const& x) { cout << x << endl; exit(0); }
template <class T> constexpr bool chmin(T& x, T const& y) { if (x > y) { x = y; return true; } return false; }
template <class T> constexpr bool chmax(T& x, T const& y) { if (x < y) { x = y; return true; } return false; }
template <class It> constexpr auto sumof(It b, It e) { return accumulate(b,e,typename iterator_traits<It>::value_type{}); }
const ll INF = (1LL<<62)-1; // ~ 4.6e18
// <<<
// >>> lazy segtree
template <class Handler>
struct LazySegtree : Handler {
    using Value = typename Handler::Value;
    using Lazy = typename Handler::Lazy;
    using Handler::unit_value; // () -> Value
    using Handler::unit_action; // () -> Lazy
    using Handler::merge; // (Value,Value) -> Value
    using Handler::act; // (Lazy,Lazy&,Value&) -> void

    vector<Value> v; // use [1..2*cap-1]
    vector<Lazy> lz; // use [1..2*cap-1]
    int n, cap, ht; // original size, capacity == (1<<ht)

    LazySegtree() {}
    LazySegtree(int n) { init(n); }
    template <class It> LazySegtree(It first, It last) { init(first, last); }
    void init(int n) {
        assert(n >= 0); this->n = n;
        cap = 1, ht = 0;
        while (cap < n) cap <<= 1, ht++;
		v.assign(2*cap, unit_value());
		lz.assign(2*cap, unit_action());
    }
    template <class It> void init(It first, It last) {
        init(distance(first,last));
        copy(first, last, next(v.begin(), cap));
        for (int i = cap-1; i >= 1; i--) v[i] = merge(v[2*i],v[2*i+1]);
    }
    int size() const { return n; }

    void flush(int k) {
        act(lz[k], lz[2*k], v[2*k]);
        act(lz[k], lz[2*k+1], v[2*k+1]);
        lz[k] = unit_action();
    }

    Value get(int a, int b, int l, int r, int k) {
        if (b <= l || r <= a) return unit_value();
        if (a <= l && r <= b) return v[k];
        flush(k);
        Value p = get(a,b, l,(l+r)/2, 2*k);
        Value q = get(a,b, (l+r)/2,r, 2*k+1);
        return merge(p,q);
	}
    Value get(int a, int b) {
        assert(0 <= a && a <= b && b <= size());
        return get(a,b,0,cap,1);
    }

    void apply(int a, int b, Lazy const& x, int l, int r, int k) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) { act(x, lz[k], v[k]); return; }
        flush(k);
        apply(a,b, x, l,(l+r)/2, 2*k);
        apply(a,b, x, (l+r)/2,r, 2*k+1);
        v[k] = merge(v[2*k],v[2*k+1]);
	}
    void apply(int a, int b, Lazy const& x) {
        assert(0 <= a && a <= b && b <= size());
        apply(a,b,x,0,cap,1);
    }

    Value operator[](int i) const { return get(i); }
    Value get(int i) const {
        assert(0 <= i && i < size());
        Lazy x = unit_action(); Value y = v[i += cap];
        while (i > 1) i >>= 1, act(lz[i], x, y);
        return y;
    }
    void set(int i, Value const& x) {
        assert(0 <= i && i < size());
        i += cap;
        for (int p = ht; p >= 1; p--) flush(i >> p);
        v[i] = x;
        while (i > 1) i >>= 1, v[i] = merge(v[2*i],v[2*i+1]);
    }
    vector<Value> dat() const {
        vector<Value> ret(size());
        for (int i = 0; i < size(); i++) ret[i] = get(i);
        return ret;
    }
};
// <<<

struct RangeAddMax {
    using Value = int;
    using Lazy = int;
    constexpr static Value unit_value() { return -INF; }
    constexpr static Lazy unit_action() { return 0; }
    constexpr static Value merge(Value x, Value y) { return max(x,y); }
    static void act(Lazy x, Lazy &y, Value &z) {
        y += x, z += x;
    }
};

int32_t main() {
    int n,m; cin >> n >> m;
    vector<int> l(m),r(m),a(m);
    vector<vector<int> > v(n);
    rep (i,m) {
        cin >> l[i] >> r[i] >> a[i];
        l[i]--,r[i]--;
        v[r[i]].eb(i);
    }
    LazySegtree<RangeAddMax> dp(n);
    rep (i,n) {
        int val = max(0LL,dp.get(0,i));
        dp.set(i,val);
        for (int k : v[i]) dp.apply(l[k],i+1,a[k]);
    }
    cout << max(0LL,dp.get(0,n)) << endl;
}
