#include <bits/stdc++.h>
using namespace std;

long long dp[10000][100][2];
long long mod = 1e9 + 7;
int main() {
  string n;
  cin>>n; 
  int d;
  cin>>d;

  int len = n.length();
  for (int i=0; i<len; i++) {
    for (int j=0; j<d; j++) {
      dp[i][j][0] = 0;
      dp[i][j][1] = 0;
    }
  }
  for (int j=0; j<10; j++) {
    if (j < n[0] - '0') {
      dp[0][j%d][1] += 1;
    } else if (j == n[0] - '0') {
      dp[0][j%d][0] += 1;
      break;
    }
  }
  for (int i=1; i<len; i++) {
    for (int j=0; j<d; j++) {
      for (int k=0; k<10; k++) {
        if (k < n[i] - '0') {
          dp[i][(j+k)%d][1] += dp[i-1][j][1] + dp[i-1][j][0];
          dp[i][(j+k)%d][1] %= mod;
        } else if (k == n[i] - '0') {
          dp[i][(j+k)%d][1] += dp[i-1][j][1];
          dp[i][(j+k)%d][1] %= mod;
          dp[i][(j+k)%d][0] += dp[i-1][j][0];
          dp[i][(j+k)%d][0] %= mod;
        } else {
          dp[i][(j+k)%d][1] += dp[i-1][j][1];
          dp[i][(j+k)%d][1] %= mod;
        }
      }
    }
  }
  long long ans = dp[len-1][0][0] + dp[len-1][0][1];
  cout<<(ans-1 + mod) % mod<<endl;
}
