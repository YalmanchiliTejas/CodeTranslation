#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long 
ll dp[3001][3001];
ll game(ll i,ll j,ll sum, ll arr[])
{
    if(i+1==j)
    return max(arr[i],arr[j]);
    if(dp[i][j]!=-1)
     return dp[i][j];
    dp[i][j]= max(sum-game(i+1,j,sum-arr[i],arr),sum-game(i,j-1,sum-arr[j],arr));
    return dp[i][j];
}
int main()
{
    ll n,sum=0;
    cin>>n;
    ll arr[n];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
      cin>>arr[i];
    for(int i=0;i<n;i++)
      sum+=arr[i];
      if(n==1)
      {
          cout<<sum;
          return 0;
      }
     
      ll x=game(0,n-1,sum,arr);
      ll y=sum-x;
     
    cout<<x-y;
}