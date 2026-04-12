#include <bits/stdc++.h>
using namespace std;

inline int inv(int a, int m) {
	int i = 1, j = 0;
	for (int b = m; a > 1; swap(i, j), swap(a, b)) {
		j = (j + b / a * long(m - i)) % m;
		b %= a;
	}
	return i;
}
long f[222222] = { 1 };
int main() {
	int n, m, k, p = 1e9 + 7;
	cin >> n >> m >> k;
	for (int i = 0; i < n*m; i++)
		f[i + 1] = (i + 1)*f[i] % p;
	long a = inv(f[n*m - k] * f[k] % p, p)*f[n*m] % p;
	long b = inv(6, p)*long(k - 1) % p;
	(b *= k) %= p;
	cout << (a*(m + n) % p)*b%p << endl;
	return 0;
}
