#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int main(){
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i) cin >> a[i];
	int pref[n+1]; pref[0] = 0;
	for(int i = 1; i <= n; ++i){
		pref[i] = (pref[i-1] + a[i-1])%mod;
	}
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		ans += (1LL*a[i]*((pref[n] - pref[i+1] + mod)%mod))%mod;
	}
	ans %= mod;
	cout << ans;
}