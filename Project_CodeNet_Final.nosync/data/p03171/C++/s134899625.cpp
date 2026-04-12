#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
const long long inf = 1e18;

int n;
int a[N];
long long f[N][N];

long long calc(int l,int r) {
	if (l > r) {
		return 0;
	}
	if (f[l][r] > -inf) {
		return f[l][r];
	}
	if ((l - 1 + n - r) % 2 == 0) {
		long long res = calc(l + 1, r) + a[l];
		res = max(res, calc(l, r - 1) + a[r]);
		return f[l][r] = res;
	} else {
		long long res = calc(l + 1, r) - a[l];
		res = min(res, calc(l, r - 1) - a[r]);
		return f[l][r] = res;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	memset(f, -123, sizeof f);
	printf("%lld\n", calc(1, n));
}