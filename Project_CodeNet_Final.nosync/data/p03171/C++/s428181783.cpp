#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[3005][3005];
ll solve(ll arr[],int i,int j){
    if(j<i)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];
    
    
    return dp[i][j] = max(arr[i] + min(solve(arr,i+2,j),solve(arr,i+1,j-1)),arr[j]+min(solve(arr,i+1,j-1),solve(arr,i,j-2)));
}
int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    ll arr[n];
    ll sum =0;
    for(int i=0;i<n;i++)
        cin>>arr[i],sum+=arr[i];
    
   // cout<<solve(arr,0,n-1)<<endl;
    cout<<2*solve(arr,0,n-1)-sum;
    
    return 0;
}