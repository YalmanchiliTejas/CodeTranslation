#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9+7;

int main(){
  string K;
  int D;
  cin >> K >> D;
  vector< vector<int> > dp(D, vector<int>(2,0));
  dp[0][1] = 1;
  for(size_t i = 0; i < K.length(); ++i){
    vector< vector<int> > dp_(D, vector<int>(2,0));
    for(int j = 0; j < 10; ++j){
      for(int k = 0; k < D; ++k){
        dp_[(k+j)%D][0] += dp[k][0];
        dp_[(k+j)%D][0] %= mod;
        if('0'+j > K[i]) continue;
        if('0'+j < K[i]){
          dp_[(k+j)%D][0] += dp[k][1];
          dp_[(k+j)%D][0] %= mod;
        }else{
          dp_[(k+j)%D][1] += dp[k][1];
          dp_[(k+j)%D][1] %= mod;
        }
      }
    }
    dp = dp_;
  }
  cout << (dp[0][0] + dp[0][1] + mod - 1)%mod << endl;
}
