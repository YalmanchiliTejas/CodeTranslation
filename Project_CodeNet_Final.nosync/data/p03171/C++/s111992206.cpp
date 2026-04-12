#include<iostream>
#include<vector>
#include<algorithm>
#define MAX_N 3000
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll a[MAX_N],dp[MAX_N][MAX_N]={};
bool used[MAX_N][MAX_N]={};
ll eo;
ll n;
ll calc(ll i,ll j){
  ll sig;
  if(used[i][j]){
    return dp[i][j];
  }
  if(i>j){
    return 0;
  }
  used[i][j]=true;
  if(i==j){
    if(eo)sig=1;
    else sig=-1;
    return dp[i][i]=a[i]*sig;
  }else{
    if((j-i)%2!=eo) sig = 1;
    else sig = -1;
    if(sig>0){
      return dp[i][j] = max(calc(i+1,j)+a[i]*sig
          ,calc(i,j-1)+a[j]*sig);
    }else{
      return dp[i][j] = min(calc(i+1,j)+a[i]*sig
          ,calc(i,j-1)+a[j]*sig);
    }
  }
}
signed main(){
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  eo = n%2;
  cout << calc(0,n-1)<<endl;
  /*
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout << dp[i][j]<<" ";
    }
    cout << endl;
  }
  */
}
