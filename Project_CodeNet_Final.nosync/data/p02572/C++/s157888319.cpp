#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll ara[200005],s[200005];
main()
{
    ll n,i,ans=0;
    cin>>n;
    for(i=1;i<=n;i++)cin>>ara[i];
    s[1]=ara[1];
    for(i=2;i<=n;i++)
    {
        s[i]=s[i-1]+ara[i];
    }
    for(i=1;i<=n-1;i++)
    {
        ll sum=s[n]-s[i];
        ll d=((sum%mod)*(ara[i]%mod))%mod;
        ans=ans+d;
        ans=ans%mod;
    }
    cout<<ans<<endl;
}
