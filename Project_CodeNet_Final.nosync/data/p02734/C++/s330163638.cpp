#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

int dp[2][3005][3005];
int a[3005];
int n,k;

void add(int &a, int b)
{
    a += b;
    if (a >= mod) a %= mod;
}

int solve(bool start, int i, int sum)
{
    int &res = dp[start][i][sum];
    if (sum == k) return n - i + 2;
    if (sum > k || i > n) return 0;
    if (res != -1) return res;
    res = 0;
    add(res, solve(start, i + 1, sum));
    int num;
    if (start) num = solve(true, i + 1, sum + a[i]);
    else num = i * solve(true, i + 1, sum + a[i]);
    add(res, num);
    return res;
}

signed main()
{
    //freopen("file.inp","r",stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 1, 0);
    return 0;
}
