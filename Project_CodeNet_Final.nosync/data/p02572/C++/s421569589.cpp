#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans,sum,a[200010],mod=1000000007;
ll p(ll x,ll y)
{
    if(y==0)
    {
        return 1;
    }
    ll ret=1;
    if(y%2)
    {
        ret*=x;
    }
    ll tem=p(x,y/2);
    ret*=tem;
    ret%=mod;
    ret*=tem;
    ret%=mod;
    return ret;
}
int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",a+i);
        ans+=mod;
        ans-=(a[i]*a[i])%mod;
        sum+=a[i];
        sum%=mod;
    }
    ans+=sum*sum;
    ans%=mod;
    ans*=p(2,mod-2);
    ans%=mod;
    printf("%lld",ans);
}
