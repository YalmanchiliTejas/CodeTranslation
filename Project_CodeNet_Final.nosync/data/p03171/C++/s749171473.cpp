#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3005;

int n;
int a[N], dp[N][N][2];

int recur(int i, int j, int player)
{
    if(j < i)
        return 0;
    int &ans = dp[i][j][player];
    if(ans != -1)
        return ans;
    if(!player)
        ans=max(a[i] + recur(i + 1, j, player^1), a[j] + recur(i, j - 1, player^1));
    else
        ans=min(-a[i] + recur(i + 1, j, player^1), -a[j] + recur(i, j - 1, player^1));
    return ans;
}

int32_t main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << recur(1, n, 0);
    return 0;
}
