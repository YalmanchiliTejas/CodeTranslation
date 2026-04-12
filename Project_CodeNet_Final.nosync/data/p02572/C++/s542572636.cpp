#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int n;
long long aa, bb;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		long long ta;
		scanf("%lld", &ta);
		aa = (aa + ta) % MOD;
		bb = (bb + ta * ta) % MOD;
	}
	printf("%lld\n", (aa * aa % MOD + MOD - bb) % MOD * ((MOD + 1) / 2) % MOD);
}