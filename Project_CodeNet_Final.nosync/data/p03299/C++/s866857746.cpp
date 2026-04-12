
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pll = pair<ll,ll>;
#define f(i,a,b) for (int i = a; i < b; i++)
#define pb push_back
#define Min(a,b) a=min(a,b)

const int mod = 1e9+7;

ll modpow(ll a, ll b) {
	return b?modpow(a*a%mod,b/2)*(b&1?a:1)%mod:1;
}

pll solve(vi ds) {
	int x = mod;
	f(i,0,ds.size()) Min(x,ds[i]);
	int w = 0;
	ll a = 1, b = 1;
	vi nxt;
	f(i,0,ds.size()) if (x == ds[i]) {
		if (nxt.size()) {
			pll sol = solve(nxt);
			a = a*sol.first%mod;
			b = b*((sol.first+sol.second)%mod)%mod;
			nxt = vi();
		}
		w++;	
	} else nxt.pb(ds[i]-x);
	if (nxt.size()) {
		pll sol = solve(nxt);
		a = a*sol.first%mod;
		b = b*((sol.first+sol.second)%mod)%mod;
	}
	return pll(a*modpow(2,x)%mod,
		(b*modpow(2,w)%mod+(modpow(2,x)+mod-2)*a%mod)%mod);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif

	int n;
	cin>>n;
	vi ds(n);
	f(i,0,n) cin>>ds[i];
	cout << solve(ds).second << endl;

#ifdef LOCAL
	cout << setprecision(12) << (long double)(clock()-start) / CLOCKS_PER_SEC << endl;
#endif
	
	return 0;
}

