#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 200005;

int n;

ll a[N_MAX];

ll dp[N_MAX][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    if(n == 2)
    {
        cout << max(a[1], a[2]) << "\n";
        return 0;
    }
    ll ans = LLONG_MIN;
    int up;
    if(n & 1)
        up = 2;
    else
        up = 1;
    dp[1][0] = a[1];
    dp[1][1] = dp[1][2] = LLONG_MIN;
    for(int i = 2; i <= n; i++)
        for(int j = 0; j <= up; j++)
        {
            dp[i][j] = LLONG_MIN;
            for(int k = 0; k <= j; k++)
                if(i - 2 - (j - k) >= 0)
                    if(dp[i - 2 - (j - k)][k] != LLONG_MIN)
                        dp[i][j] = max(dp[i][j], dp[i - 2 - (j - k)][k] + a[i]);
            if(j + (n - i) == up)
                ans = max(ans, dp[i][j]);
        }
    cout << ans << "\n";
    return 0;
}
