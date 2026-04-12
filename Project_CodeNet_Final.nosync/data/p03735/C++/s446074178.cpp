
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


template
<class T>
struct heap
{
private:
	multiset<T, greater<T>>big;
	multiset<T, less<T>>sml;
public:
	void insert(T x)
	{
		big.insert(x);
		sml.insert(x);
	}
	void erase(T x)
	{
		big.erase(big.find(x));
		sml.erase(sml.find(x));
	}
	T getMax()
	{
		assert(big.size() && sml.size());
		return *big.begin();
	}
	T getMin()
	{
		assert(big.size() && sml.size());
		return *sml.begin();
	}
};

LL difference(vector<pair<LL, LL>>&vec)
{
	sort(vec.begin(), vec.end(), [](const pair<LL, LL>& p1, const pair<LL, LL>& p2)
	{
		if (p1.first == p2.first)
			return p1.second > p2.second;
		return p1.first < p2.first;
	});
	heap<LL>S,T;
	for (int i = 0; i < vec.size(); ++i)S.insert(vec[i].first);
	for (int i = 0; i < vec.size(); ++i)T.insert(vec[i].second);
	LL ans = (S.getMax() - S.getMin()) * (T.getMax() - T.getMin());
	for (int i = 0; i < vec.size(); ++i)
	{
		S.erase(vec[i].first);
		S.insert(vec[i].second);
		T.erase(vec[i].second);
		T.insert(vec[i].first);
		ans = min(ans, (S.getMax() - S.getMin()) * (T.getMax() - T.getMin()));
	}
	return ans;
}

int main(void)
{
	LL N;
	vector<pair<LL, LL>>vec;
	cin >> N;
	heap<LL> L, R;
	int sind, lind;
	LL minv = LLONG_MAX, maxv = 0;
	LL minpar = 0, maxpar = LLONG_MAX;
	for (int i = 0; i < N; ++i)
	{
		LL x, y;
		cin >> x >> y;
		if (x > y)swap(x, y);
		vec.push_back({ x, y });
		L.insert(x);
		R.insert(y);
		if (minv > x)
		{
			minv = x;
			minpar = y;
			sind = i;
		}
		else if (minv == x && minpar > y)
		{
			minv = x;
			minpar = y;
			sind = i;
		}
		if (maxv < y)
		{
			maxv = y;
			maxpar = x;
			lind = i;
		}
		else if (maxv == y && maxpar < x)
		{
			maxv = y;
			maxpar = x;
			lind = i;
		}
	}
	LL ans = (L.getMax() - L.getMin()) * (R.getMax() - R.getMin());
	if (sind == lind)
	{
		LL diff = difference(vec);
		LL can = diff;
		ans = min(ans, can);
	}
	else
	{
		auto small = vec[sind];
		auto large = vec[lind];
		//sindとlindの2箇所を削除する(後ろから)
		vec.erase(vec.begin() + max(sind, lind), vec.begin() + max(sind, lind) + 1);
		vec.erase(vec.begin() + min(sind, lind), vec.begin() + min(sind, lind) + 1);
		swap(small.first, small.second);
		vec.insert(vec.begin(), small);
		vec.push_back(large);
		LL diff = difference(vec);
		LL can = diff;
		ans = min(ans, can);
	}
	cout << ans << endl;
	return 0;
}
