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

long long dp[3001];

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
	}

	long long result = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = S - numlist[i]; j >= 0; j--)
		{
			if (j == 0)
				dp[numlist[i]] = (dp[numlist[i]] + i) % MOD;
			else
				dp[numlist[i] + j] = (dp[numlist[i] + j] + dp[j]) % MOD;
		}

		result = (result + dp[S]) % MOD;
	}

	cout << result;

	return 0;
}
