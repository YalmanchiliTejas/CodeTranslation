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

string k;
int d,n;
int dp[1<<14][2][100];

int main() {
    cin>>k>>d;
    n=k.size();
    dp[0][1][0]=1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<d; j++) {
            for(int h=0; h<10; h++) {
                (dp[i+1][0][(j+h)%d]+=dp[i][0][j])%=mod;
            }
            for(int h=0; h<(k[i]-'0'); h++) {
                (dp[i+1][0][(j+h)%d]+=dp[i][1][j])%=mod;
            }
            (dp[i+1][1][(j+(k[i]-'0'))%d]+=dp[i][1][j])%=mod;
        }
    }
    int ans=((dp[n][1][0]+dp[n][0][0])%mod-1+mod)%mod;
    writeln(ans);
}
