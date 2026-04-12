#include <bits/stdc++.h>
#define ll long long
#define mk make_pair
using namespace std;
const int N = 1e5 + 5;
const int mod = 998244353;
const int g = 3;
inline ll Pow(ll a, int x) {
	ll res = 1;
	while (x) {
		if (x & 1) res = res * a % mod;
		a = a * a % mod;
		x >>= 1;
	}
	return res;
}
void NTT(int *a, int n, int rev) {
	for (int i = 0, j = 0; i < n; ++i) {
		if (i > j) swap(a[i], a[j]);
		for (int k = n >> 1; (j ^= k) < k; k >>= 1);
	}	
	for (int i = 2; i <= n; i <<= 1) {
		int m = i >> 1;
		int w = Pow(g, (mod - 1) / i);
		if (rev == -1) w = Pow(w, mod - 2);
		for (int j = 0; j < n; j += i) {
			ll Wx = 1;
			for (int k = 0; k != m; k++) {
				ll z = a[j + m + k] * Wx % mod;
				a[j + m + k] = a[j + k] - z + mod;
				if (a[j + m + k] >= mod) a[j + m + k] -= mod;
				a[j + k] = a[j + k] + z;
				if (a[j + k] >= mod) a[j + k] -= mod;
				Wx = Wx * w % mod;
			}
		}
	}
	if (rev == -1) {
		ll inv = Pow(n, mod - 2);
		for (int i = 0; i < n; i++) a[i] = a[i] * inv % mod;
	}
}
ll fac[N], inv[N];
char A[N], B[N];
int n, a, b, len;
int aa[N], bb[N], cc[N], dd[N];
void solve(int x) {
	if (x == 0) {
		for (int i = 1; i < len; i++) aa[i] = 0;
		aa[0] = 1;
		return;
	}
	if (x == 1) {
		for (int i = 0; i < len; i++) aa[i] = 0; 
		for (int i = 0; i <= a; i++) aa[i] = inv[i + 1];
		return;
	}
	solve(x / 2);
	if (x & 1) {
		for (int i = 0; i < len; i++) bb[i] = 0;
		for (int i = 0; i <= a; i++) bb[i] = inv[i + 1];
		NTT(aa, len, 1);
		NTT(bb, len, 1);
		for (int i = 0; i < len; i++) bb[i] = (ll)bb[i] * aa[i] % mod;
		NTT(bb, len, -1);
		for (int i = a + 1; i < len; i++) bb[i] = 0;
		NTT(bb, len, 1);
		for (int i = 0; i < len; i++) aa[i] = (ll)aa[i] * bb[i] % mod;
		NTT(aa, len, -1);
		for (int i = a + 1; i < len; i++) aa[i] = 0;
	} else {
		NTT(aa, len, 1);
		for (int i = 0; i < len; i++) aa[i] = (ll)aa[i] * aa[i] % mod;
		NTT(aa, len, -1);
		for (int i = a + 1; i < len; i++) aa[i] = 0;
	}
}
int main() {
	fac[0] = 1;
	for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % mod;
	inv[N - 1] = Pow(fac[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % mod;
	scanf("%s", A + 1);
	scanf("%s", B + 1);
	n = strlen(A + 1);
	for (int i = 1; i <= n; i++) {
		if (A[i] == '1' && B[i] == '1') a++;
		if (A[i] == '1' && B[i] == '0') b++;
	}
	len = 1;
	while (len <= 2 * a) len <<= 1;
	solve(b);
	ll ans = 0;
	for (int i = 0; i <= a; i++) {
		ans += (ll)aa[i] * fac[a] % mod;
		ans %= mod;
	}
	ans *= fac[b] * fac[a + b] % mod;
	ans %= mod;
	cout << ans << endl;
} 