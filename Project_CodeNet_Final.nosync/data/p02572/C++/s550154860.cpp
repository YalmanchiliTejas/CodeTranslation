#include <cstdio>

const int N = 2e5 + 5;
const long long MOD = 1e9 + 7;

int a[N];

int main() {
	int n;
	std::scanf("%d", &n);
	for(int i = 1; i <= n; i++) std::scanf("%d", &a[i]);
	long long sum = 0, ans = 0;
	for(int i = n; i >= 1; i--) {
		ans = (ans + a[i] * sum % MOD) % MOD;
		sum = (sum + a[i]) % MOD; 
	}
	std::printf("%lld\n", ans);
	return 0;
}