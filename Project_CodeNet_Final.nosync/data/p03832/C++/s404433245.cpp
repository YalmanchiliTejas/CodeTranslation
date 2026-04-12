#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int N, A, B, C, D;
long long FACT[1024];
long long fact(int n) {
	return FACT[n];
}
long long inv(int n) {
	long long r = 1, x = n;
	int m = 1000000005;
	while (m) {
		if (m&1) (r *= x) %= mod;
		m>>=1;
		(x *= x) %= mod;
	}
	return r;
}
long long comb(int n, int m) {
	long long r = fact(n) * inv(fact(m)) % mod * inv(fact(n-m)) % mod;
	return r;
}
long long memo_f[1024][1024];
bool visited_f[1024][1024];
long long f(int n, int m) {
	if (m > B) return n == 0 ? 1 : 0;
	if (visited_f[n][m]) return memo_f[n][m];
	visited_f[n][m] = true;
	long long r = f(n, m+1);
	long long rr = 1;
	for (int i = 0; i <= D && n-i*m >= 0; ++ i) {
		if (i >= C) {
			(r += f(n-i*m, m+1) * rr % mod) %= mod;
		}
		if (n-i*m < m) break;
		(rr *= comb(n-i*m, m)) %= mod;
		(rr *= inv(i+1)) %= mod;
	}
	return memo_f[n][m] = r;
}
int main() {
	FACT[0] = 1;
	for (int i = 1; i < 1024; ++ i) FACT[i] = i * FACT[i-1] % mod;
	cin >> N >> A >> B >> C >> D;
	cout << f(N, A) << endl;
}
