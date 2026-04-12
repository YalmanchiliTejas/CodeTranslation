#include <stdio.h>

int main(void) {
	int N;
	int H[20];
	int i,max,cnt=0;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d",&H[i]);
	}

	for (i = 0; i < N; i++) {
		if (i == 0) {
			max = H[i];
			cnt++;
		}
		else {
			if (max <= H[i]) {
				cnt++;
				max = H[i];
			}
		}
	}

	printf("%d", cnt);
}