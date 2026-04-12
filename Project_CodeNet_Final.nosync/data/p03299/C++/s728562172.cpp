#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

map<pair<VI,int>,ll> hs;
int n,h[110];
ll solve(VI x,int ty) {
	if (x.empty()) return 1;
	if (hs.count(mp(x,ty))) return hs[mp(x,ty)];
	int v=*min_element(all(x));
	if (ty==0) {
		ll ans=1;
		if (v==1) {
			VI c;
			for (auto p:x) {
				if (p==1) {
					ans=ans*2%mod;
					ans=ans*solve(c,0)%mod;
					c.clear();
				} else {
					c.pb(p);
				}
			}
			ans=ans*solve(c,0)%mod;
			return hs[mp(x,ty)]=ans;
		} else {
			VI y=x;
			rep(i,0,SZ(y)) y[i]-=v-1;
			ll all=solve(y,0);
			ll dif=solve(y,1)*2%mod;
			all=(all-dif+mod)%mod;
			return hs[mp(x,ty)]=(all+dif*powmod(2,v-1))%mod;
		}
	} else {
		// RBRB
		ll ans=1;
		if (v==1) {
			VI c;
			for (auto p:x) {
				if (p==1) {
					ans=ans*solve(c,1)%mod;
					c.clear();
				} else {
					c.pb(p);
				}
			}
			ans=ans*solve(c,1)%mod;
			return hs[mp(x,ty)]=ans;
		} else {
			VI y=x;
			rep(i,0,SZ(y)) y[i]-=v-1;
			ll dif=solve(y,1);
			return hs[mp(x,ty)]=dif*powmod(2,v-1)%mod;	
		}
	}
}

int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",h+i);
	printf("%lld\n",solve(VI(h,h+n),0));
}
