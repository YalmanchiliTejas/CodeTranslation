#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

int X, Y, Z;

int main()
{
	in >> X >> Y >> Z;
	out << (X - Z) / (Y + Z) << std::endl;
	return 0;
}