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

// constant value
const ll mod = 1000000007ll;

template<class ll>
inline ll getceilexponent(ll a)
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
inline ll getfloorexponent(ll a)
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


map<ll, ull> getprimefactorization(ll num)
{
	map<ll, ull> primetocount;

	int rootnum = sqrt(num);
	vector<bool> iscompositenumber(rootnum + 1, false);
	for (int p = 2; num != 1 && p <= rootnum; ++p)
	{
		if (!iscompositenumber[p])
		{
			for (int i = p * 2; i <= rootnum; i += p)
			{
				iscompositenumber[i] = true;
			}

			int count = 0;
			while (num % p == 0)
			{
				++count;
				num /= p;
			}
			if (count >= 1)
			{
				primetocount.insert(make_pair(p, count));
			}
		}
	}
	if (num != 1)
	{
		primetocount.insert(make_pair(num, 1));
	}

	return primetocount;
}

// computational complexity: o(log(max(a, b))) 
template<class ll>
inline ll getgcd(ll a, ll b)
{
	if (b == 0)
	{
		return a;
	}
	return getgcd(b, a % b);
}

// computational complexity: o(log(max(a, b))) 
template<class ll>
inline pair<ll, ll> getbezoutsidentitysoulution(ll a, ll b)
{
	if (b == 0)
	{
		return { 1, 0 };
	}
	auto sol = getbezoutsidentitysoulution(b, a % b);
	return { sol.second, sol.first - (a / b) * sol.second };
}

inline ll getmodvalue(ll a, ll m)
{
	return (a % m + m) % m;
}

// computational complexity: o(log(max(a, n))) 
inline ll getmodinverse(ll a, ll m)
{
	auto sol = getbezoutsidentitysoulution(a, m);
	if (a * sol.first + m * sol.second != 1)
	{
		return -1;
	}
	return getmodvalue(sol.first, m);
}

ll getmodcombinatorialnumber(ll n, ll r, ll m)
{
	ll res = 1;
	for (; n > 0; --n, --r)
	{
		res = (((res * n) % m) * getmodinverse(n, m)) % m;
	}
	return getmodvalue(res, m);
}

ll getmodpower(ll base, unsigned t, ll m)
{
	if (t == 0)
	{
		return 1ll;
	}

	auto res = getmodpower(base, t >> 1, m);
	res = getmodvalue(res * res, m);
	if (t % 2 == 1)
	{
		res = getmodvalue(res * base, m);
	}
	return res;
}

#define moder (int)(1e9+7)
#define inf (int)(3e18+7)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define all(v) v.begin(),v.end()
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define vecunique(vec) sort(vec.begin(), vec.end());decltype(vec)::iterator result = std::unique(vec.begin(), vec.end());vec.erase(result, vec.end())

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;

	vector<ll> Hs(N);
	for (ll i = 0; i < N; ++i)
	{
		cin >> Hs[i];
	}

	ll res = 1;
	ll height = Hs[0];
	for (ll i = 1; i < N; ++i)
	{
		if (Hs[i] >= height)
		{
			++res;
		}
		height = max(height, Hs[i]);
	}

	cout << res << endl;

	return 0;
}