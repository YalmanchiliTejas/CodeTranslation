#include<bits/stdc++.h>
#define LLI long long int
using namespace std;

int a[3007] = {};
LLI dp[3007][3007] = {};

int main() {
	
	int i,j;
	int N;
	
	cin >> N;
	for( i=1; i<=N; i++)
		cin >> a[i];
	
	
	int flag = N&1;
	if( flag) {
		for( i=1; i<=N; i++)
			dp[i][i] = a[i];
	}
	else {
		for( i=1; i<=N; i++)
			dp[i][i] = -a[i];
	}
	flag = !flag;
	for( i=2; i<=N; i++, flag = !flag) {
		for( j=1; j+i-1<=N; j++) {
			if( flag)
				dp[j][j+i-1] = max( dp[j+1][j+i-1] + a[j], dp[j][j+i-2] + a[j+i-1]);
			else
				dp[j][j+i-1] = min( dp[j+1][j+i-1] - a[j], dp[j][j+i-2] - a[j+i-1]);
		}
	}
	
	printf("%lld\n", dp[1][N]);
	
	return 0;
}