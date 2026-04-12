#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int m = 0;
	vector<int> t(n);
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
		m = max(m, t[i]);
	}
	vector<int> g;
	for (int i = 1; i <= (m + 1) / 2; i++)
		if (m % i == 0)
		{
			g.push_back(i);
			g.push_back(m / i);
		}
	sort(g.begin(), g.end());
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += g[lower_bound(g.begin(), g.end(), t[i]) - g.begin()] - t[i];
	cout << ans << endl;

	return 0;
}
