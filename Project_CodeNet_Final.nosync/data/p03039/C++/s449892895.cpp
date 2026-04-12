#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <utility>
#include <algorithm>
#include <ctime>
#include <cstdarg>
#include <sstream>
#include <functional>
using namespace std;

int const MAX_N = 512 * 1024;
long long const LL_INF = 5000000000000000000LL;
long long const MODULE = 1000000007LL;

long long x[MAX_N], y[MAX_N];

void calc_every(int n, int m, long long* x) {
	for (int i = 0; i < n; i++) x[i] = 0;
	for (int dd = 0; dd < n; dd++) {
		long long cnt = n - dd;
		if (dd == 0)
			x[dd] = (cnt * ( (m*(m-1LL)/2) % MODULE )) % MODULE;
		else
			x[dd] = (((cnt * m) % MODULE) * m) % MODULE;
	}
	for (int dd = 0; dd < n; dd++) x[dd] = (x[dd] * ((long long)dd)) % MODULE;
}

long long inv[MAX_N], fakt[MAX_N], rev_fakt[MAX_N];

long long mulmod(long long a, long long b) {
	return ((a % MODULE)* (b % MODULE)) % MODULE;
}

long long cnk(long long n, long long k) {
	if (k > n) return 0;
	if (k <= 0) return 1;
	return ((fakt[n] * rev_fakt[n - k]) % MODULE* rev_fakt[k]) % MODULE;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long n, m, k;
	cin >> n >> m >> k;

	calc_every(n, m, x);
	calc_every(m, n, y);

	inv[1] = 1;
	for (int i = 2; i <= n*m; i++) inv[i] = mulmod(inv[MODULE % i], (MODULE - MODULE / i));
	fakt[0] = 1; fakt[1] = 1;
	rev_fakt[0] = 1; rev_fakt[1] = 1;
	for (int i = 2; i <= n*m; i++) {
		fakt[i] = mulmod(fakt[i - 1], i);
		rev_fakt[i] = mulmod(rev_fakt[i - 1], inv[i]);
	}

	long long dg_2 = cnk(n * m - 2, k - 2);

	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans = (ans + (x[i] * dg_2)) % MODULE;
	for (int i = 0; i < m; i++)
		ans = (ans + (y[i] * dg_2)) % MODULE;
	cout << ((ans % MODULE + MODULE) % MODULE);
	return 0;
}
