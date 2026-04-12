#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
const long long mod = 1000000007;

int search(int *d, int t, int n) {
	int r = 0;
	for (int i = 20; i >= 0; i--) {
		int c = r + (1 << i);
		if (c >= n)continue;
		if (d[c] >= t)r = c;
	}
	if (r == 0) {
		if (d[0] >= t)return 1;
		else return 0;
	}
	else {
		return r + 1;
	}
}

int main() {
	int N;
	scanf("%d", &N);
	int *A = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", A + i);
	}
	std::vector<int> c;
	c.push_back(A[0]);
	for (int i = 1; i < N; i++) {
		int r = search(c.data(), A[i], c.size());
		if (r >= c.size()) {
			c.push_back(A[i]);
		}
		else {
			c[r] = A[i];
		}
	}
	printf("%d", c.size());
	return 0;
}