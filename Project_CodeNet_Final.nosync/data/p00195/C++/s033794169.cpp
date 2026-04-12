#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <iostream>
#include <sstream>
#include <climits>
#include <cfloat>
#include <complex>

using namespace std;

int main()
{
	while (true)
	{
		int am[5], pm[5];
		for (int i = 0; i < 5; ++i)
			scanf("%d %d", am+i, pm+i);
		if (!(*am | *pm))
			break;

		int shop, m = 0;
		for (int i = 0; i < 5; ++i)
		{
			if (am[i] + pm[i] > m)
			{
				m = am[i] + pm[i];
				shop = i;
			}
		}
		printf("%c %d\n", 'A' + shop, m);
	}

	return 0;
}