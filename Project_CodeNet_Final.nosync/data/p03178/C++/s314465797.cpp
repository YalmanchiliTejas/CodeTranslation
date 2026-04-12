# include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 2;
const int mod = 1e9 + 7;

int d, n, ans, dp[N][105], pref[N];
string s;

int main(){
      cin >> s >> d;

      n = s.size();
      s = ' ' + s;

      for(int i = 1; i <= n; i ++){
            pref[i] = pref[i - 1] + s[i] - '0';
      }

      dp[0][0] = 1;

      for(int i = 1; i < n; i ++){
            for(int j = 0; j <= 9; j ++){
                  if(i == 1 && !j)
                        continue;
                  for(int k = 0; k < d; k ++){
                        int to = (k + j) % d;
                        dp[i][to] = (dp[i - 1][k] + dp[i][to]) % mod;
                  }
            }
            ans = (ans + dp[i][0]) % mod;
      }

      memset(dp, 0, sizeof(dp));
      dp[0][0] = 1;

      for(int i = 1; i < n; i ++){
            for(int j = 0; j <= 9; j ++){
                  for(int k = 0; k < d; k ++){
                        int to = (k + j) % d;
                        dp[i][to] = (dp[i - 1][k] + dp[i][to]) % mod;
                  }
            }
      }

      for(int i = 1; i <= n; i ++){
            for(int j = 0; j < s[i] - '0'; j ++){
                  if(i == 1 && !j)
                        continue;
                  int sum = (pref[i - 1] + j) % d;
                  ans = (ans + dp[n - i][(d - sum + d) % d]) % mod;

            }
      }

      if(pref[n] % d == 0)
            ans = (ans + 1) % mod;

      cout << ans << endl;
}
