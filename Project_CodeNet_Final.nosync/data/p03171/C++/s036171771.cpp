/*
Author: Sagar Gupta
E mail: sagar.june97p@gmail.com
*/

#pragma comment(linker, "/STACK:268435456")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl ("\n")
#define deb(n) cerr << #n << " = " << (n) << '\n'
#define FOR(i, n) for (int(i) = 0; (i) < n; (i)++)
#define PI (3.141592653589)
#define ordered_set tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;
    cout.precision(10);
    // Those who cannot acknowledge themselves, will invariably fail
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long dp[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 0;
        }
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            if ((gap + 1) % 2 == n % 2)
            {
                // first player
                if (i == j)
                {
                    dp[i][j] = arr[i];
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1] + arr[j], dp[i + 1][j] + arr[i]);
                }
            }
            else
            {
                // second player
                if (i == j)
                {
                    dp[i][j] = -arr[i];
                }
                else
                {
                    dp[i][j] = min(dp[i][j - 1] - arr[j], dp[i + 1][j] - arr[i]);
                }
            }
        }
    }
    cout << dp[0][n - 1];

    return 0;
}