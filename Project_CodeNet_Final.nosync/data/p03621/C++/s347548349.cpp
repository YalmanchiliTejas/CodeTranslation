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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll MOD = 998244353;
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

const int N = 10010;
char s[N], p[N];
int n, m, k;
ll dp[2][N];
ll a[N];
ll f[N];
ll rf[N];
ll C[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = mult(f[i - 1], i);

	scanf("%s", s);
	scanf("%s", p);
	m = strlen(s);
	n = k = 0;
	for (int i = 0; i < m; i++) {
		if (s[i] == '0') continue;
		if (p[i] == '1')
			n++;
		else
			k++;
	}

	dp[0][0] = 1;
	if (k == 0)
		a[0] = 1;
	for (int i = 0; i < n + k; i++) {
		for (int j = 0; j <= k; j++)
			dp[1][j] = 0;
		for (int j = 0; j <= k; j++) {
			if (j < k)
				dp[1][j + 1] = add(dp[1][j + 1], dp[0][j]);
			if (i - j < n)
				dp[1][j] = add(dp[1][j], mult(dp[0][j], j));
		}
		for (int j = 0; j <= k; j++)
			dp[0][j] = dp[1][j];
		if (i >= k - 1)
			a[i + 1 - k] = dp[0][k];
	}

	C[0] = 1;
	for (int i = 1; i <= n + k; i++) {
		for (int j = i; j > 0; j--)
			C[j] = add(C[j], C[j - 1]);
	}

	ll ans = 0;
	for (m = 0; m <= n; m++)
		ans = add(ans, mult(a[m], mult(f[n - m], C[n - m])));
	ans = mult(ans, mult(f[n], mult(f[k], f[k])));
	printf("%lld\n", ans);

	return 0;
}
