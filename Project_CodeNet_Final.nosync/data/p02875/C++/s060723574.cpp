#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

const int MX = 10000000;

int inv[MX];

int main() {
	int n;
	ignore = scanf("%d", &n);
	
	inv[1] = 1;
	for (int i = 2; i < n; i++) {
		inv[i] = md - (md / i) * 1LL * inv[md % i] % md;
	}
	
	int bad = 0;
	for (int k = 0, c = 1, p = 1; k < n / 2; k++) {
		bad += p * 1LL * c % md;
		bad %= md;
		
		p *= 2;
		p %= md;
		
		c = c * 1LL * (n - k) % md;
		c = c * 1LL * inv[k + 1] % md;
	}
	
	int ans = 1;
	for (int i = 0; i < n; i++) ans = (3LL * ans) % md;
	
	ans = (ans - 2 * bad) % md;
	if (ans < 0) ans += md;
	
	printf("%d\n", ans);
	
	return 0;
}
