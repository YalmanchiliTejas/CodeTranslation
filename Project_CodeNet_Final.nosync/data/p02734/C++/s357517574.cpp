#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
constexpr int MOD = 998244353;
int n, s, a;
long long dp[3005], ans;
int main(){
	scanf("%d%d", &n, &s);
	rep(i,n){
		scanf("%d", &a);
		for(int j=s; j>a; j--) (dp[j] += dp[j-a]) %= MOD;
		dp[a] += i+1;
		(ans += dp[s]) %= MOD;
	}
	printf("%lld\n", ans);
}