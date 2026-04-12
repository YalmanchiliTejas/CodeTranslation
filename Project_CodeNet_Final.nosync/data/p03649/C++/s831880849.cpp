#pragma once
#include <stdio.h>
#include <sstream>
#include <string>
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
#define bit(x,v) ((ll)x << v)

const ll INF = 1000000007;
const int MAX = 210000;
const int MOD = 1000000007;

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
long long COM(int n, int k) {
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
vector<vector<int> > calcNext(const string& S) {
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

void solv() {
	ll n;
	cin >> n;
	ll a[60];
	for (size_t i = 0; i < n; i++)
		cin >> a[i];
	
	ll d[60];
	memset(d, 0, sizeof(d));
	ll v = 0;
	while (true)
	{
		bool under = true;
		for (size_t i = 0; i < n; i++)
		{
			ll va = a[i] + v + d[i];
			if (va >= n) {
				under = false;
			}
			ll div = (va / n);
			d[i] -= (div * n) + div;
			v += div;
		}
		if (under) break;
	}

	cout << v << endl;
}

int main() {
	//COMinit();
	solv();

	return 0;
}
