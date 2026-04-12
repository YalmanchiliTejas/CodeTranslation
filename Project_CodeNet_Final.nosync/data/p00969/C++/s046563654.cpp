#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <algorithm>


static int n;
static int d[5000];


static int u_lookup(int addr, int weight) {
	const int target = d[addr] + weight;
	int b = addr + 1, e = n;
	
	if (b >= n || d[b] > target || d[e - 1] < target) {
		return -1;
	}
	while (b < e) {
		const int m = (b + e) / 2;
		if (d[m] == target) {
			return m;
		}
		
		if (d[m] < target) {
			b = m + 1;
		}
		else {
			e = m;
		}
	}
	return -1;
}


int main(int argc, char* argv[]) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &d[i]);
	}
	std::sort(d, d + n);

	int count_max = 2;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int count = 2;
			int k = j;
			for (;;) {
				k = u_lookup(k, d[j] - d[i]);
				if (k == -1) {
					break;
				}
				++count;
			}
			count_max = std::max(count_max, count);
		}
	}
	printf("%d\n", count_max);

	return EXIT_SUCCESS;
}

