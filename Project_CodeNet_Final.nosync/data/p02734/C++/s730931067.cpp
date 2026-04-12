#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 3005;

const int mod = 998244353;
int add(int a, int b) {
	return a + b < mod ? a + b : a + b - mod;
}

int n, s;
int a[N];

int dp[N][N];

int f(int i, int j) {
	if(j < 0) return 0;
	if(j == 0) return n - i + 1;
	if(i == n) return 0;
	int &ans = dp[i][j];
	if(~ans) return ans;
	return ans = add(f(i + 1, j), f(i + 1, j - a[i]));
}


int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d %d", &n, &s);

	for(int i = 0; i < n; i++) scanf("%d", a + i);

	int ans = 0;

	for(int i = 0; i < n; i++) {
		ans = add(ans, f(i, s));
	}

	printf("%d\n", ans);
}
