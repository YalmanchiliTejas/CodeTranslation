#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ll_MAX LONG_LONG_MAX
#define ll_MIN LONG_LONG_MIN
#define pi pair<int,int>
#define endl "\n"
#define MAXN 100005
#define mod 1000000007
using namespace std;

void solve()
{
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    solve();
    ll n;
    cin>>n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        /* code */
        cin>>a[i];
    }
    vector<ll> pref(n, 0);
    pref[0] = a[0];
    for (ll i = 1; i < n; i++)
    {
        /* code */
        pref[i] = (pref[i-1] + a[i])%mod;
    }
    ll ans = 0;
    for(ll i=0; i<n; i++)
    {
        ans = (ans + (a[i]*pref[n-1])%mod - (a[i]*pref[i])%mod + mod )%mod;
    }
    cout<<ans<<'\n';
}