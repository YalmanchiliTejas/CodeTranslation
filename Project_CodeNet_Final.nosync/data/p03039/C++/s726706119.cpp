#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2e5 + 10;
const ll mod = 1e9+7;

ll n, m, k;
ll p, q;

ll mypow(ll x, ll p){
	ll ret = 1;
	while(p){
		if(p&1){
			ret *= x;
			ret %= mod;
		}
		x *= x;
		x %= mod;
		p >>= 1;
	}

	return ret;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> k;
	p = q = 1;

	ll ck = k - 2;
	ll cn = n*m - 2;
	for(ll i=1; i<=cn; i++){
		p *= i;
		p %= mod;
	}

	for(ll i=1; i<=cn-ck; i++){
		q *= i;
		q %= mod;
	}
	for(ll i=1; i<=ck; i++){
		q *= i;
		q %= mod;
	}
	
	ll ans = 0;
	ll ot = 0;
	for(ll i=1; i<=n; i++){
		ans += ot * m;	
		ans %= mod;
		
		ot += i * m;
		ot %= mod;
	}

	ot = 0;
	for(ll i=1; i<=m; i++){
		ans += ot * n;
		ans %= mod;

		ot += i * n;
		ot %= mod;
	}

	ans *= p;
	ans %= mod;
	ans *= mypow(q, mod-2);
	ans %= mod;
	
	cout << ans << endl;
}
