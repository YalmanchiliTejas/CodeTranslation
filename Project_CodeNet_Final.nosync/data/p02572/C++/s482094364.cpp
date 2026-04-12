#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n - 1);
    ll cpt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cpt += a[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        cpt -= a[i];
        b[i] = cpt % MOD;
    }

    ll ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans += a[i] * b[i] % MOD;
    }

    ans %= MOD;

    cout << ans << endl;

    return 0;
}