#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const ll md = 998244353;

const int mx = 50000;

ll mpow(ll a, ll e){
	ll res = 1;
	do {
		if(e&1) res = res * a % md;
		a = a * a % md;
	} while(e /= 2);
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<ll> fs(mx,1);
	rep(i,1,mx) fs[i] = i*fs[i-1] % md;
	vector<ll> ifs(mx);
	rep(i,0,mx) ifs[i] = mpow(fs[i], md-2);

	auto bin = [&](int n, int k){
		return fs[n] * ifs[k] % md * ifs[n-k] % md;
	};

	string a,b;
	cin >> a >> b;
	int same = 0, dif = 0, n = sz(a);
	rep(i,0,n){
		if(a[i]=='1' && b[i]=='1') ++same;
	}
	dif = count(all(a), '1') - same;

	vector<vi> dp(same+1, vi(dif+1));
	dp[0][0] = 1;
	rep(i,1,same+1) dp[i][0] = 0;
	rep(d,1,dif+1) dp[0][d] = dp[0][d-1]*ll(d)*d%md;
	rep(i,1,same+1) rep(d,1,dif+1)
		dp[i][d] = d*(ll(d)*dp[i][d-1] + ll(i)*dp[i-1][d])%md;
	ll ans = 0;
	rep(i,0,same+1){
		ll cur = 1;
		cur *= bin(same, i);
		cur %= md;
		cur *= fs[same-i]*fs[same-i]%md;
		cur %= md;
		cur *= bin(dif + same, same-i);
		cur %= md;
		cur *= dp[i][dif];
		cur %= md;
		ans += cur;
	}
	ans %= md;
	if(ans < 0) ans += md;
	cout << ans << endl;
}