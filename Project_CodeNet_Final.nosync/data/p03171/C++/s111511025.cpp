#include<bits/stdc++.h>
using namespace std;
#define N 3005
#define ll long long
ll dp[N][N], n, arr[N];

int main()
{
    //memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];

    for(int i = n; i >= 1; i--)
    {
        for(int j = i; j <= n; j++)
        {
            dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);
        }
    }
    cout << dp[1][n] << endl;
    //cout << -cal(1, n) << endl;
}
