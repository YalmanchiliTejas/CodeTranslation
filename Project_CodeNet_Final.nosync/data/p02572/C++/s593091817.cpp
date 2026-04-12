#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

const ll mod = 1e9+7;

//べき乗高速化
ll mpow(ll x, ll n){
	ll ans = 1;
	while(n != 0){
		if (n&1) ans = ans * x % mod;
		x = x*x % mod;
		n  = n >> 1;
	}
	return ans;
}


int main(){
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	ll sum = 0;
	ll sum2 = 0;
	rep(i,n) {
		sum += a[i] % mod;
		sum2 += (a[i] % mod) * (a[i] % mod);
		sum2 %= mod;
	}
	sum %= mod;
	ll ans = sum * sum - sum2;
	ans %= mod;
	ans *= mpow(2, mod - 2);
	ans %= mod;
	if(ans < 0){
		cout << ans + mod << endl;
	}else{
		cout << ans << endl;
	}
    return 0;
}

