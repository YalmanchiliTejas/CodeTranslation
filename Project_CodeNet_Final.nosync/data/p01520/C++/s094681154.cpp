#include <cstdio>

using namespace std;

int main() {
	int N, T, E;
	scanf("%d %d %d", &N, &T, &E);
	int X[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &X[i]);
	}
	bool found = false;
	for (int i = T - E; i <= T + E; i++) {
		for (int j = 0; j < N; j++) {
			if (i % X[j] == 0) {
				printf("%d\n", j+1);
				found = true;
				goto end;
			}
		}
	}
end:
	if (!found) {
		printf("-1\n");
	}
	return 0;
}