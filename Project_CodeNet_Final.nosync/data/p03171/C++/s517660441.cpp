#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
  int n;
  cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];

  ll dp[n + 1][n + 1];  // この区間で自分に回ってきたとき、自分がとれる最大値
  memset(dp, 0, sizeof(dp));
  for (int w = 1; w <= n; w++)
    for (int i = 0; i + w <= n; i++)
      dp[i][i + w] = max(v[i] - dp[i + 1][i + w], v[i + w - 1] - dp[i][i + w - 1]);

  cout << dp[0][n] << endl;
}
