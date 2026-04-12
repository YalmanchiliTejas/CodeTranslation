#include <stdio.h>
#include <algorithm>

#define LIM_S 200002
#define LIM_N 100001

char str[LIM_S];

int N;
int H[LIM_N];

void receive_input() {
	fgets(str, sizeof(str), stdin);
	sscanf(str, "%d", &N);

	for (size_t i = 0; i < N; i++) {
		scanf("%d", &H[i]);
	}
}

void initialize() {
}

int solve() {
	int count = 0;
	int max = H[0];

	for (size_t i = 0; i < N; i++) {
		if (max <= H[i]) {
			count++;
			max = H[i];
		}
	}

	return count;
}

int main(void) {
	receive_input();
	initialize();

	printf("%d\n", solve());

	return 0;
}
