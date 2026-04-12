#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
template <typename Int, Int MOD, int N>
struct comb_util {
	std::array<Int, N + 1> fc, ifc;

	comb_util() {
		fc[0] = 1;
		for (int i = 1; i <= N; i++) fc[i] = fc[i - 1] * i % MOD;
		ifc[N] = inv(fc[N]);
		for (int i = N - 1; i >= 0; i--) ifc[i] = ifc[i + 1] * (i + 1) % MOD;
	}

	Int fact(Int n) { return fc[n]; }

	Int inv_fact(Int n) { return ifc[n]; }

	Int inv(Int n) { return pow(n, MOD - 2); }

	Int pow(Int n, Int a) {
		Int res = 1, exp = n;
		for (; a; a /= 2) {
			if (a & 1) res = res * exp % MOD;
			exp = exp * exp % MOD;
		}
		return res;
	}

	Int perm(Int n, Int r) {
		if (r < 0 || n < r)
			return 0;
		else
			return fc[n] * ifc[n - r] % MOD;
	}

	Int binom(Int n, Int r) {
		if (n < 0 || r < 0 || n < r) return 0;
		return fc[n] * ifc[r] % MOD * ifc[n - r] % MOD;
	}

	Int homo(Int n, Int r) {
		if (n < 0 || r < 0) return 0;
		return r == 0 ? 1 : binom(n + r - 1, r);
	}
};

using comb = comb_util<long long, 1000000007, 300000>;
comb cb;
int add(int &a, const int &b) {
	a += b;
	if (a >= MOD)a -= MOD;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M, K;
	cin >> N >> M >> K;
	int coef = cb.binom(N*M - 2, K - 2);
	int sum = 0;

	int tmp = 0;
	for (int i = 1; i < N; i++) {
		add(tmp, (i * (N - i)) % MOD);
	}
	tmp = (((tmp * M) % MOD)*M) % MOD;
	add(sum, tmp);

	tmp = 0;
	for (int i = 1; i < M; i++) {
		add(tmp, (i * (M - i)) % MOD);
	}
	tmp = (((tmp * N) % MOD)*N) % MOD;
	add(sum, tmp);

	int res = (sum * coef) % MOD;



	cout << res << endl;
}