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
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
template<unsigned int mod_>
struct ModInt{
	using uint = unsigned int;
	using ll = long long;
	using ull = unsigned long long;

	constexpr static uint mod = mod_;

	uint v;
	ModInt():v(0){}
	ModInt(ll v):v(normS(v%mod+mod)){}
	explicit operator bool() const {return v!=0;}
	static uint normS(const uint &x){return (x<mod)?x:x-mod;}		// [0 , 2*mod-1] -> [0 , mod-1]
	static ModInt make(const uint &x){ModInt m; m.v=x; return m;}
	ModInt operator+(const ModInt& b) const { return make(normS(v+b.v));}
	ModInt operator-(const ModInt& b) const { return make(normS(v+mod-b.v));}
	ModInt operator-() const { return make(normS(mod-v)); }
	ModInt operator*(const ModInt& b) const { return make((ull)v*b.v%mod);}
	ModInt operator/(const ModInt& b) const { return *this*b.inv();}
	ModInt& operator+=(const ModInt& b){ return *this=*this+b;}
	ModInt& operator-=(const ModInt& b){ return *this=*this-b;}
	ModInt& operator*=(const ModInt& b){ return *this=*this*b;}
	ModInt& operator/=(const ModInt& b){ return *this=*this/b;}
	ll extgcd(ll a,ll b,ll &x,ll &y) const{
		ll u[]={a,1,0},v[]={b,0,1};
		while(*v){
			ll t=*u/ *v;
			rep(i,3) swap(u[i]-=t*v[i],v[i]);
		}
		if(u[0]<0) rep(i,3) u[i]=-u[i];
		x=u[1],y=u[2];
		return u[0];
	}
	ModInt inv() const{
		ll x,y;
		extgcd(v,mod,x,y);
		return make(normS(x+mod));
	}
	bool operator==(const ModInt& b) const { return v==b.v;}
	bool operator!=(const ModInt& b) const { return v!=b.v;}
	friend istream& operator>>(istream &o,ModInt& x){
		ll tmp;
		o>>tmp;
		x=ModInt(tmp);
		return o;
	}
	friend ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}
};
using mint = ModInt<1000000007>;
mint ex(mint x,int p){
	mint a = 1;
	while(p){
		if(p&1) a*=x;
		x*=x;
		p/=2;
	}
	return a;
}

int N;
using P = pair<int,int>;
vector<int> h;
using State = array<int,3>;	//l,r,hastwo?
vector<P> pranges;
map<State,mint> dp,ndp;
using P = pair<int,int>;
int prevx;
void calc(P ran,int X){
	int L = ran.fs, R = ran.sc;
	int K = pranges.size();
	int i = L;
	mint f[2] = {}, nf[2] = {};
	f[0] = 1;
	while(i!=R+1){
		int id = lower_bound(all(pranges),P(i,-1))-pranges.begin();
		int j = -1;
		bool isempty = 0;
		if(id==K || pranges[id].fs!=i){	//empty
			if(id==K) j = R;
			else j = min(R,pranges[id].fs-1);
			isempty = 1;
		}else{
			j = pranges[id].sc;
		}
		assert(j!=-1);
		int len = j-i+1;
		mint x,y;
//		printf("(i,j) = %d,%d\n",i,j);

		if(isempty){
			x = 2, y = ex(2,len)-2;
		}else{
			int dh = prevx-X;
			mint a = dp[{i,j,0}];
			mint b = dp[{i,j,1}];
			x = a*ex(2,dh);
			y = b;
		}
		if(i==L){
			nf[0] += f[0]*x;
			nf[1] += f[0]*y+f[1]*(x+y);
		}else{
			nf[0] += f[0]*x/2;
			nf[1] += f[0]*(x/2+y)+f[1]*(x+y);
		}

		rep(d,2) f[d] = nf[d], nf[d] = 0;
		i = j+1;
	}
	ndp[{L,R,0}] = f[0];
	ndp[{L,R,1}] = f[1];
//	printf("[%d,%d]   val = %d,%d\n",L,R,f[0].v,f[1].v);
}
int main(){
	cin>>N;
	h.resize(N);
	rep(i,N) cin>>h[i];
	vector<int> xs;
	rep(i,N){
		xs.pb(h[i]-1);
	}
	xs.pb(0);
	sort(all(xs));
	xs.erase(unique(xs.begin(),xs.end()),xs.end());
	reverse(all(xs));
	prevx = -1;
	for(int x:xs){
//		printf("-------x = %d---------\n",x);
		vector<P> ps;
		int l = -1;
		rep(i,N){
			if(h[i]>x){
				if(l==-1) l = i;
			}else{
				if(l!=-1) ps.pb(P(l,i-1));
				l = -1;
			}
		}
		if(l!=-1) ps.pb(P(l,N-1));
//		show(ps);
		for(P p:ps){
			calc(p,x);
		}
		dp = ndp;
		ndp.clear();
		prevx = x;
		pranges = ps;
	}
	mint ans = 0;
	for(auto it:dp){
		State s = it.fs;
		mint v = it.sc;
		assert(s[0]==0 && s[1]==N-1);
		ans += v;
	}
	cout<<ans<<endl;
}
