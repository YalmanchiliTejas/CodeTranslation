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
        ans+=(sum*ar[i])%mod;
        sum=(sum+ar[i])%mod;
    }
    cout<<ans%mod<<endl;
    return 0;
}
