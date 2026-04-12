#include <bits/stdc++.h>

#define int long long int
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int dp[3001][3001][2];
int mod=1e9+7;
int func(int arr[],int l,int r,int p)
{   //cout<<p<<endl;
    if(l>r)
    return 0;
    if(dp[l][r][p]!=-1)
    return dp[l][r][p];
    if(p==0)
    return dp[l][r][p]=max(arr[l]+func(arr,l+1,r,!p),arr[r]+func(arr,l,r-1,!p));
    else
    return dp[l][r][p]=min(func(arr,l+1,r,!p),func(arr,l,r-1,!p));
}

int32_t main() {
    IOS;
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
    cin>>arr[i];
    sum+=arr[i];
    }
    cout<<2*func(arr,0,n-1,0)-sum<<endl;
}