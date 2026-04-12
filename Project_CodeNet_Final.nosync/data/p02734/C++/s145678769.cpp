#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
int main(){
	ll n, s, ans = 0, mod = 998244353;
	scanf("%lld %lld", &n, &s);
	ll a[n], dp[n][s + 1], p[s + 1];
	for (int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
		for (int j = 0; j <= s; j++) dp[i][j] = 0;
		if (a[i] <= s) dp[i][a[i]] += i + 1;
	}
	fill(p, p + s + 1, 0);
	for (int i = 0; i < n; i++){
		for (int j = a[i]; j <= s; j++){
			(dp[i][j] += p[j - a[i]]) %= mod;
		}
		for (int j = 0; j <= s; j++){
			(p[j] += dp[i][j]) %= mod;
		}
	}
	for (int i = 0; i < n; i++){
		(ans += ((n - i) * dp[i][s]) % mod) %= mod;
	}
	printf("%lld\n", ans);
}