#include <bits/stdc++.h>

using namespace std;
const int MAXN = 4e5 + 5;
#define ll long long
int n;
ll d[MAXN], f[MAXN][2];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", d + i);
	f[1][1] = -1e18;
	for (int i = 2; i <= n; i ++) {
		if (i & 1) {
			f[i][1] = max(max(f[i - 3][1], f[i - 3][0]), max(f[i - 2][1], f[i - 2][0])) + d[i];
			f[i][0] = f[i - 2][0] + d[i - 1];
		}
		else {
			f[i][1] = max(f[i - 2][1], f[i - 2][0]) + d[i];
			f[i][0] = f[i - 2][0] + d[i - 1];
		} 
	} 
	printf("%lld\n", max(f[n][0], f[n][1]));
	return 0;
} 