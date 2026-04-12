#include <bits/stdc++.h>

using namespace std;

const int md = int(1e9) + 7;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  string k;
  int d;
  cin >> k >> d;

  vector< vector<int> > dp(d, vector<int>(2));
  dp[0][0] = 1;
  for (int i = 0; i < (int) k.length(); i++) {
    vector< vector<int> > new_dp(d, vector<int>(2));
    for (int j = 0; j < d; j++) {
      for (auto any : {false, true}) {
        for (int dig = 0; dig < 10; dig++) {
          if (!any && dig > k[i] - '0') {
            break;
          }
          add(new_dp[(j + dig) % d][any || dig < k[i] - '0'], dp[j][any]);
        }
      }
    }
    swap(dp, new_dp);
  }
  int ans = (dp[0][false] + dp[0][true]) % md;
  sub(ans, 1);
  cout << ans << '\n';
  return 0;
}