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
#define MOD 998244353
#define MAX 4000
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
ll dp[MAX][MAX][3]={};
signed main(){
  init_io();
  ll n,s;
  cin >> n >> s;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  dp[0][0][0]=1;
  for(int i=0;i<n;i++){
    for(int j=0;j<=s;j++){
      dp[i+1][j][0] += dp[i][j][0]%MOD;
      dp[i+1][j][0] %=MOD;

      dp[i+1][j][1] += dp[i][j][0]+dp[i][j][1];
      dp[i+1][j][1] %= MOD;

      dp[i+1][j][2] += (dp[i][j][0]+dp[i][j][1]+dp[i][j][2])%MOD;
      dp[i+1][j][2] %= MOD;

      if(j>=a[i]){
        ll v = (dp[i][j-a[i]][0]+dp[i][j-a[i]][1])%MOD;
        dp[i+1][j][1] += v;
        dp[i+1][j][1] %= MOD;

        dp[i+1][j][2] += v;
        dp[i+1][j][2] %= MOD;
      }
    }
  }
  cout << dp[n][s][2]<<endl;
}
