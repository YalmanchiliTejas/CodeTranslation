#include <bits/stdc++.h>
using namespace std;

int n;
int a[3010];
long long int dp[3002][3002][3];

long long int rek(int x, int y, int z) {
	if (x > y) return 0;
	long long int &ret = dp[x][y][z];
	if (ret != -1) return ret;

	if (z == 0) {
		ret = max(rek(x+1, y, 1) + a[x], rek(x, y-1, 1) + a[y]);
	}
	else {
		ret = min(rek(x+1, y, 0) - a[x], rek(x, y-1, 0) - a[y]);
	}
	
	return ret;
}

int main () {
	
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	memset(dp, -1, sizeof dp);
	cout << rek(0, n-1, 0);
	
	
	return 0;
}