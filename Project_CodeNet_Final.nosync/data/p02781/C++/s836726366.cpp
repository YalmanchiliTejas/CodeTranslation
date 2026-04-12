// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
string s,t;
ll k,n,ans=0;
int z_c(int v){
  int res = 0;
  while(v!=0){
    if(v%10!=0) res++;
    v/=10;
  }
  return res;
}
signed main(){
  init_io();
  cin >> s >> k;
  n = s.size();
  ll n_arr[n];
  for(int i=0;i<n;i++){
    n_arr[i] = s[i]-'0';
  }
  t = s;
  ll dp[110][4][2]={};
  dp[0][1][1] = 1;
  dp[0][1][0] = n_arr[0]-1;
  for(int i=1;i<n;i++){
    dp[i][1][0] = 9;
    for(int j=1;j<=3;j++){
      if(n_arr[i]==0){
        dp[i][j][1] += dp[i-1][j][1];
        dp[i][j][0] += dp[i-1][j][0] + dp[i-1][j-1][0]*9;
      }else{
        dp[i][j][1] += dp[i-1][j-1][1];
        dp[i][j][0] += dp[i-1][j-1][1]*(n_arr[i]-1) + dp[i-1][j-1][0]*9 
          + dp[i-1][j][1] + dp[i-1][j][0];
      }
    }
  }
  cout << dp[n-1][k][0] + dp[n-1][k][1]<<endl;
}
