#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    long long dp[n][n];
    for (int i = 0; i < n; i++)
        dp[i][i] = arr[i];
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= n - i; j++)
            dp[j][j + i - 1] = max(arr[j] - dp[j + 1][j + i - 1], arr[j + i - 1] - dp[j][j + i - 2]);
    cout << dp[0][n - 1] << "\n";
    return 0;
}