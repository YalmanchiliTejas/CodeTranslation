#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n; i++)
using P = pair<ll, ll>;

ll mod(ll n)
{
    if (n < 0)
        return n + 1000000007;
    else
        return n % 1000000007;
}

int main()
{
    // ll n, sum = 0, d_sum = 0, ans = 0;
    // cin >> n;
    // rep(i, n)
    // {
    //     ll a;
    //     cin >> a;
    //     sum = mod(sum + a);
    //     d_sum = mod(d_sum + mod(a * a));
    // }
    // sum = mod(sum);
    // d_sum = mod(d_sum);

    // cout << mod(mod(mod(sum * sum) - d_sum) / 2) << endl;
    // return 0;
    ll n, sum = 0, ans = 0;
    cin >> n;
    ll a[n], b[n];
    rep(i, n)
    {
        cin >> a[i];
        sum += a[i];
        sum=mod(sum);
    }

    for (ll i = 0; i < n - 1; i++)
    {
        sum -= a[i];
        // sum %= 1000000007;
        sum=mod(sum);
        ans += (a[i] * sum);
        ans=mod(ans);
        // ans %= 1000000007;
    }
    cout << ans << endl;
    return 0;
}