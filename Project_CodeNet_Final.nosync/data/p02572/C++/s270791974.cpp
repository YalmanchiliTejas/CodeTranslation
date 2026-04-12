#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7,INF=1e18;
#define ll long long
#define pll pair<ll,ll>
#define x first
#define y second
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    // cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> a(n);
        for(int i=0;i<n;i++)
        cin>>a[i];
        ll sum=a[n-1],ans=0;
        for(int i=n-2;i>=0;i--)
        {
            ans=(ans+(sum*a[i])%mod)%mod;
            sum=(sum+a[i])%mod;
        }
        cout<<ans<<"\n";
    }
    return 0;
}