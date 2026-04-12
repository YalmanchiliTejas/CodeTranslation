#include <stdio.h>

int main() {
	int n, a, pos, left, right, mid, ans[100010], size = 1;
	scanf("%d %d", &n, &a);
	ans[0] = a;
	for (int i = 1; i < n; i++) {
		scanf("%d", &a);
		if (ans[size - 1] >= a)
			ans[size++] = a;
		else {
			left = 0;
			right = size - 1;
			while (left <= right) {
				mid = (left + right) / 2;
				if (ans[mid] < a) {
					pos = mid;
					right = mid - 1;
				}
				else
					left = mid + 1;
			}
			ans[pos] = a;
		}
	}
	printf("%d\n", size);
	return 0;
}
