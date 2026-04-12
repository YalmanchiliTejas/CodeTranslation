#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                           \
  cerr << __LINE__ << ": " << #x << " = {";        \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];        \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  long long A[N];
  for (int i = 0; i < N; i++) cin >> A[i];
  long long dp[N + 1][2][2];
  const long long INF = INT_MAX;
  dp[0][0][0] = 0;
  dp[0][0][1] = -INF;
  dp[0][1][0] = -INF;
  dp[0][1][1] = -INF;
  for (int i = 1; i <= N; i++) {
    if (i & 1) {
      dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][1][0]);
      dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][1][1]);
      dp[i][1][0] = dp[i - 1][0][1] + A[i - 1];
      dp[i][1][1] = dp[i - 1][0][0] + A[i - 1];
    } else {
      dp[i][0][0] = dp[i - 1][1][1];
      dp[i][0][1] = max(dp[i - 1][0][0], dp[i - 1][1][0]);
      dp[i][1][0] = dp[i - 1][0][0] + A[i - 1];
      dp[i][1][1] = dp[i - 1][0][1] + A[i - 1];
    }
  }
  long long ans = max(dp[N][0][0], dp[N][1][0]);
  cout << ans << endl;
  return 0;
}
