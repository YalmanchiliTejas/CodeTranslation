#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll arr[3005];
ll n;
ll dp[3005][3005];
ll solve(ll i,ll j)
{

    if(i>j)
        return 0;
    if(i==j)
    {
        return arr[i];
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll ret=0;
    ret=max(arr[i]-solve(i+1,j),arr[j]-solve(i,j-1));
    return dp[i][j]=ret;
}
int main()
{
    sc1(n);
    for(ll i=1;i<=n;i++)
    {
        sc1(arr[i]);
    }
    memset(dp,-1,sizeof dp);
    ll ans=solve(1,n);
    printf("%lld\n",ans);
    return 0;
}
