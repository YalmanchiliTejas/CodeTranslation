#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
const long long mod = 1000000007;

long long fact[maxn];

long long add_mod (long long a, long long b) {
	return (a + b) % mod;
}

long long mul_mod (long long a, long long b) {
	return (a * b) % mod;
}

long long sub_mod (long long a, long long b) {
	return (a + mod - b) % mod;
}

long long pow_mod (long long a, long long b) {
	long long res = 1, t = a;
	while (b) {
		if (b & 1)
			res = mul_mod(res, t);
		t = mul_mod(t, t);
		b >>= 1;
	}
	return res;
}

long long div_mod (long long a, long long b) {
	return mul_mod(a, pow_mod(b, mod - 2));
}

long long ncr_mod (int n, int r) {
	return div_mod(fact[n], mul_mod(fact[n - r], fact[r]));
}

void precalc () {
	fact[0] = 1LL;
	for (long long i = 1; i < maxn; ++i)
		fact[i] = mul_mod(fact[i - 1], i);
}

signed main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	precalc();
	long long n, m, k;
	cin >> n >> m >> k;
	long long ans = 0LL;
	for (long long dx = 0LL; dx < m; ++dx) 
		ans = add_mod(ans, mul_mod(mul_mod(dx, mul_mod((m - dx) * n, n)), ncr_mod(n * m - 2, k - 2)));
	for (long long dy = 0LL; dy < n; ++dy) 
		ans = add_mod(ans, mul_mod(mul_mod(dy, mul_mod((n - dy) * m, m)), ncr_mod(n * m - 2, k - 2)));
	cout << ans << '\n';
}
