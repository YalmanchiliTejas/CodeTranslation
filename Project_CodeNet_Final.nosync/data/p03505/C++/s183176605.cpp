#include <cstdio>
typedef long long ll;
ll k, a, b;
int main() {
	scanf("%lld%lld%lld", &k, &a, &b);
	k -= a;
	if (k <= 0) printf("1");
	else if (a > b) printf("%lld", (((k - 1) / (a - b) + 1) << 1) + 1);
	else printf("-1");
	return 0;
}