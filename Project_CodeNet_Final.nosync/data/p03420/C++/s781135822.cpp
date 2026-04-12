#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, K, tot;

int main() {
	scanf("%lld%lld", &N, &K);

	for (ll b = 1; b <= N; ++b) {
		for (ll nb = 0; nb <= N; nb += b) {
			tot += max(0LL, min(nb + b - 1, N) - (nb + K) - (nb + K == 0) + 1);
		}
	}

	printf("%lld\n", tot);
}