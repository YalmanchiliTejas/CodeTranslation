#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)

int mod = 100000007;
struct mint {
    ll x;
    mint(ll x=0):x( (x%mod + mod) % mod ) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ( (x += a.x) >= mod ) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ( ( x += mod - a.x) >= mod ) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        ( x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    mint inv() const { return pow(mod - 2); }
    mint& operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) { return mint(*this) /= a; }
};
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

struct combination
{
    vector<mint> fact, ifact;
    combination(int n) : fact(n+1), ifact(n+1) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }
    mint operator() (int n, int k) {
        if ( k < 0 || k > n ) return 0;
        return fact[n] * ifact[k] * ifact[n-k];
    }
};



int main() {
  int n;
  cin >> n >> mod;

  vector< vector<mint> > dp(3005, vector<mint>(3005, 0) );
  vector<mint> p(3005 * 3005, 0), p2(3005, 0), f(3005, 0);
  combination c(3005);
  p[0] = 1, p2[0] = 2;
  for(int i = 1; i < 3005 * 3005; ++i) p[i] = mint(2) * p[i-1];
  for(int i = 1; i < 3005; ++i) p2[i] = p2[i-1] * p2[i-1];

  dp[0][0] = 1;
  for (int n = 1; n < 3005; ++n) {
    for (int k = 0; k <= n; ++k) {
      dp[n][k] += dp[n-1][k];
      if (k-1>=0) dp[n][k] += dp[n-1][k-1];
      dp[n][k] += mint(k) * dp[n-1][k];
    }
  }

  rep(k, n+1) {
    rep(x, k+1) {
      f[k] += dp[k][x] * p[(n - k) * x];
    }
    f[k] *= p2[n - k];
  }

  mint ans = 0;
  rep(k, n + 1) {
    if (k%2 == 0) {
      ans += c(n,k) * f[k];
    } else {
      ans -= c(n,k) * f[k];
    }
  }
  cout << ans << endl;
  return 0;
}