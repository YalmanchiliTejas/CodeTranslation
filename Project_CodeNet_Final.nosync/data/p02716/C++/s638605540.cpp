#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long a[n], dp[n+1], odds[n];
  dp[0] = dp[1] = 0;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; i += 2)
    odds[i] = (i ? odds[i-2] : 0) + a[i];
  for (int i = 1; i < n; i++)
    dp[i+1] = max(a[i] + dp[i-1],i % 2 ? odds[i-1] : dp[i]);
  cout << dp[n] << '\n';
  return 0;
}