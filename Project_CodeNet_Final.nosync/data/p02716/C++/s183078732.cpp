#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;
const LL N = 2e5 + 10;
const LL INF = 1e18;
LL a[N], f[N][3][2];
LL n;

void iniv() {
	for (LL i = 0; i <= n; i++) {
		for (LL j = 0; j < 3; j++) {
			for (LL k = 0; k < 2; k++) {
				f[i][j][k] = -INF;
			}
		}
	}
	f[0][0][0] = 0;
}

void dp() {
	for (LL i = 0; i < n; i++) {
		for (LL j = 0; j < 3; j++) {
			for (LL k = 0; k < 2; k++) {
				if (k == 0) f[i + 1][j][1] = max(f[i + 1][j][1], f[i][j][k] + a[i + 1]);

				LL nj = j;
				if (k == 0) nj++;
				if (nj < 3) f[i + 1][nj][0] = max(f[i + 1][nj][0], f[i][j][k]);
			}
		}
	}
}

int main() {
	cin >> n;
	for (LL i = 1; i <= n; i++) cin >> a[i];

	iniv(); dp();

	LL res = (n % 2 ? max(f[n][1][0], f[n][2][1]) : max(f[n][0][0], f[n][1][1]));
	cout << res << endl;

	return 0;
}