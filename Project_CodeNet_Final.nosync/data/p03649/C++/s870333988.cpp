#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
int64_t rll() {
	long long n;
	scanf("%lld", &n);
	return n;
}

int64_t solve_gu(int n, int64_t *a) {
	std::priority_queue<int64_t> que;
	for (int i = 0; i < n; i++) que.push(a[i]);
	int64_t cur = 0;
	while (que.top() >= n - cur) {
		int64_t c = que.top();
		int64_t cnt = (c + cur + 1) / (n + 1);
		que.pop();
		que.push(c - (n + 1) * cnt);
		cur += cnt;
	}
	return cur;
}

int main() {
	int n = ri();
	int64_t a[n];
	for (int i = 0; i < n; i++) a[i] = rll();
	std::cout << solve_gu(n, a) << std::endl;
	return 0;
}
