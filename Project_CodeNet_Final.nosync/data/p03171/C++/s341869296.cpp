#include<bits/stdc++.h>
using namespace std;

int a[3100];
long long dp[3100][3100] = {0};


int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int d = 1; d <= n; ++d) {
    for (int i = 0; i + d <= n; ++i) {
      dp[i][i + d] = max(a[i] - dp[i + 1][i + d], a[i + d - 1] - dp[i][i + d - 1]);
    }
  }
  cout << dp[0][n] << '\n';
}
