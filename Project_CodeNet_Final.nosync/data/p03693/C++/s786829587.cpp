#include "bits/stdc++.h"
#define MOD 1000000007
#define INF 11234567890
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

int r, g, b;

int main()
{
	in >> r >> g >> b;

	auto tmp = r * 100 + g * 10 + b;
	if (tmp % 4 == 0)
	{
		out << "YES" << std::endl;
	}
	else
	{
		out << "NO" << std::endl;
	}
	return 0;
}