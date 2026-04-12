#include <stdio.h>

#define N 100

int main() {
	static char cc[N][N + 1], s[N], aa[N], bb[N];
	int n, m, i, j, k, good;

	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s", cc[i]);
	for (i = 0; i < n; i++) {
		good = 1;
		for (j = 0; j < m; j++)
			if (cc[i][j] != '.') {
				good = 0;
				break;
			}
		aa[i] = good;
	}
	for (j = 0; j < m; j++) {
		good = 1;
		for (i = 0; i < n; i++)
			if (cc[i][j] != '.') {
				good = 0;
				break;
			}
		bb[j] = good;
	}
	for (i = 0; i < n; i++)
		if (!aa[i]) {
			k = 0;
			for (j = 0; j < m; j++)
				if (!bb[j])
					s[k++] = cc[i][j];
			s[k] = '\0';
			printf("%s\n", s);
		}
	return 0;
}
