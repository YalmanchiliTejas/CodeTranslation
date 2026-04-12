#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[3009],dp[3009][3009];
ll best(ll l,ll r,bool b)
{
    if(l>r) return 0;
    ll &ret=dp[l][r];
    if(ret<1e14) return ret;
    if(b)
    return ret=min(best(l+1,r,0)-a[l],best(l,r-1,0)-a[r]);
    return ret=max(best(l+1,r,1)+a[l],best(l,r-1,1)+a[r]);
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
    dp[i][j]=1e14;
cout<<best(0,n-1,0);
return 0;
}
