// https://atcoder.jp/contests/dp/tasks/dp_l
#include <bits/stdc++.h>
#define ll long long int
#define pr pair<ll, ll>
#define infinity (ll)4e18
#define tp tuple<ll, ll, ll>
using namespace std;
long long int mod = 1e9 + 7;

ll dp[3001][3001][2];

ll sum(ll pre[], ll i, ll j)
{
    if (i > j)
        return 0;
    if (i == 0)
        return pre[j];
    return pre[j] - pre[i - 1];
}

ll solve(ll pre[], ll a[], ll i, ll j, ll cur)
{
    if (i > j)
        return 0;
    if (i == j)
        return a[i];
    if (dp[i][j][cur] != -1)
        return dp[i][j][cur];
    dp[i][j][cur] = max(a[i] + sum(pre, i + 1, j) - solve(pre, a, i + 1, j, (cur + 1) % 2), a[j] + sum(pre, i, j - 1) - solve(pre, a, i, j - 1, (cur + 1) % 2));
    return dp[i][j][cur];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll a[n], pre[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    pre[0] = a[0];
    for (ll i = 1; i < n; i++)
        pre[i] = pre[i - 1] + a[i];
    memset(dp, -1, sizeof(dp));
    cout << 2 * solve(pre, a, 0, n - 1, 0) - pre[n - 1] << endl;
    return 0;
}