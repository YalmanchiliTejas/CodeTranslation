#include <cstdio>

typedef long long LL;
const int Mod = 1000000007, Phi = Mod - 1, Inv2 = (Mod + 1) / 2;
const int MN = 105;

inline LL pw(LL e) {
	e = (e % Phi + Phi) % Phi;
	LL b = 2, a = 1;
	for (; e; e >>= 1, b = b * b % Mod)
		if (e & 1) a = a * b % Mod;
	return a;
}

int N, A[MN];
int stk[MN], tp;
LL B[MN], dp[MN];

inline void Add(int i, LL x) {
	dp[i] = (dp[i] + x) % Mod;
}

int main() {
	scanf("%d", &N), A[0] = A[N + 1] = 1, B[0] = 1;
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
		B[i] = B[i - 1] + (A[i] > A[i - 1] ? A[i] - A[i - 1] : 0);
	}
	dp[0] = 1, stk[tp = 1] = 0;
	for (int i = 1; i <= N + 1; ++i) {
		while (tp && A[stk[tp]] >= A[i]) {
			int j = stk[tp];
			if (j != i - 1) {
				int k = stk[tp + 1];
				LL num2 = B[i - 1] - B[j];
				LL num1 = num2 - (A[k] - A[j]);
				Add(i, 4 * (pw(num2) - pw(num1)) * dp[j]);
			} else Add(i, 2 * dp[j]);
			--tp;
		}
		if (tp) {
			int j = stk[tp];
			if (j != i - 1) {
				int k = stk[tp + 1];
				if (A[k] != A[i]) {
					LL num2 = B[i - 1] - B[j] - (A[i] - A[j]);
					LL num1 = num2 - (A[k] - A[i]);
					Add(i, 4 * (pw(num2) - pw(num1)) * dp[j]);
				}
			} else Add(i, 2 * dp[j]);
		}
		stk[++tp] = i;
	}
	printf("%lld\n", (dp[N + 1] + Mod) * Inv2 % Mod);
	return 0;
}