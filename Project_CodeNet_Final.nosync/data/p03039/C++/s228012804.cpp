#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, k;
constexpr ll mod = 1e9 + 7;
ll fact[300000], finv[300000], inv[300000];
void init() {
	fact[0] = fact[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i <= n * m; i++) {
		fact[i] = fact[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}
ll ncr(ll n, ll r) {
	if (n == 0)
		return 1;
	if (k == 0)
		return n;
	return fact[n] * (finv[r] * finv[n - r] % mod) % mod;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	init();

	ll sum = 0;
	for (int i = 1; i < n; i++) {
		sum += ncr(n * m - 2, k - 2) * (n - i) % mod * m % mod * m % mod * i % mod;
		sum %= mod;
	}
	for (int i = 1; i < m; i++) {
		sum += ncr(n * m - 2, k - 2) * (m - i) % mod * n % mod * n % mod * i % mod;
		sum %= mod;
	}
	printf("%lld\n", sum);
}