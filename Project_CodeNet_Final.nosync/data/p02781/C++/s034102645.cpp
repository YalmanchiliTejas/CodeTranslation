#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

const int MAXN = 100;

int Pow(int x, int y) {
	int ret = 1;
	for (int i = 1; i <= y; i++)
		ret *= x;
	return ret;
}

int C(int n, int m) {
	if (m < 0) return 0;
	if (m == 0) return 1;
	if (m == 1) return n;
	if (m == 2) return std::max(n * (n - 1) / 2, 0);
	if (m == 3) return std::max(n * (n - 1) * (n - 2) / 6, 0);
}

char S[MAXN + 5];

int main() {
	scanf("%s", S + 1);
	int K; scanf("%d", &K);
	int cnt = strlen(S + 1), B = 0, Z = 0;
	for (int i = 1; i <= cnt; i++) {
		int x = S[i] - '0';
		B += (9 - x) * C(cnt - i, K - i + Z) * Pow(9, K - i + Z);
		if (!x)
			Z++;
	}
	int A = C(cnt, K) * Pow(9, K);
	printf("%d", std::max(A - B, 0));
	return 0;
}