#include <stdio.h>

#define lli long long int

lli patty[55], panjang[55];

lli dp(lli en, lli ex) {
	if (ex == 0)
		return 0;
	if (ex >= (panjang[en] - en))
		return patty[en];
	if (ex > (panjang[en - 1] + 1))
		return (patty[en - 1] + 1 + dp(en - 1, ex - (panjang[en - 1] + 2)));
	return dp(en - 1, ex - 1);
}

int main() {
	lli n, x, ans;
	scanf("%lld %lld", &n, &x);
	patty[0] = 1;
	panjang[0] = 1;
	for (lli i = 1; i < 51; i++) {
		patty[i] = (2 * patty[i - 1]) + 1;
		panjang[i] = (2 * panjang[i - 1]) + 3;
	}
	ans = dp(n, x);
	printf("%lld\n", ans);
	return 0;
}