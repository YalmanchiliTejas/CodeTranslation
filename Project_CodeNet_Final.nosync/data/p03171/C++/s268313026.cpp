#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9+7;


int main()
{
    int n;
    cin >> n;
    vector <ll> a(n);
    vector <vector <ll>> dp(n, vector <ll> (n, 0));
    for (int i=0; i<n; ++i)
        cin >> a[i];

    for (int len=1; len<=n; ++len)
    {
        for (int i=0; i+len<=n; ++i)
        {
            int j = i + len - 1;
            if (i == j)
                dp[i][j] = a[i];
            else
                dp[i][j] = max(a[j] - dp[i][j-1], a[i] - dp[i+1][j]);
        }
    }

    cout << dp[0][n-1];
    return 0;
}