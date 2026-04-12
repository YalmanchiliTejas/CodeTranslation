#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

typedef long long lint;
const lint N = 3300, INF = N*1e9+7;
lint n, a[N], dp[N][N][2];

lint solve(lint i, lint j, lint k){
	if (dp[i][j][k] != INF){
		return dp[i][j][k];
	}

	if (i == j){
		if (k==0) return dp[i][j][k] = a[i];
		else 	  return dp[i][j][k] = -a[i];
	}

	if (k == 0){ //maximize
		return dp[i][j][k] = max(solve(i + 1, j, 1) + a[i], solve(i, j - 1, 1) + a[j]);
	} else {
		return dp[i][j][k] = min(solve(i + 1, j, 0) - a[i], solve(i, j - 1, 0) - a[j]);
	}

}

int main(){
#ifdef LOCAL
	freopen("input", "r", stdin);
#endif

	scanf("%lld", &n);

	for (lint i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}

	for (lint i = 0; i < N; i++)
		for (lint j = 0; j < N; j++)
			dp[i][j][0] = dp[i][j][1] = INF;

	printf("%lld\n", solve(0, n-1, 0));

	return 0; 
}