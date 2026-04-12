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

const int MAX = 510000;
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
	edge(int _t) : t(_t) {}
};
bool use[100010];


vector<edge> te[100010];
vector<edge> fe[100010];
int t[64];
int d[100100];
int n;

void Solve() {
	int h, w;
	cin >> h >> w;
	string t[10];
	for (size_t i = 0; i < h; i++)
	{
		cin >> t[i];
	}

	for (size_t i = 0; i < h - 1; i++)
	{
		for (size_t j = 0; j < w - 1; j++)
		{
			if (t[i + 1][j] == '#' &&
				t[i][j + 1] == '#') {
				cout << "Impossible" << endl;
				return;
			}
		}
	}
	cout << "Possible" << endl;
}


int main() {
	Solve();
	return 0;
}

