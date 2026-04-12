#include <bits/stdc++.h>
using namespace std;
const int N = 10004, K = 102, M = 1000000007;

int n;
char a[N];
int k;

int dp[N][K][2];
int main()
{
    cin >> a;
    n = strlen(a);
    cin >> k;
    dp[0][0][1] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            for (int u = 0; u <= 9; ++u)
            {
                dp[i + 1][(j + u) % k][0] = (dp[i + 1][(j + u) % k][0] + dp[i][j][0]) % M;
            }
            for (char u = '0'; u < a[i]; ++u)
            {
                dp[i + 1][(j + u - '0') % k][0] = (dp[i + 1][(j + u - '0') % k][0] + dp[i][j][1]) % M;
            }
            dp[i + 1][(j + a[i] - '0') % k][1] = (dp[i + 1][(j + a[i] - '0') % k][1] + dp[i][j][1]) % M;
        }
    }
    cout << ((dp[n][0][0] - 1 + M) % M + dp[n][0][1]) % M << endl;
    return 0;
}
