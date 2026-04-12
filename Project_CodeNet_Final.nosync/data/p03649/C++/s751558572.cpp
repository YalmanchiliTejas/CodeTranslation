#include <algorithm>
#include <stdio.h>

using ll = long long;
using namespace std;
int main() {
	ll n, a[50];
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", a + i);

	ll K = 0;
	while (true) {
		ll Total = 0, time[50];
		for (int i = 0; i < n; i++) {
			time[i] = (max(0ll, a[i] - (n - 1)) + (n - 1)) / n;
			Total += time[i];
		}

		if (!Total)
			break;

		K += Total;
		for (int i = 0; i < n; i++) {
			a[i] -= time[i] * n;
			a[i] += Total - time[i];
		}
	}
	printf("%lld\n", K);
}