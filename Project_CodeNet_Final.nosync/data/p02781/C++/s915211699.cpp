#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  ll k;
  cin >> s;
  cin >> k;

  ll n = s.size();

  // num is less than S
  vector<vector<ll>> dp1(n + 1, vector<ll>(k + 2));
  // num can be S
  vector<vector<ll>> dp2(n + 1, vector<ll>(k + 2));

  // index 0: digit
  // index 1: num of nonzeros left

  dp2[0][k] = 1;

  for (ll i = 0; i < n; i++) {
    ll d = s[i] - '0';
    for (ll j = 0; j <= k; j++) {
      if (d == 0) {
        dp1[i + 1][j] = dp1[i][j]     * 1  // 0
                      + dp1[i][j + 1] * 9; // 1 ~ 9

        dp2[i + 1][j] = dp2[i][j]     * 1; // 0

      } else {
        dp1[i + 1][j] = dp1[i][j]     * 1        // 0
                      + dp1[i][j + 1] * 9        // 1 ~ 9
                      + dp2[i][j]     * 1        // 0
                      + dp2[i][j + 1] * (d - 1); // 1 ~ d - 1

        dp2[i + 1][j] = dp2[i][j + 1] * 1;       // d
      }
    }
  }
  cout << dp1[n][0] + dp2[n][0] << endl;
}
