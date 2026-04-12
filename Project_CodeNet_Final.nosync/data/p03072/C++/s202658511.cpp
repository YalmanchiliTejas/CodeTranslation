#include <stdio.h>

int main() {
	int a;
	int b[20];
	int answer = 0;

	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d", &b[i]);
	}

	int max = 0;
	for (int i = 0; i < a; i++) {
		if (b[i] >= max) {
			answer++;
			max = b[i];
		}
	}
	printf("%d", answer);
}