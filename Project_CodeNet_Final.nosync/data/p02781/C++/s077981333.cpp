#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string n;
	cin >> n;
	int k;
	cin >> k;

	vector<vector<unsigned long long>> dp(2, vector<unsigned long long>(3, 0));
	{
		int i = n[0] - '0';
		dp[0][0] = 1;
		dp[1][0] = i - 1;
	}

	for (size_t i = 1; i < n.size(); ++i)
	{
		vector<vector<unsigned long long>> dpcpy = dp;
		int j = n[i] - '0';
		if (0 < j) {
			dp[0][0] -= dpcpy[0][0];
			dp[0][1] -= dpcpy[0][1];
			dp[0][1] += dpcpy[0][0];
			dp[0][2] -= dpcpy[0][2];
			dp[0][2] += dpcpy[0][1];

			dp[1][0] = 9 + dpcpy[0][0] + dpcpy[1][0];
			dp[1][1] = dpcpy[0][0] * (j - 1) + dpcpy[1][0] * 9 + dpcpy[0][1] + dpcpy[1][1];
			dp[1][2] = dpcpy[0][2] + dpcpy[0][1] * (j - 1) + dpcpy[1][1] * 9 + dpcpy[1][2];
		}
		else {
			dp[0][0] = dpcpy[0][0];
			dp[0][1] = dpcpy[0][1];
			dp[0][2] = dpcpy[0][2];

			dp[1][0] = 9 + dpcpy[1][0];
			dp[1][1] = dpcpy[1][1] + dpcpy[1][0] * 9;
			dp[1][2] = dpcpy[1][2] + dpcpy[1][1] * 9;
		}
	}

	cout << dp[0][k - 1] + dp[1][k - 1] << endl;

	return 0;
}
