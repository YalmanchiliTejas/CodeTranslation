#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL n, m, i, j, k, a[55], c[55];
LL dfs(LL n, LL k){
	if(k <= 0 || n < 0) return 0;
	if(k >= c[n]) return a[n];
	LL s = dfs(n-1, k-1);
	if(k > c[n-1]+1) s++;
	s += dfs(n-1, k-c[n-1]-2);
	return s;
}
int main(){
	scanf("%lld%lld", &n, &k);
	a[0] = c[0] = 1;
	for(i=1; i<=n; i++){
		a[i] = a[i-1] * 2 + 1;
		c[i] = c[i-1] * 2 + 3;
	}
	printf("%lld\n", dfs(n, k));
	return 0;
}