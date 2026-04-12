#include <bits/stdc++.h>
using namespace std;
const int p = 1e9 + 7;
int main() {
  do {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  } while (false);
  int n, m;
  cin >> n >> m;
  string str;
  cin >> str;
  if (str[0] == 'B') {
    for (int i = 0; i < m; i++) {
      if (str[i] == 'R') {
        str[i] = 'B';
      } else {
        str[i] = 'R';
      }
    }
  }
  while (!str.empty() && str.back() == 'R') {
    str.pop_back();
  }
  if (str.empty()) {
    vector<int> dp(n);
    int sum = 0;
    for (int i = 1; i < n; i++) {
      dp[i] = (i + 1 + sum) % p;
      if (i) {
        sum = (sum + dp[i - 1]) % p;
      }
    }
    cout << (dp[n - 1] + 1) % p << endl;
  } else {
    int limit = INT_MAX, last = -1;
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == 'B') {
        int len = i - last - 1;
        if (len & 1) {
          limit = min(limit, len);
        } else if (-1 == last) {
          limit = min(limit, len + 1);
        }
        last = i;
      }
    }
    vector<int> dp(n);
    int sum_0 = 0, sum_1 = 0;
    for (int i = 1; i < n; i++) {
      if (i & 1) {
        if (i <= limit) {
          dp[i] = i + 1;
        }
        dp[i] = (dp[i] + sum_1) % p;
        sum_0 = (sum_0 + dp[i - 1]) % p;
      } else {
        dp[i] = (dp[i] + sum_0) % p;
        sum_1 = (sum_1 + dp[i - 1]) % p;
      }
      if (i - limit - 1 > 0) {
        if (i - limit - 1 & 1) {
          sum_1 = (sum_1 - dp[i - limit - 1] + p) % p;
        } else {
          sum_0 = (sum_0 - dp[i - limit - 1] + p) % p;
        }
      }
    }
    cout << dp[n - 1] << endl;
  }
  return 0;
}
