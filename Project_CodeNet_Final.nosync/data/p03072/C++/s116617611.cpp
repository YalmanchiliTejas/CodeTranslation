#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

int main()
{
	LL N;
	in >> N;
	std::vector<LL>H(N);
	rep(i, N) in >> H[i];

	LL ans = 0;
	rep(i, N)
	{
		bool ok = true;
		rep(j, i)
		{
			if (H[j] > H[i])
			{
				ok = false;
				break;
			}
		}
		if (ok) ++ans;
	}
	out << ans << std::endl;
}
