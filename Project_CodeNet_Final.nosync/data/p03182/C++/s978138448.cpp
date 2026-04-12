// oh, the less I know the better
// corner cases // int vs ll // cin vs scanf // clear structures // statement // doublesz
#include <bits/stdc++.h>
#define endl '\n'
#define fst first
#define snd second
#define pb push_back
#define sz(x) int(x.size())
#define REP(i,n) for(int i = 0; i < int(n); ++i)
#define trace(x) cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5+20;
const ll INF = 1e18;

struct STree{ // example: range sum with range addition
	vector<ll> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void push(int k, int s, int e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]+=lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, ll v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=min(st[2*k],st[2*k+1]); // operation
	}
	ll query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return INF; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return min(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
	}
	void upd(int a, int b, ll v){upd(1,0,n,a,b,v);}
	ll query(int a, int b){return query(1,0,n,a,b);}
};  // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

vector<ii> intv[N];

int main(){

	fastio;
	int n,m;
	cin >> n >> m;
	ll ans = 0;
	for(int i = 0; i < m; ++i){
		int l,r,a;
		cin >> l >> r >> a;
		ans += a;
		intv[r].pb(ii(l,a));
	}

	ll res = INF;
	STree st(n+5);
	for(int i = 1; i <= n+1; ++i){
		for(auto par : intv[i-1]){
			int l = par.fst, val = par.snd;
			st.upd(0,l,val);
		}
		st.upd(i,i+1,st.query(0,i));
	}
	res = st.query(0,n+1);
	cout << ans-res << endl;

	return 0;
}
