#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, xa[52], ya[52], xb[52], yb[52], xc[102], yc[102], xd[52], yd[52], xe[52], ye[52], f[103][103]; long long d[103][103];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
void rec(int x, int y) {
	f[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (0 <= tx && tx <= 2 * n + 1 && 0 <= ty && ty <= 2 * n + 1) {
			if (d[y][x] == d[ty][tx] && !f[ty][tx]) rec(tx, ty);
		}
	}
}
int main() {
	while (cin >> n, n) {
		for (int i = 0; i < n; i++) {
			cin >> xa[i] >> yb[i] >> xb[i] >> ya[i];
			xc[2 * i] = xa[i], yc[2 * i] = ya[i], xc[2 * i + 1] = xb[i], yc[2 * i + 1] = yb[i];
		}
		sort(xc, xc + 2 * n);
		sort(yc, yc + 2 * n);
		memset(xd, 0, sizeof(xd));
		memset(yd, 0, sizeof(yd));
		memset(xe, 0, sizeof(xe));
		memset(ye, 0, sizeof(ye));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2 * n; j++) {
				if (xa[i] == xc[j] && !xd[i]) xa[i] = j + 1, xd[i] = 1;
				if (ya[i] == yc[j] && !yd[i]) ya[i] = j + 1, yd[i] = 1;
				if (xb[i] == xc[j] && !xe[i]) xb[i] = j + 1, xe[i] = 1;
				if (yb[i] == yc[j] && !ye[i]) yb[i] = j + 1, ye[i] = 1;
			}
		}
		memset(d, 0, sizeof(d));
		memset(f, 0, sizeof(f));
		for (int i = 0; i < n; i++) {
			for (int j = xa[i]; j < xb[i]; j++) {
				for (int k = ya[i]; k < yb[i]; k++) {
					d[j][k] += (1LL << i);
				}
			}
		}
		int ret = 0;
		for (int i = 0; i <= 2 * n + 1; i++) {
			for (int j = 0; j <= 2 * n + 1; j++) {
				if (!f[i][j]) {
					rec(j, i); ret++;
				}
			}
		}
		cout << ret << endl;
	}
}