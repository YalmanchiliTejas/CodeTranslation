#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n, mod = 1e9 + 7;
	scanf("%lld", &n);
	ll a[n], s = 0, ans = 0;
	for (int i = 0; i < n; i++){
		scanf("%lld", &a[i]), s += a[i];
	}
	for (int i = 0; i < n; i++){
		s -= a[i];
		(ans += (a[i] * (s % mod) % mod)) %= mod;
	}
	printf("%lld\n", ans);
}