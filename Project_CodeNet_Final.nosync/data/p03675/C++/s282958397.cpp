
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;

int main(void)
{
	int n;
	vector<int>a, ans;
	set<int>se;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int aa;
		cin >> aa;
		a.push_back(aa);
	}
	for (int i = n - 1; i >= 0; i -= 2)
	{
		ans.push_back(a[i]);
		se.insert(i);
	}
	for (int i = 0; i < n; ++i)
	{
		if (!se.count(i))
		{
			ans.push_back(a[i]);
		}
	}
	assert(n == ans.size());
	for (int i = 0; i < n; ++i)
	{
		cout << ans[i] << " \n"[i == n - 1];
	}
	return 0;
}
