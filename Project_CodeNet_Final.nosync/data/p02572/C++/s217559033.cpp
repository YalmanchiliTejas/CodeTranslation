#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define mp make_pair
#define PI acos(-1)
using namespace std;
const int mod = 1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i,j,k,x,y,z,m,t,n,b,c,d,a,l,r;
    cin >> n;
    vector<ll>v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    vector<ll> cum(n);
    cum[0] = v[0];
    for (int i = 1; i < n; i++)
        cum[i] = cum[i - 1] + v[i];
    ll ans = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        ll temp=(v[i] % mod)*((cum[n - 1] - cum[i])%mod);
        temp%= mod;
        ans=(ans+temp)%mod;
    }
    cout<<ans<<endl;
}
