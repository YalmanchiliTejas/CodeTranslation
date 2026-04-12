#include <stdio.h>
#include <algorithm>

using ll = long long;
using namespace std;
int main() {
	ll n, k, total = 0;
	scanf("%lld %lld", &n, &k);
	
	if (k) {
		for (ll i = k + 1; i <= n; i++)
			total += (n / i) * (i - k) + max(0ll, n % i - k + 1);
	} else {
		total = n * n;
	}

	printf("%lld\n", total);
}