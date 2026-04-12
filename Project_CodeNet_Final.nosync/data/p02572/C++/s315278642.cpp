#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;

void solve()
{
    ll n,i,sum=0,mod=1e9+7,currsum=0,ans=0;
    cin>>n;
    vector<ll> v(n);

    for(i=0;i<n;i++)
    {
        cin>>v[i];
        sum=(sum+v[i])%mod;
        sum=(sum%mod+mod)%mod;
    }

    for(i=0;i<n-1;i++)
    {
        currsum=(currsum+v[i])%mod;
        currsum=(currsum%mod+mod)%mod;

        ans=(ans%mod+((sum-currsum)%mod*v[i]%mod)%mod)%mod;
        ans=(ans%mod+mod)%mod;
    }

    cout<<ans;
}

int main()
{
    solve();
}