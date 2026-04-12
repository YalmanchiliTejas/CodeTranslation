#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

int main()
{
	LL A, B, C, X, Y;
	in >> A >> B >> C >> X >> Y;

	LL ans = 1145148101919364364;
	for (LL i = 0; i <= 212345; i += 2)
	{
		LL wantA = X - i / 2, wantB = Y - i / 2, res = C * i;
		if (wantA > 0) res += A * wantA;
		if (wantB > 0) res += B * wantB;
		ans = std::min(ans, res);
	}

	out << ans << std::endl;
}
