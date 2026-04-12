#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
typedef long long ll;
typedef long double ld;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    ll N = 3e3 + 10, n, i, j;
    cin >> n;
    ll a[n], dp[N][N];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (i = n - 1; i >= 0; i--)
    {
        for (j = i; j < n; j++)
        {
            dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
        }
    }

    cout << dp[0][n - 1] << "\n";

    return 0;
}