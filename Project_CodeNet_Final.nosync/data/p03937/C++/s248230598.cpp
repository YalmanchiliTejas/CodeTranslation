#include <cstdio>

int N, M, C;

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N * M; ++i) {
		char s[2];
		scanf("%1s", s);
		C += *s == '#';
	}
	puts(C == N + M - 1 ? "Possible" : "Impossible");
	return 0;
}