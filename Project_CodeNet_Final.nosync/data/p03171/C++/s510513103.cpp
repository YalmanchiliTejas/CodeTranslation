#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
int main(){
	ll n;
	scanf("%lld", &n);
	ll a[n];
	for (ll i = 0; i < n; i++) scanf("%lld", &a[i]);
	ll dp[n][n];
	if (n % 2 == 0){
		for (ll i = 0; i < n; i++) dp[i][i] = -a[i];
	}else{
		for (ll i = 0; i < n; i++) dp[i][i] = a[i];
	}
	for (ll i = 1; i < n; i++){
		for (ll j = 0; i + j < n; j++){
			if ((n - i) % 2 == 0){
				dp[j][i + j] = min(-a[j] + dp[j + 1][i + j], -a[i + j] + dp[j][i + j - 1]);
			}else{
				dp[j][i + j] = max(a[j] + dp[j + 1][i + j], a[i + j] + dp[j][i + j - 1]);
			}
		}
	}
	printf("%lld\n", dp[0][n - 1]);
}