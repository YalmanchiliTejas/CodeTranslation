#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  if (n % 2 == 0) {
    vector dp(n, vector(2, -LINF));
    dp[1][0] = a[0];
    dp[1][1] = a[1];
    for (int i = 3; i < n; i += 2) {
      dp[i][0] = dp[i - 2][0] + a[i - 1];
      dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + a[i];
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
  } else {
    vector dp_l(n, vector(2, -LINF));
    dp_l[1][0] = a[0];
    dp_l[1][1] = a[1];
    for (int i = 3; i < n; i += 2) {
      dp_l[i][0] = dp_l[i - 2][0] + a[i - 1];
      dp_l[i][1] = max(dp_l[i - 2][0], dp_l[i - 2][1]) + a[i];
    }
    vector dp_r(n, vector(2, -LINF));
    dp_r[n - 2][0] = a[n - 2];
    dp_r[n - 2][1] = a[n - 1];
    for (int i = n - 4; i >= 0; i -= 2) {
      dp_r[i][0] = max(dp_r[i + 2][0], dp_r[i + 2][1]) + a[i];
      dp_r[i][1] = dp_r[i + 2][1] + a[i + 1];
    }
    ll ans = -LINF;
    REP(i, n) {
      if (i & 1) {
        // chmax(ans, dp_l[i][0] + (i + 2 < n ? max(dp_r[i + 2][0], dp_r[i + 2][1]) : 0LL));
        // chmax(ans, dp_r[i][1] + (i >= 2 ? max(dp_l[i - 2][0], dp_l[i - 2][1]) : 0LL));
      } else {
        chmax(ans, (i > 0 ? max(dp_l[i - 1][0], dp_l[i - 1][1]) : 0LL) + (i + 1 < n ? max(dp_r[i + 1][0], dp_r[i + 1][1]) : 0LL));
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
