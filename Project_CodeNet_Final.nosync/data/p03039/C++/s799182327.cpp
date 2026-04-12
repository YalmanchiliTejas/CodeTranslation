#include <algorithm>
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7, MAXN = 2e5 + 10;
long long ans, k, fi[MAXN], f[MAXN];
int n, m;
long long ch(long long a, long long b) {
	return f[a] * fi[a - b] % MOD * fi[b] % MOD;
}

int main() {
	cin >> n >> m >> k;
	fi[1] = 1;
	for (int i = 2; i < MAXN; i++)
		fi[i] = -(MOD / i) * fi[MOD % i] % MOD;
	fi[0] = f[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fi[i] *= fi[i - 1], fi[i] %= MOD;
		f[i] = f[i - 1] * i % MOD;
	}
	long long sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			sum += i + j;
	for (int i = 0; i < n; i++) {
		long long bf = sum;
		for (int j = 0; j < m; j++) {
			ans += ch(n * m - 2, k - 2) * (sum % MOD) % MOD;
			ans %= MOD;
			sum += -(m - 1 - j) * n + (j + 1) * n;
		}
		sum = bf;
		sum += -(n - 1 - i) * m + (i + 1) * m;
	}
	ans *= fi[2], ans %= MOD;
	if (ans < 0)
		ans += MOD;
	cout << ans;
}