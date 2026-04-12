#include <iostream>
#include <vector>
using namespace std;

int main(){
  using ll = long long;
  string N;
  int K;
  cin >> N >> K;
  vector<vector<ll>> dp(K+1,vector<ll>(2,0));
  dp[0][1] = 1;
  for(size_t i = 0; i < N.length(); ++i){
    vector<vector<ll>> dp_(K+1,vector<ll>(2,0));
    for(int j = 0; j <= K; ++j){
      dp_[j][0] += dp[j][0];// 1~9
      if(j+1 <= K) dp_[j+1][0] += dp[j][0]*9;// 0
      
      if(N[i] == '0'){
        dp_[j][1] += dp[j][1];
      }else{
        if(j < K) dp_[j+1][1] += dp[j][1];
        dp_[j][0] += dp[j][1];
      }
      if(j < K)
        dp_[j+1][0] += dp[j][1]*max(0,N[i]-'1');
    }
    swap(dp,dp_);
  }
  cout << dp[K][0]+dp[K][1] << endl;
}
