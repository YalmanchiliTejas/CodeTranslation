#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int a[maxn];
int n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> sum(n + 1);
    for (int i = 1; i <= n; i++) sum[i] = (sum[i - 1] + a[i - 1]);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = (ans + a[i] * ((sum[n] - sum[i + 1]) % mod) % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}