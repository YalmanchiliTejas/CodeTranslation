#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define LL long long
const int maxn = 200010;
const int mod = (int)(1e9 + 7);
using namespace std;

vector<pair<int, int>> bags;

int solve1(vector<pair<int, int>> b, int Bmin, int Bmax, int min_i, int max_i)
{
	int i, j, ret;
	vector<pair<int, int>> c;
	c.clear();
	for (i = 0; i < b.size(); i ++)
		if (i != min_i && i != max_i)
		{
			if (b[i].first > Bmax)
				Bmax = b[i].first;
			else if (b[i].second < Bmin)
				Bmin = b[i].second;
		}
	for (i = 0; i < b.size(); i ++)
		if (i != min_i && i != max_i)
		{
			if (b[i].first < Bmin && b[i].second > Bmax)
				c.push_back(b[i]);
		}
	if (c.size() == 0)
	{
		return ret = Bmax - Bmin;
	}
	ret = mod;
	sort(c.begin(), c.end());
	for (i = 0; i < c.size(); i ++)
	{
		if (Bmax - c[i].first < ret)
			ret = Bmax - c[i].first;
		Bmax = max(c[i].second, Bmax);
	}
	return ret;
}

void solve2(vector<pair<int, int>> b, int &Bmin, int &Rmax, int min_i, int max_i)
{
	int i, j;
	for (i = 0; i < b.size(); i ++)
		if (i != min_i && i != max_i)
		{
			Bmin = min(Bmin, b[i].second);
			Rmax = max(Rmax, b[i].first);
		}
}

int main()
{
	int N, i, j, x, y, min_i, max_i, Bmax, Bmin, Rmin, Rmax;
	int dis;
	LL ans;
	cin >> N;
	min_i = max_i = 0;
	for (i = 0; i < N; i ++)
	{
		cin >> x >> y;
		if (x > y)
			swap(x, y);
		bags.push_back(make_pair(x, y));

		if (x < bags[min_i].first)
			min_i = i;
		if (y > bags[max_i].second)
			max_i = i;
	}
	if (min_i != max_i)
	{
		Rmin = bags[min_i].first;
		Rmax = bags[max_i].second;
		Bmin = min(bags[min_i].second, bags[max_i].first);
		Bmax = max(bags[min_i].second, bags[max_i].first);
		dis = solve1(bags, Bmin, Bmax, min_i, max_i);
		ans = 1LL * dis * (Rmax - Rmin);
		
		Rmin = bags[min_i].first;
		Bmax = bags[max_i].second;
		Bmin = bags[min_i].second;
		Rmax = bags[max_i].first;

		solve2(bags, Bmin, Rmax, min_i, max_i);
		ans = min(ans, 1LL * (Bmax - Bmin) * (Rmax - Rmin));
	}
	else
	{
		Rmax = Rmin = bags[min_i].first;
		Bmin = Bmax = bags[max_i].second;

		solve2(bags, Bmin, Rmax, min_i, max_i);
		ans = 1LL * (Bmax- Bmin) * (Rmax - Rmin);
	}
	cout << ans;
	return 0;
}