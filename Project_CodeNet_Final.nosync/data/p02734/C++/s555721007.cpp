#include<bits/stdc++.h>

using namespace std;
  
int main() {
  int n, s;
  cin >> n >> s;
  int arr[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  long long ans(0);
  vector<long long> dp(s + 1);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    long long t(dp[s]);
    for (int j = s; j >= 0; --j) {
      if ((dp[j] || j == 0) && j + arr[i] <= s) {
        if (j == 0) {
          dp[arr[i]] += i + 1;
        } else {
          dp[j + arr[i]] += dp[j];
        }
        dp[j + arr[i]] %= 998244353;
      }
      
    }
    ans += ((dp[s] + 998244353 - t) * (n - i)) % 998244353;
      ans %= 998244353;
  }
  
  cout << ans << '\n';
  return 0;
}