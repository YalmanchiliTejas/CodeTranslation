#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;
ll dp[10001][100][2];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int d;
  cin >> d;
  dp[0][0][0] = 1;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < d; j++) {
      for (int k = 0; k < s[i]-'0'; k++)
	(dp[i+1][(j+k)%d][1] += dp[i][j][0]) %= mod;
      for (int k = 0; k < 10; k++)
	(dp[i+1][(j+k)%d][1] += dp[i][j][1]) %= mod;
      (dp[i+1][(j+(s[i]-'0'))%d][0] += dp[i][j][0]) %= mod;
    }
  }
  cout << (dp[s.size()][0][0]+dp[s.size()][0][1]-1+mod)%mod << endl;
}
