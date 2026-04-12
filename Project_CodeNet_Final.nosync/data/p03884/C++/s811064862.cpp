#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define all(x) x.begin(),x.end()
#define let auto const

int main() {
  i64 K;
  cin >> K;
  i64 MAX = 600;
  vector<vector<i64>> dp(MAX, vector<i64>(7, 0));
  rep(i,0,MAX) {
    dp[i][6] = 1;
  }
  for(i64 i = 5; i >= 0; i--) {
    i64 sum = 0;
    for(int j = MAX - 1;j >= 0;j--) {
      sum += dp[j][i + 1];
      dp[j][i] = sum;
    }
  }

  for(i64 i = MAX - 2; i >= 0; i--) {
    dp[i][0] += dp[i + 1][0];
  }

  for(int i = 0;i < MAX;i++) {
    i64 cnt = K / dp[i][0];
    K = K % dp[i][0];
    rep(q, 0, cnt) {
      cout << 'F';
    }
    cout << "ESTIVAL";
  }
  cout << endl;
}
