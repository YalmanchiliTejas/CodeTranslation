#include <bits/stdc++.h>
using namespace std;

int a[3000];
long long dp[3000][3000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    for (int i=0; i<n; i++)
        dp[i][i] = (n % 2 == 0 ? -a[i] : a[i]);
    for (int diff=1; diff<n; diff++)
        for (int i=0; i+diff<n; i++) {
            int j = i + diff;
            if (n % 2 != diff % 2)
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j]);
            else
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j]);
        }

    cout << dp[0][n-1] << "\n";

    return 0;
}
