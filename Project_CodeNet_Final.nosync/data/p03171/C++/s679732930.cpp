#include <iostream>
#define nmax 3005
using namespace std;
int n, v[nmax];
long long dp[nmax][nmax];

int main()
{
    int i, j;
    cin >> n;
    for(i = 1; i <= n ;i++)
        cin>>v[i];

    for(i = 1; i <= n; i++)
        dp[i][i] = v[i];

    for(i = n; i >= 1; i--)
        for(j = i + 1; j <= n; j++)
            dp[i][j] = max(v[i] - dp[i+1][j], v[j] - dp[i][j - 1]);

    cout << dp[1][n];

    return 0;
}