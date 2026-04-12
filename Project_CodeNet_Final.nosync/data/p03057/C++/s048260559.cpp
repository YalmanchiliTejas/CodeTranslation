#include <cstdio>
#include <algorithm>

typedef long long LL;
const int Mod = 1000000007;
const int MN = 200005, MM = 200005;

int N, M, K;
char S[MM];
int A[MN], B[MN], Ans;

int main() {
	scanf("%d%d%s", &N, &M, S + 1);
	K = 0x3f3f3f3f;
	int isfirst = 1, len = 0;
	for (int i = 1; i <= M; ++i) {
		if (S[i] != S[1]) {
			if (isfirst || len & 1) K = std::min(K, len / 2 + 1);
			isfirst = len = 0;
		} else ++len;
	}
	if (isfirst) {
		int X1 = 1, X2 = 0;
		for (int i = 1; i <= N; ++i) {
			X2 -= (X2 = X1 + X2) >= Mod ? Mod : 0;
			X1 += (X1 = X2 - X1) < 0 ? Mod : 0;
		}
		printf("%lld\n", (2ll * X1 + X2) % Mod);
		return 0;
	}
	if (N & 1) return puts("0"), 0;
	N /= 2;
	K = std::min(K, N);
	A[0] = B[0] = 1;
	for (int i = 1; i <= N; ++i) {
		A[i] = B[i - 1];
		if (i > K) A[i] += (A[i] -= B[i - K - 1]) < 0 ? Mod : 0;
		B[i] -= (B[i] = B[i - 1] + A[i]) >= Mod ? Mod : 0;
	}
	for (int i = 1; i <= K; ++i)
		Ans = (Ans + 2ll * i * A[N - i]) % Mod;
	printf("%d\n", Ans);
	return 0;
}