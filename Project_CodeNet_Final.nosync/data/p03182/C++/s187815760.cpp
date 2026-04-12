#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;(i)--)
#define rrep1(i,n) for(int i=((int)(n));i>0;(i)--)
#define sz(c) ((int)(c).size())
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, ll> P;
typedef pair<int, pair<int, int> > PP;
const int MAX=2e5+10;

template <typename T,typename E>
struct SegmentTree{
	using F = function<T(T,T)>;
	using G = function<T(T,E)>;
	using H = function<E(E,E)>;
	int n,height;
	F f;
	G g;
	H h;
	T ti;
	E ei;
	vector<T> dat;
	vector<E> laz;
	  SegmentTree(F f,G g,H h,T ti,E ei):
	    f(f),g(g),h(h),ti(ti),ei(ei){}
  
	void init(int n_){
		n=1;height=0;
		while(n<n_) n<<=1,height++;
		dat.assign(2*n,ti);
		laz.assign(2*n,ei);
	}
	void build(const vector<T> &v){
		int n_=v.size();
		init(n_);
		for(int i=0;i<n_;i++) dat[n+i]=v[i];
		for(int i=n-1;i;i--)dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
	}
	inline T reflect(int k){
		return laz[k]==ei?dat[k]:g(dat[k],laz[k]);
	}
	inline void eval(int k){
		if(laz[k]==ei) return;
		laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
		laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
		dat[k]=reflect(k);
		laz[k]=ei;
	}
	inline void thrust(int k){
		for(int i=height;i;i--) eval(k>>i);
	}
	inline void recalc(int k){    
		while(k>>=1)dat[k]=f(reflect((k<<1)|0),reflect((k<<1)|1));
	}
	void update(int a,int b,E x){
		thrust(a+=n);
		thrust(b+=n-1);
		for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
			if(l&1) laz[l]=h(laz[l],x),l++;
			if(r&1) --r,laz[r]=h(laz[r],x);
		}
		recalc(a);
		recalc(b);
	}
	void set_val(int a,T x){
		thrust(a+=n);
		dat[a]=x;laz[a]=ei;
		recalc(a);
	}
	T query(int a,int b){
		thrust(a+=n);
		thrust(b+=n-1);
		T vl=ti,vr=ti;
		for(int l=a,r=b+1;l<r;l>>=1,r>>=1) {
			if(l&1) vl=f(vl,reflect(l++));
			if(r&1) vr=f(reflect(--r),vr);
		}
		return f(vl,vr);
	}
};

int N,M;
vector<P> IV[MAX];
void input(){
    cin>>N>>M;
    rep(_,M){
        int l, r;
        ll a;
        cin>>l>>r>>a;
        IV[r].pb(mp(l,a));
    }
}

ll ans;
void solve(){
    auto f=[](ll a,ll b){return max(a,b);};
    auto g=[](ll a,ll b){return a+b;};
    ll ti=0;
    SegmentTree<ll,ll> seg(f,g,g,ti,ti);
    seg.init(N+1);
    rep1(k,N){
        ll x=seg.query(0,k);
        seg.set_val(k, x);
        rep(i,sz(IV[k])){
            P p=IV[k][i];
            int l=p.fi;
            ll a=p.se;
            seg.update(l,k+1,a);
        }
    }
    ans=seg.query(0,N+1);
}

void output(){
    cout<<ans;
}

int main(){
  input();
  solve();
  output();
}