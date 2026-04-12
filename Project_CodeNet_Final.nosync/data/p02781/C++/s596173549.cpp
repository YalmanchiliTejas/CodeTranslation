#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  
  string N;
  int K;
  cin >> N >> K;

  long long dp[110][2][5] = {0};
  dp[0][0][0] = 1;
  for(int i = 0;i < N.size();i++) {
    for(int j = 0;j < 2;j++) {
      for(int k = 0;k <= K;k++) {
        int n = N[i]-'0';
        for(int d = 0;d < 10;d++) {
          if(d > n && j == 0) continue;
          int nk = k;
          if(d != 0) nk++;
          dp[i+1][j||d < n][nk] += dp[i][j][k];
        }
      }
    }
  }

  cout << dp[N.size()][0][K]+dp[N.size()][1][K] << endl;

}
