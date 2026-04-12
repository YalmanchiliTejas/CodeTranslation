#define _USE_MATH_DEFINES
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <math.h>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

#define ll long long
#define ull unsigned long long

const ll limit = (ll)(1e9 + 7);

ll gcd(ll a, ll b) {
	if (a < b)
		swap(a, b);
	while (ll r = a % b)
		a = b, b = r;
	return b;
}

class mod
{
public:
	ll val;

	mod(ll v)
	{
		val = v % limit;
	}

	mod()
	{
		val = 0;
	}

	const mod operator -(const mod &v) const
	{
		mod ret(v.val);
		ret -= val;
		return ret;
	}

	const mod operator +(const mod &v) const
	{
		mod ret(v.val);
		ret += val;
		return ret;
	}

	void operator -=(const mod &v)
	{
		val -= v.val;

		if (val < 0)
			val += limit;
	}

	void operator +=(const mod &v)
	{
		if (val + v.val >= limit)
			val -= limit;
		val += v.val;
	}

	void operator +=(ll &v)
	{
		if (val + v >= limit)
			val -= limit;
		val += v;
	}

	void operator *=(const mod &v)
	{
		val *= v.val;
		val %= limit;
	}

	void operator *=(ll &v)
	{
		val *= v;
		val %= limit;
	}

	ll modinv(ll a)
	{
		ll b = limit, u = 1, v = 0;
		while (b)
		{
			ll t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		u %= limit;
		if (u < 0)
			u += limit;
		return u;
	}

	void operator /=(const mod &v)
	{
		val *= modinv(v.val);
		val %= limit;
	}

	void operator /=(ll &v)
	{
		val *= modinv(v);
		val %= limit;
	}
};

struct UnionFind
{
	vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
	vector<int> childN;
	ll r = 0;

	UnionFind(int N) : par(N), childN(N)
	{
		//最初は全てが根であるとして初期化
		for (int i = 0; i < N; i++)
			par[i] = i, childN[i] = 1;
	}

	int root(int x)
	{
		// データxが属する木の根を再帰で得る：root(x) = {xの木の根}
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	void unite(int x, int y)
	{
		// xとyの木を併合
		int rx = root(x); //xの根をrx
		int ry = root(y); //yの根をry
		if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
		par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
		r -= childN[rx] * (childN[rx] - 1) / 2;
		r -= childN[ry] * (childN[ry] - 1) / 2;
		childN[ry] += childN[rx];
		childN[rx] = 0;
		r += childN[ry] * (childN[ry] - 1) / 2;
	}

	bool same(int x, int y)
	{
		// 2つのデータx, yが属する木が同じならtrueを返す
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
};

class WarshallFloyd
{
public:
	vector<vector<int>> d;
	int n;

	WarshallFloyd(int _n) : n(_n) { d.resize(n, vector<int>(n, limit)); }

	void run()
	{
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (d[i][k] < limit && d[k][i] < limit)
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	}

};

//	for priority queue
//	default -> 	priority_queue<int, std::vector<int>, std::greater<int>> q;
//	priority_queue<ipair, vector<ipair>, greater<ipair>>
using ipair = pair<int, pair<int, int>>;
bool operator>(const ipair a, const ipair b) { return a.first > b.first; };
bool operator<(const ipair a, const ipair b) { return a.first < b.first; };

using xpair = pair<int, int>;
bool operator>(const xpair &a, const xpair &b) { return a.second > b.second || (a.second == b.second && a.first > b.first); };
bool operator<(const xpair &a, const xpair &b) { return a.second < b.second || (a.second == b.second && a.first > b.first); };
bool operator==(const xpair &a, const xpair &b) { return a.first == b.first; };

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<mod> b(n, 0);
	for (int i = 1; i < n; i++)
		b[i] = b[i - 1] + a[i - 1];
	mod r(0);
	for (int i = 0; i < n; i++)
	{
		b[n - i - 1] *= a[n - i - 1];
		r += b[n - i - 1];
	}


	printf("%lld", r.val);
	return 0;
}
