#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

const long long NINF = -(1LL << 60);
long long dp[200005][3];
int n;
int a[200005];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= 2; j++){
			dp[i][j] = NINF;
		}
	}
	dp[0][1] = 0;
	dp[1][0] = a[1];
	for(int i = 2; i <= n; i++){
		for(int j = 0; j <= 2; j++){
			for(int k = 0; k <= j; k++){
				if(i - k - 2 >= 0){
					dp[i][j] = max(dp[i][j], dp[i - k - 2][j - k] + a[i]);
				}
			}
		}
	}
	
	long long ans = NINF;
	
	int margin;
	if(n & 1) margin = 2;
	else margin = 1;
	
	for(int i = 0; i <= margin; i++){
		ans = max(ans, dp[n - i][margin - i]);
	}
	printf("%lld\n", ans);
	
	return 0;
}