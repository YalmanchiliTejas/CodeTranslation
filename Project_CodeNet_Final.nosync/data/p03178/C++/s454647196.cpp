#include<bits/stdc++.h>
using namespace std;
string k;
int n, d;
const int MOD = 1000000007;
vector dp(10001, vector (101, vector (2, 0))); // 上からi桁見てDで割ったあまりがjでありK以下であることが確定して{いる, いない}場合の数
void solve(){
  dp[0][0][1] = 1;
  for(int i=0; i<n; i++){
    int digit = k[i] - '0';
    for(int j=0; j<d; j++){
      for(int num=0; num<10; num++){
        if(num < digit){
          dp[i+1][(j+num)%d][0] += dp[i][j][0] + dp[i][j][1];
        }
        else if(num == digit){
          dp[i+1][(j+num)%d][0] += dp[i][j][0];
          dp[i+1][(j+num)%d][1] += dp[i][j][1]; 
        }
        else{
          dp[i+1][(j+num)%d][0] += dp[i][j][0];
        }
        dp[i+1][(j+num)%d][0] %= MOD;
        dp[i+1][(j+num)%d][1] %= MOD;
      }
    }
  }
}
int main(){
  cin >> k >> d;
  n = k.size();
  solve();
  cout << ((dp[n][0][0] + dp[n][0][1]) % MOD + MOD - 1) % MOD<< endl;
}