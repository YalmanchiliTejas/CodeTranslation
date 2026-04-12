#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL); 
  ll i,n,x,y,z,t,j;
  cin>>n; t=n;
  ll arr[n],dp[n][n];
  for(i=0;i<n;i++)cin>>arr[i];
  for(t=0;t<n;t++)
    for(i=0,j=t;j<n;j++,i++){
       x=(i+1<=j-1)?dp[i+1][j-1]:0ll;
       y=(i+2<=j)?dp[i+2][j]:0ll;
       z=(i<=j-2)?dp[i][j-2]:0ll;
       dp[i][j]=max(arr[i]+min(x,y),arr[j]+min(x,z));
    }
  //  cout<<dp[0][n-1];
  cout<<2*dp[0][n-1]-accumulate(arr,arr+n,0ll);
}