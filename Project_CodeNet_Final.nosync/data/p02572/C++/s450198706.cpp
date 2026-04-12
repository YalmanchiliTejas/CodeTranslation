#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int a[200005];
long long ps[200005];

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	for (int i = 0; i < n; i++) {
		ps[i] = a[i];
		if (i - 1 >= 0) ps[i] = (ps[i] + ps[i - 1]) % MOD;
	}
	
	long long res = 0;
	
	for (int i = n - 1; i > 0; i--) {
		res = (res + 1LL * a[i] * ps[i - 1]) % MOD;
	}
	
	printf("%lld\n", res);
}
