#include <bits/stdc++.h>
using namespace std;
const int N = 3087;
int a[N];
long long dp[N][N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[i][i] = a[i];
    }
    for (int w = 2; w <= n; ++w) 
        for (int l = 0, r; (r = l + w - 1) < n; ++l)
            dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
    cout << dp[0][n - 1] << endl;
}
