#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

const int MaxN = 200000;

int n;

struct number
{
	int u, v;
	number() {}
	number(const int &_u, const int &_v)
		: u(_u), v(_v) {}

	friend inline bool operator<(const number &lhs, const number &rhs)
	{
		if (lhs.u != rhs.u)
			return lhs.u < rhs.u;
		return lhs.v < rhs.v;
	}
};
number a[MaxN + 1];

struct info
{
	int u, v;
	info() {}
	info(const int &x)
		: u(x), v(x) {}
	info(const int &_u, const int &_v)
		: u(_u), v(_v) {}

	friend inline info operator+(const info &lhs, const int &rhs)
	{
		int a = min(lhs.u, rhs);
		int b = max(lhs.v, rhs);
		return {a, b};
	}
};
info pre[MaxN + 1], suf[MaxN + 1];

int main()
{
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i].u >> a[i].v;
		if (a[i].u < a[i].v)
			swap(a[i].u, a[i].v);
	}

	sort(a + 1, a + n + 1);

	pre[1] = a[1].v;
	suf[n] = a[n].v;
	for (int i = 2; i <= n; ++i)
		pre[i] = pre[i - 1] + a[i].v;
	for (int i = n - 1; i; --i)
		suf[i] = suf[i + 1] + a[i].v;

	s64 res = (s64)(a[n].u - a[1].u) * (suf[1].v - suf[1].u);
	for (int i = 1; i < n; ++i)
	{
		int x1 = min(a[1].u, suf[i + 1].u);
		int x2 = max(a[i].u, suf[i + 1].v);
		int y1 = min(a[i + 1].u, pre[i].u);
		int y2 = max(a[n].u, pre[i].v);
		res = min(res, (s64)(x2 - x1) * (y2 - y1));
	}

	cout << res << endl;

	return 0;
}