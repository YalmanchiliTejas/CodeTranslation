#include "omp.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <cassert>
#include <fstream>
#include <algorithm>
#include <list>
#include <random>
#include <ctime>
#include <random>
#include <bitset>
#include <unordered_set>
#include <cassert>
#include <list>
#include <functional>


using namespace std;

typedef long long ll;
typedef long double ld;


const int sze = 1 << 15, INF = 1e9 + 10;

signed main()
{
	int n;
	cin >> n;

	vector<int> values(n), challengers(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> values[i];
		challengers[i] = values[i];
	}

	sort(values.begin(), values.end());
	
	map<int, int> ans;

	for (int i = 0; i < n; ++i)
	{
		if (i >= n / 2)
			ans[values[i]] = values[n / 2 - 1];
		else if (i < n / 2)
		{
			ans[values[i]] = values[n / 2];
		}
	}

	for (int v : challengers)
		cout << ans[v] << '\n';

	return 0;
}