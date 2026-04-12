#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

LL N, K, ans;

int main()
{
	in >> N >> K;
	if (K == 0) ans = N * N;
	else
	{
		for (LL b = K + 1; b <= N; ++b)
		{
			LL res1 = (b - K)*(N / b);
			LL res2 = (K > N - N / b * b ? 0 : N - N / b * b - (K - 1));
			ans += res1 + res2;
		}
	}
	out << ans << std::endl;
	return 0;
}