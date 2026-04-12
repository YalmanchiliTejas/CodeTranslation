#include <iostream>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>
#include <functional>

#include <vector>

using namespace std;

const long long MOD = 998244353;

long long dp[3001][3001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, S;
	cin >> N >> S;

	vector<long long> numlist(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> numlist[i];
		dp[i][numlist[i]] = i;
	}

	long long result = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= S; j++)
		{
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
			if (j >= numlist[i])
				dp[i][j] = (dp[i][j] + dp[i - 1][j - numlist[i]]) % MOD;
		}

		result = (result + dp[i][S]) % MOD;
	}

	cout << result;

	return 0;
}
