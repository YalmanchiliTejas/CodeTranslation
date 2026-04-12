#include <bits/stdc++.h>
#include <cstring>
#include <limits>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define fw(i, start, end) for (ll i = start; i < end; ++i)
#define fe(i, start, end) for (ll i = start; i <= end; ++i)
#define L(T)  \
    ll T;     \
    cin >> T; \
    while (T--)
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'

ll dp[3004][3004];
int a[3004];
ll solve(ll i, ll j)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == j)
    {
        return dp[i][j] = a[i];
    }
    dp[i][j] = 0;
    dp[i][j] = max(a[i] - solve(i + 1, j), a[j] - solve(i, j - 1));
    return dp[i][j];
}
int main()
{
    FASTIO
    ll n;
    cin >> n;
    // ll s = 0;
    fw(i, 1, n + 1)
    {
        cin >> a[i];
        // s += a[i];
    }
    memset(dp, -1, sizeof dp);
    ll ans = solve(1, n);
    cout << ans << endl;
    return 0;
}