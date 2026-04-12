#include<bits/stdc++.h>

using namespace std;

#define int long long

int dp[3010][3010];
int mod;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i][i] = a[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;
            dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}
