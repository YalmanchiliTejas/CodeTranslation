#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...)
#define dumpv(...)
#endif

#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

struct mint {
  ll v;
  mint() : v(0) {}
  mint(ll v) : v((v % MOD + MOD) % MOD) {}
  mint pow(ll t) const;
  mint inv() const;
};
mint& operator+=(mint& a, mint b) { return a = a.v + b.v; }
mint& operator-=(mint& a, mint b) { return a = a.v - b.v; }
mint& operator*=(mint& a, mint b) { return a = a.v * b.v; }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint operator*(mint a, mint b) { return a *= b; }
mint operator-(mint a) { return 0 - a; }
mint& operator/=(mint& a, mint b) { return a *= b.inv(); }
mint operator/(mint a, mint b) { return a /= b; }
mint mint::pow(ll t) const {
  if (!t) return 1;
  mint a = pow(t >> 1);
  a *= a;
  if (t & 1) a *= *this;
  return a;
}
mint mint::inv() const { return pow(MOD - 2); }
bool operator==(mint a, mint b) { return a.v == b.v; }
bool operator!=(mint a, mint b) { return a.v != b.v; }
istream& operator>>(istream& os, mint& a) { return (os >> a.v); }
ostream& operator<<(ostream& os, const mint& a) { return (os << a.v); }

struct mset
{
  vector<mint> fact;  // n! (mod MOD)
  vector<mint> ifact; // k!^{M-2} (mod MOD)
  mset(int n) : fact(n + 1), ifact(n + 1)
  {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
      fact[i] = fact[i - 1] * i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i)
      ifact[i - 1] = ifact[i] * i;
  }
  mint perm(int n, int k)
  { // nPk (mod MOD)
    if (k < 0 || n < k)
      return 0;
    return fact[n] * ifact[n - k];
  }
  mint comb(int n, int k)
  { // nCk (mod MOD)
    if (k < 0 || n < k)
      return 0;
    return fact[n] * ifact[k] * ifact[n - k];
  }
};

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  mset ms(200005);
  mint xres = 0;
  mint yres = 0;
  // x axis
  for (int i = 1; i < m; i++) {
    xres += ((mint)i * (m - i) * n * n);
  }
  xres *= ms.comb(n * m - 2, k - 2);
  // y axis
  for (int i = 1; i < n; i++) {
    yres += ((mint)i * (n - i) * m * m);
  }
  yres *= ms.comb(n * m - 2, k - 2);
  cout << xres + yres << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  // freopen("temp.1", "r", stdin);
  solve();
  return 0;
}