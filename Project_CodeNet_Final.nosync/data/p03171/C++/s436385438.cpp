#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[3000][3000];
ll a[3000];
ll dfs(ll l,ll r){
  if(dp[l][r]>=0)return dp[l][r];
  if(l==r)return dp[l][r]=a[l];
  ll ret=max(-dfs(l+1,r)+a[l],-dfs(l,r-1)+a[r]);
  return dp[l][r]=ret;
}
int main(){
  ll n;cin>>n;
  for(ll i=0;i<n;i++)for(ll j=0;j<n;j++)dp[i][j]=-1;
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  cout<<dfs(0,n-1)<<endl;
}