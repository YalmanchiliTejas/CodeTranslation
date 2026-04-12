#include <iostream>
#include <vector>
#include <string>

int main()
{
	
	std::string n;
	int k;

	std::cin >> n >> k;

	long long dp[102][2][5] = {};
	dp[0][0][0] = 1;

	const int L = n.length();

	for (int i = 0; i < L; ++i)
	{
		const int D = n[i] - '0';

		for (int j = 0; j < 2; ++j)
		{
			for (int nonzero = 0; nonzero < (k + 1); ++nonzero)
			{
				for (int d = 0; d <= (j ? 9 : D); ++d)
				{
					dp[i + 1][j || d != D][(d == 0 ? nonzero : nonzero + 1)] += dp[i][j][nonzero];
				}
			}
		}
	}

	std::cout << (dp[L][0][k] + dp[L][1][k]) << std::endl;
}