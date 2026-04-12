#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m=1e9+7;
ll mod(ll x)
{
    return ((x%m+m)%m);
}
ll add(ll a,ll b)
{
    return mod(mod(a)+mod(b));
}
ll mul(ll a,ll b)
{
    return mod(mod(a)*mod(b));
}
int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<ll>b(n+1);
    for(int i=n-1;i>=0;i--)
    {
        b[i]=b[i+1]+a[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans=add(ans,mul(a[i],b[i+1]));
    }
    cout<<ans;
}
