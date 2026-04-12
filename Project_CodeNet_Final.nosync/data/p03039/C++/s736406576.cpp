#include <stdio.h>
#include <algorithm>

#define lli long long int

using namespace std;

lli bigmod = 1000000007, faktorial[200010];

lli pangkat(lli a, lli b) {
	lli temp, total;
	if (b == 0)
		return 1;
	temp = pangkat(a, b / 2);
	total = (temp * temp) % bigmod;
	if (b & 1)
		total = (total * a) % bigmod;
	return total;
}

lli combine(lli p, lli r) {
	lli ret, temp;
	ret = faktorial[p];
	temp = pangkat(faktorial[r], bigmod - 2);
	ret = (ret * temp) % bigmod;
	temp = pangkat(faktorial[p - r], bigmod - 2);
	ret = (ret * temp) % bigmod;
	return ret;
}

int main() {
	lli n, m, k, sum = 0, ans, c;
	scanf("%lld %lld %lld", &n, &m, &k);
	faktorial[0] = 1;
	for (lli i = 1; i <= (n * m); i++)
		faktorial[i] = (faktorial[i - 1] * i) % bigmod;
	lli dist[n + 5][m + 5];
	for (lli i = 1; i <= n; i++)
		for (lli j = 1; j <= m; j++)
			dist[i][j] = i * j * (i + j - 2) / 2;
	for (lli i = 0; i < n; i++)
		for (lli j = 0; j < m; j++)
			sum = (sum + dist[n - i][m - j] + dist[n - i][j + 1] - dist[n - i][1] - dist[1][j + 1]) % bigmod;
	c = combine((n * m) - 2, k - 2);
	ans = (c * sum) % bigmod;
	printf("%lld\n", ans);
	return 0;
}