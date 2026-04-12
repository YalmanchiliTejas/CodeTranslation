#pragma once
#include <stdio.h>
#include <sstream>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <deque>
#include <limits>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define bit(x,v) ((ll)x << v)

const ll INF = 1000000007;
const ll MAX = 4000010;
const ll MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int pr[100010];
void uini(int n) {
	for (size_t i = 0; i <= n; i++)
	{
		pr[i] = i;
	}
}

int parent(int x) {
	if (x == pr[x]) return x;
	return pr[x] = parent(pr[x]);
}

bool unit(int x, int y) {
	int px = parent(x);
	int py = parent(y);

	if (px == py) return false;
	if (px < py) {
		pr[py] = px;
	}
	else {
		pr[px] = py;
	}
	return true;
}

// res[i][c] := i 文字目以降で最初に文字 c が登場する index (存在しないときは n)
vector<vector<int> > calcNext(const string & S) {
	int n = (int)S.size();
	vector<vector<int> > res(n + 1, vector<int>(26, n));
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < 26; ++j) res[i][j] = res[i + 1][j];
		res[i][S[i] - 'a'] = i;
	}
	return res;
}
// mod 1000000007 の世界で a += b する関数
void add(long long& a, long long b) {
	a += b;
	if (a >= MOD) a -= MOD;
}
const ll ainf = 998244353;

struct cell {
	int x, y;
	int deep;
	cell(int x, int y, int deep) : x(x), y(y), deep(deep) {}
};

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int W, H, N;
int X1[500], X2[500], Y1[500], Y2[500];

bool fld[500 * 6][500 * 6];
int compress(int* x1, int* x2, int w) {
	vector<int> xs;
	for (int i = 0; i < N; i++)
	{
		for (int d = -1; d <= 1; d++)
		{
			int tx1 = x1[i] + d, tx2 = x2[i] + d;
			if (1 <= tx1 && tx1 <= W) xs.push_back(tx1);
			if (1 <= tx2 && tx2 <= W) xs.push_back(tx2);
		}
	}

	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());

	for (size_t i = 0; i < N; i++)
	{
		x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
		x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
	}
	return xs.size();
}
const int MAX_N = 1 << 17;
//
//int n,dat[2 * MAX_N - 1];
//
//void init(int n_) {
//	n = 1;
//	while (n < n_)
//	{
//		n *= 2;
//	}
//	for (size_t i = 0; i < 2 * n - 1; i++)
//	{
//		dat[i] = INT_MAX;
//	}
//}
//
//void update(int k, int a) {
//	k += n - 1;
//	dat[k] = a;
//	while (k > 0) {
//		k = (k - 1) / 2;
//		dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
//	}
//}
//int query(int a, int b, int k, int l, int r) {
//	if (r <= a || b <= 1) return INT_MAX;
//
//	if (a <= l && r <= b) return dat[k];
//	else {
//		int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
//		int vr = query(a, b, k * 2 + 1, (l + r) / 2, r);
//		return min(vl, vr);
//	}
//	
//	auto p = tie(a,b,k);
//}
ll fmemo[1000010];
ll fact(ll x) {
	if (fmemo[x] > 0) return fmemo[x];
	if (x == 0) return 1;
	fmemo[x] = (x * fact(x - 1));
	fmemo[x] %= INF;
	return fmemo[x];
}

void solv() {

	ll n, m, k;
	cin >> n >> m >> k;
	ll bas = COM(n * m - 2, k - 2);
	ll sumx = 0;
	for (ll i = 1; i <= n; i++)
	{
		ll p = ((n - i) * (n - i + 1)) / 2;
		p *= m;
		p %= INF;
		p *= m;
		p %= INF;
		sumx += p;
		sumx %= INF;
	}

	ll sumy = 0;
	for (ll i = 1; i <= m; i++)
	{
		ll p = ((m - i) * (m - i + 1)) / 2;
		p *= n;
		p %= INF;
		p *= n;
		p %= INF;
		sumy += p;

		sumy %= INF;
	}

	ll res = sumx;
	
	res %= INF;
	res += sumy;
	res %= INF;
	res *= bas;
	res %= INF;
	cout << res << endl;
}

int main() {
	COMinit();
	solv();

	return 0;
}
