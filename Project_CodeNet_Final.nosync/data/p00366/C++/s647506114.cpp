#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

std::vector<LL>divisor(LL num)
{
	std::vector<LL>res;
	for (LL i = 1; i*i <= num; ++i)
	{
		if (num % i == 0)
		{
			res.push_back(i);
			if ((num / i) != i)
			{
				res.push_back(num / i);
			}
		}
	}
	return res;
}

int main()
{
	LL N;
	in >> N;
	std::vector<LL>t(N);
	rep(i, N) in >> t[i];

	std::sort(t.begin(), t.end());
	auto divs = divisor(t[N - 1]);
	std::sort(divs.begin(), divs.end());

	LL ans = 0;
	rep(i, N)
	{
		auto it = std::lower_bound(divs.begin(), divs.end(), t[i]);
		ans += *it - t[i];
	}

	out << ans << std::endl;
	return 0;
}

