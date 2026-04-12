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
int mod = 998244353;

const int maxn = 3002;
int dp[maxn][maxn];

int32_t main()
{
    IOS;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n, s;
    cin >> n >> s;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        dp[i][v[i]] += i;
        dp[i][v[i]] %= mod;
        if(v[i] == s)
        {
            ans += i * (n - i + 1);
            ans %= mod;
        }
        for(int j = 1; j <= s; j++)
        {
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= mod;
            if(j - v[i] >= 1)
            {
                dp[i][j] += dp[i-1][j-v[i]];
                dp[i][j] %= mod;
                if(j == s)
                {
                    ans += dp[i-1][j-v[i]] * (n - i + 1);
                    ans %= mod;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}