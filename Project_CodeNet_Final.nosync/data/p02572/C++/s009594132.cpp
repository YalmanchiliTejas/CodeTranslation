// Sakhiya07 - Yagnik Sakhiya
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ld long double

#define pll pair<ll,ll>
#define ff first
#define ss second

#define pb push_back
#define all(x) x.begin(),x.end()

#define MOD  1000000007
const int N = 100005; 

#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);srand(time(NULL));

void solve()
{
    ll ans = 0;
    ll n;
    cin >> n;
    ll a[n];
    ll sum = 0;
    for(ll i=0;i<n;i++)
    {
        cin >> a[i];
        sum += a[i];
        sum %= MOD;
    }
    for(ll i=0;i<n;i++)
    {
        sum -= a[i];
        sum = (sum + MOD)%MOD;
        ll temp = sum * a[i];
        temp %= MOD;
        ans = (ans + temp)%MOD;
    }
    cout<<ans;
}

int main()
{
    FAST;
    int t = 1;
 // cin >> t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
}