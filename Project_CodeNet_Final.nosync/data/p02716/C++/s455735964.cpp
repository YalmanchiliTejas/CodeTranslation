#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  REP(i, n) { cin >> a[i]; }
  const ll INF = 1e18;
  vector<vector<vector<ll>>> dp(n + 1,
                                vector<vector<ll>>(2, vector<ll>(2, -INF)));
  dp[0][1][0] = 0;
  REP(i, n) {
    REP(j, 2) {
      REP(k, 2) if (dp[i][j][k] != -INF) {
        if (i % 2 == 1) {
          chmax(dp[i + 1][j][0], dp[i][j][k]);
        } else {
          chmax(dp[i + 1][0][0], dp[i][1][k]);
        }
        if (i % 2 == 1) {
          chmax(dp[i + 1][1][1], dp[i][0][0] + a[i]);
        } else {
          chmax(dp[i + 1][j][1], dp[i][j][0] + a[i]);
        }
      }
    }
  }
  int b = !(n % 2 == 1);
  cout << max(dp[n][b][0], dp[n][b][1]) << endl;
}
