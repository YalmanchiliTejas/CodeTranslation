#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n + 2), s(n + 2);
    vector<vector<ll>> dp(n + 2, vector<ll>(n + 2));
    forx(i, 1, n + 1)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        dp[i][i] = a[i];
    }

    forx(i, 1, n)
    {
        forx(l, 1, n - i + 1)
        {
            int r = l + i;
            dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
        }
    }
    cout << dp[1][n] << endl;

    return 0;
}