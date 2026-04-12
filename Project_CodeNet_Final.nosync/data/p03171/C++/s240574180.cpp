#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
#define ll long long
using namespace std;
const int nmax=101234;

ll n,a[3012],dp[3001][3001],dp2[3001][3001];
ll DP(ll l,ll r);


ll DP2(ll l,ll r)
{
    if(dp2[l][r])
        return dp2[l][r];
    if(l!=r)
        return dp2[l][r]=min(DP(l+1,r)-a[l],DP(l,r-1)-a[r]);
    else
        return dp2[l][r]=-a[l];
}

ll DP(ll l,ll r)
{
    if(dp[l][r])
        return dp[l][r];
    if(l!=r)
        return dp[l][r]=max(DP2(l+1,r)+a[l],DP2(l,r-1)+a[r]);
    else
        return dp[l][r]=a[l];
}

int main()
{
    scanf("%lld",&n);
    for(ll i=0; i<n; ++i)
    {
        scanf("%lld",&a[i]);
    }
    DP(0,n-1);
    printf("%lld",dp[0][n-1]);
    return 0;
}
