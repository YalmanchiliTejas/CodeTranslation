#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#define maxn 105
#define LL long long
using namespace std;
LL a[maxn];
LL len[maxn];
LL dfs(long long level, long long length) {
	if (length <= 0) return 0;
	if (len[level] <= length) {
		return a[level];
	}
	if (length > len[level] / 2) {
		return 1 + a[level - 1] + dfs(level - 1, length - len[level - 1] - 2);
	}
	else if (length == len[level] / 2)	return a[level - 1];
	else return dfs(level - 1, length - 1);
}

int main() {
	a[0] = 1;
	len[0] = 1;
	for (int i = 1; i <= 50; i++) a[i] = 2 * a[i - 1] + 1;
	for (int i = 1; i <= 50; i++) len[i] = 2 * len[i - 1] + 3;
	LL n, k;	scanf("%lld%lld", &n, &k);
	LL ans = dfs(n, k);
	printf("%lld\n", ans);
	return 0;
}
