#include <bits/stdc++.h>

#define N_MAX 3002
#define ll long long

using namespace std;

int n;

ll a[N_MAX];

ll dp[N_MAX][N_MAX];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = n; i >= 1; i--)
        for(int j = i; j <= n; j++)
            dp[i][j] = max(-dp[i + 1][j] + a[i], -dp[i][j - 1] + a[j]);
    cout << dp[1][n] << "\n";
    return 0;
}
