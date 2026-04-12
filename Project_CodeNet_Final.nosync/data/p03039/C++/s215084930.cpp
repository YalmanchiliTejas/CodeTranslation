#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
const int mod = 1000000007;
struct mint {
  ll x;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
mint comb(int n, int k) {
    mint x = 1;
    mint y = 1;
    rep(i,k) {
        x *= n-i;
        y *= i+1;
    }
    return x/y;
}

int main() 
{
    int n, m, k;
    cin >> n >> m >> k;

    mint ans = 0;
    for(int d=1; d<=n-1; d++) {
        mint pat = 1;
        pat *= (n-d);
        pat *= m;
        pat *= m;
        pat *= d;
        ans += pat;
    }

    for(int d=1; d<=m-1; d++) {
        mint pat = 1;
        pat *= (m-d);
        pat *= n;
        pat *= n;
        pat *= d;
        ans += pat;
    }
    ans *= comb(n*m-2, k-2);

    cout << ans << endl;


    return 0;
}
