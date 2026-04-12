#include <bits/stdc++.h>
using namespace std;

const int N = 2e+5 + 5;
long long int a[N], dp[N][2];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[1][1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            dp[i][1] = a[i] + max(dp[i - 2][0], dp[i - 2][1]);
            dp[i][0] = a[i - 1] + dp[max(0, i - 2)][0];
        }
        else
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = a[i] + max(dp[i - 2][1], dp[i - 2][0]);
            if (i == 3)
                dp[i][1] = a[i];
        }
    }
    cout << max(dp[n][0], dp[n][1]);
}