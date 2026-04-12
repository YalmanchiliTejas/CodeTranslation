#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void add(int &a, int b)
{
	a += b;
	if (a >= MOD)
		a -= MOD;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string k;
	cin >> k;
	int d;
	cin >> d;

	vector<vector<int>> dp(d, vector<int>(2));
	dp[0][0] = 1;
	for (int digit = 0; digit < k.size(); digit++)
	{
		vector<vector<int>> new_dp(d, vector<int>(2));
		for (int sum = 0; sum < d; sum++)
		{
			for (bool smaller_already : {true, false})
			{
				for (int new_digit = 0; new_digit < 10; new_digit++)
				{
					if (new_digit > k[digit] - '0' && !smaller_already)
						break;
					add(new_dp[(sum + new_digit) % d][smaller_already || new_digit < k[digit] - '0'], dp[sum][smaller_already]);
				}
			}
		}
		dp = new_dp;
	}
	cout << (dp[0][true] + dp[0][false] + MOD - 1) % MOD << "\n";
}

