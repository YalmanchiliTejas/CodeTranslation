#include <stdio.h>

typedef long long int ll;
constexpr int kMod = int(1E9 + 7), kN = int(2E5 + 10);

ll a[kN], s[kN];

int main() {
	int n;
	ll ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	s[n] = a[n];
	for (int i = n - 1; i >= 1; i--) s[i] = (s[i + 1] + a[i]) % kMod;
	for (int i = 1; i < n; i++) ans += a[i] * s[i + 1] % kMod;
	printf("%lld\n", ans % kMod);
}
