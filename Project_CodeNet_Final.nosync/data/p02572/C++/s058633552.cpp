#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll sum[n];
    sum[n - 1] = a[n - 1];
    for (ll i = n - 2; i >= 0; i--)
    {
        sum[i] = ((sum[i + 1] % mod) + (a[i] % mod)) % mod;
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans = ((ans % mod) + ((a[i] % mod) * (sum[i + 1] % mod)) % mod) % mod;
    }
    cout << ans << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}