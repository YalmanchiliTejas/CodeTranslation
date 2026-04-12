#include<stdio.h>
int main(void) {
	int n, cnt = 1, t = 0;
	scanf("%d", &n);
	int* h = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	for (int i = 1; i < n; i++) {
		t = 0;
		for (int j = 0; j < i; j++) {
			if (h[j] > h[i])t = 1;
		}
		if (t == 0)cnt++;
	}
	printf("%d", cnt);
}