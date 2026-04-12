#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int A, B, a[15][15], b[15][15], c[15][15], d[15][15], g[105][105];
int main() {
	cin >> A >> B;
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < B; j++) {
			cin >> d[i][j];
		}
	}
	bool found = true;
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < B; j++) {
			a[i][j] = -1;
			for (int k = 0; k <= 100; k++) {
				for (int l = 0; l <= 100; l++) {
					int val = (i + 1) * k + (j + 1) * l;
					if (val > d[i][j]) continue;
					int nc = d[i][j] - val; bool flag = false;
					for (int p = 0; p < A; p++) {
						for (int q = 0; q < B; q++) {
							if ((p + 1) * k + (q + 1) * l + nc < d[p][q]) {
								flag = true;
							}
						}
					}
					if (!flag) a[i][j] = k, b[i][j] = l, c[i][j] = nc;
				}
			}
			if (a[i][j] == -1) found = false;
		}
	}
	if (!found) cout << "Impossible" << endl;
	else {
		cout << "Possible" << endl;
		for (int i = 0; i <= 100; i++) {
			for (int j = 0; j <= 100; j++) {
				g[i][j] = inf;
			}
		}
		int xs = 0, ys = 0;
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < B; j++) {
				g[a[i][j]][b[i][j]] = min(g[a[i][j]][b[i][j]], c[i][j]);
				xs = max(xs, a[i][j]);
				ys = max(ys, b[i][j]);
			}
		}
		int cnt = 0;
		for (int i = 0; i <= 100; i++) {
			for (int j = 0; j <= 100; j++) {
				if (g[i][j] != inf) cnt++;
			}
		}
		cout << xs + ys + 2 << " " << xs + ys + cnt << endl;
		for (int i = 0; i < xs; i++) cout << i + 1 << " " << i + 2 << " X\n";
		for (int i = 0; i < ys; i++) cout << xs + i + 3 << " " << xs + i + 2 << " Y\n";
		for (int i = 0; i <= 100; i++) {
			for (int j = 0; j <= 100; j++) {
				if (g[i][j] != inf) {
					cout << i + 1 << " " << xs + j + 2 << " " << g[i][j] << "\n";
				}
			}
		}
		cout << 1 << " " << xs + 2 << "\n";
	}
	return 0;
}