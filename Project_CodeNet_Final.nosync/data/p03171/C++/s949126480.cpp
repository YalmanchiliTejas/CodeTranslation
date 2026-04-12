#include "bits/stdc++.h"
#define ll long long
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef pair<ll, ll> pairs;
typedef pair<ll, pairs> tpl;
ll dp[3001][3001][2], a[10001], sum;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> a[i], sum += a[i];
    for (ll i = 0; i < n; i++)
        dp[i][i][0] = a[i], dp[i][i][1] = 0;

    for (ll d = 1; d < n; d++)
    {
        for (ll i = 0; i + d < n; i++)
        {
            ll j = d + i;

            dp[i][j][0] = max(a[i] + dp[i + 1][j][1], a[j] + dp[i][j - 1][1]);
            dp[i][j][1] = min(dp[i + 1][j][0], dp[i][j - 1][0]);
        }
    }

    cout << 2 * dp[0][n - 1][0] - sum;
}