#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

const int maxn = 2e5+10;
long long f[maxn];
long long inv[maxn];

int Pow(int x,int k, int mod) {
	int res = 1;
	while (k) {
		if (k & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		k >>= 1;
	}
	return res;
}

long long get(int n, int m) {
	long long res = 0;
	for(int i=1;i<=n;i++) {
		long long t = 1ll * m * m % mod;
	        long long t1 = 0;
		t1 += 1ll * (n - i + 1) * ( n - i) / 2;
		t1 %= mod;
		res += 1ll * t * t1 % mod;	
		res %= mod;
	}
	return res;
}



long long C(int k, int n) {
	long long res = 0;
	res = 1ll * f[n] * inv[k] % mod;
	res = 1ll * res * inv[n - k] % mod;
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	f[0] = 1;
	inv[0] = 1;
	for(int i=1;i<maxn;i++) {
		f[i] = f[i-1] * i % mod;
		inv[i] = inv[i-1] * Pow(i, mod - 2, mod) % mod;
	}

	int n , m, k;
	cin >> n >> m >> k;
	int t = n * m;

	long long t1 = get(n, m);
	long long t2 = get(m, n);
	long long t3 = C(k-2, t-2);

	cerr << t3 << " " << t1 <<" " << t2 << endl;
	long long res = 1ll * t3 * (t1 + t2) % mod;
	cout << res;
	return 0;
}
