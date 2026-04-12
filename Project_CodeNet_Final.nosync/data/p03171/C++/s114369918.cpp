#include <stdio.h>
#include <string.h>
#include <algorithm>

#define lli long long int

using namespace std;

lli a[3010], t[3010][3010], j[3010][3010];

lli taro(lli left, lli right);

lli jiro(lli l, lli r) {
	lli depan, belakang;
	if (l == r)
		return (-1 * a[l]);
	if (j[l][r] != -1)
		return j[l][r];
	depan = taro(l + 1, r) - a[l];
	belakang = taro(l, r - 1) - a[r];
	j[l][r] = min(depan, belakang);
	return j[l][r];
}

lli taro(lli left, lli right) {
	lli d, b;
	if (left == right)
		return a[left];
	if (t[left][right] != -1)
		return t[left][right];
	d = jiro(left + 1, right) + a[left];
	b = jiro(left, right - 1) + a[right];
	t[left][right] = max(d, b);
	return t[left][right];
}

int main() {
	lli n, ans;
	scanf("%lld", &n);
	for (lli i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	memset(t, -1, sizeof t);
	memset(j, -1, sizeof j);
	ans = taro(1, n);
	printf("%lld\n", ans);
	return 0;
}