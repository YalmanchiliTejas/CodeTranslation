#include <bits/stdc++.h>
using namespace std;

int a[3010];
long long dp[3010][3010];
int vis[3010][3010];
int n;

long long dfs(int l, int r){
	if (l == r) return n & 1 ? a[l] : -a[l];
	if (vis[l][r]) return dp[l][r];
	vis[l][r] = 1;
	int p = (n - (r - l + 1)) & 1;
	if (p == 0) dp[l][r] = max(dfs(l + 1, r) + a[l], dfs(l, r - 1) + a[r]);
	else dp[l][r] = min(dfs(l + 1, r) - a[l], dfs(l, r - 1) - a[r]);
	return dp[l][r];
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	printf("%lld\n", dfs(0, n - 1));
	return 0;
}
