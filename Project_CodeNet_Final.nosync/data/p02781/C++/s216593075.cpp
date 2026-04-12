#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vvvi = std::vector<vvi>;

int f(const std::string& N, int K, int max_K)
{
	vvvi dp(N.size(), vvi(max_K+1, vi(2, 0)));
	int d0 = N[0] - '0';
	dp[0][0][0] = 1;
	dp[0][0][1] = 0;
	dp[0][1][0] = d0 - 1;
	dp[0][1][1] = 1;

	for (size_t i = 1; i < N.size(); i++)
	{
		int d = N[i] - '0';
		dp[i][0][0] = 1;
		dp[i][0][1] = 0;

		for (size_t j = 1; j <= max_K; j++)
		{
			if (d > 0)
			{
				dp[i][j][0] = dp[i-1][j-1][0]*9 + dp[i-1][j][0] + dp[i-1][j-1][1]*(d-1) + dp[i-1][j][1];
				dp[i][j][1] = dp[i-1][j-1][1];
			}
			else
			{
				dp[i][j][0] = dp[i-1][j-1][0]*9 + dp[i-1][j][0];
				dp[i][j][1] = dp[i-1][j][1];
			}
		}
	}

	return dp[N.size()-1][K][0] + dp[N.size()-1][K][1];
}

int main()
{
	std::string N;
	int K;
	std::cin >> N >> K;

	int ans = f(N, K, 3);

	std::cout << ans;
}