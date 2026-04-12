#include <bits/stdc++.h>
using namespace std;

const int N = 3010;

typedef long long LL;

int mod;

inline int Pow(int x, int y, int mod = mod) {
	int res = 1;
	for (; y; y >>= 1, x = (LL)x * x % mod) if (y & 1) res = (LL)res * x % mod;
	return res; 
}

int S[N][N], C[N][N];

inline void init(int n) {
	S[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) 
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
	for (int i = 1; i <= n; i++) {
		S[i][1] = 1;
		for (int j = 1; j <= i; j++)
			S[i][j] = (S[i - 1][j - 1] + (LL)S[i - 1][j] * j) % mod;
	}
}

int main() {
	int n, res = 0; cin >> n >> mod, init(n + 1);
	for (int i = 0; i <= n; i++) {
		int other = Pow(2, Pow(2, n - i, mod - 1)), tmp = (LL)C[n][i] * other % mod, base = Pow(2, n - i);
		for (int j = 1, t = base; j <= i; j++) {
			tmp = (tmp + (LL)C[n][i] * t % mod * other % mod * S[i + 1][j + 1]) % mod;
			t = (LL)t * base % mod;
		}
		if (i & 1) res = (res - tmp + mod) % mod;
		else res = (res + tmp) % mod;
	}
	cout << res << endl;
}