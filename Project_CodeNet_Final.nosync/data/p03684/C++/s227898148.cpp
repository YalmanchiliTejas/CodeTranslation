
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


#include <vector>

class union_find
{
private:
	std::vector<int>parent;
	std::vector<int>rank;
	std::vector<int>clump;
public:
	union_find(int siz)
	{
		parent.resize(siz);
		rank.resize(siz);
		clump.resize(siz);
		for (int i = 0; i < siz; ++i)
		{
			parent[i] = i;
			rank[i] = 0;
			clump[i] = 1;
		}
	}
	void unite(int x, int y)
	{
		int xr = find(x);
		int yr = find(y);
		if (xr == yr)return;
		if (rank[xr] > rank[yr])
		{
			parent[yr] = xr;
			clump[xr] += clump[yr];
		}
		else if (rank[yr] > rank[xr])
		{
			parent[xr] = yr;
			clump[yr] += clump[xr];
		}
		else if (xr != yr)
		{
			parent[yr] = xr;
			clump[xr] += clump[yr];
			++rank[xr];
		}
	}
	int find(int x)
	{
		if (parent[x] == x)
		{
			return x;
		}
		else
		{
			return parent[x] = find(parent[x]);
		}
	}
	bool check(int x, int y)
	{
		return find(x) == find(y);
	}
	int size(int x)
	{
		return clump[find(x)];
	}
};



int main(void)
{
	int n;
	cin >> n;
	vector<pair<LL, int>>x, y;
	for (int i = 0; i < n; ++i)
	{
		LL xx, yy;
		cin >> xx >> yy;
		x.push_back({ xx,i });
		y.push_back({ yy,i });
	}
	union_find uf(n);
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	vector<pair<LL, pair<int, int>>>vec;
	for (int i = 1; i < n; ++i)
	{
		vec.push_back({ x[i].first - x[i - 1].first,{x[i].second,x[i - 1].second} });
		vec.push_back({ y[i].first - y[i - 1].first,{ y[i].second,y[i - 1].second } });
	}
	sort(vec.begin(), vec.end());
	LL ans = 0;
	int i = 0;
	while (uf.size(0) < n)
	{
		auto p = vec[i];
		if (!uf.check(p.second.first, p.second.second))
		{
			uf.unite(p.second.first, p.second.second);
			ans += p.first;
		}
		++i;
	}
	cout << ans << endl;
	return 0;
}
