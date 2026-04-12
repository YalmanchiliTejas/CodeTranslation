#include<iostream>
#include<vector>
using namespace std;

int main(){
  string N;
  cin >> N;

  int K;
  cin >> K;


  long long dp[105][4][2] = {};
  // dp[i + 1][k][1] = dp[i][k][1] + dp[i][k - 1][1] * 9 + dp[i][k - 1][0] * (N[i] - '0' - 1);
  // dp[i + 1][k][0] = dp[i][k or k - 1][0];

  dp[0][0][0] = 1;
  for(int i = 1; i <= N.length(); i++){
    for(int k = 0; k <= K; k++){
      dp[i][k][1] = dp[i - 1][k][1]; // ...0...
      if(N[i - 1] != '0'){
        dp[i][k][1] += dp[i - 1][k][0];
      }
      if(k - 1 >= 0){
        dp[i][k][1] += dp[i - 1][k - 1][1] * 9; // ...*...
        dp[i][k][1] += dp[i - 1][k - 1][0] * max(0, (N[i - 1] - '0' - 1));
      }

      if(N[i - 1] != '0'){
        if(k - 1 >= 0){
          dp[i][k][0] = dp[i - 1][k - 1][0];
        }
      }else{
        dp[i][k][0] = dp[i - 1][k][0];
      }
      //cout << "i = " << i << ", k = " << k << ' ' << dp[i][k][1] << ' ' << dp[i][k][0] << endl;
    }
  }

  cout << dp[N.length()][K][1] + dp[N.length()][K][0] << endl;
}
