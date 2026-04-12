#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << (x) << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
struct starryskytree{
	int N;
	using D = ll;
	D id_ = 1e17;		//initialize	!!このあとaddクエリがきてもidを超えないようにする!!
	D id  = 1e18;		//id
	vector<D> mn,ad;
	starryskytree(){}
	starryskytree(int n){
		N=1;
		while(N<n) N*=2;
		mn.assign(N*2,id_);
		ad.assign(N*2,0);
	}
	starryskytree(vector<D>& vc){
		int n = vc.size();
		N=1;
		while(N<n) N*=2;
		mn.assign(N*2,id_);
		ad.assign(N*2,0);
		rep(i,n) mn[i+N]=vc[i];
		for(int i=N-1;i>0;i--) mn[i]=min(mn[i*2],mn[i*2+1]);
	}
	void add(int a,int b,D v){
		add(a,b,0,N,1,v);
	}
	void add(int a,int b,int l,int r,int k,D v){
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b){
			ad[k]+=v;
			return;
		}
		add(a,b,l,(l+r)/2,k*2,v);
		add(a,b,(l+r)/2,r,k*2+1,v);
		mn[k]=min(mn[k*2]+ad[k*2],mn[k*2+1]+ad[k*2+1]);
	}
	D getmin(int a,int b){
		return getmin(a,b,0,N,1);
	}
	D getmin(int a,int b,int l,int r,int k){
		if(b<=l||r<=a) return id;
		if(a<=l&&r<=b) return mn[k]+ad[k];
		return ad[k]+min(getmin(a,b,l,(l+r)/2,k*2),getmin(a,b,(l+r)/2,r,k*2+1));
	}
	void assign(int x,ll v){
		add(x,x+1,v-getmin(x,x+1));
	}
	void changemin(int x,ll v){
		D dif = v - getmin(x,x+1);
		if(dif<0) add(x,x+1,dif);
	}
};

using P = pair<int,int>;
int N,M;
V<P> r2lc[200010];
int main(){
	cin>>N>>M;
	ll csum = 0;
	rep(i,M){
		int l,r,c;
		cin>>l>>r>>c;
		l--;
		r2lc[r].pb(P(l,c));
		csum += c;
	}
	starryskytree seg(N+2);

	seg.assign(0,0);
	rep1(i,N){
		ll val = seg.getmin(0,i);
		seg.assign(i,val);
		for(P lc:r2lc[i]){
			int l = lc.fs;
			ll c = lc.sc;
			seg.add(0,l+1,c);
		}
	}
	ll tmp = seg.getmin(0,N+1);
	cout<<csum-tmp<<endl;
}