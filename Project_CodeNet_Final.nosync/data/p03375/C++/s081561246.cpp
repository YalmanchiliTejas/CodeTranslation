//#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;

#define boost ios::sync_with_stdio(0); cin.tie(0)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

const int N = 3000 + 5;
int MOD;

/***************************************************************************/

ll power(ll a, ll n, ll m) {
	if(n == 0) return 1;
	ll p = power(a, n>>1, m);
	p = (p * p) % m;
	if(n & 1) p = (p * a) % m;
	return p;
}

ll dp[N][N];

ll fun(int p, int c) {
	if(c < 0) return 0;
	if(p == 0) return (c == 0);
	ll &memo = dp[p][c];
	if(memo != -1) return memo;
	ll ans = (fun(p-1, c-1) + fun(p-1, c) * (c+1)) % MOD;
	return memo = ans;
}

ll fact[N], ifact[N];

void calculateFact() {

	fact[0] = 1;

	for(int i=1; i<N; i++) {
		fact[i] = (i * fact[i-1]) % MOD;
	}
	ifact[N-1] = power(fact[N-1], MOD-2, MOD);

	for(int i=N-1; i>=1; i--) {
		ifact[i-1] = (i * ifact[i]) % MOD;
	}
}

ll nck(int n, int k) {
	
	if(n < k || k < 0) return 0;

	ll ans = fact[n];
	ans = (ans * ifact[k]) % MOD;
	ans = (ans * ifact[n-k]) % MOD;

	return ans;
}

int main() {

	boost;

	int n; cin>>n>>MOD;
	calculateFact();

	memset(dp, -1, sizeof dp);

	ll ans = power(2, power(2, n, MOD-1), MOD);

	for(int i=1; i<=n; i++) {
		ll bb = power(2, power(2, n-i, MOD-1), MOD);
		ll pp = power(2, n-i, MOD);
		ll cc = 1;

		ll cnt = bb;

		for(int j=1; j<=i; j++) {
			cc = (cc * pp) % MOD;
			cnt += ((cc * fun(i, j)) % MOD * bb) % MOD;
		}
		cnt %= MOD;
		cnt = (cnt * nck(n, i)) % MOD;

		if(i & 1) ans -= cnt;
		else ans += cnt;
	}

	ans %= MOD;
	if(ans < 0) ans += MOD;

	cout<<ans<<"\n";
	
	return 0;
}