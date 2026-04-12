#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

const LL inf = 112345678901234567;

LL get_max(std::vector<LL>v)
{
	LL res = 0;
	rep(i, v.size()) res = std::max(res, v[i]);
	return res;
}

LL get_min(std::vector<LL>v)
{
	LL res = inf;
	rep(i, v.size()) res = std::min(res, v[i]);
	return res;
}

int main()
{
	LL N;
	in >> N;
	std::vector<LL>a(N);
	rep(i, N) in >> a[i];

	LL ans = 0;
	while (true)
	{
		std::sort(a.begin(), a.end());
		if (a[N - 1] <= N - 1) break;
		if (a[N - 1] - a[0] <= N * N)
		{
			LL add = std::max<LL>(a[N - 1] - N * N, 0);
			ans += add * N;
			rep(i, N) a[i] -= add;
			do
			{
				rep(j, N - 1) ++a[j];
				a[N - 1] -= N;
				++ans;
				std::sort(a.begin(), a.end());
			} while (a[N - 1] > N - 1);
			break;
		}

		LL left = 0, right = inf;
		while (right - left > 1)
		{
			LL mid = (right + left) / 2;
			auto a_ = a;
			rep(i, N - 1) a[i] += mid;
			a[N - 1] -= N * mid;
			if (a[N - 1] < a[0] || get_max(a) <= N - 1) right = mid;
			else left = mid;
			a = a_;
		}
		rep(i, N - 1) a[i] += right;
		a[N - 1] -= N * right;
		ans += right;
	}
	out << ans << std::endl;
}
