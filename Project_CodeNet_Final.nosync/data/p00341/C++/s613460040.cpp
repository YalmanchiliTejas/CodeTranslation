#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

int main()
{
	std::vector<int>e(12);
	rep(i, 12) in >> e[i];
	std::sort(e.begin(), e.end());
	bool f1 = e[0] == e[1] && e[1] == e[2] && e[2] == e[3];
	bool f2 = e[4] == e[5] && e[5] == e[6] && e[6] == e[7];
	bool f3 = e[8] == e[9] && e[9] == e[10] && e[10] == e[11];
	if (f1&&f2&&f3) out << "yes" << std::endl;
	else out << "no" << std::endl;
}

