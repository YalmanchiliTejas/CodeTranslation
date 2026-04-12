#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <list>
#include <unordered_set>
#include <tuple>
#include <cmath>
#include <limits>
#include <type_traits>
#include <iomanip>
using namespace std;

using INT = long long;
using UINT = unsigned long long;

unsigned gcd(unsigned a, unsigned b) {
	while (1) {
		if (a < b) swap(a, b);
		if (!b) break;
		a %= b;
	}
	return a;
}

const UINT mod = 1000000007;

UINT PowMod(UINT x, UINT y)
{
	if (y == 0)
	{
		return 1;
	}
	else if (y == 1)
	{
		return x % mod;
	}
	else if (y % 2 == 0)
	{
		auto tmp = PowMod(x, y / 2);
		return tmp * tmp % mod;
	}
	else
	{
		auto tmp = PowMod(x, y / 2);
		return (tmp * tmp % mod) * x % mod;
	}
}

UINT getModInv(UINT N)
{
	return PowMod(N, mod - 2);
}

struct uf
{
	vector<INT> p;

	uf(INT n) : p(n)
	{
		for (size_t i = 0; i < n; i++)
		{
			p[i] = i;
		}
	}

	INT rt(INT n)
	{
		return p[n] == n ? n : p[n] = rt(p[n]);
	}

	void un(INT n, INT m)
	{
		p[rt(n)] = p[rt(m)];
	}

	bool eq(INT n, INT m)
	{
		return rt(n) == rt(m);
	}
};

int main()
{
	int r, g, b;
	cin >> r >> g >> b;
	cout << (((g * 10 + b) % 4 == 0) ? "YES" : "NO") << endl;
	return 0;
}
