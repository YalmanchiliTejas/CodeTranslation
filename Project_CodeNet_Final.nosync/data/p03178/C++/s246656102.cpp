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
#define MAX_N 110000
#define MOD 1000000007
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
ll dp[MAX_N][101][2]={};
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
signed main(){
  init_io();
  ll d,n;
  string k;
  cin >> k >> d;
  n = k.size();
  dp[0][0][0] = 1;
  for(int i=0;i<n;i++){
    for(int j=0;j<d;j++){
      for(int b=0;b<2;b++){
        ll end;
        if(b==1) end = 9;
        else end = k[i]-'0';
        for(int l=0;l<=end;l++){
          ll nd = (j+l)%d;
          ll nb = (b||(l!=end));
          dp[i+1][nd][nb] += dp[i][j][b];
          dp[i+1][nd][nb] %= MOD;
        }
      }
    }
  }
  cout << (dp[n][0][0]+dp[n][0][1]-1+MOD)%MOD <<endl;
}
