#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
const int INF = 1e15;
using Graph = vector<vector<int>>;

int dp[1100][2][6];

signed main(){
  string N;
  cin >> N;
  int K;
  cin >> K;

  //i桁目までで0以外をk個使用しており、Nより小さいか、あるいは等しいか
  dp[0][0][0] = 1;

  for( int i = 0; i < N.size(); i++ ){ //i桁目について
    for( int k = 0; k <= K; k++ ){
      //i桁目までで既にNより小さいのでNより下はなんでもok
      dp[i+1][1][k+1] += dp[i][1][k]*9;
      dp[i+1][1][k] += dp[i][1][k];

      int NX = N.at(i)-'0';
      //i桁目まではNと等しく、その下は小さい場合
      if( NX != 0 ) dp[i+1][1][k] += dp[i][0][k];
      for( int n = 1; n < NX; n++ ){
        dp[i+1][1][k+1] += dp[i][0][k];
      }

      //i+1桁目もNと等しい場合
      if( NX == 0 ) dp[i+1][0][k] += dp[i][0][k];
      else dp[i+1][0][k+1] += dp[i][0][k];
    }
  }
  int A = (int)N.size();
  cout << dp[A][0][K] + dp[A][1][K] << endl;

 }
