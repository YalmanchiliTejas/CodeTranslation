#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
int n;
ll dp[200005], a[200005], b, ans = -1e15;
int main(){
	scanf("%d", &n);
	rep(i,n){
		scanf("%lld", a+i);
		dp[i] = (i>1?dp[i-2]:0) + a[i];
		if(i&1) dp[i] = max(dp[i], dp[i-1]);
	}
	if(n&1){
		for(int i=n-1; i>=0; i-=2){
			ans = max(ans, (i?dp[i-1]:0)+b);
			b += a[i];
		}
	}else ans = dp[n-1];
	printf("%lld\n", ans);
}