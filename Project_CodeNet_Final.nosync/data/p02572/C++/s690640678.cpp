#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...)
#define dumpv(...)
#endif

#define rep(i, n) for (int i = 0; i < (n); i++)
#define mins(x, y) (x = min(x, y))
#define maxs(x, y) (x = max(x, y))
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using P = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

struct mint {
  ll v;
  mint(ll v = 0) : v((v % MOD + MOD) % MOD) {}
  mint pow(ll t) const;
  mint inv() const;
};
mint& operator+=(mint& a, mint b) { return a = a.v + b.v; }
mint& operator-=(mint& a, mint b) { return a = a.v - b.v; }
mint& operator*=(mint& a, mint b) { return a = a.v * b.v; }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint operator*(mint a, mint b) { return a *= b; }
mint operator-(mint a) { return (mint)0 - a; }
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

void solve() {
  int n;
  cin >> n;
  vl a(n);
  rep(i, n) cin >> a[i];
  vl c(n + 1);
  rep(i, n) c[i + 1] += c[i] + a[i];
  mint ans = 0;
  rep(i, n) {
    ans += ((mint)a[i] * (c[n] - c[i + 1]));
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  // freopen("temp.1", "r", stdin);
  solve();
  return 0;
}