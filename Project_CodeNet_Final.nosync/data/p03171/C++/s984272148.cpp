#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

LL N;
std::vector<LL>a;
std::vector<std::vector<std::vector<std::pair<LL, LL>>>>memo;

std::pair<LL, LL> dp(LL i, LL j, LL k)
{
	std::pair<LL, LL>res(0, 0);
	if (j < i) return res;
	if (memo[i][j][k].first != -1) return memo[i][j][k];
	if (k == 0)
	{
		LL res1_X = dp(i + 1, j, (k + 1) % 2).first + a[i];
		LL res1_Y = dp(i + 1, j, (k + 1) % 2).second;
		LL res2_X = dp(i, j - 1, (k + 1) % 2).first + a[j];
		LL res2_Y = dp(i, j - 1, (k + 1) % 2).second;
		if (res1_X - res1_Y >= res2_X - res2_Y) res = std::make_pair(res1_X, res1_Y);
		else res = std::make_pair(res2_X, res2_Y);
	}
	else
	{
		LL res1_Y = dp(i + 1, j, (k + 1) % 2).second + a[i];
		LL res1_X = dp(i + 1, j, (k + 1) % 2).first;
		LL res2_Y = dp(i, j - 1, (k + 1) % 2).second + a[j];
		LL res2_X = dp(i, j - 1, (k + 1) % 2).first;
		if (res1_X - res1_Y <= res2_X - res2_Y) res = std::make_pair(res1_X, res1_Y);
		else res = std::make_pair(res2_X, res2_Y);
	}
	return memo[i][j][k] = res;
}

int main()
{
	in >> N;
	a.resize(N);
	rep(i, N) in >> a[i];

	memo.resize(N);
	rep(i, memo.size())
	{
		memo[i].resize(N);
		rep(j, memo[i].size()) memo[i][j].resize(2, std::make_pair(-1, -1));
	}
	out << dp(0, N - 1, 0).first - dp(0, N - 1, 0).second << std::endl;
}
