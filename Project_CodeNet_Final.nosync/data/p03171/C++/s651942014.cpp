#include <iostream>
#include <cstring>

using namespace std;

#define int long long

int N, a[3005];
int dp[3005][3005]; // dp[head][tail]

int DP(int h, int t, int cur = 0)
{
	if (h == t) return cur % 2 == 0 ? a[h] : -a[h];
	if (dp[h][t] != -1) return dp[h][t];
	
	int &ret = dp[h][t];
	if (cur % 2 == 0) {
		ret = max(DP(h + 1, t, cur + 1) + a[h], DP(h, t - 1, cur + 1) + a[t]);
	} else {
		ret = min(DP(h + 1, t, cur + 1) - a[h], DP(h, t - 1, cur + 1) - a[t]);
	}

	return ret;
}

signed main()
{
	cin >> N;

	for (int i = 0; i < N; ++i) cin >> a[i];

	memset(dp, -1, sizeof dp);
	cout << DP(0, N - 1) << endl;
}
