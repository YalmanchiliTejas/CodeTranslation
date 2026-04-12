#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>

using namespace std;

using VL = vector<long long>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;

using VB = vector<bool>;
using VVB = vector<VB>;
using VVVB = vector<VVB>;

int n;
VL a;
VVL memo;
VVB checked;

long long dfs(int a_idx, int head) {
// printf("%d %d\n", a_idx, head);
	if (a_idx == n) {
		return 0;
	} else if (checked[a_idx][head]) {
		return memo[a_idx][head];
	}

	int rest = n - 1 - a_idx;
	int tail = head + rest;

// printf("head %d, tail %d\n", head, tail);

	// 前をとる
	auto val1 = dfs(a_idx+1, head+1);
	// 後ろをとる
	auto val2 = dfs(a_idx+1, head);

	if (a_idx % 2 == 0) {
		// 先手 aを足して最大化
		memo[a_idx][head] = max(val1 + a[head], val2 + a[tail]);
	} else {
		// 後手 aを引いて最小化
		memo[a_idx][head] = min(val1 - a[head], val2 - a[tail]);
	}

	checked[a_idx][head] = true;
	return memo[a_idx][head];
}


int main() {
	cin >> n;

	a.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	memo.assign(n + 1, VL(n + 1, 0));
	checked.assign(n + 1, VB(n + 1, false));

	auto ans = dfs(0, 0);
	cout << ans << endl;
	return 0;
}
