#include<stdio.h>
int main(void) {
	int n, h[40];
	int i, j, k;
	int ans = 1;
	int flg = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	for (i = 1; i < n; i++) {
		flg = 0;
		for (j = 0; j < i; j++) {
			if (!(h[j] <= h[i])) {
				flg = 1;
				break;
			}
		}
		if (flg == 0) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
