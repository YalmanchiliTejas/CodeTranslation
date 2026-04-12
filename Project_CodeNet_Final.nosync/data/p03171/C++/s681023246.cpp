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
template <class T> constexpr T inf = numeric_limits<T>::max() / 2 - 1;
constexpr int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr long double gold = 1.618033988;
constexpr long double eps = 1e-15;

#define mod 1000000007LL
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
#define fro front()
#define bac back()
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

namespace updater {
    template <class T> static void add(T &x, const T &y) { x += y; }
    template <class T> static void ext_add(T &x, const T &y, size_t w) { x += y * w; }
    template <class T> static void mul(T &x, const T &y) { x *= y; }
    template <class T> static void ext_mul(T &x, const T &y, size_t w) { x *= (T)pow(y,w); }
    template <class T> static bool chmax(T &x, const T &y) { return x < y ? x = y,true : false; }
    template <class T> static bool chmin(T &x, const T &y) { return x > y ? x = y,true : false; }
};
using updater::chmax;
using updater::chmin;

template <class T> T minf(const T &x, const T &y) { return min(x,y); }
template <class T> T mixf(const T &x, const T &y) { return max(x,y); }
bool bit(i64 n, uint8_t e) { return (n >> e) & 1; }
i64 mask(i64 n, uint8_t e) { return n & ((1 << e) - 1); }
int ilog(uint64_t x, uint64_t b = 2) { return x ? 1 + ilog(x / b,b) : -1; }
template <class F> i64 binry(i64 ok, i64 ng, const F &fn) {
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
template <class T> void read_vct(vector<T> &v, size_t n = 0) {
	v.resize(n);
	if(n) {
		for(size_t i=0; i<n; ++i) cin>>v[i];
	} else {
		T input;
		while(cin>>input,input) {
			v.emplace_back(input);
		}
	}
}

template <class A, size_t N> void read_ary(A (&array)[N], size_t n = N) {
	for(size_t i=0; i<n; ++i) cin>>array[i];
}


int n;
int f[1<<12];
i64 taro[1<<12][1<<12];
i64 jiro[1<<12][1<<12];
bool taro_vis[1<<12][1<<12];
bool jiro_vis[1<<12][1<<12];

i64 calc_jiro(int ,int );

i64 calc_taro(int a,int b) {
	if(a>b) return 0;
	if(taro_vis[a][b]) return taro[a][b];
	taro_vis[a][b]=true;
	i64 p1=calc_jiro(a+1,b);
	i64 p2=calc_jiro(a,b-1);
	p1+=f[a];
	p2+=f[b];
	return taro[a][b]=max(p1,p2);
}

i64 calc_jiro(int a,int b) {
	if(a>b) return 0;
	if(jiro_vis[a][b]) return jiro[a][b];
	jiro_vis[a][b]=true;
	i64 p1=calc_taro(a+1,b);
	i64 p2=calc_taro(a,b-1);
	p1-=f[a];
	p2-=f[b];
	return jiro[a][b]=min(p1,p2);
}

signed main() {
	cin>>n;
	read_ary(f,n);
	writeln(calc_taro(0,n-1));
}