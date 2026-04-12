#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 8, MAX_M = MAX_N * (MAX_N - 1) / 2;

int N, M, a[MAX_M], b[MAX_M];

bool graph[MAX_N][MAX_N];

void solve() {
	for (int i = 0; i < M; i++) {
		graph[a[i] - 1][b[i] - 1] = true;
		graph[b[i] - 1][a[i] - 1] = true;
	}

	int ans = 0, perm[MAX_N - 1];
	for (int i = 0; i < N - 1; i++) {
		perm[i] = i + 1;
	}

	do {
		int pos = 0;
		bool ok = true;

		for (int i = 0; i < N - 1; i++) {
			if (!graph[pos][perm[i]]) {
				ok = false;
			}

			pos = perm[i];
		}

		if (ok) ans++;
	} while (next_permutation(perm, perm + N - 1));

	printf("%d\n", ans);
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}

	solve();
}