#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[3009],dp[3009][3009];
ll best(ll l,ll r,bool b)
{
    if(r<l)return 0;
    ll &ret=dp[l][r];
    if(ret!=LLONG_MAX)
    return ret;
    if(b)
    return ret=max(best(l+1,r,0)+a[l],best(l,r-1,0)+a[r]);
    return ret=min(best(l+1,r,1)-a[l],best(l,r-1,1)-a[r]);
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n;
for(ll i=0;i<n;i++)
    cin>>a[i];
for(ll i=0;i<=n;i++)
for(ll j=0;j<=n;j++)
dp[i][j]=LLONG_MAX;
cout<<best(0,n-1,1);
return 0;
}
