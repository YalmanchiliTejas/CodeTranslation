#include <bits/stdc++.h>

constexpr long long mod{1000000007};

std::string k;
int d;
using vll = std::vector<long long>;
using vvll = std::vector<vll>;
std::vector<vvll> digit_dp;

long long rc(const unsigned int, const int, const int);

int main()
{
	std::cin >> k >> d;
	digit_dp.resize(k.size() + 1, vvll(d, vll(2, -1)));
	digit_dp[k.size()][0][0] = digit_dp[k.size()][0][1] = 1;
	for (int i{1}; i < d; i++)
		digit_dp[k.size()][i][0] = digit_dp[k.size()][i][1] = 0;
	printf("%lld\n", (rc(0, 0, 1) + mod - 1) % mod);

	return 0;
}

long long rc(const unsigned int digit, const int rest, const int tight)
{
	long long& sum{digit_dp[digit][rest][tight]};
	if (sum >= 0) return sum;
	sum = 0;

	int limit{10};
	if (tight) limit = k[digit] - '0';

	for (int i{}; i < limit; i++)
	{
		sum += rc(digit + 1, (rest + i) % d, false);
		sum %= mod;
	}
	if (tight)
	{
		sum += rc(digit + 1, (rest + limit) % d, true);
		sum %= mod;
	}
	return sum;
}