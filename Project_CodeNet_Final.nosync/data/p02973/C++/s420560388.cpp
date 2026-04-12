#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

const int N = 1e5+23;
const int inf = 2e9;
int a[N];
int dp[N];

void solve() {
  // find the longest non-decreasing sequence in reverse
  int n; scanf("%d", &n);
  for (int i = n-1; i >= 0; --i) {
    scanf("%d", a+i);
    dp[i] = inf;
  }
  dp[0] = -inf;
  dp[n] = inf;
  for (int i = 0; i < n; ++i) {
    int j = upper_bound(dp, dp+n+1, a[i]) - dp;
    if (dp[j-1] <= a[i] && a[i] <= dp[j])
      dp[j] = a[i];
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (dp[i] < inf)
      ans = i;
  }
  printf("%d", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
