#include <bits/stdc++.h>
using namespace std;
#define M 110
#define N 100
#define rep(i, x, y) for(int i = (x); i <= (y); ++ i)
int d[M][M], f[M][M];
int main() {
	cin.tie(0);
	int n, m; cin >> n >> m;
	rep(i, 1, n) rep(j, 1, m) {
		cin >> d[i][j];
	}
	rep(i, 0, N) rep(j, 0, N) {
		f[i][j] = 0;
		rep(k, 1, n) rep(w, 1, m) {
			f[i][j] = max(f[i][j], d[k][w] - i * k - j * w);
		}
	}
	rep(i, 1, n) rep(j, 1, m) {
		int t = 1000;
		rep(k, 0, N) rep(w, 0, N) {
			t = min(t, f[k][w] + i * k + j * w);
		}
		if(t != d[i][j]) {
			puts("Impossible");
			return 0;
		}
	}
	puts("Possible");
	printf("%d %d\n", N + N + 2, N + N + (N + 1) * (N + 1));
	rep(i, 1, N) {
		printf("%d %d X\n", i, i + 1);
		printf("%d %d Y\n", i + 101, i + 102);
	}
	rep(i, 0, N) rep(j, 0, N) {
		printf("%d %d %d\n", i + 1, N + N + 2 - j, f[i][j]);
	}
	printf("1 %d\n", N + N + 2);
	return 0;
}