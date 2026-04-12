#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (1e+9)+7;

int main(){
  string k;
  int d;
  cin >> k >> d;
  int n=k.size();
  vector<ll> kl(n);
  for(int i=0;i<n;i++){
    kl[i] = k[i] - '0';
  }
  ll dp[n+1][d+1][2] = {};  // dp[桁][%MOD][フラグ]
  dp[0][0][0] = 1;
  int flags[] = {0,1};
  for(int dig = 0;dig < n; dig++){
    for(int base = 0; base < d; base++){
      for(int less: flags){
        for(int x = 0; x<= (less?9:kl[dig]);x++){
          dp[dig+1][(base + x)%d][less | x < kl[dig]] += dp[dig][base][less];
          dp[dig+1][(base + x)%d][less | x < kl[dig]] %= MOD;
        }
      }
    }
  }
  cout << (dp[n][0][0] + dp[n][0][1] - 1 + MOD)%MOD  << endl; 
}