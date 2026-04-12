#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned uint;
typedef unsigned long long ULL;
using namespace std;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 2005;
int f[MAXN][MAXN * 3][3], a[MAXN][3], arr[MAXN * 3], g[MAXN], n;
int b0[MAXN * 3], b1[MAXN * 3][MAXN], b2[MAXN][3], b3[MAXN][MAXN][3];

void upd(int i) {
	for (int k = 0; k < i * 3 + 2; k++)
	for (int x = 0; x < 3; x++) if (i * 3 - 1 + x != k) {
		int t = f[i][k][x] - g[i];
		chkmax(b0[k], t);
		chkmax(b1[k][a[i][x]], t);
		chkmax(b2[i][x], t);
		chkmax(b3[i][arr[k]][x], t);
	}
}

int main() {
	scanf("%d", &n);
	int c = 0;
	scanf("%d%d", &a[0][1], &a[0][2]);
	arr[c++] = a[0][1], arr[c++] = a[0][2];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++)
			scanf("%d", &a[i][j]), arr[c++] = a[i][j];
		g[i] = g[i - 1] + (a[i][0] == a[i][1] && a[i][0] == a[i][2]);
	}
	scanf("%d", &a[n][0]);
	arr[c++] = a[n][0];
	memset(b0, 0xc0, sizeof(b0));
	memset(b1, 0xc0, sizeof(b1));
	memset(b2, 0xc0, sizeof(b2));
	memset(b3, 0xc0, sizeof(b3));
	
	for (int i = 1; i <= n; i++) {
		upd(i - 1);
		for (int k = 0; k < i * 3 - 1; k++) {
			int e = (k < 2 ? -3 : (k - 2) / 3 * 3) + 2, d = (e + 1) / 3;
			for (int x = 0; x < 3; x++) {
				int a1 = x == 0 ? a[i][1] : a[i][0];
				int a2 = x == 2 ? a[i][1] : a[i][2];
				chkmax(f[i][k][x], b0[k] + g[i - 1]);
				if (a1 == a2) chkmax(f[i][k][x], b1[k][a1] + g[i - 1] + 1);
			}
			for (int x = 0; x < 3; x++) {
				int a1 = x == 0 ? a[i][1] : a[i][0];
				int a2 = x == 2 ? a[i][1] : a[i][2];
				chkmax(f[i][k][x], b2[d][k - e] + g[i - 1]);
				if (a1 == a2) chkmax(f[i][k][x], b3[d][a1][k - e] + g[i - 1] + 1);
			}
		}
		int e = i * 3 - 1;
		for (int x = 0; x < 3; x++) {
			int a1 = x == 0 ? 1 : 0;
			int a2 = x == 2 ? 1 : 2;
			for (int j = 0; j < i; j++)
			for (int y = 0; y < 3; y++) {
				chkmax(f[i][a1 + e][a2], b2[j][y] + g[i - 1]);
				if (a[j][y] == a[i][x]) chkmax(f[i][a1 + e][a2], b3[j][a[i][x]][y] + g[i - 1] + 1);
			}
			f[i][a2 + e][a1] = f[i][a1 + e][a2];
		}
	}
	printf("%d\n", f[n][n * 3][2]);
	return 0;
}