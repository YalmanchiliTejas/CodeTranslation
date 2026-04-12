#include <cstdio>

typedef long long LL;
const int MN = 3005;

int Mod;

inline int pw(int e, int m = Mod) {
	int b = 2, a = 1;
	for (; e; e >>= 1, b = (LL)b * b % m)
		if (e & 1) a = (LL)a * b % m;
	return a;
}

int N, C[MN][MN], S[MN][MN], Ans;

int main() {
	scanf("%d%d", &N, &Mod);
	for (int i = 0; i <= N; ++i) C[i][0] = 1;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= i; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
	S[0][0] = 1;
	for (int i = 1; i <= N + 1; ++i)
		for (int j = 1; j <= i; ++j)
			S[i][j] = (S[i - 1][j - 1] + (LL)S[i - 1][j] * j) % Mod;
	for (int i = 0; i <= N; ++i) {
		int Sum = 0, C0 = pw(N - i), Coef = 1;
		for (int j = 0; j <= i; ++j)
			Sum = (Sum + (LL)S[i + 1][j + 1] * Coef) % Mod,
			Coef = (LL)Coef * C0 % Mod;
		Sum = (LL)Sum * C[N][i] % Mod * pw(pw(N - i, Mod - 1)) % Mod;
		Ans = (Ans + (i & 1 ? -Sum : Sum)) % Mod;
	}
	printf("%d\n", (Ans + Mod) % Mod);
	return 0;
}