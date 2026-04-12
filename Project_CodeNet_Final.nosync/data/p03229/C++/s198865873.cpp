#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	int a[n];
	for (auto &i : a) i = ri();
	std::sort(a, a + n);
	
	int64_t res = 0;
	if (!(n & 1)) {
		int half = n / 2;
		int cnt = 0;
		for (int i = 0; i + 1 < n; i++) {
			if (i < half - 1) cnt += 2;
			else if (i < half) cnt++;
			else if (i < half + 1) cnt--;
			else cnt -= 2;
			res += (int64_t) (a[i + 1] - a[i]) * cnt;
		}
	} else {
		int half = n / 2;
		for (int i = 0; i < 2; i++) {
			int64_t cur_res = 0;
			int cnt = 0;
			for (int j = 0; j + 1 < n; j++) {
				if (j < half - i) cnt += 2;
				else if (j < half - i + 2) cnt += i ? 1 : -1;
				else cnt -= 2;
				cur_res += (int64_t) (a[j + 1] - a[j]) * cnt;
			}
			res = std::max(res, cur_res);
		}
	}
	printf("%" PRId64 "\n", res);
	return 0;
}
