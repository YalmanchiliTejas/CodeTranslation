#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long n,a[3500],dp[3050][3050][3],sum;
long long f(int l,int r,int ran)
{
    if(l>r)return 0;
    if(dp[l][r][ran]!=-1)return dp[l][r][ran];
    long long mx;
    if(ran==0)
    {
        mx=0;
        mx=max(f(l,r-1,1)+a[r],f(l+1,r,1)+a[l]);
    }
    else
    {
        mx=1e18;
        mx=min(f(l,r-1,0)-a[r],f(l+1,r,0)-a[l]);
    }
    return dp[l][r][ran]=mx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    cout<<f(0,n-1,0);
}
