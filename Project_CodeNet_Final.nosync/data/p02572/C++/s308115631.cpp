#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <climits>
#include <numeric>
#include<stdio.h>
#include <queue>
#include <iomanip>
#include <float.h>
#include <set>
#include<functional>
#include <stack>
#include <time.h>
#include <climits>
#include <bitset>
#include <fstream>
#include<map>
#include <cassert>
#include<sstream>
#include<fstream>
#include <cstring>
using namespace std;
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree
{
	using F = function< Monoid(Monoid, Monoid) >;
	using G = function< Monoid(Monoid, OperatorMonoid) >;
	using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;
	using P = function< OperatorMonoid(OperatorMonoid, int) >;

	int sz;
	vector< Monoid > data;
	vector< OperatorMonoid > lazy;
	const F f;
	const G g;
	const H h;
	const P p;
	const Monoid M1;
	const OperatorMonoid OM0;


	LazySegmentTree(int n, const F f, const G g, const H h, const P p,
		const Monoid &M1, const OperatorMonoid OM0)
		: f(f), g(g), h(h), p(p), M1(M1), OM0(OM0)
	{
		sz = 1;
		while (sz < n) sz <<= 1;
		data.assign(2 * sz, M1);
		lazy.assign(2 * sz, OM0);
	}

	void set(int k, const Monoid &x)
	{
		data[k + sz] = x;
	}

	void build()
	{
		for (int k = sz - 1; k > 0; k--) {
			data[k] = f(data[2 * k + 0], data[2 * k + 1]);
		}
	}

	void propagate(int k, int len)
	{
		if (lazy[k] != OM0) {
			if (k < sz) {
				lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
				lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
			}
			data[k] = g(data[k], p(lazy[k], len));
			lazy[k] = OM0;
		}
	}

	Monoid update(int a, int b, const OperatorMonoid &x, int k, int l, int r)
	{
		propagate(k, r - l);
		if (r <= a || b <= l) {
			return data[k];
		}
		else if (a <= l && r <= b) {
			lazy[k] = h(lazy[k], x);
			propagate(k, r - l);
			return data[k];
		}
		else {
			return data[k] = f(update(a, b, x, 2 * k + 0, l, (l + r) >> 1),
				update(a, b, x, 2 * k + 1, (l + r) >> 1, r));
		}
	}

	Monoid update(int a, int b, const OperatorMonoid &x)
	{
		return update(a, b, x, 1, 0, sz);
	}


	Monoid query(int a, int b, int k, int l, int r)
	{
		propagate(k, r - l);
		if (r <= a || b <= l) {
			return M1;
		}
		else if (a <= l && r <= b) {
			return data[k];
		}
		else {
			return f(query(a, b, 2 * k + 0, l, (l + r) >> 1),
				query(a, b, 2 * k + 1, (l + r) >> 1, r));
		}
	}

	Monoid query(int a, int b)
	{
		return query(a, b, 1, 0, sz);
	}

	Monoid operator[](const int &k)
	{
		return query(k, k + 1);
	}
};
map< int64_t, int > prime_factor(int64_t n) {
	map< int64_t, int > ret;
	for (int64_t i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret[i]++;
			n /= i;
		}
	}
	if (n != 1) ret[n] = 1;
	return ret;
}
long long MOD = 998244353;
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
template< typename T >
struct BinaryIndexedTree {
	vector< T > data;

	BinaryIndexedTree(int sz) {
		data.assign(++sz, 0);
	}

	T sum(int k) {
		T ret = 0;
		for (++k; k > 0; k -= k & -k) ret += data[k];
		return (ret);
	}

	void add(int k, T x) {
		for (++k; k < data.size(); k += k & -k) data[k] += x;
	}
};
typedef pair<int, int>p;
vector< int64_t > divisor(int64_t n) {
	vector< int64_t > ret;
	for (int64_t i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(begin(ret), end(ret));
	return (ret);
}
long long mod = 1e9 + 7;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[200004];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	sum %= mod;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + mod - a[i];
		sum %= mod;
		long long tmp = sum*a[i];
		ans = (ans + tmp) % mod;
	}
	cout << ans;
}

