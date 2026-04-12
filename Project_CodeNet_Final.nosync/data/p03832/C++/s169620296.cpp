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
ll ar[40];
bool use[40];
ll table[1001][1001];
ll n, a, b, c, d;
ll memo[1001][1001];
ll rec(int v, int rem) {

	if (rem == 0) return 1;
	if (v > b) return 0;
	ll & res = memo[v][rem];

	if (~res) return res;
	res = rec(v + 1, rem);
	res %= INF;
	ll vr = 1;
	ll pt = 1;
	for (ll i = 1; i < c; i++)
	{
		ll va = rem - (v * (i - 1));
		if (va < 0) {
			return res = 0;
		}
		vr *= table[va][v];
		vr %= INF;
		vr *= inv[i];
		vr %= INF;

	}

	for (ll i = c; i <= d; i++)
	{
		if (v * i > rem) break;
		vr *= table[rem - (v * (i - 1))][v];
		vr %= INF;

		vr *= inv[i];

		vr %= INF;
		res += (vr  * rec(v + 1, rem - v * i)) % INF;
		res %= INF;
	}

	return res;
}
void solv() {

	cin >> n;
	cin >> a >> b;
	cin >> c >> d;
	table[0][0] = 1;
	for (size_t i = 1; i <= n; i++)
	{
		table[i][0] = 1;
		for (size_t j = 1; j <= n; j++)
		{
			table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
			table[i][j] %= INF;
		}
	}

	memset(memo, -1, sizeof(memo));
	cout << rec(a, n);
}




int main() {
	COMinit();
	solv();

	return 0;
}
