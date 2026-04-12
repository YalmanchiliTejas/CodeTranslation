#include <bits/stdc++.h>

using namespace std;
using i64 = int_fast64_t;
using ui64 = uint_fast64_t;
using db = long double;
using pii = pair<int, int>;
using pli = pair<int_fast64_t, int>;
using pll = pair<int_fast64_t, int_fast64_t>;
using pdi = pair<double, int>;
template <class T> using vct = vector<T>;
template <class T> using heap = priority_queue<T>;
template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;

#define stdout_precision 10
#define stderr_precision 2
#define each(i,v) for (auto i = begin(v); i != end(v); ++i)
#define reach(i,v) for (auto i = rbegin(v); i != rend(v); ++i)
#define urep(i,s,t) for (int i = (s); i <= (t); ++i)
#define drep(i,s,t) for (int i = (s); i >= (t); --i)
#define rep(i,n) urep(i, 0, (n)-1)
#define rep1(i,n) urep(i, 1, (n))
#define rrep(i,n) drep(i, (n)-1, 0)
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define fir first
#define sec second
#define front fro
#define back bac
#define u_map unordered_map
#define u_set unordered_set
#define l_bnd lower_bound
#define u_bnd upper_bound
#define rsz resize
#define ers erase
#define emp emplace
#define emf emplace_front
#define emb emplace_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define popcnt __builtin_popcount

struct setupper {
    setupper() {
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        std::cerr.tie(nullptr);
        std::cout << fixed << setprecision(stdout_precision);
        std::cerr << fixed << setprecision(stderr_precision);
#ifdef Local
        std::cerr << "\n---stderr---\n";
        auto print_atexit = []() {
            std::cerr << "Exec time : " << clock() / (double)CLOCKS_PER_SEC * 1000.0 << "ms\n";
            std::cerr << "------------\n";
        };
        atexit((void(*)())print_atexit);
#endif
    }
} setupper_;

namespace std {
    template <class T> void hash_combine(size_t &seed, T const &key) {
        seed ^= hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    template <class T, class U> struct hash<pair<T,U>> {
        size_t operator()(pair<T,U> const &pr) const
        {
            size_t seed = 0;
            hash_combine(seed,pr.first);
            hash_combine(seed,pr.second);
            return seed;
        }
    };
    template <class Tup, size_t index = tuple_size<Tup>::value - 1> struct hashval_calc {
        static void apply(size_t& seed, Tup const& tup) {
            hashval_calc<Tup, index - 1>::apply(seed, tup);
            hash_combine(seed,get<index>(tup));
        }
    };
    template <class Tup> struct hashval_calc<Tup,0> {
        static void apply(size_t& seed, Tup const& tup) {
            hash_combine(seed,get<0>(tup));
        }
    };
    template <class ...T> struct hash<tuple<T...>> {
        size_t operator()(tuple<T...> const& tup) const
        {
            size_t seed = 0;
            hashval_calc<tuple<T...>>::apply(seed,tup);
            return seed;
        }
    };
}

template <class T, class U> ostream& operator << (ostream& s, pair<T,U> p) { return s << p.fir << " " << p.sec; }
template <class T> ostream& operator << (ostream& s, vct<T> v) { each(i,v) { if(i != begin(v)) s << " "; s << *i; } return s; }
#define dump(...) cerr << " [ " << __LINE__ << " : " << __FUNCTION__ << " ] " << #__VA_ARGS__ << " : ";\
dump_func(__VA_ARGS__)
template <class T> void dump_func(T x) { cerr << x << '\n'; }
template <class T,class ...Rest> void dump_func(T x, Rest ... rest) { cerr << x << ","; dump_func(rest...); }
template <class T = int> T read() { T x; return cin >> x, x; }
template <class T> void write(T x) { cout << x << '\n'; }
template <class T, class ...Rest> void write(T x, Rest ... rest) { cout << x << ' '; write(rest...); }
void writeln() {}
template <class T, class ...Rest> void writeln(T x, Rest ... rest) { cout << x << '\n'; writeln(rest...); }
#define esc(...) writeln(__VA_ARGS__), exit(0)
const auto add = [](auto &x, auto y) { x += y; };
const auto mul = [](auto &x, auto y) { x *= y; };
const auto lam_min = [](auto x, auto y) { return min(x, y); };
const auto lam_max = [](auto x, auto y) { return max(x, y); };
const auto chmax = [](auto &m, auto x) { if(m < x){ m = x; return true; } return false; };
const auto chmin = [](auto &m, auto x) { if(m > x){ m = x; return true; } return false; };
bool bit(i64 n, uint8_t e) { return (n >> e) & 1; }
i64 mask(i64 n, uint8_t e) { return n & ((1 << e) - 1); }
int ilog(uint64_t x, uint64_t b = 2) { return x ? 1 + ilog(x / b,b) : -1; }
template <class F> i64 binsr(i64 ok, i64 ng, const F &fn) {
    while (abs(ok - ng) > 1) {
        i64 mid = (ok + ng) / 2;
        (fn(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class A, size_t N, class T> void init(A (&array)[N], const T &val) { fill((T*)array,(T*)(array + N),val); }
template <class T> T cmprs(T &v) {
    T tmp = v, ret = v;
    sort(all(tmp));
    tmp.erase(unique(all(tmp)), end(tmp));
    each(i,ret) *i = l_bnd(all(tmp),*i) - begin(tmp);
    return ret;
}

template <class T> constexpr T inf = numeric_limits<T>::max() / 2 - 1;
constexpr int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr long double gold = 1.618033988;
constexpr long double eps = 1e-15;
constexpr uint_fast64_t mod = 1e9 + 7;


template <class Monoid, class T = Monoid> struct LazySegtree {
    typedef function<Monoid(const Monoid&, const Monoid&)> opr_t;
    typedef function<void(Monoid&, const Monoid&)> lazy_opr_t;
    typedef function<void(Monoid&, const Monoid&, size_t)> update_opr_t;
    const opr_t opr;
    const lazy_opr_t lazy_opr;
    const update_opr_t update_opr;
    const Monoid idel,lazy_idel;
    vector<Monoid> data,lazy;
    vector<bool> lazyflag;
    size_t range = 1;

    LazySegtree(int n, Monoid idel_ = Monoid(), const opr_t &opr_ = lam_max, const lazy_opr_t &lazy_opr_ = [](Monoid &x, Monoid y){x += y;}, const update_opr_t &update_opr_ = [](Monoid &x, Monoid y, size_t w){x += y;}, Monoid lazy_idel_ = 0) : opr(opr_),lazy_opr(lazy_opr_),update_opr(update_opr_),idel(idel_),lazy_idel(lazy_idel_)
    {
        while(n >= range) range <<= 1;
        data.assign(range << 1,idel);
        lazy.assign(range << 1,lazy_idel);
        lazyflag.assign(range << 1,false);
    }

    template <class P> void copy(P s, P t) {
        for(size_t i = range; s != t; ++s, ++i) data[i] = *s;
        for(size_t i = range - 1; i; --i) data[i] = opr(data[i * 2],data[i * 2 + 1]);
    }

    template <class A> void copy(A &v) {
        copy(begin(v),end(v));
    }

    void eval(size_t k, int l, int r) {
        if(!lazyflag[k]) return;
        update_opr(data[k],lazy[k],r - l);
        if(r - l > 1) {
            lazy_opr(lazy[k * 2],lazy[k]);
            lazy_opr(lazy[k * 2 + 1],lazy[k]);
            lazyflag[k * 2] = lazyflag[k * 2 + 1] = true;
        }
        lazy[k] = lazy_idel;
        lazyflag[k] = false;
    }

    void update(size_t a, size_t b, Monoid val, size_t k = 1, int l = 0, int r = -1) {
        if(r < 0) r = range;
        eval(k,l,r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy_opr(lazy[k],val);
            lazyflag[k] = true;
            eval(k,l,r);
        } else {
            update(a,b,val,k * 2,l,l + r >> 1);
            update(a,b,val,k * 2 + 1,l + r >> 1,r);
            data[k] = opr(data[k * 2],data[k * 2 + 1]);
        }
    }

    Monoid query(size_t a, size_t b, size_t k = 1, int l = 0, int r = -1) {
        if(r < 0) r = range;
        if(b <= l || r <= a) return idel;
        eval(k,l,r);
        if(a <= l && r <= b) return data[k];
        return opr(query(a,b,k * 2,l,l + r >> 1),query(a,b,k * 2 + 1,l + r >> 1,r));
    }
};

int n;
vct<pii> ad[1<<18],er[1<<18];

int main() {
    int m;
    cin>>n>>m;
    while(m--) {
        int x,y,a; cin>>x>>y>>a;
        ad[y].emb(x,a);
    }
    LazySegtree<i64> sg(n+1);
    i64 ans=0;
    for(int i=1; i<=n; ++i) {
        i64 tmp=sg.query(0,i);
        sg.update(i,i+1,tmp);
        for(pii &p:ad[i]) sg.update(p.fir,i+1,p.sec);
    }
    writeln(sg.query(0,n+1));
}
