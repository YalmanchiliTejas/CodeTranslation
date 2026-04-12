#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

#define INF 1e9

ll dp[109][5][2];

int main(){
  string S; int K;
  cin >> S >> K;
  int N = S.size();
  dp[0][0][0] = 1;
  REP(i, N){
    int D = S[i] - '0';
    REP(j, K+1){
      REP(k, 2){
        // 0を選ぶ
        dp[i+1][j][k||(D>0)] += dp[i][j][k];
        // 0以外を選ぶ
        if(k == 0){
          if(D == 0) continue;
          // Dを選ぶ
          dp[i+1][j+1][k] += dp[i][j][k];
          // 0 < x < D を選ぶ
          dp[i+1][j+1][1] += (D-1) * dp[i][j][k];
        }
        else{
          dp[i+1][j+1][k] += 9LL * dp[i][j][k];
        }
      }
    }
    cerr << "i:" << i << " dp:" << dp[i+1][K][1] << endl;
  }
  cerr << dp[N][K][0] << " " << dp[N][K][1] << endl;
  cout << dp[N][K][0] + dp[N][K][1] << endl;
  return 0;
}
