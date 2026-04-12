#include <cstdio>

#define N 123

int a[11][11];
int d[N + 1][N + 1];

int main() {
	int i, j, k, l, m, n, t;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) scanf("%d", &a[i][j]);
	for (i = 0; i <= N; i++) for (j = 0; j <= N; j++) {
		t = 0;
		for (k = 1; k <= n; k++) for (l = 1; l <= m; l++) {
			if (a[k][l] - i * k - j * l >= t) {
				t = a[k][l] - i * k - j * l;
			}
		}
		d[i][j] = t;
	}
	for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) {
		t = 999;
		for (k = 0; k <= N; k++) for (l = 0; l <= N; l++) {
			if (d[k][l] + i * k + j * l <= t) {
				t = d[k][l] + i * k + j * l;
			}
		}
		if (t != a[i][j]) {
			puts("Impossible");
			return 0;
		}
	}
	puts("Possible");
	printf("%d %d\n", (N + 1) * 2, N * 2 + (N + 1) * (N + 1));
	for (i = 0; i < N; i++) {
		printf("%d %d X\n", i + 1, i + 2);
		printf("%d %d Y\n", N + N + 1 - i, N + N + 2 - i);
	}
	for (i = 0; i <= N; i++) for (j = 0; j <= N; j++) printf("%d %d %d\n", i + 1, N + N + 2 - j, d[i][j]);
	printf("1 %d\n", N + N + 2);
	return 0;
}
