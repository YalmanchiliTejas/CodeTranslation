#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	char cc;
	bool aa = false, bb = false;
	for(int64 ii = 0;ii < 3;ii++)
	{
		cin >> cc;
		if(cc == 'A')
		{
			aa = true;
		}
		else
		{
			bb = true;
		}
	}
	if(aa && bb)
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}
