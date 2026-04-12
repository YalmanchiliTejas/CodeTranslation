#include <iostream>
#include <cstdio>

using namespace std;

const int N = 200005;

typedef long long LL;

int n, a[N], Lm[N], Rm[N];

LL L[N], R[N], f[N][3];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	if (n % 2 == 0) {
		memset(f, 0xcf, sizeof f);
		f[1][0] = a[1];
		f[2][1] = a[2];
		f[3][0] = a[1] + a[3];
		f[3][2] = a[3];
		for (int i = 4; i <= n; i++) {
			f[i][0] = f[i - 2][0] + a[i];
			f[i][1] = max(f[i - 3][0] + a[i], f[i - 2][1] + a[i]);
			f[i][2] = max(f[i - 3][1] + a[i], max(f[i - 4][0] + a[i], f[i - 2][2] + a[i]));
		}
		printf("%lld\n", max(f[n][1], f[n - 1][0]));
	} else {
		memset(f, 0xcf, sizeof f);
		f[1][0] = a[1];
		f[2][1] = a[2];
		f[3][0] = a[1] + a[3];
		f[3][2] = a[3];
		for (int i = 4; i <= n; i++) {
			f[i][0] = f[i - 2][0] + a[i];
			f[i][1] = max(f[i - 3][0] + a[i], f[i - 2][1] + a[i]);
			f[i][2] = max(f[i - 3][1] + a[i], max(f[i - 4][0] + a[i], f[i - 2][2] + a[i]));
		}
		printf("%lld\n", max(f[n][2], max(f[n - 1][1], f[n - 2][0])));
	}
	return 0;
}