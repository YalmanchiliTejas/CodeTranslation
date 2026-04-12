#include <bits/stdc++.h>
#ifdef DBP
#define deb(...) fprllf(stderr,__VA_ARGS__)
#else
#define deb(...) 0
#endif
#define fst first
#define snd second
#define fore(x,a,b) for(ll x=(a), qwerty=(b); x<qwerty; x++)
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) ll((a).size())
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

struct STree { // example: range sum with range addition
	vector<ll> st,lazy;ll n;
	STree(ll n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void push(ll k, ll s, ll e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]+=lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(ll k, ll s, ll e, ll a, ll b, ll v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v; // accumulate lazy
			push(k,s,e);return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=max(st[2*k],st[2*k+1]); // operation
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return -(1LL<<60); // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		ll m=(s+e)/2;
		return max(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

const ll N=2e5+5;
ll n,m;
vector<pair<ll,ll> > g[N];
ll dp[N];

int main(){FIN;
	cin>>n>>m;
	STree st(n+1);
	fore(x,0,m){
		ll l,r;ll v;cin>>l>>r>>v;
		g[l].pb({r,v});
	}
	for(auto p:g[n])st.upd(n,p.fst+1,p.snd);
	for(ll x=n-1; x>=0; x--){
		dp[x] = st.query(x,n+1);
		st.upd(x,x+1,dp[x]);
		for(auto p:g[x])st.upd(x,p.fst+1,p.snd);
	}
	cout << dp[0] << "\n";
}