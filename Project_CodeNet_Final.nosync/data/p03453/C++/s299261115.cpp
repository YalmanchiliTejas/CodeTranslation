#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
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

template<class D>
vector<pair<D,mint>> dijkstra(const vector<vector<pair<int,D>>>& G, int s = 0){	//G:(v,cost)
	using P = pair<D,int>;
	priority_queue<P,vector<P>,greater<P> > que;
	int N = G.size();

	using DM = pair<D,mint>;

	D inf = 1e18;
	vector<DM> d(N,DM(inf,0));
	d[s] = DM(0,1);
	que.push(P(0,s));

	while(!que.empty()){
		P p=que.top();
		que.pop();
		int v = p.sc;
		D c = p.fs;
		if(d[v].fs!=c) continue;
		for(auto p:G[v]){
			int to=p.fs;
			if(d[to].fs>d[v].fs+p.sc){
				d[to].fs=d[v].fs+p.sc;
				d[to].sc=d[v].sc;
				que.push(P(d[to].fs,to));
			}else if(d[to].fs == d[v].fs+p.sc){
				d[to].sc += d[v].sc;
			}
		}
	}

	return d;
}
using ll = long long;
using P = pair<int,int>;

int xs[200010],ys[200010];
ll cs[200010];

int main(){
	int N,M,S,T;
	cin>>N>>M>>S>>T;
	S--,T--;
	vector<vector<pair<int,ll>>> G(N);
	rep(i,M){
		int x,y;
		ll c;
		cin>>x>>y>>c;
		x--,y--;
		G[x].pb(pair<int,ll>(y,c));
		G[y].pb(pair<int,ll>(x,c));
		xs[i] = x, ys[i] = y, cs[i] = c;
	}
	auto a = dijkstra(G,S);
	auto b = dijkstra(G,T);
	ll dst = a[T].fs;
	mint ans = a[T].sc * b[S].sc;
	rep(v,N){
		if(a[v].fs+b[v].fs==dst && a[v].fs==b[v].fs){
			ans -= a[v].sc*a[v].sc*b[v].sc*b[v].sc;
		}
	}
	rep(e,M){
		int x = xs[e], y = ys[e];
		ll c = cs[e];
		if(a[x].fs + c + b[y].fs != dst) swap(x,y);
		if(a[x].fs + c + b[y].fs != dst) continue;
		if(abs(a[x].fs-b[y].fs)<c) ans -= a[x].sc*a[x].sc*b[y].sc*b[y].sc;
	}
	cout<<ans<<endl;
}
