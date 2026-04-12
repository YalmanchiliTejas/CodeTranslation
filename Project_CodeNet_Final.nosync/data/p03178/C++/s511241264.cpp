#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../lib/dump.hpp"
#else
#define dump(...)
#define dumpv(...)
#endif

#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

struct mint
{
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
mint mint::pow(ll t) const
{
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

mint dp[10005][101][2];

void solve()
{
  string K;
  int D, N;
  cin >> K >> D;
  N = K.length();
  dp[0][0][0] = 1;
  rep(i, N) rep(d, D) rep(isless, 2)
  {
    int c = K[i] - '0';
    rep(x, 10)
    {
			int nd = (d + x) % D, nisless = isless;
			if (!isless && c < x) continue;
			if (x < c) nisless = 1;
      dp[i + 1][nd][nisless] += dp[i][d][isless];
      // if (x < c)
      //   dp[i + 1][(d + x) % D][1] += dp[i][d][isless];
      // else if (x == c)
      //   dp[i + 1][(d + x) % D][isless] += dp[i][d][isless];
      // else {
      //   if (isless) dp[i + 1][(d + x) % D][isless] += dp[i][d][isless];
      // }
    }
  }
  dump(dp[N][0][0], dp[N][0][1]);
  cout << dp[N][0][0] + dp[N][0][1] - 1 << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  // freopen("temp.1", "r", stdin);
  solve();
  return 0;
}