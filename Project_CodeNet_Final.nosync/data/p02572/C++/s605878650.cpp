#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int MOD = 1000000007;

int main()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    rep (i, n)
        cin >> a[i];

    sort(a.begin(), a.end());

    vector<ll> sum(n + 1, 0);
    rep (i, n)
        sum[i + 1] = sum[i] + a[i];

    ll ans = 0;
    for (int i = 0; i < n - 1; i++)
        ans = (ans + (a[i] * ((sum[n] - sum[i + 1]) % MOD) % MOD)) % MOD;

    cout << ans << endl;
    return 0;
}
