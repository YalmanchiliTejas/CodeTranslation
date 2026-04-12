#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const long long mod = 998244353;
int N, S, A[3000];
long long dptable[3000][3001];
long long dp(int i, int j) {
	if (j < 0) return 0;
	if (j == 0) return N - i + 1;
	if (i == N) return 0;
	if (dptable[i][j] != -1) return dptable[i][j];
	return (dptable[i][j] = dp(i + 1, j) + dp(i + 1, j - A[i])) % mod;
}
int main() {
	memset(dptable, -1, sizeof dptable);
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
	long long ans = 0;
	for (int i = 0; i < N; ++i) ans = (ans + dp(i, S)) % mod;
	printf("%lld", ans);
	return 0;
}