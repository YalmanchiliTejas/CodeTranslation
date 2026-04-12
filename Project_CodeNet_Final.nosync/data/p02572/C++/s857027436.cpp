#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template <int mod>
struct ModInt {
    int val;
    ModInt() : val(0) {}
    ModInt(long long x) : val(x >= 0 ? x % mod : (mod - (-x) % mod) % mod) {}
    int getmod() { return mod; }
    ModInt &operator+=(const ModInt &p) {
        if ((val += p.val) >= mod) {
            val -= mod;
        }
        return *this;
    }
    ModInt &operator-=(const ModInt &p) {
        if ((val += mod - p.val) >= mod) {
            val -= mod;
        }
        return *this;
    }
    ModInt &operator*=(const ModInt &p) {
        val = (int)(1LL * val * p.val % mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }
    ModInt operator-() const { return ModInt(-val); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
    bool operator==(const ModInt &p) const { return val == p.val; }
    bool operator!=(const ModInt &p) const { return val != p.val; }
    ModInt inverse() const {
        int a = val, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }
    ModInt pow(long long n) const {
        ModInt ret(1), mul(val);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.val; }
    friend istream &operator>>(istream &is, ModInt &a) {
        long long t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }
    static int get_mod() { return mod; }
};
const int MOD = 1000000007;  // if inv is needed, this shold be prime.
using modint = ModInt<MOD>;

int main(){
    int n;
    cin >> n;
    vector<modint> a(n);
    vector<modint> sum(n+1);
    rep(i, n){
        cin >> a.at(i);
        if(i != 0)sum.at(i) = sum.at(i-1) + a.at(i);
        else sum.at(i) = a.at(i);
    }
    modint ans = 0;
    rep(i, n){
        ans += a.at(i) * (sum.at(n-1) - sum.at(i));
    }
    cout << ans << endl;
    
}