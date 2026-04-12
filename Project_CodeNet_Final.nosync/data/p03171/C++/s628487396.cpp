#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll dp[3010][3010];

int main()
{
    int n, a[3010];

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }


    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j <= n; j++)
        {
            dp[i][j] = max(a[i] - dp[i+1][j],
                           a[j] - dp[i][j-1]);
        }
    }

    cout << dp[1][n] << "\n";

    return 0;
}

