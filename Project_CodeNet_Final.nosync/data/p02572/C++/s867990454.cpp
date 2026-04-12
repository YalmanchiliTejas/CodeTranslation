#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const ll mod = 1e9 + 7;
ll a[N], s[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        s[i] = (s[i - 1] + a[i]) % mod;
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = (ans + (a[i] * s[i - 1] % mod)) % mod;
    }
    cout << ans;
}