#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include<random>
#include<array>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(a) a.begin(), a.end()
using pii = pair<int,int>;
using piii = pair<pii,int>;
using pll = pair<long long, long long>;
using plll = pair<pll, long long>;
// #pragma GCC optimize("Ofast")
#define pcnt __builtin_popcount
#define buli(x) __builtin_popcountll(x)
#define pb push_back
#define mp make_pair
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define isSquare(x) (sqrt(x)*sqrt(x) == x)
template<class T>bool chmax(T &a, const T &b) {if(a<b){a = b; return 1;} return 0; };
template<class T>bool chmin(T &a, const T &b) {if(a>b){a = b; return 1;} return 0; };
inline void in(void){return;}
template <typename First, typename... Rest> void in(First& first, Rest&... rest){cin >> first;in(rest...);return;}
inline void out(void){cout << "\n";return;}
template <typename First, typename... Rest> void out(First first, Rest... rest){cout << first << " ";out(rest...);return;}
const double EPS = 1e-9;
const int mod = 1e9 + 7;
const int INF = 1e9;
const long long INFLL = 1e18;
void iosetup() {
    cin.tie(nullptr);ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
}
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
    os << p.first << " " << p.second;
    return os;
}
template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
    is >> p.first >> p.second;
    return is;
}
template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
    for(int i = 0; i < (int) v.size(); i++) {
        os << v[i] << (i + 1 != v.size() ? " " : "");
    }
    return os;
}
template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
    for(T &in : v) is >> in;
    return is;
}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S, T>& t){return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S, T>& t){return pair<S,T>(s.first-t.first, s.second-t.second);}
template<class S, class T> pair<S,T> operator*(const pair<S,T> &s, const S& t){return pair<S,T>(s.first*t, s.second*t);}
template <typename T> void Exit(T first){cout << first << endl;exit(0); };
template< int mod > struct ModInt {
    int x; ModInt() : x(0) {}
    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    ModInt &operator+=(const ModInt &p) {if((x += p.x) >= mod) x -= mod;return *this;}
    ModInt &operator-=(const ModInt &p) {if((x += mod - p.x) >= mod) x -= mod;return *this;}
    ModInt &operator*=(const ModInt &p) {x = (int) (1LL * x * p.x % mod);return *this;}
    ModInt &operator/=(const ModInt &p) {*this *= p.inverse();return *this;}
    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }
    ModInt inverse() const {int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) { t = a / b; swap(a -= t * b, b); swap(u -= t * v, v); }return ModInt(u);}
    ModInt pow(int64_t n) const {ModInt ret(1), mul(x); while(n > 0) {if(n & 1) ret *= mul;mul *= mul;n >>= 1;}return ret;}
    friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x;}
    friend istream &operator>>(istream &is, ModInt &a) { int64_t t; is >> t; a = ModInt< mod >(t); return (is); }
    static int get_mod() { return mod; }
}; using modint = ModInt< mod >;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const pii dxy[4] = {pii(1,0), pii(0, 1), pii(-1, 0), pii(0, -1)};
const int calender[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
const int ucalender[13] = {0, 31,29,31,30,31,30,31,31,30,31,30,31};
bool range(int a, int b, int x){if(a <= x and x < b)return true;else return false;}
bool range(int a, int b, int c, int d, pii p){if(a <= p.first and p.first < b and c <= p.second and p.second < d) return true;else return false;}

static const long long MOD=1e9 + 7;

long long modinv(long long a, const long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}//mod mでの逆元aを計算

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

struct combination{
    int mod = MOD;
    vector<long long> fact, ifact, inv;
    combination(int n, const int tmp = MOD):fact(n+1), ifact(n + 1), inv(n+1){
        mod = tmp;
        assert(n < mod);
        fact[0] = 1;
        for(int i = 1; i <= n; i++) fact[i] = fact[i-1]*i%mod;
        ifact[n] = modpow(fact[n], mod - 2, mod);
        for(int i = n; i >= 1; --i) ifact[i-1] = ifact[i] * i%mod;
        for(int i = 1; i <= n; i++) inv[i] = fact[i-1] * ifact[i] % mod;
    }
    long long C(int n, int k){
        if(k < 0 || k > n) return 0;
        return fact[n]*ifact[k]%mod*ifact[n-k] % mod;
    }
};
// combination cb(10, 11); 
// cout << cb.C(10, 3) << endl;


const int MAX = 1e3 + 5;
modint dp[MAX][MAX];
int main(){
    iosetup();
    int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
    memset(dp, 0, sizeof dp);
    combination cb(50000, mod); 
    dp[0][0] = 1;
    dp[A-1][0] = 1;
    rep(i, A, B + 1){
        rep(j, 0, N + 1){
            dp[i][j] = dp[i-1][j];
            rep(k, C, D + 1){
                if(j - k * i < 0) break;
                dp[i][j] += dp[i-1][j-k*i] * cb.C(N - (j - k * i), k * i) 
                * cb.fact[i*k] * modinv(modpow(cb.fact[i], k, mod) * cb.fact[k], mod);
            }
        }
    }
    cout << dp[B][N] << endl;

    return 0;
}