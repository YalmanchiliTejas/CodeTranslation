#include <bits/stdc++.h>

using namespace std;

#if 1
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

#define int long long

const int MOD = 998244353;

int n, k, s;
int a[5010];
int dp[5010];
int ans = 0;

signed main()
{
    //freopen("input_02.txt", "r", stdin);
    //freopen("output_02.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        dp[0] = i + 1;
        if (a[i] <= s)
        {
            ans = (ans + (n - i) * dp[s - a[i]]) % MOD;
        }
        for (int j = s; j >= a[i]; j--)
        {
            dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        }
    }
    cout << ans;
}
