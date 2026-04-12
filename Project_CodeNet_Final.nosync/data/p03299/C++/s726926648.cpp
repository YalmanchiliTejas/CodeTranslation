#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define fi first
#define sc second
const ll mod = 1000000007;
#define repn(i,n) for(int i=1;i<=n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define mp make_pair
#define pb push_back

int n,a[105];
ll modpow(ll a,ll n){
    ll ret = 1;
    while(n){
        if(n&1) ret = ret*a%mod;
        a = a*a%mod;
        n >>= 1;
    }
    return ret;
}
P rec(int l,int r,int dep){
	int mn = mod;
	for(int i=l;i<=r;i++) mn = min(mn,a[i]);
	int cnt = 0;
	vector<P>ret;
	int sum = 0;
	for(int i=l;i<=r;i++){
		if(a[i] == mn){
			if(cnt) ret.pb(rec(i-cnt,i-1,mn));
			cnt = 0;
			sum++;
		}
		else cnt++;
	}
	if(cnt) ret.pb(rec(r-cnt+1,r,mn));
	
	//01010101....
	ll val = 1;
	rep(i,ret.size()) val = val * ret[i].fi % mod * 2LL % mod;
	
	//all
	ll val2 = modpow(2LL,sum);
	rep(i,ret.size()) val2 = val2 * (ret[i].fi*4LL%mod+ret[i].sc) % mod;
	val2 = (val2-2LL*val)%mod;
	if(val2 < 0) val2 += mod;
	
	val = val * modpow(2LL,mn-dep-1) % mod;
	return mp(val,val2);
}
int main(){
	cin >> n;
	repn(i,n) cin >> a[i];
	
	P ret = rec(1,n,0);
	ll ans = ret.fi*2LL+ret.sc;
	cout << (ans%mod+mod)%mod << endl;
}