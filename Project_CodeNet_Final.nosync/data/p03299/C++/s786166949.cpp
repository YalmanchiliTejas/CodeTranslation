#include <bits/stdc++.h>

using namespace std;

const int _INT_MAX_ = 0x3fffffff;

const int MOD = int(1e9) + 7;

int fpow(int base, int exp) {
	int result = 1;
	for (; exp; exp >>= 1) {
		if (exp & 1)
			result = (long long)result * base % MOD;
		base = (long long)base * base % MOD;
	}
	return result;
}

int n, h[110];

pair<int, int> solve(int l, int r, int limit) {
	int min_height = _INT_MAX_;
	for (int i = l; i < r; ++i) {
		min_height = min(min_height, h[i]);
	}
	
	pair<int, int> result = {2, 1};
	int tot = -1;
	for (int i = l; i <= r; ++i) {
		if (i == r || min_height == h[i]) {
			++tot;
			if (i > l) {
				pair<int, int> tmp = solve(l, i, min_height);
				result.first = (long long)result.first * tmp.first % MOD;
				result.second =
					(long long)result.second * (tmp.first + tmp.second) % MOD;
			}
			l = i + 1;
		}
	}
	
	result.second = (long long)result.second * fpow(2, tot) % MOD;
	result.second = (result.second - result.first + MOD) % MOD;
	result.first = (long long)result.first * fpow(2, min_height - limit - 1) % MOD;
	result.second = (result.first + result.second) % MOD;
	return result;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &h[i]);
	}
	pair<int, int> ans = solve(0, n, 0);
	printf("%d\n", ans.second);
}