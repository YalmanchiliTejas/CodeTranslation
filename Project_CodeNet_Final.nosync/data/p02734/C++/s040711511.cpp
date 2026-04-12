#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, S;
    cin >> n >> S;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector< vector<ll> > dp(n, vector<ll>(S + 1, 0));
    if (a[0] <= S)
        dp[0][a[0]] = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= S; ++j)
        {
            if (j - a[i] >= 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % MOD;
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
        }
        if (a[i] <= S)
            dp[i][a[i]] = (dp[i][a[i]] + i + 1) % MOD;
    }
    ll odp = 0;
    for (int i = 0; i < n; ++i)
        odp = (odp + dp[i][S]) % MOD;
    cout << odp;
    return 0;
}
