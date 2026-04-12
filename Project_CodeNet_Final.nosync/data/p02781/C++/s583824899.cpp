#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
int main(){
  string s;cin >> s;
  ll K,n = s.size(),i,j,k,l;cin >> K;
  ll dp[n+1][2][K+2];
  memset(dp,0,sizeof(dp));dp[0][0][0] = 1;
  ll z;
  for(i=0;i<n;i++){
    z = s[i]-'0';
    for(j=0;j<2;j++){
      for(k=0;k<=K;k++){
        dp[i+1][j|(z!=0)][k] += dp[i][j][k];
        for(l=1;l<=(j ? 9:z);l++){
          dp[i+1][j|(l<z)][k+1] += dp[i][j][k];
        }
      }
    }
  }
  printf("%lld\n",dp[n][0][K]+dp[n][1][K]);
}