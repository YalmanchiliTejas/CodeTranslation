#include <stdio.h>
#include <algorithm>
#include <climits>

long long input[200010];
long long dp[3][200010];
bool check[3][200010];
int n;

long long func(int left, int x) {
	if (x > n) {
		if (left <= 1)
			return 0;
		return LLONG_MIN / 2;
	}
	if (check[left][x] == true)
		return dp[left][x];

	check[left][x] = true;
	dp[left][x] = func(left, x + 2) + input[x];

	if (left > 0) {
		dp[left][x] = std::max(dp[left][x], func(left - 1, x + 1));
	}

	return dp[left][x];
}

int main(void) {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%lld", input + i);

	if (n % 2 == 0)
		printf("%lld\n", func(1, 1));
	else
		printf("%lld\n", func(2, 1));
}