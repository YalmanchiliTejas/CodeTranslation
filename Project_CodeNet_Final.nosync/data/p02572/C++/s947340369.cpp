#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7;
ll pro(ll A[], ll n)
{

    ll array_sum = 0;
    for (ll i = 0; i < n; i++)
        array_sum = (array_sum%mod + A[i]%mod)%mod;
    ll array_sum_square = ((array_sum%mod) * (array_sum%mod))%mod;
    ll individual_square_sum = 0;
    for (ll i = 0; i < n; i++)
        individual_square_sum = ((individual_square_sum%mod)+((A[i]%mod)*(A[i]%mod))%mod)%mod;
    return (array_sum_square - individual_square_sum)/2;
}
ll po(ll x,ll y)
{
    ll ans=1;
    while(y>0)
    {

        if(y%2)
            ans=(ans*x)%mod;
        y/=2;
        x=(x*x)%mod;
    }
    return ans%mod;
}
int main()
{
    ll t=1;
    //cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n+1],i,sum=0;
        for(i=0;i<n;i++)
            {cin>>a[i];
              sum=(sum%mod+a[i]%mod)%mod;
            }
            sum=((sum)*(sum))%mod;
            ll k=0;
            for(i=0;i<n;i++)
            {
                ll m=(a[i]*a[i])%mod;
                k=(k%mod+m%mod)%mod;
            }
            sum+=mod;
            sum-=k;
            ll ans=((sum%mod)*(po(2,mod-2)%mod))%mod;
          cout<<ans<<endl;
         // else
           // cout<<(sum-k)/2<<endl;
    }

}
