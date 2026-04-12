#include <stdio.h>

int main() {
	int n, maxi = 0, h, ans = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &h);
		if (h >= maxi) {
			ans++;
			maxi = h;
		}
	}
	printf("%d\n", ans);
	return 0;
}