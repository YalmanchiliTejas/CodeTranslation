#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
#define pb push_back
#define chmax(x,y) x=max(x,y)
#define show(x) cout<<#x<<" "<<x<<endl
using namespace std;

template<class Handler>
struct segtree_lazy{
	using val_t = typename Handler::val_t;
	using opr_t = typename Handler::opr_t;
	int N;
	vector<val_t> val;
	vector<opr_t> lazy;
	segtree_lazy(){}
	segtree_lazy(int n){init(n);}
	segtree_lazy(const vector<val_t>& vc){init(vc);}
	void init(int n){
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,val_t::e);
		lazy.assign(N*2,opr_t::e);
	}
	void init(const vector<val_t>& vc){
		int n=vc.size();
		N=1;
		while(N<n) N*=2;
		val.assign(N*2,val_t::e);
		rep(i,n) val[i+N] = vc[i];
		for(int i=N-1;i>0;i--) val[i] = val[i*2] + val[i*2+1];
		lazy.assign(N*2,opr_t::e);
	}
	val_t realvalue(int k){
		return Handler::act(lazy[k],val[k]);
	}
	val_t calc(int a,int b,int l=0,int r=-1,int k=1){
		if(r==-1) r=N;
		if(b<=l||r<=a) return val_t::e;
		if(a<=l&&r<=b) return realvalue(k);
		propagate(k);
		val_t ret = calc(a,b,l,(l+r)/2,k*2) + calc(a,b,(l+r)/2,r,k*2+1);
		val[k] = realvalue(k*2) + realvalue(k*2+1);
		return ret;
	}
	void update(int a,int b,const opr_t& x,int l=0,int r=-1,int k=1){
		if(r==-1) r=N;
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b){
			Handler::setg2fg(x,lazy[k]);
			return;
		}
		propagate(k);
		update(a,b,x,l,(l+r)/2,k*2);
		update(a,b,x,(l+r)/2,r,k*2+1);
		val[k] = realvalue(k*2) + realvalue(k*2+1);
	}
	void propagate(int k){
		Handler::setg2fg(lazy[k],lazy[k*2]);
		Handler::setg2fg(lazy[k],lazy[k*2+1]);
		lazy[k]= opr_t::e;
	}
};
struct handler{
	struct val_t{
		int n[10];
		val_t(){*this = e;}
		val_t(vector<int> v){
//			show(v.size());
			rep(i,10) n[i]=v[i];
		}

		const static val_t e;
		val_t operator+(const val_t &r) const {
			vector<int> v(10);
			rep(i,10) v[i] = n[i]+r.n[i];
			return val_t(v);
		}
	};
	struct opr_t{
		int f[10];
		opr_t(){*this = e;}
		opr_t(vector<int> v){
//			show(v.size());
			rep(i,10) f[i]=v[i];
		}
		const static opr_t e;
	};
	static opr_t getfg(const opr_t &f, const opr_t &g){
		vector<int> v(10);
		rep(i,10) v[i] = f.f[g.f[i]];
		return opr_t(v);
	}
	static void setg2fg(const opr_t &f, opr_t &g){
		g = getfg(f,g);
	}
	static val_t act(const opr_t &f, const val_t &v){
		vector<int> x(10);
		rep(i,10) x[f.f[i]]+=v.n[i];
		return val_t(x);
	}
};
using val_t = typename handler::val_t;
using opr_t = typename handler::opr_t;
const val_t val_t::e = val_t({0,0,0,0,0,0,0,0,0,0});
const opr_t opr_t::e = opr_t({0,1,2,3,4,5,6,7,8,9});


int N,Q;
const int MN = 100000;
vector<int> G[MN];

int id[MN*2];
int le[MN],ri[MN];
int I;
void dfs(int v,int p=-1){
	id[I]=v,le[v]=I++;
	for(int u:G[v]) if(u!=p) dfs(u,v);
	id[I]=v+N,ri[v]=I;
}

void eulertour(int r){
	dfs(r);
}

int main(){
	cin>>N>>Q;
	rep(i,N-1){
		int a,b;
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	eulertour(0);
	val_t be({1,0,0,0,0,0,0,0,0,0});
	segtree_lazy<handler> seg(vector<val_t>(N,be));
//	seg.init(vector<val_t>(N,be));
	rep(qt,Q){
		int t,v,x,y;
		cin>>t>>v>>x>>y;
		int l = le[v], r = ri[v];
		if(t==1){
			val_t val = seg.calc(l,r);
			int ans = 0;
			for(int i=x;i<=y;i++) ans+=val.n[i];
			cout<<ans<<endl;
		}else{
			vector<int> vc(10);
			rep(i,10) vc[i]=i;
			vc[x]=y;
			opr_t f(vc);
			seg.update(l,r,f);
		}
	}
}