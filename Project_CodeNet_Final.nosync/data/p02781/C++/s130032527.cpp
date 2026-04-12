#include <bits/stdc++.h>
using namespace std;

#define each(i, c) for (auto& i : c)
#define mkp(a, b) make_pair(a, b)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> Pll;
const ll MOD = 1e9+7;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << ": " << p.second << ")"; return os; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ", "; os << ")"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; each (i, m) os << i << ", "; os << "}"; return os; }

int main() {
  string s;
  cin >> s;
  ll n = s.size();

  ll k;
  cin >> k;

  ll dp[105][2][k+1];
  memset(dp, 0, sizeof(dp));

  dp[0][0][0] = 1;
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < 2; ++j) {
      for (ll ki = 0; ki <= k; ++ki) {
        ll x = s[i] - '0';
        for (ll d = 0; d < 10; ++d) {
          ll in = i+1;
          ll jn = j;
          ll kn = ki;
          if (d > 0) ++kn;
          if (kn > k) continue;
          if (j == 0) {
            if (d > x) continue;
            if (d < x) jn = 1;
          }
          dp[in][jn][kn] += dp[i][j][ki];
        }
      }
    }
  }

  ll ans = dp[n][0][k] + dp[n][1][k];
  cout << ans << endl;

  return 0;
}