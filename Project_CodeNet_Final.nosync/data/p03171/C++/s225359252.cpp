#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;
using vld = vector<ld>;
using vvld = vector<vld>;

typedef pair<ll, ll> P;

#define bit(n) (1LL << (n))

//#define int long long

#define all(v) v.begin(), v.end()

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

template <class T>
inline void chmax(T& a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T& a, T b) {
  a = std::min(a, b);
}

#define mod (ll)(1e9 + 7)
// #define mod (998244353ll)

const long long INF = 1LL << 60;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n;
  cin >> n;
  vll a(n);
  rep(i, n) {
    cin >> a[i];
  }

  // dp[何個取ったか][右から何個取ったか]
  vvll dp(n + 1, vll(n + 2));

  for (int i = n - 1; i >= 0; i--) {
    rep(j, i + 1) {
      if (i % 2 == 0) {
        dp[i][j] = dp[i + 1][j] + a[i - j];
        chmax(dp[i][j], dp[i + 1][j + 1] + a[n - 1 - j]);
      } else {
        dp[i][j] = dp[i + 1][j] - a[i - j];
        chmin(dp[i][j], dp[i + 1][j + 1] - a[n - 1 - j]);
      }
    }
  }

  cout << dp[0][0] << endl;

  return 0;
}
