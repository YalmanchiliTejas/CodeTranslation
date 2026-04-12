#include <cstdio>
#include <algorithm>

typedef long long LL;
const int Mod = 1000000007;
const int MN = 100005;

inline int qPow(int b, LL e) {
	e = (e % (Mod - 1) + Mod - 1) % (Mod - 1);
	int a = 1;
	for (; e; e >>= 1, b = (LL)b * b % Mod)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}

int N, A[MN];
LL B[MN];
int stk[MN], val[MN], top;
inline bool cmp(int i, int j) { return A[i] < A[j]; }
int f[MN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	A[0] = A[N + 1] = 1;
	for (int i = 1; i <= N; ++i) B[i] = A[i - 1] < A[i] ? A[i] - A[i - 1] : 0;
	for (int i = 1; i <= N; ++i) B[i] += B[i - 1];
	f[0] = 1;
	stk[top = 1] = 0;
	for (int i = 1; i <= N + 1; ++i) {
		f[i] = f[i - 1] * 2 % Mod;
		if (A[i - 1] > A[i]) {
			int p = std::lower_bound(stk + 1, stk + top + 1, i, cmp) - stk;
			f[i] = (f[i] + (LL)qPow(2, B[i - 1] + 1) * (val[top] - val[p] + Mod)) % Mod;
			if (p > 1 && A[i] < A[stk[p]]) f[i] = (f[i] + (LL)qPow(2, B[i - 1] - B[stk[p - 1] + 1] + A[stk[p - 1] + 1] + 1) * (qPow(2, -A[i] + 1) - qPow(2, -A[stk[p]] + 1) + Mod) % Mod * f[stk[p - 1]]) % Mod;
		}
		while (top && A[stk[top]] >= A[i]) --top;
		stk[++top] = i;
		if (top > 1) val[top] = (val[top - 1] + (LL)qPow(2, A[stk[top - 1] + 1] - B[stk[top - 1] + 1] + 1) * (qPow(2, -A[stk[top - 1]]) - qPow(2, -A[stk[top]]) + Mod) % Mod * f[stk[top - 1]]) % Mod;
	}
	printf("%lld\n", (LL)qPow(2, -1) * f[N + 1] % Mod);
	return 0;
}