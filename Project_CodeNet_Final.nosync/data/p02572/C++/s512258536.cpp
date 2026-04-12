// May this submission get accepted
#include <bits/stdc++.h>

// エイリアス
using  ll = long signed long;
using ull = long unsigned long;
using  ld = long double;
using namespace std;

// AtCoder/Codeforces 用 デバッグ検知
#ifdef ONLINE_JUDGE
constexpr bool DEBUG_MODE = false;
#else
constexpr bool DEBUG_MODE = true;
#endif

// エイリアス (補完・コンパイルが重くなる)
// #include <boost/multiprecision/cpp_int.hpp>
// using mll = boost::multiprecision::cpp_int;

// 汎用マクロ
#define ALLOF(x) (x).begin(), (x).end()
#define REP(i,n) for (long long i=0, i##_len=(n); i<i##_len; i++)
#define RANGE(i,is,ie) for (long long i=(is), i##_end=(ie); i<=i##_end; i++)
#define DSRNG(i,is,ie) for (long long i=(is), i##_end=(ie); i>=i##_end; i--)
#define STEP(i, is, ie, step) for (long long i=(is), i##_end=(ie), i##_step = (step); i<=i##_end; i+=i##_step)
#define UNIQUE(v) do { sort((v).begin(), (v).end()); (v).erase(unique((v).begin(), (v).end()), (v).end()); } while (false)
#define FOREACH(i,q) for (auto &i : q)
template<typename T, typename U> bool chmax(T &a, const U b) { if (a < b) {a = b; return true;} return false; }
template<typename T, typename U> bool chmin(T &a, const U b) { if (a > b) {a = b; return true;} return false; }
constexpr int INF = numeric_limits<int>::max();
constexpr long long LINF = numeric_limits<long long>::max();
constexpr long double EPS = 1e-10L;
#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" : "IMPOSSIBLE")
#define IIF(q,t,f) ((q) ? (t) : (f))
#define DUMP(q) DUMP_FUNC(q, #q, __FILE__, __LINE__)
template <typename T> void DUMP_PROC(T x) { if (is_integral<T>() || is_floating_point<T>()) cerr << "\e[32m" << x << "\e[m"; else cerr << x; }
template<> void DUMP_PROC<char>(char x) { cerr << "\e[36m\'" << x << "\'\e[m"; }
template<> void DUMP_PROC<string>(string x) { cerr << "\e[33m\"" << x << "\"\e[m"; }
template <typename T, typename U> void DUMP_PROC(pair<T, U> x) { cerr << "{"; DUMP_PROC(x.first); cerr << ", "; DUMP_PROC(x.second); cerr << "}"; }
template <typename ...T, typename U, U... Seq> void DUMP_PROC(tuple<T...> &x, integer_sequence<U, Seq...>) { (void)(int[]){(cerr << ((const char*[]){"", ", "})[!!Seq] << (DUMP_PROC(get<Seq>(x)), ""), 0)...}; }
template <typename ...T> void DUMP_PROC(tuple<T...> x) {cerr << "{"; DUMP_PROC(x, index_sequence_for<T...>()); cerr << "}";}
template <typename T> void DUMP_PROC(vector<T> x) { cerr << "["; for (auto &xi : x) { DUMP_PROC(xi); cerr << (&xi != &*x.rbegin()?", ":""); } cerr << "]"; }
template <typename T> void DUMP_FUNC(T x, const char* name, const char* fn, int ln) { cerr << "\e[32m[DEBUG]\e[m " << name << ": "; DUMP_PROC(x); cerr << " @ " << fn << "(" << ln << ")" << endl; }

// gcc拡張マクロ
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll

// 標準入出力
struct qin { // query input
    size_t sz;
    qin(size_t _sz = 1) : sz(_sz) {}
    template <typename T> operator T () const { T a; cin >> a; return a; }
    template <typename T> operator vector<T> () const { vector<T> a(sz); for (size_t i = 0; i < sz; i++) cin >> a[i]; return a; }
    template <typename T, typename U> operator pair<T, U> () const { T f; U s; cin >> f >> s; return pair<T, U>(f, s); }
};
qin in1; // input one
template <typename T> void say(const T x, const char* end = "\n") { cout << x << end; }
void say(const ld x, const char* end = "\n") { cout << setprecision(30) << x << end; }
template <typename T> void say(const vector<T> x, const char* sep = " ", const char* end = "\n") { REP(i, x.size()) { cout << x[i] << (i+1 == i_len ? end : sep); } }
template <typename T> void say(const vector<vector<T>> x, const char* sep = " ", const char* end = "\n") { REP(i, x.size()) { say(x[i], sep, end); } }

// モジュール
// [[LIBRARY]] modint3.cpp
// [Inclusion] modint3.cpp
// い　つ　も　の
constexpr long long pdiv = 1000000007LL;
// constexpr long long pdiv = 998244353LL;
struct modint {
    long long x = 0;
    constexpr modint(long long _x = 0) noexcept: x(regularize(_x)) { }
    static constexpr long long regularize(long long x) noexcept { x %= pdiv; return x + (x < 0 ? pdiv : 0); }
    static constexpr long long regularize(modint a) noexcept { return a.x; }
    static constexpr long long llpow(long long a, long long n) noexcept {
        a %= pdiv; if (a < 0) a += pdiv;
        n %= pdiv-1; if (n < 0) n += pdiv-1;
        long long result = 1;
        for (long long base = a; n; n >>= 1) {
            if (n & 1) (result *= base) %= pdiv;
            (base *= base) %= pdiv;
        }
        return result;
    }
    static constexpr long long llinv(long long a) noexcept { return llpow(a, pdiv-2); }
    constexpr modint pow(long long n) const noexcept { return modint(llpow(x, n)); }
    constexpr modint inv() const noexcept { return modint(llinv(x)); }
    constexpr modint operator+ (long long a) const noexcept { return modint(x + a % pdiv); }
    constexpr modint operator- (long long a) const noexcept { return modint(pdiv + x - a % pdiv); }
    constexpr modint operator* (long long a) const noexcept { return modint(x * (a % pdiv)); }
    constexpr modint operator/ (long long a) const noexcept { return modint(x * llinv(a)); }
    constexpr modint operator+ (modint a) const noexcept { return modint(x + a.x); }
    constexpr modint operator- (modint a) const noexcept { return modint(x - a.x); }
    constexpr modint operator* (modint a) const noexcept { return modint(x * a.x); }
    constexpr modint operator/ (modint a) const noexcept { return modint(x * a.inv().x); }
    template <typename T> constexpr modint& operator+= (T a) noexcept { x += regularize(a); if (x >= pdiv) x -= pdiv; return *this; }
    template <typename T> constexpr modint& operator-= (T a) noexcept { x += pdiv - regularize(a); if (x >= pdiv) x -= pdiv; return *this; }
    template <typename T> constexpr modint& operator*= (T a) noexcept { (x *= regularize(a)) %= pdiv; return *this; }
    template <typename T> constexpr modint& operator/= (T a) noexcept { (x *= llinv(a)) %= pdiv; return *this; }
    constexpr modint operator- () const noexcept { return modint(pdiv - x); }
    template <typename T> constexpr modint& operator= (T a) noexcept { x = regularize(a); return *this; }
    template <typename T> constexpr bool operator== (T a) noexcept { return x == regularize(a); }
};
constexpr modint operator+ (const long long a, const modint b) noexcept { return modint(a) + b; }
constexpr modint operator- (const long long a, const modint b) noexcept { return modint(a) - b; }
constexpr modint operator* (const long long a, const modint b) noexcept { return modint(a) * b; }
constexpr modint operator/ (const long long a, const modint b) noexcept { return modint(a) / b; }
constexpr modint operator"" _p(unsigned long long _x) noexcept { return modint(_x); }
ostream& operator<< (ostream& ost, const modint a) { return ost << a.x; }
istream& operator>> (istream& ist, modint &a) { return ist >> a.x; }
constexpr modint pow(modint a, long long n) noexcept { return a.pow(n); }
vector<modint> fac_cache = {1}, invfac_cache = {1};
void prepare_fac(long long nmax) {
    long long m0 = fac_cache.size() - 1;
    if (m0 < nmax) {
           fac_cache.resize(nmax+1);
        invfac_cache.resize(nmax+1);        
        for (long long n = m0+1; n <= nmax; n++) {
            fac_cache[n] = fac_cache[n-1] * n;
        }
        invfac_cache[nmax] = fac_cache[nmax].inv();
        for (long long n = nmax-1; n > m0; n--) {
            invfac_cache[n] = invfac_cache[n+1] * (n+1);
        }
    }
}
modint    fac(long long n) { prepare_fac(n); return    fac_cache[n]; }
modint invfac(long long n) { prepare_fac(n); return invfac_cache[n]; }
constexpr bool isinpascal(long long n, long long r) noexcept { return n >= 0 && r >= 0 && n >= r; }
modint nCr(long long n, long long r) { return !isinpascal(n, r) ? 0_p : fac(n) * invfac(r) * invfac(n-r); }
modint nPr(long long n, long long r) { return !isinpascal(n, r) ? 0_p : fac(n) * invfac(n-r); }
modint nHr(long long n, long long r) { return nCr(n+r-1, r); }

// [[/LIBRARY]]

// 処理内容
int main() {
    
    ios::sync_with_stdio(false); // stdioを使うときはコメントアウトすること
    cin.tie(nullptr);            // インタラクティブ問題ではコメントアウトすること
    
    ll n = in1;
    vector<ll> a = qin(n);
    
    modint u = 0, v = 0;
    REP(i, n) {
        u += a[i];
        v += a[i] * a[i];
    }
    say((u * u - v) / 2);
    
}