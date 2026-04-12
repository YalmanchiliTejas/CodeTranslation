#include <bits/stdc++.h>
using namespace std;

const long INF = 1L << 60;
int a[200010];
long dp[200010][4];

template<class T> inline bool chmax(T &a, const T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

int main(){
	int n, a;
	scanf("%d", &n);
	int k = n % 2 + 1;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= k; j++)
			dp[i][j] = -INF;
	dp[0][0] = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a);
		for(int j = 0; j <= k; j++) {
			chmax(dp[i+1][j+1], dp[i][j]);
          	if((i+j) % 2) 
				chmax(dp[i+1][j], dp[i][j]);
			else
				chmax(dp[i+1][j], dp[i][j] + a);
		}
	}
	printf("%ld\n", dp[n][k]);
}
