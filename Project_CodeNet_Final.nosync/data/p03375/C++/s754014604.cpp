#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll MOD;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}

const int N = 3020;
int n;
ll C[N][N];
ll D[N][N];
ll p2[N * N];
ll pp2[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &MOD);

	for (int i = 0; i < N; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 1; i < N; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	p2[0] = 1;
	for (int i = 1; i < N * N; i++)
		p2[i] = add(p2[i - 1], p2[i - 1]);
	pp2[0] = 2;
	for (int i = 1; i < N; i++)
		pp2[i] = mult(pp2[i - 1], pp2[i - 1]);

	D[0][0] = 1;
	for (int i = 0; i < N - 2; i++)
		for (int j = 0; j <= i; j++) {
			D[i + 1][j] = add(D[i + 1][j], mult(D[i][j], j));
			D[i + 1][j + 1] = add(D[i + 1][j + 1], D[i][j]);
		}

	ll ans = 0;
	for (int k = 0; k <= n; k++) {
		ll res = 0;
		for (int p = 0; p <= k; p++) {
			ll cur = add(D[k][p], mult(D[k][p + 1], p + 1));
			res = add(res, mult(cur, p2[p * (n - k)]));
		}
		res = mult(res, pp2[n - k]);
		res = mult(res, C[n][k]);
		if (k & 1)
			ans = sub(ans, res);
		else
			ans = add(ans, res);
	}
	printf("%lld\n", ans);

	return 0;
}
