// Author: HarshKumar

#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const ll N = 1e6 + 6, M = 1e9 + 7;
ll f[N], s[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n, i, x, m, p;
    cin >> n >> x >> m;
    s[1] = p = x;
    f[x] = 1;
    for (i = 2; i <= n; i++)
    {
        x = p * p % m;
        p = x;
        s[i] = s[i - 1] + x;
        if (f[x])
            break;
        f[x] = i;
    }
    if (i == n + 1)
        return cout << s[n], 0;
    ll q = (n - f[x] + 1) / (i - f[x]);
    ll r = (n - f[x] + 1) % (i - f[x]);
    ll ans = (s[i] - s[f[x]]) * q + s[f[x] + r - 1];
    cout << ans;
}