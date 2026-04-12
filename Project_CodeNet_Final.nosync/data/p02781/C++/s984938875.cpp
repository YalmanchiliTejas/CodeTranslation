#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
ll dp[110][2][4];
int main(){ 
  string s;
  cin >> s;
  int K;
  cin >> K;
  int n = sz(s);
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    int d = s[i] - '0';
    for (int f = 0; f < 2; f++) {
      for (int c = 0; c <= (f ? 9 : d); c++) {
        if (c == 0) {
          dp[i+1][f | (c < d)][0] += dp[i][f][0];
          dp[i+1][f | (c < d)][1] += dp[i][f][1];
          dp[i+1][f | (c < d)][2] += dp[i][f][2];
          dp[i+1][f | (c < d)][3] += dp[i][f][3];
        } else {
          dp[i+1][f | (c < d)][1] += dp[i][f][0];
          dp[i+1][f | (c < d)][2] += dp[i][f][1];
          dp[i+1][f | (c < d)][3] += dp[i][f][2];
        }
     }
   }
  }
  cout << dp[n][0][K] + dp[n][1][K] << endl;
  return 0;
} 