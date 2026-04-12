#include <stdio.h>
#include <algorithm>

#define LIM_S 200002
#define LIM_N 100001

char str[LIM_S];

int N, K;
char S[LIM_S];

void receive_input() {
	fgets(str, sizeof(str), stdin);
	sscanf(str, "%d", &N);
	fgets(str, sizeof(str), stdin);
	sscanf(str, "%s", S);
	fgets(str, sizeof(str), stdin);
	sscanf(str, "%d", &K);
}

void initialize() {
}

void solve() {
	char c = S[K-1];

	for (size_t i = 0; i < N; i++) {
		printf("%c", (c == S[i]) ? c : '*');
	}
}

int main(void) {
	receive_input();
	initialize();

	solve();

	return 0;
}
