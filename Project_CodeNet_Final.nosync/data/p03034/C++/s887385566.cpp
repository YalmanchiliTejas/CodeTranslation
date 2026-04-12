#include <cstdio>
#include <algorithm>
int readint() {
	char ch = getchar();
	int res = 0; bool f = false;
	if (ch == '-') {
		f = true;
		ch = getchar_unlocked();
	}
	while ('0' <= ch && ch <= '9') {
		res = res * 10 + ch - '0';
		ch = getchar_unlocked();
	}
	if (f) res = -res;
	return res;
}
int main() {
	int A[50176];
	// step #1. read input
	int N = readint();
	int H = (N >> 1);
	for (int i = 0; i < H; ++i) A[i] = readint();
	if (N & 1) readint();
	for (int i = H - 1; i >= 0; --i) A[i] += readint();
	// step #2. calculate the answer
	long long ans = 0;
	for (int i = 1; i < N; ++i) {
		long long sum = 0;
		int pos = i;
		while (pos < H) {
			sum += A[pos];
			ans = std::max(ans, sum);
			pos += i;
		}
		if ((N - 1) % i != 0) {
			pos = (N - 1) - pos;
			while (pos >= i) {
				sum += A[pos];
				ans = std::max(ans, sum);
				pos -= i;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}