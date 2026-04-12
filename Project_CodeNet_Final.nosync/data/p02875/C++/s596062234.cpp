#include <bits/stdc++.h>
#define int long long
#define mod 998244353

using namespace std;

int C[10000050];
int n;

int qexp(int b, int e){
	if(e == 0) return 1;
	int half = qexp(b,e/2) % mod;
	half *= half;
	half %= mod;
	if(e % 2 == 0) return half;
	else return (half*b)%mod;
}
int inv(int x){
	return qexp(x, mod-2);
}
int32_t main(){
	cin >> n;
	C[0] = 1;
	for(int i=1; i<=n/2; ++i){
		C[i] = (C[i-1]*(n-i+1)) % mod;
		C[i] *= inv(i); C[i] %= mod;
	}
	for(int i=n; i>=n/2+1; --i){
		C[i] = C[n-i];
	}
	int ans = qexp(3,n);
	for(int i=n/2+1; i<=n; ++i){
		int sub = 2*C[i]; sub %= mod;
		sub *= qexp(2,n-i); sub %= mod;
		ans -= sub;
		ans += mod; ans %= mod;
	}
	cout << ans;
}
