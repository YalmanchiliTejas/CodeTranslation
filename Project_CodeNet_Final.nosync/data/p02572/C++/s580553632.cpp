#include <bits/stdc++.h>
#define repi(i, a, b) for (int i = (int)(a) ; i < (int)(b) ; i++)
#define rep(i, n) repi(i, 0, n)
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
// using P = pair<int, int>;
struct Vec{
    double x, y;
};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
     return false;
}
using namespace std;

const int mod = 1000000007;
class mint {
public:
    long long x;
    mint(long long x=0) : x((x%mod+mod)%mod) {}
    mint operator-() const { 
      return mint(-x);
    }
    mint& operator+=(const mint& a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint& a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const  mint& a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint& a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint& a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint& a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint& a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint& a) const {
        mint res(*this);
        return res/=a;
    }

    friend ostream& operator<<(ostream& os, const mint& m){
        os << m.x;
        return os;
    }
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    // cout << fixed << setprecision(15);
    int n;
    mint s = 0;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
        s += a[i];
    }
    mint ans = 0;
    rep(i, n - 1){
        s -= a[i];
        mint ar = (a[i] * s.x);
        ans += ar;
    }
    cout << ans << endl;
    return 0;
}