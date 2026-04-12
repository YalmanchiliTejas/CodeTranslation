#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <functional>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <iomanip>
#include <complex>
 
using namespace std;
typedef int64_t i64;
typedef double db;
typedef vector<vector<int64_t>> mat;
typedef pair<int,int> pii;
typedef pair<int64_t,int> pli;
typedef pair<db,int> pdi;
 
#define esc(x) cout << (x) << endl,exit(0)
#define inf(T) (numeric_limits<T>::max() / 2 - 1)
#define each(i,v) for(auto i = begin(v); i != end(v); ++i)
#define reach(i,v) for(auto i = rbegin(v); i != rend(v); ++i)
#define urep(i,s,t) for(int64_t i = (s); i <= (t); ++i)
#define drep(i,s,t) for(int64_t i = (s); i >= (t); --i)
#define rep(i,n) urep(i,0,(n) - 1)
#define rep1(i,n) urep(i,1,(n))
#define rrep(i,n) drep(i,(n) - 1,0)
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define vct vector
#define prque priority_queue
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
#define fir first
#define sec second
 
struct setupper {
    setupper(uint8_t prec) {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(prec);
        #ifdef Local
        #define debug 1
        #define print(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
        cout << "-- Execution At Local ---\n" << "\n<Standard Output>\n\n";
        auto print_atexit = []() {
            time_t end_time = time(NULL);
            struct tm *ret = localtime(&end_time);
            cout << "\n----------------\n";
            cout << "\nSuccessfully Executed At " << (ret -> tm_hour) << ":" << (ret -> tm_min) << ":" << (ret -> tm_sec) << "\n\n";
        };
        atexit(print_atexit);
        #endif
    }
} setupper_obj(10);
 
template <class T, class U> ostream& operator << (ostream &s, pair<T,U> p) { return s << p.fir << " " << p.sec; }
template <class T> ostream& operator << (ostream &s, vector<T> &v) { for(auto i = v.begin(); i != v.end(); ++i) { if(i != begin(v)) s << " "; s << *i; } return s; }
 
template <class T> void hash_combine(size_t &seed, T const &key) {
    hash<T> hasher;
    seed ^= hasher(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
namespace std {
    template <class T, class U> struct hash<pair<T,U>> {
        size_t operator()(pair<T,U> const &p) const {
            size_t seed(0);
            hash_combine(seed,p.first);
            hash_combine(seed,p.second);
            return seed;
        }
    };
    template <class T, class U, class V> struct hash<tuple<T,U,V>> {
        size_t operator()(tuple<T,U,V> const &t) const {
            size_t seed(0);
            hash_combine(seed,get<0>(t));
            hash_combine(seed,get<1>(t));
            hash_combine(seed,get<2>(t));
            return seed;
        }
    };
}
 
const auto add = [](auto &x, auto y) { x += y; };
const auto mul = [](auto &x, auto y) { x *= y; };
const auto lam_min = [](auto x, auto y) { return min(x,y); };
const auto lam_max = [](auto x, auto y) { return max(x,y); };
bool odd(i64 x) { return x & 1; }
bool even(i64 x) { return !odd(x); }
bool parity(i64 x, i64 y) { return odd(x) ^ even(y); }
bool bit(i64 n, uint8_t e) { return n >> e & 1; }
i64 mask(i64 n, uint8_t e) { return n & (1 << e) - 1; };
int ilog(i64 x, uint64_t b) { if(x) return ilog(x / b,b) + 1; return -1; }
i64 qceil(i64 x, i64 y) { return x > 0 ? (x - 1) / y + 1 :  x / y; }
i64 gcd(i64 a, i64 b) { if(!b) return abs(a); return gcd(b, a % b); }
i64 lcm(i64 a, i64 b) { if(a | b) return abs(a / gcd(a, b) * b); return 0; }
i64 extgcd(i64 a, i64 b, i64 &x, i64 &y) {
    i64 d = a;
    if(b) {
        d = extgcd(b,a % b,y,x);
        y -= (a / b) * x;
    } else {
        x = 1,y = 0;
    }
    return d;
}
i64 bins(i64 ok, i64 ng, auto judge) {
    while(abs(ok - ng) > 1) {
        i64 mid = ok + ng >> 1;
        (judge(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class T, class U> bool chmax(T& m, U x) { if(m < x) { m = x; return 1; } return 0; }
template <class T, class U> bool chmin(T& m, U x) { if(m > x) { m = x; return 1; } return 0; }
template <class T> T cmprs(T &v) {
    T tmp = v,ret = v;
    sort(all(tmp));
    tmp.erase(unique(all(tmp)),end(tmp));
    each(i,ret) *i = l_bnd(all(tmp),*i) - begin(tmp) + 1;
    return ret;
}
 
const int dx[9] = {1,0,-1,0,1,-1,-1,1,0},dy[9] = {0,1,0,-1,1,1,-1,-1,0};
const i64 mod = 1e9 + 7;
const db gold = (sqrt(5.0) + 1.0) * 0.5;
const db eps = 1e-15;

i64 c[51],w[51];

void calc(int l) {
	if(l) {
		calc(l-1);
		c[l]=c[l-1]*2+1;
		w[l]=w[l-1]*2+3;
	} else c[0]=w[0]=1;
}

int main() {
	calc(50);
	int n;
	i64 x;
	cin>>n>>x;
	i64 ans=0;
	do {
		if(x>=w[n]) { ans+=c[n]; break; }
		if(n-->=0&&x>w[n]+1) {
			x-=w[n]+2;
			ans+=c[n]+1;
		} else x--;
	} while(n>=0);
	esc(ans);
}