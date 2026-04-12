


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[5000][5000];

ll topdown(ll *arr,ll l,ll r)
{
    if(l>r)
    {
        dp[l][r]=0;
        return 0;
    }
    if(dp[l][r]!=-1)
    {
        return dp[l][r];
    }
    ll op1=arr[l]+min(topdown(arr,l+1,r-1),topdown(arr,l+2,r));
    ll op2=arr[r]+min(topdown(arr,l,r-2),topdown(arr,l+1,r-1));
    dp[l][r]=max(op1,op2);
    return dp[l][r];
}

int main()
{
    ll n=0,sum=0;
    cin>>n;
    ll *arr= new ll[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    memset(dp,-1,sizeof dp);
    cout<<2*topdown(arr,0,n-1)-sum;
    return 0;
}