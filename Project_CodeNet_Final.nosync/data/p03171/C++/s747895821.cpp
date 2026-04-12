#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3000;
int a[MAXN + 1];
long long pre[MAXN + 1];
long long dp[MAXN + 1][MAXN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        dp[i][i] = a[i];
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            long long sum = pre[j] - pre[i - 1];
            dp[i][j] = max(sum - dp[i + 1][j], sum - dp[i][j - 1]);
        }
    }
    cout << 2 * dp[1][n] - pre[n] << endl;
    return 0;
}
