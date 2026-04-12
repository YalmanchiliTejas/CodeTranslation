#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector< vector<long long> > dp(n + 1, vector<long long>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j + i <= n; j++) {
      long long vl = a[j] - dp[j + 1][j + i];
      long long vr = a[j + i - 1] - dp[j][j + i - 1];
      dp[j][j + i] = max(vl, vr);
    }
  }
  cout << dp[0][n] << '\n';
  return 0;
}