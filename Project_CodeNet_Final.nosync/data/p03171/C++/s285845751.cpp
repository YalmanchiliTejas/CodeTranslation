#include "bits/stdc++.h"

using namespace std;

void solve()
{
	int N;
	cin >> N;
	vector<long> as(N);
	for (int i = 0; i < N; i++)
	{
		cin >> as[i];
	}

	vector<vector<long>> dp(N+1, vector<long>(N+1));

	for (int i = 1; i <= N; i++)
		for (int l = 0; l <= N-i; l++)
		{
			if ((N-i)&1)
			{
				dp[i][l] = min(dp[i-1][l+1]-as[l], dp[i-1][l]-as[i+l-1]);
			}
			else
			{
				dp[i][l] = max(dp[i-1][l+1]+as[l], dp[i-1][l]+as[i+l-1]);
			}
		}

	cout << dp[N][0] << endl;
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
