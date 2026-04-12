/*
May the God who gives endurance and encouragement give you the same attitude of mind toward each other that Christ Jesus had,
so that with one mind and one voice you may glorify the God and Father of our Lord Jesus Christ.
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int N = (int)1e3+5;
const ll base = (ll)1e9+7;
int n, a, b, c, d;
ll P[N][N], fact[N], dp[N][N];
ll inv_fact_pw[N][N], inv_fact[N];

ll fast_pw(ll x, ll y) {
	if (y == 0) return 1;
	if (y == 1) return x;
	ll tmp = fast_pw(x, y / 2ll);
	tmp = (tmp * tmp) % base;
	if (y % 2ll) tmp = (tmp * x) % base;
	return tmp;
}

void init() {
	fact[0] = inv_fact[0] = 1;
	for (int i = 0; i <= n; ++i) {
		P[i][i] = P[i][0] = 1;
		if (i > 0) {
			fact[i] = fact[i - 1] * (ll)i % base;
			inv_fact[i] = inv_fact[i - 1] * fast_pw(i, base - 2) % base;
		}
		inv_fact_pw[i][0] = 1;
		for (int j = 1; j <= n; ++j)
			inv_fact_pw[i][j] = inv_fact_pw[i][j - 1] * fast_pw(fact[i], base - 2) % base;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			P[i][j] = (P[i - 1][j] + P[i - 1][j - 1]) % base;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= i; ++j)
			P[i][j] = (P[i][j] * fact[j]) % base;
}

ll solve(int i, int j) {
	if (i == a - 1) return j == 0;
	if (dp[i][j] != -1) return dp[i][j];
	ll &ret = dp[i][j];
	ret = solve(i - 1, j);
	for (int k = c; k <= d; ++k) if (k * i <= j) {
		ll tmp = solve(i - 1, j - k*i);
		tmp = tmp * P[n - j + k * i][k * i] % base;
		tmp = tmp * inv_fact_pw[i][k] % base;
		tmp = tmp * inv_fact[k] % base;
		ret = (ret + tmp) % base;
	}
	return ret;
}

int main() {
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	init();
	memset(dp, -1, sizeof(dp));
	printf("%lld", solve(b, n));
	return 0;
}
