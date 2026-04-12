#include <bits/stdc++.h>
using namespace std;
const int N = 110;
char n[N];
int k;
int dp[N][5];
int main() {
	scanf("%s", n);
	scanf("%d", &k);
	int sz = strlen(n);
	reverse(n, n + sz);
	dp[0][0] = 1;
	for(int i = 1; i < sz; ++i) {
		dp[i][0] = 1;
		for(int j = 1; j <= k; ++j) {
			dp[i][j] = dp[i - 1][j] + (9 * dp[i - 1][j - 1]);
		}
	}
	int ans = 0;
	/*cout<<ans<<endl;
	for(int i = 0; i < sz; ++i) {
		for(int j = 0; j <= k; ++j) {
			cout<<dp[i][j]<<" ";
		} cout<<endl;
	}*/
	for(int i = sz - 1, j = k; i >= 0 and j >= 0; --i, --j) {
		if(j == 0) {
			ans++;
			break;
		}
		int num = n[i] - '0';
		if(num == 0) {
			j++;
			continue;
		}
		int l = 1;
		if(i == 0) l = 0;
		ans += (num - l) * dp[i][j - 1] + dp[i][j];
	}
	printf("%d\n", ans);
	return 0;
}

