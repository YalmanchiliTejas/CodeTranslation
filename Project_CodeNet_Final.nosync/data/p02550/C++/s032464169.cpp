/* lib.cpp */
 
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <queue>
#include <algorithm>
#include <iostream>
#include <iomanip>
 
#define overload4(_1,_2,_3,_4,name,...) name
#define overload3(_1,_2,_3,name,...) name
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(n) for(ll i=(n)-1;i>=0;i--)
#define rrep2(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep3(i,a,b) for(ll i=(b)-1;i>=(a);i--)
#define rrep4(i,a,b,c) for(ll i=a+(b-a-1)/c*c;i>=a;i-=c)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define each(i,...) for(auto&& i:__VA_ARGS__)
#define all1(i) begin(i),end(i)
#define all2(i,a) begin(i),begin(i)+a
#define all3(i,a,b) begin(i)+a,begin(i)+b
#define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)
#define rall1(i) (i).rbegin(),(i).rend()
#define rall2(i,k) (i).rbegin(),(i).rbegin()+k
#define rall3(i,a,b) (i).rbegin()+a,(i).rbegin()+b
#define rall(...) overload3(__VA_ARGS__,rall3,rall2,rall1)(__VA_ARGS__)
#define sum(...) accumulate(all(__VA_ARGS__),0LL)
#define dsum(...) accumulate(all(__VA_ARGS__),0.0L)
#define elif else if
#define unless(a) if(!(a))
#define mp make_pair
#define mt make_tuple
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
#define Sort(a) sort(all(a))
#define Rev(a) reverse(all(a))
#define Uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));in(name)
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
 
using namespace std;
using ll = long long;
using ull = unsigned ll;
using ld = long double;
using pll = pair<ll, ll>;
using graph = vector<vector<int>>;
 
const ll LINF = 0x1fffffffffffffff;
const ll MINF = 0x1fffffffffff;
const ll INF = 0x3fffffff;
const ll MOD = 1e9 + 7;
const ll MODD = 998244353;
const ld EPS = 1e-9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int edx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int edy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
template<class T> inline T min(const vector<T> &v){ return *min_element(all(v)); }
inline char min(const string &v){ return *min_element(all(v)); }
template<class T> inline T max(const vector<T> &v){ return *max_element(all(v)); }
inline char max(const string &v){ return *max_element(all(v)); }
template <class T> inline void chmin(T &a, T b) { a = min(a, b); }
template <class T> inline void chmax(T &a, T b) { a = max(a, b); }
 
inline int scan(){ return getchar(); }
inline void scan(int &a){ scanf("%d", &a); }
inline void scan(unsigned &a){ scanf("%u", &a); }
inline void scan(long &a){ scanf("%ld", &a); }
inline void scan(long long &a){ scanf("%lld", &a); }
inline void scan(unsigned long long &a){ scanf("%llu", &a); }
inline void scan(char &a){ cin >> a; }
inline void scan(float &a){ scanf("%f", &a); }
inline void scan(double &a){ scanf("%lf", &a); }
inline void scan(long double &a){ scanf("%Lf", &a); }
inline void scan(vector<bool> &vec){ for(unsigned i = 0; i < vec.size(); i++) { int a; scan(a); vec[i] = a; } }
inline void scan(char a[]){ scanf("%s", a); }
inline void scan(string &a){ cin >> a; }
template<class T> inline void scan(vector<T> &vec);
template<class T, size_t size> inline void scan(array<T, size> &vec);
template<class T, class L> inline void scan(pair<T, L> &p);
template<class T, size_t size> inline void scan(T (&vec)[size]);
template<class T> inline void scan(vector<T> &vec){ for(auto &i : vec) scan(i); }
template<class T> inline void scan(deque<T> &vec){ for(auto &i : vec) scan(i); }
template<class T, size_t size> inline void scan(array<T, size> &vec){ for(auto &i : vec) scan(i); }
template<class T, class L> inline void scan(pair<T, L> &p){ scan(p.first); scan(p.second); }
template<class T, size_t size> inline void scan(T (&vec)[size]){ for(auto &i : vec) scan(i); }
template<class T> inline void scan(T &a){ cin >> a; }
inline void in(){}
template <class Head, class... Tail> inline void in(Head &head, Tail&... tail){ scan(head); in(tail...); }
inline void print(){ putchar(' '); }
inline void print(const bool &a){ printf("%d", a); }
inline void print(const int &a){ printf("%d", a); }
inline void print(const unsigned &a){ printf("%u", a); }
inline void print(const long &a){ printf("%ld", a); }
inline void print(const long long &a){ printf("%lld", a); }
inline void print(const unsigned long long &a){ printf("%llu", a); }
inline void print(const char &a){ printf("%c", a); }
inline void print(const char a[]){ printf("%s", a); }
inline void print(const float &a){ printf("%.15f", a); }
inline void print(const double &a){ printf("%.15f", a); }
inline void print(const long double &a){ printf("%.15Lf", a); }
inline void print(const string &a){ for(auto&& i : a) print(i); }
template<class T> inline void print(const vector<T> &vec);
template<class T, size_t size> inline void print(const array<T, size> &vec);
template<class T, class L> inline void print(const pair<T, L> &p);
template<class T, size_t size> inline void print(const T (&vec)[size]);
template<class T> inline void print(const vector<T> &vec){ if(vec.empty()) return; print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar(' '); print(*i); } }
template<class T> inline void print(const deque<T> &vec){ if(vec.empty()) return; print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar(' '); print(*i); } }
template<class T, size_t size> inline void print(const array<T, size> &vec){ print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar(' '); print(*i); } }
template<class T, class L> inline void print(const pair<T, L> &p){ print(p.first); putchar(' '); print(p.second); }
template<class T, size_t size> inline void print(const T (&vec)[size]){ print(vec[0]); for(auto i = vec; ++i != end(vec); ){ putchar(' '); print(*i); } }
template<class T> inline void print(const T &a){ cout << a; }
inline int out(){ putchar('\n'); return 0; }
template<class T> inline int out(const T &t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> inline int out(const Head &head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
 
inline int first(bool i = true){ return out(i?"first":"second"); }
inline int yes(bool i = true){ return out(i?"yes":"no"); }
inline int Yes(bool i = true){ return out(i?"Yes":"No"); }
inline int No(){ return out("No"); }
inline int YES(bool i = true){ return out(i?"YES":"NO"); }
inline int NO(){ return out("NO"); }
inline int Yay(bool i = true){ return out(i?"Yay!":":("); }
inline int possible(bool i = true){ return out(i?"possible":"impossible"); }
inline int Possible(bool i = true){ return out(i?"Possible":"Impossible"); }
inline int POSSIBLE(bool i = true){ return out(i?"POSSIBLE":"IMPOSSIBLE"); }
inline void Case(ll i){ printf("Case #%lld: ", i); }
 
ll modpow(ll a, ll b, ll p = MOD) { ll ret = 1; while (b != 0) { if ((b & 1) == 1) ret *= a; a *= a; if (a >= p) a %= p; if (ret >= p) ret %= p; b >>= 1; } return ret; }
int digit(ll x, ll base = 10) { int ret = 0; while (x) { x /= base; ret++; } return ret; }
int sumOfDigit(ll x, ll base = 10) { int ret = 0; while(x) { ret += x % base; x /= base; } return ret; }
ll factrial(int n) { ll ret = 1; for(int i = 1;i <= n;i++) { ret *= i; } return ret; }
ll gcd(ll a, ll b) { while(b != 0) { a %= b; swap(a, b); } return abs(a); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll modinv(ll a, ll p = MOD) { ll b = p, u = 1, v = 0; while(b) { ll tmp = a / b; a -= tmp * b; u -= tmp * v; swap(a, b); swap(u, v); } u %= p; if (u < 0) u += p; return u; }
bool isprime(ull x) { if(x <= 1) return false; for(int i = 2;i * i <= x;i++) if(x % i == 0) return false; return true; }
map<ll, ll> factor(ull x){ map<ll, ll> ret; for(ll i = 2; i * i <= x; i++) while(x % i == 0){ ret[i]++; x /= i; } if(x != 1) ret[x]++; return ret; }
set<ll> divisor(ull x){ set<ll> ret; for(ll i = 1; i * i <= x; i++) if(x % i == 0){ ret.insert(i); ret.insert(x / i); } return ret; }
ll minDivisor(ull x, ll n = 2) { if(x <= 1) return 1; for(int i = n;i * i <= x;i++) if(x % i == 0) return i; return x; }
ll countDivisor(ull x) { map<ll, ll> m = factor(x); ll ret = 1; for(auto i : m) { ret *= i.second + 1; } return ret; }
 
class disjoint_set
{
    vector<int> _parent, _size;
 
public:
    disjoint_set(int n) : _parent(n), _size(n) {
        for (int i = 0; i < n; i++) {
            _parent[i] = i;
            _size[i] = 1;
        }
    }
    int root(int x) {
        if (_parent[x] == x) return x;
        return _parent[x] = root(_parent[x]);
    }
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        _parent[rx] = ry;
        _size[ry] += _size[rx];
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return _size[root(x)]; }
};
 
void init() { cin.tie(nullptr); cout << fixed << setprecision(15); }
 
int solve() {
    LL(n, x, m);
    vector<ll> a(m), b(2 * m);
    rep(i, m) {
        a[i] = i * i % m;
    }
    vector<ll> seen(2 * m);
    ll val = 0;
    ll i = x;
    ll cnt = 0;
    ll r = 0;
    while(true) {
        cnt++;
        
        if(seen[i]) { 
            r = cnt - seen[i];
            i = seen[i];
            break;
        }
 
        seen[i] = cnt;
        i = a[i];
    }
    if(r == 0) exit(1);
    
    ll ans = 0;
    b[0] = x;
    rep(j, 2 * m - 1) {
        b[j + 1] = a[b[j]];
    }
    i--;
    rep(j, i) {
        ans += b[j];
    }
    ll p, q = 0;
    rep(j, i, i + r) {
        p += b[j];
    }
    rep(j, i, i + (n - i) % r) {
        q += b[j];
    }
    ans += ((n - i) / r) * p + q;
    
    out(ans);
 
    return 0;
}
 
int main() { init(); solve(); return 0; }