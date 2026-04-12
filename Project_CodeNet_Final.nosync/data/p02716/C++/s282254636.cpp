#include <bits/stdc++.h>
using namespace std;

#define ll long long int

#define endl '\n'

#define rep(i, a, b) for (ll i = a; i < b; i++)

void solve()

{

    ll n;

    cin >> n;

    ll a[n + 1];

    rep(i, 1, n + 1) cin >> a[i];

    ll ps[n + 1], dp[n + 1];

    dp[0] = 0;
    dp[1] = 0;

    ps[1] = a[1];

    for (ll i = 3; i <= n; i += 2)
        ps[i] = ps[i - 2] + a[i];

    rep(i, 2, n + 1)
    {

        if (i & 1)
        {

            dp[i] = max(dp[i - 1], a[i] + dp[i - 2]);
        }

        else
        {

            dp[i] = max(dp[i - 2] + a[i], ps[i - 1]);
        }
    }

    cout << dp[n] << endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
