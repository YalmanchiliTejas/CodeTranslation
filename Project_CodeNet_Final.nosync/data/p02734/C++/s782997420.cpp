#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;

int main() {

  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;

  long long ans = 0;
  vector<int> dp(s + 5, 0);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;

    for (int j = s-x; j >= 1; --j) {
      dp[j + x] = (dp[j + x] + dp[j]) % M;
    }
    if (x <= s) dp[x] += i;
    ans = (ans + dp[s]) % M;
  }

  cout << ans << '\n';

}




