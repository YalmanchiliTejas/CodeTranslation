#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repr(i, a, b) for (ll i =a; i < b; i++)
#define all(a) a.begin(), a.end()
#define w(tc) ll tc;cin>>tc;while(tc--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define PI 3.14159265359
static const int INF = 1e9+7;
using namespace std;
ll minimumProduct(ll a,ll b,ll x,ll y,ll n)//Check once by reducing a first and b second and then vice versa.
{
    ll m1=min(a-x,n);
    n=n-m1;
    ll m2=min(b-y,n);
    a=a-m1;
    b=b-m2;
    ll ans=a*b;
    return ans;
}
int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,n)
    {
        cin>>a[i];
        a[i]=a[i]%INF;
    }
    vector<ll>prefix(n);
    prefix[0]=a[0]%INF;
    repr(i,1,n)
    {
        prefix[i]=(prefix[i-1]+a[i])%INF;
    }
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        ll ad=(a[i]*(prefix[n-1]-prefix[i]))%INF;
        sum=sum+ad;
        sum=sum%INF;
    }
    if(sum<0)
    {
        cout<<sum+INF<<endl;
    }
    else
    {
        cout<<sum<<endl;
    }
}
