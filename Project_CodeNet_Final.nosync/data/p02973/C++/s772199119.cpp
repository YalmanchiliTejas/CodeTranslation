#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<map>
#include <algorithm>
#include<cstdlib>
#include<cmath>
#include<deque>
#include <numeric>
#include<valarray>
typedef unsigned long long ull;
typedef  long long ll;

int main() {
	int N;

	std::cin >> N ;

	std::vector < ll > ax;
	ax.reserve(1000);
	int cntsize = 1;
	ll tmpinx;
	std::cin >> tmpinx;
	ax.push_back(tmpinx);


	for (int i = 1; i < N; i++) 
	{
		ll tmpin;
		std::cin >> tmpin;

		if (ax[cntsize - 1] >= tmpin)
		{
			ax.push_back(tmpin);
			cntsize++;
			continue;
		}
		for (int cnti = 0; cnti < cntsize; cnti++)
		{
			if (ax[cnti] < tmpin)
			{
				ax[cnti] = tmpin;
				break;
			}
		}
	}

	std::cout << ax.size() << std::endl;

	return 0;
}
