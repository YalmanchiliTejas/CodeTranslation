#include <bits/stdc++.h>
using namespace std;

int main()
{
	int64_t n, inf = (1LL << 60);
	cin >> n;
	vector<int64_t> as(n);
	for (auto &a : as)
	{
		cin >> a;
	}

	reverse(as.begin(), as.end());

	vector<int64_t> dp(n, inf);

	for (auto &a : as)
	{
		*upper_bound(dp.begin(), dp.end(), a) = a;
	}

	cout << distance(dp.begin(), lower_bound(dp.begin(), dp.end(), inf)) << endl;

	return 0;
}