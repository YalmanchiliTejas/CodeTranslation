//
// Created by rajshah9914 on 30/03/20.
//

#include <bits/stdc++.h>
using namespace std;
long long a[100000];
long long dp[3001][3001];
long long play(long long l,long long r)
{
    if(l>r)
        return 0;
    if(l==r)
        return a[l];
    if(dp[l][r]!=-1)
        return dp[l][r];
    long long ans=a[l]-play(l+1,r);
    ans=max(ans,a[r]-play(l,r-1));
    return dp[l][r]=ans;

}

long long solve()
{
    long long n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(long long i=0;i<n;i++)
        cin>>a[i];
    cout<<play(0,n-1);
}
int main()
{
    solve();
}

