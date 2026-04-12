/**
*	created: 29.08.2020 20:57:26
**/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
using ll = long long;
using P = pair<int,int>;
// #define endl '\n'
#define int long long
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,s,n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1ll << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
template<typename T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
template<typename T> T pow(T a, ll n) {T r(1); while(n) {if (n & 1) r *= a; a *= a; n >>= 1;} return r;}
struct faster_io {faster_io() {cin.tie(0); ios_base::sync_with_stdio(false);}} faster_io_;

// ModInt
template <int mod> struct ModInt {
    int x;
    ModInt() : x(0) {}
    ModInt(long long x_) {if ((x = x_ % mod + mod) >= mod) x -= mod;}
    ModInt& operator+=(ModInt rhs) {if ((x += rhs.x) >= mod) x -= mod; return *this;}
    ModInt& operator-=(ModInt rhs) {if ((x -= rhs.x) < 0) x += mod; return *this;}
    ModInt& operator*=(ModInt rhs) {x = (unsigned long long)x * rhs.x % mod; return *this;}
    ModInt& operator/=(ModInt rhs) {x = (unsigned long long)x * rhs.inv().x % mod; return *this;}
    ModInt operator-() const {return -x < 0 ? mod - x : -x;}
    ModInt operator+(ModInt rhs) const {return ModInt(*this) += rhs;}
    ModInt operator-(ModInt rhs) const {return ModInt(*this) -= rhs;}
    ModInt operator*(ModInt rhs) const {return ModInt(*this) *= rhs;}
    ModInt operator/(ModInt rhs) const {return ModInt(*this) /= rhs;}
    bool operator==(ModInt rhs) const {return x == rhs.x;}
    bool operator!=(ModInt rhs) const {return x != rhs.x;}
    ModInt inv() const {return pow(*this, mod - 2);}
    friend ostream& operator<<(ostream& s, ModInt<mod> a) {s << a.x; return s;}
    friend istream& operator>>(istream& s, ModInt<mod>& a) {s >> a.x; return s;}
};

using mint = ModInt<MOD>;

signed main() {
    int n; cin >> n;
    vector<mint> a(n), b(n);
    rep(i,n) {
        cin >> a[i];
        b[i] = a[i];
    }
    reverse(all(b));
    rep2(i,1,n) b[i] += b[i-1];
    reverse(all(b));
    mint ans = 0;
    rep(i,n-1) ans += a[i]*b[i+1];
    cout << ans << endl;
    return 0;
}