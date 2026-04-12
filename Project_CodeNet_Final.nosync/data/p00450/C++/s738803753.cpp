#include "stdio.h"

int N;
int flag[100000] = {};
int ans;

int main() {
	
	scanf("%d", &N);
	while (N != 0) {
		ans = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &flag[i]);
			if (i % 2 == 1) {
				for (int j = i - 1; j >= 0; j--) {
					if (flag[j] == flag[i])break;
					flag[j] = flag[i];
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (flag[i] == 0)ans++;
		}
		printf("%d\n", ans);
		scanf("%d", &N);
	}

	return 0;
}