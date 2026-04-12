#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
#define INF 1000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll unuse = (n % 2) + 1;
  vector<vector<ll>>dp(n+1, vector<ll>(unuse+1));
  dp[1][0] = a[0];
  dp[2][0] = a[0];
  dp[2][1] = a[1];
  if (unuse == 2) {
    dp[3][0] = a[0] + a[2];
    dp[3][1] = 0;
    dp[3][2] = a[2];
  }

  if (unuse == 1) {
    for (int i = unuse + 2; i <= n; i++) {
      dp[i][0] = dp[i-2][0] + a[i-1];
      dp[i][1] = a[i-1] + max(dp[i-2][1], dp[i-3][0]);
    }
    cout << max(dp[n][1], dp[n-1][0]) << endl;
  }
  else {
    for (int i = unuse + 2; i <= n; i++) {
      dp[i][0] = dp[i-2][0] + a[i-1];
      dp[i][1] = a[i-1] + max(dp[i-2][1], dp[i-3][0]);
      dp[i][2] = a[i-1] + max(dp[i-2][2], max(dp[i-3][1], dp[i-4][0]));
    }
    cout << max(dp[n][2], max(dp[n-1][1], dp[n-2][0])) << endl;
  }
}