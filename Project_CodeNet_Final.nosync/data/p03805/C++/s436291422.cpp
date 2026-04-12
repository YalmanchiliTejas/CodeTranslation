#include <stdio.h>
#include <string.h>
#include <algorithm>

bool road[8][8];
int main()
{
	memset(road, 0, sizeof(bool) * 64);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		road[a - 1][b - 1] = true;
		road[b - 1][a - 1] = true;
	}

	int buf[8];
	for (int i = 0; i < n; i++) {
		buf[i] = i;
	}

	int cnt = 0;
	do {
		bool f = true;
		for (int i = 0; i < n-1; i++) {
			if (!road[buf[i]][buf[i + 1]]) {
				f = false;
				break;
			}
		}
		if (f) {
			cnt++;
		}
	} while (std::next_permutation(&buf[1], &buf[n]));
	printf("%d\n", cnt);
	return 0;
}
