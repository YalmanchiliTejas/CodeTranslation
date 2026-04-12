#include <cstdio>
using namespace std;
int main(){
	register int n, k, b;
	register long long ans;
	ans = 0;
	scanf("%d %d", &n, &k);
	if (k == 0) {
		printf("%lld", 1ll * n * n);
		return 0;
	}
	for (b = k + 1; b <= n; ++b) {
		ans += n / b * (b - k);
		if (n % b >= k) ans += n % b - k + 1;
	}
	printf("%lld", ans);
	return 0;
}