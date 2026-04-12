#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define ll long long int
ll arr[3005];
ll dp[3005][3005];
ll func(ll i,ll j)
{
    if(i>j)
    return 0;
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    ll m1 = arr[i]+min(func(i+2,j),func(i+1,j-1));
    ll m2 = arr[j]+min(func(i,j-2),func(i+1,j-1));
   
    dp[i][j] = max(m1,m2);
    
    return dp[i][j];
}
int main() {
    ll n,i;
    cin>>n;
    ll sum = 0;
    memset(dp,-1,sizeof(dp));
    for(i=1;i<=n;i++)
    {
        
        cin>>arr[i];
    
        sum = sum + arr[i];
    }
    ll ans = func(1,n);
    ll y = sum-ans;
    cout<<ans-y<<endl;
    //cout<<ans<<endl;
	return 0;
}
