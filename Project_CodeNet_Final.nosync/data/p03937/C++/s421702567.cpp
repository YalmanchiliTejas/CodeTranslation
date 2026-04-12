#include<stdio.h>
int M[12][12];
int main() {
	int n, m, i, j; scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)for (j = 1; j <= m; j++) {
		char x; scanf(" %c", &x);
		M[i][j] = x == '#';
	}
	for (i = 1; i <= n; i++)for (j = 1; j <= m; j++)if (M[i][j] && M[i + 1][j] && M[i][j + 1]) { printf("Impossible"); return 0; }
	for (i = 1; i <= n; i++)for (j = 1; j <= m; j++)if (M[i][j] && M[i - 1][j] && M[i][j - 1]) { printf("Impossible"); return 0; }
	printf("Possible");
	return 0;
}