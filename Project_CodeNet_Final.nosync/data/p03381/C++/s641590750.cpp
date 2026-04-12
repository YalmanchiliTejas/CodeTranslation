#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

LL N;

int main()
{
	in >> N;
	std::vector<std::pair<LL, LL>>A(N);
	std::vector<LL>ans(N);
	rep(i, N)
	{
		in >> A[i].first;
		A[i].second = i;
	}
	std::sort(A.begin(), A.end());
	rep(i, N)
	{
		auto ter = A[i].second;
		if (i >= N / 2)
		{
			ans[ter] = A[N / 2 - 1].first;
		}
		else
		{
			ans[ter] = A[N / 2].first;
		}
	}
	rep(i, N) out << ans[i] << std::endl;
	return 0;
}
