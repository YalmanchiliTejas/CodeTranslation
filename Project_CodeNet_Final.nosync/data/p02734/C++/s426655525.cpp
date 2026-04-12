#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, s;
  cin >> n >> s;

  vector<int> a(n);
  for (auto&& e : a)
    cin >> e;

  int ans = 0;
  vector<int> dp(s + 1);
  for (int i = 0; i < n; i++) {
    dp[0] = i + 1;
    for (int j = s; j >= a[i]; j--) {
      dp[j] += dp[j - a[i]];
      dp[j] %= 998244353;
    }
    ans += dp[s];
    ans %= 998244353;
  }
  cout << ans << endl;
}
