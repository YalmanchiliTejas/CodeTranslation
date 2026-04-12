#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define sb __builtin_popcount
#define MOD (ll)998244353
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;

ll dp[3001][3001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, s;
    cin >> n >> s;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j <= s; j++)
        {
            if (j == 0)
            {
                dp[i][j + arr[i - 1]] = i;
            }
            if (j + arr[i - 1] <= s)
            {
                dp[i][j + arr[i - 1]] += dp[i - 1][j];
                dp[i][j + arr[i - 1]] %= MOD;
            }
            if (j != s)
            {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
            }
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    ll sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        sum += (n - i + 1ll) * dp[i][s];
        sum %= MOD;
    }
    cout << sum << endl;
}