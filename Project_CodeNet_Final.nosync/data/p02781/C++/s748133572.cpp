#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
int n, k;
int64 dp[105][5][2];
char a[105];

int64 F(int i, int c, int eq) {
	if(c > k)
		return 0;
	
	if(i == n + 1)
		return c == k;

	int64 &ans = dp[i][c][eq];

	if(ans != -1)
		return ans;

	ans = 0;

	int lim = eq ? (a[i] - '0') : 9;

	for(int d = 0; d <= lim; d++) {
		int neq = eq && d == (a[i] - '0');
		ans += F(i + 1, c + (d > 0), neq);
	}

	return ans;
}

int main() {
	scanf("%s%d", a + 1, &k);
	n = strlen(a + 1);

	memset(dp, -1, sizeof(dp));

	printf("%lld\n", F(1, 0, 1));
	return 0;
}