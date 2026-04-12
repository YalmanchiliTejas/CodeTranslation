#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  int K, dp[101][4][2];
  memset(dp, 0, sizeof(int) * 101 * 4 * 2);
  dp[0][0][0] = 1;
  cin >> s >> K;
  for(int i = 0; i < s.length(); i++) {
    int d = s[i] - '0';
    for(int j = 0; j < 4; j++)
      for(int k = 0; k < 2; k++)
        for(int n = 0; n < 10; n++) {
          int ni = i + 1, nj = j, nk = k;
          if(n) nj++;
          if(nj > K) continue;
          if(!k) {
            if(n > d) continue;
            if(n < d) nk = 1;
          }
          dp[ni][nj][nk] += dp[i][j][k];
        }
  }
  cout << dp[s.length()][K][1] + dp[s.length()][K][0] << '\n';
}