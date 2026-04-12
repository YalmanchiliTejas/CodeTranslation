//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

#include <stdexcept>

using namespace std;

//conversion
//------------------------------------------
inline int toint(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class t> inline string tostring(t x) { ostringstream sout; sout << x; return sout.str(); }

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (l" << __line__ << ")" << " " << __file__ << endl

// type alias
using ll = long long;
using ull = unsigned long long;

inline bool isPower2(ull a)
{
	if (a == 0)
	{
		return false;
	}
	return !(a & (a - 1));
}

inline ll getMaxEffectiveBit(ull a)
{
	ll index = -1;
	for (; a != 0; a >>= 1)
	{
		++index;
	}
	return index;
}

inline ll getSpecifiedBit(ull a, unsigned bit)
{
	return (a & (1LL << bit)) >> bit;
}

// computational complexity: o(log(max(a, b))) 
inline ull getGcd(ull a, ull b)
{
	if (b == 0)
	{
		return a;
	}
	return getGcd(b, a % b);
}

template<class Integer>
inline Integer getPower(Integer base, unsigned exponential)
{
	Integer res = 1;
	while (exponential >= 1)
	{
		if (exponential & 1)
		{
			res *= base;
		}
		base = base * base;
		exponential >>= 1;
	}

	return res;
}

template<class Integer>
class BinaryIndexedTree
{
private:
	ull maxSize_;
	vector<Integer> values_;
public:
	BinaryIndexedTree(ull maxSize) : maxSize_(maxSize), values_(maxSize_, 0) {}

	void update(ll index, Integer increment)
	{
		if (maxSize_ <= index)
		{
			throw invalid_argument("Index should be less than maxSize.");
		}
		++index;

		while (index <= maxSize_)
		{
			values_[index - 1] += increment;
			index += index & -index;
		}
	}

	Integer query(ll index)
	{
		if (maxSize_ <= index)
		{
			throw invalid_argument("Index should be less than maxSize.");
		}
		++index;

		Integer res = 0;
		while (index > 0)
		{
			res += values_[index - 1];
			index -= index & -index;
		}
		return res;
	}
};
using bitll = BinaryIndexedTree<ll>;



int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	vector<ll> burgerSheaf(51);
	vector<ll> burgerPatty(51);

	burgerSheaf[0] = 1;
	burgerPatty[0] = 1;
	for (ll i = 1; i <= 50; ++i)
	{
		burgerSheaf[i] = burgerSheaf[i - 1] * 2 + 3;
		burgerPatty[i] = burgerPatty[i - 1] * 2 + 1;
	}

	ll N, X;
	cin >> N >> X;

	ll res = 0;
	while (N > 0 && X > 0)
	{
		--X;
		--N;
		if (X >= burgerSheaf[N])
		{
			X -= burgerSheaf[N];
			res += burgerPatty[N];
			if (X == 0)
			{
				break;
			}
			--X;
			++res;
			if (X >= burgerSheaf[N])
			{
				res += burgerPatty[N];
				break;
			}
		}
	}

	cout << res << endl;

	return 0;
}
