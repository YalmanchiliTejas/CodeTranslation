#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll addMod(ll a, ll b){
	return (a+b) % MOD;
}

ll mulMod(ll a, ll b){
	return (a*b) % MOD;
}

ll fast(ll a, ll b){
	if(b == 0) return 1;
	ll tmp = fast(a,b/2);
	tmp = mulMod(tmp,tmp);
	if(b % 2 == 1) tmp = mulMod(tmp,a);
	return tmp;
}

const int N = 2e5;

ll fact[N + 5];
ll nCk(int n, int k){
	if(n < k) return 0;
	return mulMod(fact[n], fast(mulMod(fact[n-k], fact[k]), MOD-2));
}

ll f(ll n, ll m, ll k){
	ll ret = 0;
	for(int dif = 1; dif <= n-1; dif++){
		ll val = mulMod(n-dif, m*m);
		val = mulMod(val, nCk(n*m-2,k-2));
		val = mulMod(val, dif);
		ret = addMod(ret, val);
	}
//	printf("ret %lld\n",ret);
	return ret;
}

ll solve(ll n, ll m, ll k){
	ll ret = addMod(f(n,m,k), f(m,n,k));
	return ret;
}

int main(){
	fact[0] = 1;
	for(int i=1; i<=N; i++) fact[i] = mulMod(fact[i-1], (ll)i);
	ll n,m,k;
	cin >> n >> m >> k;
	cout << solve(n,m,k) << endl;
	return 0;
}