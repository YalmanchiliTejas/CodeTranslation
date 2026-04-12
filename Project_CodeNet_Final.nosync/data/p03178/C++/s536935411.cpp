#include <iostream>
#include <cstring>
#include <string>

int d;
const int mod = 1000000007;
const int size = 100005;
std::string s;
int dp[size][2][102];

int Solve(int ndx, bool equal, int sum)
{
	if (ndx >= s.size())
		return sum == 0;
	if (dp[ndx][equal][sum] != -1)
		return dp[ndx][equal][sum];
	int ans = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (equal)
		{
			if (i < s[ndx] - '0')
				ans = (ans + Solve(ndx + 1, false, (sum + i) % d)) % mod;
			else if (i == s[ndx] - '0')
				ans = (ans + Solve(ndx + 1, true, (sum + i) % d)) % mod;
		}
		else
			ans = (ans + Solve(ndx + 1, false, (sum + i) % d)) % mod;
	}
	return dp[ndx][equal][sum] = ans;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	std::cin >> s;
	std::cin >> d;
	int ans = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (i < s[0] - '0')
			ans = (ans + Solve(1, false, i % d)) % mod;
		if (i == s[0] - '0')
			ans = (ans + Solve(1, true, i % d)) % mod;
	}
	std::cout << (ans - 1 + mod) % mod << '\n';
	// std::cin >> d;
	return 0;
}