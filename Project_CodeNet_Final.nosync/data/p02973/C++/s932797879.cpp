#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <utility>
#include <map>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
using int64 = long long;
#define ForInt(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define ForIntInit(i, begin, end) for (int i = (begin); i < (end); ++i)
#define ForItr(it, itBegin, itEnd) for (auto (it) = (itBegin); (it) != (itEnd); ++(it))


int main()
{
	int n;
	cin >> n;
	vector<int64> a(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	multiset<int64> b;
	for (int i = n - 1; i >= 0; --i)
	{
		int color = 0;
		auto it = b.upper_bound(a[i]);
		if (it != b.end())
		{
			b.erase(it);
		}
		b.insert(a[i]);
	}
	cout << b.size() << endl;

	return 0;
}
