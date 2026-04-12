#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define cinf(n,x,y) for(int i=0;i<(n);i++) cin >> x[i] >>y[i];
typedef long long int ll;
using namespace std;
long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }
ll mod=1e9+7;

struct perm {
private:
	int sz;
	vector<long long> p, invp;
public:
	perm(int n) {
		sz = n + 1;
		p.resize(sz), invp.resize(sz);
		p[0] = 1;
		for(int i=1;i<=sz - 1;i++) {
			p[i] = p[i - 1] * i%mod;
		}
		invp[sz - 1] = 1;
		ll cop = mod - 2, x = p[sz - 1];
		while (cop) {
			if (cop % 2)invp[sz - 1] = invp[sz - 1] * x%mod;
			cop >>= 1; x = x * x % mod;
		}
		for(int i=sz-2;i>=0;i--) {
			invp[i] = invp[i + 1] * (i + 1) % mod;
		}
	}
	ll comb(ll x, ll y) {
		if (x < y || y < 0)return 0;
		ll ret = p[x];
		(ret *= invp[y]) %= mod;
		(ret *= invp[x - y]) %= mod;
		return ret;
	}
	ll combP(ll x, ll y) {
		if (x < y || y < 0)return 0;
		return p[x] * invp[x - y] % mod;
	}
};
perm p(1 << 18);

void solve(){
	ll n,m,k; cin >>n>>m>>k;
	ll ans=0;
	for(int i=1;i<=n-1;i++){
		ll num=m*m%mod*(n-i)%mod;
		ll score=num*i%mod*p.comb(n*m-2,k-2)%mod;
		ans+=score;
		ans%=mod;
	}
	swap(n,m);
	for(int i=1;i<=n-1;i++){
		ll num=m*m%mod*(n-i)%mod;
		ll score=num*i%mod*p.comb(n*m-2,k-2)%mod;
		ans+=score;
		ans%=mod;
	}
	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}