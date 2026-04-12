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

template<class ll>
inline ll getCeilExponent(ll a)
{
	if (a <= 0)
	{
		throw invalid_argument("vaule equal to or less than 0 should not be valid");
	}

	ll index = 0;
	--a;
	for (; a != 0; a >>= 1)
	{
		++index;
	}
	return index;
}

template<class ll>
inline ll getFloorExponent(ll a)
{
	if (a <= 0)
	{
		throw invalid_argument("vaule equal to or less than 0 should not be valid");
	}

	ll index = 0;
	a >>= 1;
	for (; a != 0; a >>= 1)
	{
		++index;
	}
	return index;
}

// computational complexity: o(log(max(a, b))) 
template<class ll>
inline ll getGcd(ll a, ll b)
{
	if (b == 0)
	{
		return a;
	}
	return getGcd(b, a % b);
}

// computational complexity: o(log(max(a, b))) 
template<class ll>
inline pair<ll, ll> getBezoutsIdentitySolution(ll a, ll b)
{
	if (b == 0)
	{
		return { 1, 0 };
	}
	auto sol = getBezoutsIdentitySolution(b, a % b);
	return { sol.second, sol.first - (a / b) * sol.second };
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

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;

	vector<ll> Ss(N);
	for (ll i = 0; i < N; ++i)
	{
		cin >> Ss[i];
	}

	ll res = 0;
	for (ll C = 1; C + 1 < N; ++C)
	{
		ll resC = 0;
		for (ll k = 1; C * (k + 1) + 1 < N; ++k)
		{
			resC += Ss[N - 1 - C * k] + Ss[C * k];
			if ((N - 1) % C == 0 && (N - 1) / C <= k * 2 )
			{
				continue;
			}
			res = max(res, resC);
		}
	}

	cout << res << endl;


	return 0;
}
