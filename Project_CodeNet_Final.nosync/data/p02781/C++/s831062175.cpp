#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define sb __builtin_popcount
#define MOD (ll)1000000007
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string n;
    cin >> n;
    ll k;
    cin >> k;
    ll s = n.size();
    ll dp[s + 5][k + 5][2];
    memset(dp, 0, sizeof(dp));
    for (ll i = 1; i < n[0] - '0'; i++)
    {
        dp[1][1][1]++;
    }
    dp[1][1][0]++;
    dp[1][0][1]++;
    for (ll i = 2; i <= s; i++)
    {
        for (ll l = 0; l <= k; l++)
        {
            dp[i][l + 1][1] += dp[i - 1][l][1] * 9ll;
            dp[i][l][1] += dp[i - 1][l][1];
            for (ll j = 1; j < n[i - 1] - '0'; j++)
            {
                dp[i][l + 1][1] += (dp[i - 1][l][0]);
            }
            if (n[i - 1] != '0')
            {
                dp[i][l + 1][0] += dp[i - 1][l][0];
                dp[i][l][1] += dp[i - 1][l][0];
            }
            else
            {
                dp[i][l][0] += dp[i - 1][l][0];
            }
        }
    }
    cout << dp[s][k][0] + dp[s][k][1] << endl;
}