#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int get_parent(vector<int> &p, int i)
{
	return p[i] == i ? i : p[i] = get_parent(p, p[i]);
}

int main()
{
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> x, y;
	for (int i = 0; i < n; i++)
	{
		int xx, yy;
		scanf("%d %d", &xx, &yy);
		x.push_back({ xx, i });
		y.push_back({ yy, i });
	}

	vector<vector<int>> c;
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	for (int i = 1; i < n; i++)
	{
		c.push_back({ x[i].first - x[i - 1].first, x[i].second, x[i - 1].second });
		c.push_back({ y[i].first - y[i - 1].first, y[i].second, y[i - 1].second });
	}

	sort(c.begin(), c.end());
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		p[i] = i;
	long long ans = 0;
	for (int i = 0; i < c.size(); i++)
	{
		int px = get_parent(p, c[i][1]), py = get_parent(p, c[i][2]);
		if (px == py) continue;
		ans += c[i][0];
		p[px] = py;
	}
	printf("%lld\n", ans);

	return 0;
}