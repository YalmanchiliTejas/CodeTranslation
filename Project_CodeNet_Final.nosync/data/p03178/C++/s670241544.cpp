#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void add_self (int& a, int b) {
  a += b;
  if (a >= mod)
    a -= mod;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string K;
  int D;
  cin >> K >> D;
  int lg = K.size();
  vector < vector < int > > dp(D, vector < int >(2));
  dp[0][0] = 1;
  for (int i = 0; i < lg; ++i) {
    vector < vector < int > > new_dp(D, vector < int >(2));
    for (int sum = 0; sum < D; ++sum)
      for (int sm_already : {0, 1})
        for (int digit = 0; digit < 10; ++digit) {
          if (digit > K[i] - '0' && !sm_already)
            break;
          add_self (new_dp[(sum + digit) % D][sm_already || (digit < K[i] - '0')],
                    dp[sum][sm_already]);
        }
    dp = new_dp;
  }
  int ans = (dp[0][0] + dp[0][1]) % mod;
  --ans;
  if (ans == -1)
    ans = mod - 1;
  cout << ans;
}
