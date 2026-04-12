#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n; cin >> n;
  vector<vector<ll>> dp(n, vector<ll> (n));
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i], dp[i][i] = a[i];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j+i < n; j++) 
      dp[j][i+j] = max(a[j] - dp[j+1][i+j], a[i+j] - dp[j][i+j-1]);
  }
  cout << dp[0][n-1];
  return 0;
}
