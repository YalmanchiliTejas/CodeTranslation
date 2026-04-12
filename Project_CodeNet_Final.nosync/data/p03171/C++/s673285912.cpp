#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 3001;

ll dp[MAX][MAX];
int v[MAX];
int main()
{
    int n;

    cin >> n;

    for(int i = 1; i <= n; ++i)
        cin >> v[i];

    for(int i = 1; i <= n; i++)
        dp[i][i] = v[i];


    for(int i = n - 1; i >= 0; i--)
        for(int j = i + 1; j <= n; j++)
            dp[i][j] = max(v[i] - dp[i + 1][j], v[j] - dp[i][j - 1]);

    cout << dp[1][n];

    return 0;
}
