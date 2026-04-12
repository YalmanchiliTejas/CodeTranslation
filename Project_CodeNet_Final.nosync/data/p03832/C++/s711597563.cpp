#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
int n, a, b, c, d, cm[1010][1010], dp[1010][1010], chk[1010][1010], inv[1010];

int pw(int x, int k){
	if(k == 1) return x;
	return 1LL * (k % 2 ? x : 1) * pw(1LL * x * x % M, k / 2) % M;
}

int f(int x, int y){
	if(y > b) return !x;
	if(x && x < y) return 0;
	if(chk[x][y]) return dp[x][y];
	int cur = 1;
	dp[x][y] = f(x, y + 1);
	for(int k = 1; k <= d; k++){
		if(x - k * y < 0) break;
		cur = 1LL * cur * cm[x - (k - 1) * y][y] % M * inv[k] % M;
		if(c <= k) dp[x][y] = (dp[x][y] + 1LL * cur * f(x - k * y, y + 1) % M) % M;
	}
	chk[x][y] = 1;
	return dp[x][y];
}

int main(){
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	for(int i = 0; i <= n; i++){
		if(i) inv[i] = pw(i, M - 2);
		cm[i][0] = 1;
		for(int j = 1; j <= i; j++){
			cm[i][j] = (cm[i - 1][j] + cm[i - 1][j - 1]) % M;
		}
	}
	printf("%d\n", f(n, a));
}