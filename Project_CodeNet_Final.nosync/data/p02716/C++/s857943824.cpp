#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, beg, end, step) for (int i = beg; i < end; i += step)

main()
{
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n, 1)
            cin >>
        a[i];

    ll dp[n + 1][3];
    dp[1][0] = a[0];
    dp[1][1] = max(a[0], a[1]);
    dp[1][2] = max(a[0], max(a[1], a[2]));
    rep(i, 2, n, 1)
    {
        rep(j, 0, 3, 1)
        {
            if (j == 0)
            {
                if (i % 2 == 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + a[i - 1];
                }
            }
            else if (j == 1)
            {
                if (i % 2 == 0)
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][0]);
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j] + a[i], dp[i][0]);
                }
            }
            else
            {
                if (i % 2 == 0)
                {
                    dp[i][j] = max(dp[i - 1][2], max(dp[i - 1][1], dp[i - 1][0]));
                }
                else
                {
                    dp[i][j] = max(dp[i][0], max(dp[i][1], dp[i - 1][2] + a[i + 1]));
                }
            }
        }
    }
    if(n % 2 == 1)
    {
        cout << dp[n - 2][2] << endl;
    }
    else
    {
        cout << dp[n-1][1] << endl;
    }
    
    

    return 0;
}