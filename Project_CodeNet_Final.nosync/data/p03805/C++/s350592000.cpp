#include <stdio.h>
int n, m, a, b, c, x;
int t[8][8];
int k[8];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		t[a - 1][b - 1]++;
		t[b - 1][a - 1]++;
	}
	for (int i = 0; i < n; i++)k[i] = i;
	a = -1;
	while (1) {
		if (a == -1)goto A;
		a = n - 2;
		while (k[a] > k[a + 1])a--;
		if (!a)break;
		b = a + 1;
		while (b < n && k[b] > k[a])b++;
		c = k[b - 1];
		k[b - 1] = k[a];
		k[a] = c;
		for (int i = a + 1; i < n; i++) {
			if (i < a + n - i) {
				c = k[i];
				k[i] = k[a + n - i];
				k[a + n - i] = c;
			}
		}
		A:
		a = 1;
		for (int i = 0; i < n - 1; i++) {
			if (!t[k[i]][k[i + 1]])a = 0;
		}
		if (a)x++;
	}
	printf("%d\n", x);
}