#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int N = 3e5 + 7;

int add(int a, int b) {
	return (a + b) % MOD;
}

int sub(int a, int b) {
	return (a - b + MOD) % MOD;
}

int mul(int a, int b) {
	return (a * b) % MOD;
}

int binpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int divv(int a, int b) {
	return mul(a, binpow(b, MOD - 2));
}

int f[N];

void init() {
	f[0] = 1;
	for (int i = 1; i < N; i++) {
		f[i] = mul(f[i - 1], i);
	}
}

int C(int n, int k) {
	return divv(f[n], mul(f[k], f[n - k]));
}

int solve(int n, int m) {
	int ans = 0;
	for (int dl = 1; dl < n; dl++) {
		int cnt = n - dl;
		cnt = mul(cnt, m);
		cnt = mul(cnt, m);
		ans = add(ans, mul(cnt, dl));	
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	init();
	int n, m, k;
	cin >> n >> m >> k;
	int ml = C(n * m - 2, k - 2);
	int sn = solve(n, m) + solve(m, n);
	cout << mul(ml, sn) << endl;
}
