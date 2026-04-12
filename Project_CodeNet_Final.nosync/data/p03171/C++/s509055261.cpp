#include <bits/stdc++.h>
#define Roc ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ll long long
#define NAX 3009
using namespace std;
ll n, dp[ NAX ][NAX];
int main()
{
    Roc;
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)
        cin >> dp[ i ] [ i ];
    for(int i = n - 1; i >= 1; --i)
    {

        for(int j = i  + 1; j <= n; ++j)
            {
                dp[i][j] = max(dp[j][j] - dp[i][j -1], dp[i][i] - dp[i+1][j]);
                //cout << dp[i][j] << ' ';
            }
        //cout << '\n';

    }
    cout << dp[1][n];
    return 0;
}
