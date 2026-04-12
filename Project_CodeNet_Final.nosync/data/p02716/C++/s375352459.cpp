#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<int> A(N + 1);
	for(int i = 1; i <= N; ++i)
	{
		cin >> A[i];
	}
	vector<pair<int64_t, int64_t> > dp(N + 1);
	dp[0].first = 0;
	dp[0].second = 0;
	dp[1].first = 0;
	dp[1].second = A[1];
	for(int i = 2; i <= N; ++i)
	{
		if(i & 1)
		{
			// odd
			dp[i].first = max
				({
					dp[i - 1].first,
					dp[i - 1].second,
					dp[i - 2].first + A[i]
				});
			dp[i].second = dp[i - 2].second + A[i];
		}
		else
		{
			dp[i].first = dp[i].second = max
				({
					dp[i - 1].second,
					dp[i - 2].first + A[i],
					dp[i - 2].second + A[i]
				});
		}
	}

	cout << dp[N].first << "\n";

	return 0;
}
