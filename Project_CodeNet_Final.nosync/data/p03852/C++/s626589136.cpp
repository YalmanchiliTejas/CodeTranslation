#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(a) a.begin(), a.end()
#define pii pair<int,int>
#pragma GCC optimize("Ofast")
#define pcnt __builtin_popcount
#define buli(x) __builtin_popcountll(x)
#define pb push_back
#define mp make_pair
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define isSquare(x) (sqrt(x)*sqrt(x) == x)
template<class T>bool chmax(T &a, const T &b) {if(a<b){a = b; return 1;} return 0; };
template<class T>bool chmin(T &a, const T &b) {if(a>b){a = b; return 1;} return 0; };
inline void IN(void){return;}
template <typename First, typename... Rest> void IN(First& first, Rest&... rest){cin >> first;IN(rest...);return;}
inline void OUT(void){cout << "\n";return;}
template <typename First, typename... Rest> void OUT(First first, Rest... rest){cout << first << " ";OUT(rest...);return;}
const double EPS = 1e-9;
const int mod = 1e9 + 7;
const int INF = 1e9;
const long long LLINF = 1e18;
long long lcm(ll a, ll b){return a * b / __gcd(a,b);}
struct IoSetup { IoSetup() {
    cin.tie(nullptr);ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
} } iosetup;
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


int main(){
    iosetup;
    char c; cin >> c;
    if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') puts("vowel");
    else puts("consonant");
    return 0;
}
