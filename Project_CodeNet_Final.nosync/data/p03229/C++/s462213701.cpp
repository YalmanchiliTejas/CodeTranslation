#pragma region
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <iomanip>
#include <cstdint>
#include <bitset>
#include <fstream>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()

#pragma region UnionFind
struct UnionFind
{
	vector<int> par;

	UnionFind(int n) : par(n, -1) {}
	void init(int n) { par.assign(n, -1); }

	int root(int x)
	{
		if (par[x] < 0) return x;
		else return par[x] = root(par[x]);
	}

	bool issame(int x, int y)
	{
		return root(x) == root(y);
	}

	bool merge(int x, int y)
	{
		x = root(x); y = root(y);
		if (x == y) return false;
		if (par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	int size(int x)
	{
		return -par[root(x)];
	}
};
#pragma endregion
#pragma region GCD
int gcd(int a, int b)
{
	if (a%b == 0)return b;
	return gcd(b, a%b);
}
#pragma endregion
#pragma region chmin
template<class T> inline bool chmin(T& a, T b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}
#pragma endregion
#pragma region chmax
template<class T> inline bool chmax(T& a, T b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}
#pragma endregion
#pragma endregion


int main()
{
	int n; cin >> n;
	multiset<ll> s;
	rep(i, n)
	{
		ll x; cin >> x;
		s.insert(x);
	}
	deque<ll> q;
	q.push_front(*s.begin());
	q.push_back(*--s.end());
	s.erase(s.begin());
	s.erase(--s.end());
	ll res = q.back() - q.front();
	while (s.size() > 1)
	{
		ll l = *s.begin();
		ll r = *--s.end();
		ll lf, lb, rf, rb;
		lf = abs(l - q.front()), lb = abs(l - q.back()), rf = abs(r - q.front()), rb = abs(r - q.back());
		if (lf == max({ lf,lb,rf,rb }))
		{
			res += lf;
			q.push_front(l);
			s.erase(s.begin());
		}
		else if (lb == max({ lf,lb,rf,rb }))
		{
			res += lb;
			q.push_back(l);
			s.erase(s.begin());
		}
		else if (rf == max({ lf,lb,rf,rb }))
		{
			res += rf;
			q.push_front(r);
			s.erase(--s.end());
		}
		else
		{
			res += rb;
			q.push_back(r);
			s.erase(--s.end());
		}
	}
	if (s.size() == 1)
	{
		ll x = *s.begin();
		res += max(abs(x - q.front()), abs(x - q.back()));
	}
	cout << res << endl;
}