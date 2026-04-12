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
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(18);
}
signed main(){
  init_io();
  ll n;
  cin >> n;
  vector<ll> dp(n,0);
  vector<ll> a(n),sum(n,0);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  sum[n-1] = a[n-1];
  for(int i=n-2;i>=0;i--){
    sum[i] = sum[i+1];
    if((i%2==0)^(n%2==0)) sum[i] += a[i];
  }
  dp[n-1] = 0;
  dp[n-2] = max(a[n-1],a[n-2]);
  for(int i=n-3;i>=0;i--){
    if(n%2){
      if(i%2==0){
        dp[i] = max(dp[i+1],dp[i+2]+a[i]);
      }else{
        dp[i] = max(sum[i+1],dp[i+2]+a[i]);
      }
    }else{
      if(i%2==0){
        dp[i] = max(sum[i+1],dp[i+2]+a[i]);
      }else{
        dp[i] = max(dp[i+1],dp[i+2]+a[i]);
      }
    }
  }
  cout << dp[0]<<endl;
}
