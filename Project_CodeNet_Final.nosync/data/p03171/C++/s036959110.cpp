#include<bits/stdc++.h>
using namespace std;
#define lc "\n"
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0)
#define ll long long int

int main()
{
    fast_io;
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n));
    for(ll k = 0; k < n; k++)
    {
        for(ll i = 0, j = k; j < n; j++, i++)
        {
            if(i == j)
                dp[i][j] = a[i];
            else
            {
                ll i1, j1, k1;
                i1 = (i + 2 > j) ? 0 : dp[i+2][j];
                j1 = (i+1 > j-1) ? 0 : dp[i+1][j-1];
                k1 = (i > j-2) ? 0 : dp[i][j-2];
                dp[i][j] = max(a[i] + min(i1, j1), a[j] + min(j1, k1));
            }
        }
    }
    cout << dp[0][n-1] - (sum - dp[0][n-1]);
    return 0;
}
