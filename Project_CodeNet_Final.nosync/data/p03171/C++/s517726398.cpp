#include <iostream>

using namespace std;

const int MAXN = 3000 + 10;
long long a[MAXN];
long long dp[MAXN][MAXN];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        dp[i][i] = a[i];

    for (int r = 0; r < n; r++) {
        for (int l = r-1; l >= 0; l--) {
            dp[r][l] = max(a[r] - dp[r-1][l], a[l] - dp[r][l+1]);
        }
    }

    cout << dp[n-1][0];
    return 0;
}