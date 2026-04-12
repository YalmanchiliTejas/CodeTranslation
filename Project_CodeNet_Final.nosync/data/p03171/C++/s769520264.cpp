#include <bits/stdc++.h>
using namespace std;

int N;
long long a[3010], dp[3010][3010];

long long f(int x, int y) {
	if (x>y) return 0;
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = max(a[x] - f(x+1, y),
	               a[y] - f(x, y-1));
	return dp[x][y];
}

int main () {
	cin >> N;
	for(int i=1; i<=N; i++)
		cin >> a[i];
	memset(dp, -1, sizeof(dp));
	cout << f(1, N) << endl;
}
