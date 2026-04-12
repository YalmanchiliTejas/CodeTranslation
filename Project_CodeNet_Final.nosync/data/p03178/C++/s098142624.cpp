#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <assert.h>
using namespace std;
const int MOD = 1e9 + 7;
int n, d, dp[10000][100][2];
char k[10001];
int calc(int i, int sum, int less) {
	if (i == n) return sum == 0;
	if (dp[i][sum][less] != -1) return dp[i][sum][less];
	int res = 0;
	for (int j = 0; j <= ((less == 1) ? 9 : (k[i] - '0')); j++) {
		res = (res + calc(i + 1, (sum + j) % d, max(less, (j < k[i] - '0') ? 1 : 0))) % MOD;
	}
	return dp[i][sum][less] = res;
}
int main() {
	scanf("%s %d", k, &d);
	n = strlen(k);
	memset(dp, -1, sizeof(dp));
	int ans = (calc(0, 0, 0) - 1 + MOD) % MOD;
	printf("%d\n", ans);
	return 0;
}