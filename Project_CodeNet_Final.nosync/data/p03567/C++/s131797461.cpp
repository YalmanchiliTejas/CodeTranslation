#pragma once
#include <sstream>
#include <string>
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
#include <numeric>
#include <iomanip>
#define M_PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1000000007;
const int MAX_V = 201;
int now = 0;

const int MAX = 200000;
const int MOD = 1000000007;

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
struct edge {
	int t;
	ll cost;
	edge(int _t, ll _cost) : t(_t)
		, cost(_cost) {
	}
};
bool isPrime(int n) {

	if (n == 1) return false;
	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}
int anyDigitSum(int n) {
	int res = 0;
	while (n > 0)
	{
		res += n % 10;
		n /= 10;
	}
	return res;
}

void Solve() {

	string s;
	cin >> s;
	for (size_t i = 0; i < s.size() - 1; i++)
	{
		if (s[i] == 'A' && s[i + 1] == 'C') {
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No";
	cout << endl;
}
int main() {
	Solve();
	return 0;
}

