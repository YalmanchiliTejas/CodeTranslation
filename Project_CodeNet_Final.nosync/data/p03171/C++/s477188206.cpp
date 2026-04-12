#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll solve(vector<vector<ll>>&dp,ll start,ll end,ll arr[]){
  if(start==end)
    return arr[start];
  if(start>end)
    return 0;
  if(end-start==1)
    return max(arr[start],arr[end]);
  if(dp[start][end]!=-1)
    return dp[start][end];
  dp[start][end]=arr[start]+min(solve(dp,start+2,end,arr),solve(dp,start+1,end-1,arr));
  dp[start][end]=max(dp[start][end],arr[end]+min(solve(dp,start,end-2,arr),solve(dp,start+1,end-1,arr)));
  return dp[start][end];
}
int main(){
  ll n;
  cin>>n;
  ll arr[n];
  ll sum=0;
  for(ll i=0;i<n;i++){
    cin>>arr[i];
    sum+=arr[i];
  }
  vector<vector<ll>>dp(n,vector<ll>(n,-1));
  ll start=0;
  ll end=n-1;
  ll ans=solve(dp,start,end,arr);
  cout<<ans-(sum-ans)<<endl;
}