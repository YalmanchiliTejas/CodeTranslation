#include <bits/stdc++.h>
using namespace std;
const int N = 3003;
int n;
long long dp[N][N] , a[N];


int32_t main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n; i++)
		for(int j = 1 ; j <= n ;j ++){
			dp[i][j] = 0;
		}
	for(int i = 1 ; i <= n; i ++) scanf("%lld" , &a[i]) , dp[i][i] = a[i];
	for(int i = 2 ; i <= n; i ++){
		for(int j = 1 ; j <= n && (j + i - 1) <= n; j ++){
			dp[j][j+i-1] = max(a[j] - dp[j+1][j+i-1] , a[j+i-1] - dp[j][j+i-2]);
		}
	}
	printf("%lld\n" , dp[1][n]);
}