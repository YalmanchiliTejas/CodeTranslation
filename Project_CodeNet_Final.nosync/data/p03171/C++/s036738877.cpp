#include <bits/stdc++.h>
#define MOD 1000000007
//for(int i=0; i<n; ++i)
using namespace std;
#define all(c) c.begin(), c.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll sign;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n % 2 == 1)
        sign = 1ll;
    else
        sign = -1ll;

    vector<vector<ll>> dp(n, vector<ll>(n, 0ll));
    for (int i = n - 1; i >= 0; --i)
    {
        dp[i][i] = sign * a[i];
        ll det = sign;
        for (int j = i + 1; j < n; ++j)
        {
            det = -1 * det;
            if (det < 0)
                dp[i][j] = min(dp[i + 1][j] + (det * a[i]), dp[i][j - 1] + (det * a[j]));
            else
                dp[i][j] = max(dp[i + 1][j] + (det * a[i]), dp[i][j - 1] + (det * a[j]));
        }
    }
    /*
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cout << dp[i][j] << " \n"[j == n - 1];
    */

    cout << dp[0][n - 1] << endl;
    return 0;
}