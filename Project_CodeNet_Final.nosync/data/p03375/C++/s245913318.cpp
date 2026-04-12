#include <bits/stdc++.h>
#define int long long

const int N = 5001;
int n, mo;
int C[N][N], S[N][N];

int qp(int x, int y, int mod) {
	int res = 1;
	while (y) {
		if (y & 1) (res *= x) %= mod;
		y >>= 1;
		(x *= x) %= mod;
	}
	return res;
}

signed main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	std::cin >> n >> mo;
	for (int i = 0; i <= n; ++ i) {
		C[i][0] = 1, S[i][0] = 1;
		for (int j = 1; j <= i; ++ j) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mo;
			S[i][j] = (S[i - 1][j - 1] + (j + 1) * (S[i - 1][j]) % mo) % mo;
		}
	}
//	std::cerr << "Yuno" << '\n';
	int ans = 0;
	for (int i = 0; i <= n; ++ i) {
		int A = qp(2, qp(2, n - i, mo - 1), mo);
//		std::cerr << "Yuno\n";
		int B = C[n][i];
		int res = 1, base = qp(2, n - i, mo), sum = 0;
		for (int j = 0; j <= i; ++ j) {
//			std::cerr << j << '\n';
			(sum += S[i][j] * res % mo) %= mo;
			(res *= base) %= mo;
		}
		if (!(i & 1)) (ans += A * B % mo * sum % mo) %= mo;
		else ans = (ans - A * B % mo * sum % mo + mo) % mo;
//		std::cerr << i << ' ' << ans << '\n';
	}
	std::cout << ans << '\n';
	return 0;
}