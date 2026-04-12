#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,o;
ll dp[3009][3009],a[3009];
ll bt(int l,int r)
{
    if(l==r)
    {
        if(n%2)return a[l];
        else return -a[l];
    }
    if(dp[l][r]!=-1)return dp[l][r];
    if((r-l+1)%2==o)
    {
        dp[l][r]=max(bt(l+1,r)+a[l],bt(l,r-1)+a[r]);
    }
    else
    {
        dp[l][r]=min(bt(l+1,r)-a[l],bt(l,r-1)-a[r]);
    }
    return dp[l][r];
}
int main()
{
    cin>>n;
    memset(dp,-1,sizeof(dp));
    if(n%2)o=1;
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<bt(0,n-1);
}
