#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

LL N, X;
std::vector<std::vector<LL>>res;
std::vector<LL>cnt, all;
std::map<std::pair<LL, LL>, LL>memo;

LL f(LL l, LL x)
{
	if (l == 0) return 1;
	if (memo[std::make_pair(l, x)] > 0) return memo[std::make_pair(l, x)];
	LL sum = 0;
	for (int i = 4; i >= 0; --i)
	{
		if (x <= 0) break;
		if (i == 3 || i == 1)
		{
			if (x >= all[l - 1]) sum += cnt[l - 1];
			else sum += f(l - 1, x);
		}
		if (i == 2) ++sum;
		x -= res[l][i];
	}
	return memo[std::make_pair(l, x)] = sum;
}

int main()
{
	in >> N >> X;

	res.resize(N + 1);
	rep(i, res.size()) res[i].resize(5, 1);
	cnt.resize(N + 1); all.resize(N + 1);
	cnt[0] = 1; all[0] = 1;
	LL sum = 1;
	for (LL i = 1; i <= N; ++i)
	{
		res[i][1] = res[i][3] = sum;
		sum = 0;
		rep(j, 5) sum += res[i][j];
		cnt[i] = cnt[i - 1] * 2 + 1;
		all[i] = all[i - 1] * 2 + 3;
	}

	out << f(N, X) << std::endl;
	return 0;
}
