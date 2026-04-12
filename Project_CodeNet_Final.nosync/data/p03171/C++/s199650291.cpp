#include<bits/stdc++.h>
using namespace std;
#define int            long long int



int dp[3001][3001];
int f(int i, int j, int a[]) {
	if (dp[i][j] != -1)
		return dp[i][j];
	if (i == j)
		return a[i];
	int taro = INT_MIN;
	int jiro = INT_MAX;
	taro = max(a[i] + f(i + 1, j, a) - jiro, a[j] + f(i, j - 1, a) - jiro);

	jiro = min(taro - a[i] + f(i + 1, j, a), taro - a[j] + f(i, j - 1, a));
	return dp[i][j] = taro - jiro;

}

int32_t main() {
	//c_p_c();
	memset(dp, -1, sizeof(dp));
	int t;
	cin >> t;
	int a[t];
	for (int i = 0; i < t; i++) {

		cin >> a[i];

	}
	cout << f(0, t - 1, a);
}

