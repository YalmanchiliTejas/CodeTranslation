#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define forn(i,n) for(ll i=0;i < ll (n); i++)

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    ll sum=0;
    forn(i,n) cin>>a[i], sum+=a[i];
    ll ans=0;
    forn(i,n)
    {
        sum-=a[i];
        ans+=((a[i]*(sum%1000000007))%1000000007);
        ans=ans%1000000007;
    }
    cout<<ans<<endl;
    return 0;
}
