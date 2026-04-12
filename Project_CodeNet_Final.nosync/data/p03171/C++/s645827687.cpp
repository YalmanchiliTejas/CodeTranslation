#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[3002][3002][2];
ll ar[3002];
ll f(int i, int j, bool st)
{
    ll &ans = dp[i][j][st];
    if (ans != -1)
        return ans;
    if (i == j)
        return ar[i];
    ans = -3e13;
    ans = max(ans, -f(i + 1, j, !st) + ar[i]);
    ans = max(-f(i, j - 1, !st) + ar[j], ans);
    return ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> ar[i];
    }
    cout << f(0, n - 1, 1);
    return 0;
}