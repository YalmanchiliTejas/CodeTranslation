#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
 
// Remove GCC optimizer for codechef
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
using namespace __gnu_pbds;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define endl "\n"
#define int long long
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
const int INF = 1e16;
const double PI = acos(-1);
const int N = 1e6 + 7;
int mod = 1e9 + 7;

const int maxn = 1e4 + 7;

int dp[maxn][105][2];

int32_t main()
{
    IOS;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string s;
    cin >> s;
    int d, n;
    cin >> d;
    int x = s[0] - '0';
    x %= d;
    dp[0][0][0] = 1;
    n = s.size();
    for(int i = 1; i <= n; i++)
    {
        int x = s[i-1] - '0';
        for(int j = 0; j < d; j++)
        {
            int prev = (j - x + 10 * d) % d;
            dp[i][j][0] += dp[i-1][prev][0];
            dp[i][j][0] %= mod;
            for(int k = 0; k < 10; k++)
            {
                prev = (j - k + 10 * d) % d;
                dp[i][j][1] += dp[i-1][prev][1];
                if(k < x)
                    dp[i][j][1] += dp[i-1][prev][0];
                dp[i][j][1] %= mod;
            }
        }
    }
    int ans = dp[n][0][0] + dp[n][0][1] - 1 + mod;
    ans %= mod;
    cout << ans << endl;
    return 0;
}