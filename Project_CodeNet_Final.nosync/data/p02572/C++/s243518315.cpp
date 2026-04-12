#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n),v(n + 1,0);
    ll ans = 0;
    for(ll i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    for(ll i = n - 1;i >= 0;i--)
    {
        v[i] = v[i + 1] + a[i];
    }
    for(ll i = 0;i < n;i++)
    {
        ans = (ans + ((v[i] - a[i]) % MOD * a[i]) % MOD) % MOD;
    }
    cout << ans << "\n";

    return 0;
}