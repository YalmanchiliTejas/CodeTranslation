#include<bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f;
const int N=2e5+5;
using namespace std;
ll a[N];
ll sum[N];
ll ksm(ll a,ll b)
{
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
    return ans;
}
int main()
{
    ll n;
    cin>>n;
    sum[0]=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        sum[i]=(a[i]+sum[i-1])%mod;
    }
    ll ans=0;
    for(int i=1;i<=n-1;i++)
    {
        ans=(ans+a[i]*(sum[n]-sum[i]+mod))%mod;
    }
    cout<<ans<<endl;
    return 0;
}
