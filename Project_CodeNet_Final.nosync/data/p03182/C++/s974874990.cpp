#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define fore(i,ii,iii)for(int i=ii;i<iii;i++)
#define rfor(i,ii,iii)for(int i=iii-1;i>=ii;i--)
#define all(s) s.begin(),s.end()
#define sz(a) ((int)a.size())
#define pb push_back
#define mset(a,b) memset(a,b,sizeof(a))
#define fst first
#define snd second

const ll N=2e5+15;
ll l[N];
pair<ll,ll>r[N];
ll n,m;
vector<int>t[N];

struct STree { // example: range sum with range addition
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
		st[k]=max(st[2*k],st[2*k+1]); // operation
	}
	ll query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 0; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return max(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
	}
	void upd(int a, int b, ll v){upd(1,0,n,a,b,v);}
	ll query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);


vector<pair<ll,ll>>a[N];
int main() {
	ios::sync_with_stdio(false);
	STree st(N);
	cin>>n>>m;
	fore(i,0,m) {
		ll l,r,c;
		cin>>l>>r>>c;
		a[l].pb({r,c});
	}
	for(int i=n;i>=0;i--) {
		for(auto it:a[i+1]) {
			st.upd(i+1,it.fst+1,it.snd);
		}
		st.upd(i,i+1,st.query(i+1,n+1));
	}
	cout<<st.query(0,n+1)<<endl;
}