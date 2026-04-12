// Author : ps41

#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const ll M = 1e9 + 7, N = 1e6 + 5;
ll a[N], arr[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) cin >> a[i], arr[i] = a[i];
    for (ll i = 1; i < n; i++) a[i] = (a[i] % M + a[i - 1] % M) % M;
    ll ans = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        ans = (ans % M + (arr[i] * ((a[n - 1] - a[i] + M)) % M) % M) % M;
    }
    cout << ans;
}