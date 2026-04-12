#include <cstdio>
const int mod = 1000000007;
char s[10010];
long long dp[110], t[110];
void add(long long &v, long long x) {
	v += x;
	if (v >= mod) v -= mod;
}
int main() {
	int d;
	scanf("%s%d", s, &d);
	int a = 0;
	for (int i = 0; s[i]; i++) {
		s[i] -= '0';
		for (int j = 0; j < d; j++) {
			t[j] = 0;
		}
		for (int k = 0; k < 10; k++) {
			for (int j = 0; j < d; j++) {
				add(t[(j+k)%d], dp[j]);
			}
		}
		for (int k = 0; k < s[i]; k++) {
			add(t[(a+k)%d], 1ll);
		}
		a = (a + s[i]) % d;
		for (int j = 0; j < d; j++) {
			dp[j] = t[j];
		}
	}
	dp[0] += (a == 0) - 1;
	dp[0] = (dp[0] + mod) % mod;
	printf("%lld\n", dp[0]);
	return 0;
}
