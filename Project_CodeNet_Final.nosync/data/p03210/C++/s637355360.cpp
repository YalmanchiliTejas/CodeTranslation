#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <bitset>
#include <iomanip>
#include <cmath>
#include <queue>
#define in std::cin
#define out std::cout
#define end std::endl
#define REP(i, A, N) for(int i=A;i<N;++i)
typedef long long int ll;

int main()
{
	ll x;
	in >> x;
	if((x == 7) || (x == 5) || (x == 3)){
		out << "YES" << end;
	}else{
		out << "NO" << end;
	}

	return 0;
}
