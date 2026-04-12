#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod (1000000007)

int main()
{
    ll n;
    cin>>n;
    ll ar[n+1];
    ll ans=0,sum=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>ar[i];
        sum+=ar[i];
    }
    for(int i=1;i<=n;i++)
    {
        sum-=ar[i];
        ans+=(sum%mod*ar[i]%mod)%mod;
        ans%=mod;
    }
    cout<<ans%mod<<endl;
    return 0;
}
