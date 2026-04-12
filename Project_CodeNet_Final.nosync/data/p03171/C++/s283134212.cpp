#include <bits/stdc++.h>
using namespace std;

int a[3010];
long dp[3010][3010];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i=n-1; i >= 0; i--) {
		for(int j=i; j < n; j++) {
			if(i == j) {
				dp[i][j] = a[i];
			}else{
				dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
			}
		}
	}
	printf("%ld\n", dp[0][n-1]);
}
