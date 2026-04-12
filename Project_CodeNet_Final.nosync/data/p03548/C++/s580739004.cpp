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
#include <unordered_map>
using namespace std;

using lint = long long;
using uli = unsigned long long;

uli gcd(uli a, uli b) {
	while (1) {
		if (a < b) swap(a, b);
		if (!b) break;
		a %= b;
	}
	return a;
}

uli lcm(uli a, uli b)
{
	return a / gcd(a, b) * b;
}

const uli mod = 1000000007;
const double pi = 3.141592653589793238462;
const lint intmax = 9223372036854775807;

uli _PowMod(uli x, uli y, uli _mod)
{
	if (y == 0)
	{
		return 1;
	}
	else if (y == 1)
	{
		return x % _mod;
	}
	else if (y % 2 == 0)
	{
		auto tmp = _PowMod(x, y / 2, _mod);
		return tmp * tmp % _mod;
	}
	else
	{
		auto tmp = _PowMod(x, y / 2, _mod);
		return (tmp * tmp % _mod) * x % _mod;
	}
}


uli PowMod(uli x, uli y)
{
	return _PowMod(x, y, mod);
}

uli getModInv(uli N)
{
	return PowMod(N, mod - 2);
}

lint nCrMod(lint start, lint n, lint r)
{
	if (n < r)
	{
		return 0;
	}
	lint a = start;
	for (size_t i = n; i >= n - r + 1; i--)
	{
		a *= i;
		a %= mod;
	}
	for (size_t i = 1; i <= r; i++)
	{
		a *= getModInv(i);
		a %= mod;
	}
	return a;
}

lint nHrMod(lint start, lint n, lint r)
{
	return nCrMod(start, n + r - 1, r);
}

lint _nCrMod(lint start, lint n, lint r)
{
	if (n <= 0)
	{
		return 0;
	}
	return nCrMod(start, n, r);
}

struct uf
{
	vector<lint> p;

	uf(lint n) : p(n)
	{
		for (size_t i = 0; i < n; i++)
		{
			p[i] = i;
		}
	}

	lint rt(lint n)
	{
		return p[n] == n ? n : p[n] = rt(p[n]);
	}

	void un(lint n, lint m)
	{
		p[rt(n)] = p[rt(m)];
	}

	bool eq(lint n, lint m)
	{
		return rt(n) == rt(m);
	}
};

bool lineCol(lint a1x, lint a1y, lint a2x, lint a2y, lint b1x, lint b1y, lint b2x, lint b2y)
{
	auto ta = (b1x - b2x) * (a1y - b1y) + (b1y - b2y) * (b1x - a1x);
	auto tb = (b1x - b2x) * (a2y - b1y) + (b1y - b2y) * (b1x - a2x);
	auto tc = (a1x - a2x) * (b1y - a1y) + (a1y - a2y) * (a1x - b1x);
	auto td = (a1x - a2x) * (b2y - a1y) + (a1y - a2y) * (a1x - b2x);

	return tc * td < 0 && ta * tb < 0;
}

lint powInt(lint a, lint b)
{
	if (b == 0)
	{
		return 1;
	}
	if (b == 1)
	{
		return a;
	}
	lint tmp = powInt(a, b / 2);
	return (b % 2 == 1 ? a * tmp * tmp : tmp * tmp);
}

lint _sMod(string n, lint mod)
{
	lint k = (n[0] - '0') % mod;
	for (size_t i = 1; i < n.length(); i++)
	{
		k *= 10;
		k += (n[i] - '0');
		k %= mod;
	}
	return k;
}

#define forin(v, n)				\
for (size_t i = 0; i < n; i++)	\
{								\
	cin >> v[i];				\
}

#define vec(name, n)			vector<lint> name(n)
#define vec_(name, n, init)		vector<lint> name(n, init)

#define vecs(name, n)			vector<string> name(n)
#define vect(t, name, n)		vector<t> name(n)

#define vec2(name, n, m)		vector<vector<lint>> name(n, vector<lint>(m))
#define vec2_(name, n, m, init)	vector<vector<lint>> name(n, vector<lint>(m, init))

#define rep(i,n)	for(lint i = 0; i < n; i++)
#define repi(i,n,z)	for(lint i = z; i < n; i++)
#define mmax(a,b)	max((lint)a, (lint)b)
#define mmin(a,b)	min((lint)a, (lint)b)

template<typename T>
void vsort(vector<T>& v)
{
	sort(v.begin(), v.end());
}

template<typename T>
void vsortr(vector<T>& v)
{
	sort(v.rbegin(), v.rend());
}

lint div2(lint p, lint q)
{
	return (p + q - 1) / q;
}

struct xy
{
	lint x, y;
	xy() :x(0), y(0) {}
	xy(lint _x, lint _y) : x(_x), y(_y) {}
};

template<class It, class T>
bool exist(It begin, It end, const T& val)
{
	return find(begin, end, val) != end;
}

template<class It, class Pr>
bool exist_if(It begin, It end, Pr pred)
{
	return find_if(begin, end, pred) != end;
}

lint n_dig(lint n)
{
	lint ans = 0;
	while (n > 0)
	{
		n /= 10;
		ans++;
	}
	return ans;
}

string yn(bool f, string y, string n)
{
	return f ? y : n;
}

const lint alpn = 'z' - 'a' + 1;

template<class T>
T sgn(T val)
{
	if (val == T(0))
		return T(0);
	if (val < 0)
		return T(-1);
	if (val > 0)
		return T(1);
}

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

int main()
{
	lint x, y, z;
	cin >> x >> y >> z;
	cout << (x + y) / (y + z)-1 << endl;
	return 0;
}
