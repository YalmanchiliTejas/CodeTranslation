#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const ll MOD = 1e9 + 7;
int main()
{
    ll n,ans=0;
    cin>>n;
    vector<ll>a(n+5,0),b(n+5,0);
    for(ll i=1,j=n;i<=n;i++,j--)cin>>a[i];
    for(ll i=n;i>=1;i--)b[i]=a[i]+b[i+1],b[i]%=MOD;
    for(ll i=1;i<=n;i++)
    {
        ans=(ans%MOD+(a[i]*b[i+1])%MOD)%MOD;
    }
    cout<<ans<<endl;
}
