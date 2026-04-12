#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    ll post[n];
   ll mod = 1000000007;
    for(int i=0;i<n;i++)cin>>a[i];

    post[n-1]=a[n-1];

    for(int i=n-2;i>=0;i--)
    {
        post[i]=(post[i+1]%mod+a[i]%mod)%mod;
    }

    ll ans=0;

    for(int i=0;i<n-1;i++)
    {
        ans = (ans%mod+((a[i]*post[i+1])%mod))%mod;
    }

    cout<<ans<<endl;




}
