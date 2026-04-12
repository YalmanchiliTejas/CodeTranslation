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
#include <cassert>

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
	ll n, x, m; cin >> n >> x >> m;
	ll now = x;
	int l, r; l = r = -1;
	map<int, int> mp;
	vector<ll> f(m + 5);
	for (ll i = 1; i <= n; ++i)
	{
		f[i] = now;
		if (mp[now])
		{
			l = mp[now];
			r = i;
			break;
		}
		mp[now] = i;
		now *= now;
		now %= m;
	}
	ll res = 0;
	if (l == -1)
	{
		for (int i = 1; i <= n; ++i)res += f[i];
		cout << res << endl;
		return 0;
	}
	for (int i = 1; i < l; ++i)res += f[i];
	ll sum = 0;
	for (int i = l; i < r; ++i)sum += f[i];
	ll len = r - l;
	res += ((n - (l - 1)) / len * sum);
	rep(i, ((n - (l - 1)) % len))res += f[i + l];
	cout << res << endl;
}