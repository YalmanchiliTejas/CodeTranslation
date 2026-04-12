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

const ll MOD = (ll)1e9 + 7;
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

const int N = 200200;
char s[N];
int n, m;
ll dp[N];

void solve1() {
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 1; i <= n + 1; i++) {
		dp[i] = add(dp[i], dp[i - 1]);
		dp[i + 1] = dp[i - 1];
	}
	ll ans = 1;
	for (int i = 2; i <= n; i++)
		ans = add(ans, mult(i, sub(dp[n - i + 1], dp[n - i])));
	printf("%lld\n", ans);
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	scanf("%s", s);
	bool allEq = true;
	for (int i = 1; i < m; i++)
		allEq &= s[i] == s[0];
	if (allEq) {
		solve1();
		return 0;
	}
	if (n & 1) {
		printf("0\n");
		return 0;
	}
	int b = n;
	int lst = -1;
	for (int i = 0; i < m; i++) {
		if (s[i] == s[0]) continue;
		int x = i - lst - 1;
		if (x % 2 == 0) {
			if (lst == -1) b = min(b, x + 2);
		} else {
			b = min(b, x + 1);
		}
		lst = i;
	}
	b /= 2;
	n /= 2;

	dp[0] = 0;
	dp[1] = 1;
	for (int i = 1; i <= n + 1; i++) {
		dp[i] = add(dp[i], dp[i - 1]);
		dp[i + 1] = sub(dp[i], dp[max(0, i - b)]);
	}
	ll ans = 0;
	for (int i = 1; i <= b; i++)
		ans = add(ans, mult(2 * i, sub(dp[n - i + 1], dp[n - i])));
	printf("%lld\n", ans);

	return 0;
}
