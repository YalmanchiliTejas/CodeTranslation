// #include <boost/functional/hash.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// using mlint = boost::multiprecision::cpp_int;

#include <cassert>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <complex>
#include <functional>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <iomanip>

using namespace std;
using i64 = int_fast64_t;
using db = long double;
using pii = pair<int, int>;
using pli = pair<int_fast64_t, int>;
using pdi = pair<db, int>;
using plpii = pair<int_fast64_t, pair<int, int>>;
template <class T> using mat = vector<vector<T>>;
template <class T> using rprque = priority_queue<T, vector<T>, greater<T>>;

#define esc(x) cout << (x) << endl, exit(0)
#define inf(T) (numeric_limits<T>::max() / 2 - 1)
#define each(i, v) for (auto i = begin(v); i != end(v); ++i)
#define reach(i, v) for (auto i = rbegin(v); i != rend(v); ++i)
#define urep(i, s, t) for (int i = (s); i <= (t); ++i)
#define drep(i, s, t) for (int i = (s); i >= (t); --i)
#define rep(i, n) urep(i, 0, (n)-1)
#define rep1(i, n) urep(i, 1, (n))
#define rrep(i, n) drep(i, (n)-1, 0)
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define fir first
#define sec second
#define vct vector
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
    setupper(uint_fast8_t prec)
    {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(prec);
#ifdef Local
    #define debug 1
    #define print(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
        cout << "\n-- Execution At Local ---\n\n";
        //      << "\n<Standard Output>\n";
        //      << "\n----------------\n\n";
        auto print_atexit = []() {
        //     time_t end_time = time(NULL);
        //     struct tm *ret = localtime(&end_time);
            cout << "\n----------------\n";
        //     cout << "\nSuccessfully Executed At " << (ret->tm_hour) << ":" << (ret->tm_min) << ":" << (ret->tm_sec) << "\n\n";
        };
        atexit(print_atexit);
#else
    #define debug 0
#endif
    }
} setuppre_obj(10);

template <class T, class U> ostream& operator << (ostream& s, pair<T,U> p) { return s << p.fir << " " << p.sec; }
template <class T> ostream& operator << (ostream& s, vct<T> v) { each(i,v) { if(i != begin(v)) s << " "; s << *i; } return s; }

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

void read() {}
template <class T, class ...Rest> void read(T &x, Rest &... rest) { cin >> x; read(rest...); }
template <class T> void write(T x) { cout << x; }
template <class T, class ...Rest> void write(T x, Rest ... rest) { cout << x << ' '; write(rest...); }
void writeln() {}
template <class T, class ...Rest> void writeln(T x, Rest ... rest) { cout << x << endl; writeln(rest...); }
const auto add = [](auto &x, auto y) { x += y; };
const auto mul = [](auto &x, auto y) { x *= y; };
const auto lam_min = [](auto x, auto y) { return min(x, y); };
const auto lam_max = [](auto x, auto y) { return max(x, y); };
const auto chmax = [](auto &m, auto x) { if(m < x){ m = x; return true; } return false; };
const auto chmin = [](auto &m, auto x) { if(m > x){ m = x; return true; } return false; };
bool odd(i64 x) { return x & 1; }
bool even(i64 x) { return !odd(x); }
bool parity(i64 x, i64 y) { return odd(x) ^ even(y); }
bool bit(i64 n, uint8_t e) { return (n >> e) & 1; }
i64 mask(i64 n, uint8_t e) { return n & ((1 << e) - 1); }
int ilog(i64 x, uint64_t b = 2) {
    if (x) return ilog(x / b, b) + 1;
    return -1;
}
uint divcnt(i64 x, i64 d) { if(x | d) return x % d ? 0 : divcnt(x / d, d) + 1; return inf(uint); }
i64 qceil(i64 x, i64 y) { return x > 0 ? (x - 1) / y + 1 : x / y; }
i64 gcd(i64 a, i64 b) {
    if (!b) return abs(a);
    return gcd(b, a % b);
}
i64 lcm(i64 a, i64 b) {
    if (a | b) return abs(a / gcd(a, b) * b);
    return 0;
}
i64 extgcd(i64 a, i64 b, i64 &x, i64 &y) {
    i64 d = a;
    if (b) d = extgcd(b, a % b, y, x), y -= (a / b) * x;
    else x = 1, y = 0;
    return d;
}
template <class F> i64 binsr(i64 ok, i64 ng, const F &fn) {
    while (abs(ok - ng) > 1) {
        i64 mid = (ok + ng) / 2;
        (fn(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class T> T cmprs(T &v) {
    T tmp = v, ret = v;
    sort(all(tmp));
    tmp.erase(unique(all(tmp)), end(tmp));
    each(i, ret) *i = l_bnd(all(tmp), *i) - begin(tmp) + 1;
    return ret;
}

constexpr int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr long double gold = 1.618033988;
constexpr long double eps = 1e-15;
constexpr uint_fast64_t mod = 1e9 + 7;


template <uint n = 1 << 18, uint_fast64_t mod = 1000000007> struct Mathfn {
    //constexpr static int n = 1 << 18;
    uint_fast64_t fact_[n + 1],invfact_[n + 1],inv_[n + 1];

    constexpr Mathfn() : fact_(),invfact_(),inv_() {
        fact_[0] = 1;
        for(int i = 1; i <= n; ++i) fact_[i] = fact_[i - 1] * i % mod;
        inv_[1] = 1;
        for(int i = 2; i <= n; ++i) inv_[i] = mod - inv_[mod % i] * (mod / i) % mod;
        invfact_[0] = 1;
        for(int i = 1; i <= n; ++i) invfact_[i] = invfact_[i - 1] * inv_[i] % mod;
    }

    constexpr uint_fast64_t fact(int x) const {
        return x >= 0 ? fact_[x] : 0;
    }

    constexpr uint_fast64_t invfact(int x) const {
        return x >= 0 ? invfact_[x] : 0;
    }

    constexpr uint_fast64_t perm(int x, int y) const {
        return x < y || y <= 0 ? 0 : fact(x) * invfact(y) % mod;
    }

    constexpr uint_fast64_t comb(int x, int y) const {
        return fact(x) * invfact(y) % mod * invfact(x - y) % mod;
    }

    constexpr uint_fast64_t modpow(int_fast64_t x, uint_fast64_t e) const {
        if(!e) return 1;
        if(!(x %= mod)) return 0;
        return modpow(x * x % mod, e >> 1) * (e & 1 ? x : 1) % mod;
    }

    constexpr uint_fast64_t extgcd(uint_fast64_t a, uint_fast64_t b, int_fast64_t &x, int_fast64_t &y) const {
        uint_fast64_t d = a;
        if (b) d = extgcd(b, a % b, y, x), y -= (a / b) * x;
        else x = 1, y = 0;
        return d;
    }

    constexpr uint_fast64_t modinv(uint_fast64_t x) const {
        int_fast64_t z = 0,y = 0;
        extgcd(x,mod,z,y);
        return (z + mod) % mod;
    }

    constexpr int_fast64_t gcd(int_fast64_t a, int_fast64_t b) const {
        if(!b) return a > 0 ? a : -a; return gcd(b, a % b);
    }

    constexpr int_fast64_t lcm(int_fast64_t a, int_fast64_t b) const {
        if(a | b) return a / gcd(a, b) * b; return 0;
    }
};

int n,a,b,c,d;
i64 dp[1<<10][1<<10];
i64 memo[1<<10][1<<10];
constexpr auto mf=Mathfn<>();

i64 calc(int x,int y) {
	if(x<0||y<=0) return 0;
	if(!x) return 1;
	if(~memo[x][y]) return memo[x][y];
	return memo[x][y]=calc(x-y,y)*mf.comb(x-1,y-1)%mod;
}

int main() {
	rep(i,1<<10)rep(j,1<<10) memo[i][j]=-1;
	read(n,a,b,c,d);
	dp[a-1][n]=1;
	urep(i,a,b) {
		urep(j,c,d) {
			rep(k,n) {
				if(k+j*i>n) break;
				(dp[i][k]+=mf.comb(k+j*i,k)*calc(j*i,i)%mod*dp[i-1][k+j*i]%mod)%=mod;
			}
		}
		rep(k,n+1) (dp[i][k]+=dp[i-1][k])%=mod;
	}
	esc(dp[b][0]);
}