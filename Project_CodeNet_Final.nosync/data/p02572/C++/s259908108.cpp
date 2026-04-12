#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll ara[200002];

int main()
{
    ll n,i,a,ans;
    scanf("%lld",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&ara[i]);
        ara[i]=(ara[i]+ara[i-1])%mod;
    }
    ans=0;
    for(i=1; i<=n; i++)
    {
        a=ara[i]-ara[i-1];
        ans=(ans+(a*(ara[n]-ara[i]))%mod)%mod;
    }
    ans=(ans+mod)%mod;
    printf("%lld\n",ans);
    return 0;
}
