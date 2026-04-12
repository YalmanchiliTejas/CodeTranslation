#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long dfs(vector<long long> &arr,int l,int r,vector<vector<long long>> &dp)
{
    if(l>r) return 0;
    if(l==r) return arr[l];
    if(dp[l][r]!=-1)
        return dp[l][r];
    dp[l][r]=max(arr[l]-dfs(arr,l+1,r,dp),arr[r]-dfs(arr,l,r-1,dp));
    return dp[l][r];
}
int main()
{
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<vector<long long>> dp(n,vector<long long>(n,-1));
    cout<< dfs(arr,0,n-1,dp);
    return 0;
}