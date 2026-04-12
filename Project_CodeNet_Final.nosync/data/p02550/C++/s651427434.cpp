#include "bits/stdc++.h"
using namespace std;
using     ll=long long;
using    vll=vector<   ll>;
using   vvll=vector<  vll>;
using  vvvll=vector< vvll>;
using vvvvll=vector<vvvll>;
constexpr ll INF = 1LL << 60;
struct Fast{ Fast(){ cin.tie(0); ios::sync_with_stdio(false); cout<<fixed<<setprecision(numeric_limits<double>::max_digits10); } } fast;
#define REPS(i, S, E) for (ll i = (S); i <= (E); i++)
#define REP(i, N) REPS(i, 0, (N)-1)
#define DEPS(i, S, E) for (ll i = (E); i >= (S); i--)
#define DEP(i, N) DEPS(i, 0, (N)-1)
#define rep(i, S, E)  for (ll i = (S); i <= (E); i++)
#define dep(i, E, S)  for (ll i = (E); i >= (S); i--)
#define each(e, v) for (auto&& e : v)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }
template<class T> inline T MaxE(vector<T>&v,ll S,ll E){ T m=v[S]; rep(i,S,E)chmax(m,v[i]); return m; }
template<class T> inline T MinE(vector<T>&v,ll S,ll E){ T m=v[S]; rep(i,S,E)chmin(m,v[i]); return m; }
template<class T> inline T MaxE(vector<T> &v) { return MaxE(v,0,(ll)v.size()-1); }
template<class T> inline T MinE(vector<T> &v) { return MinE(v,0,(ll)v.size()-1); }
template<class T> inline T Sum(vector<T> &v,ll S,ll E){ T s=T(); rep(i,S,E)s+=v[i]; return s; }
template<class T> inline T Sum(vector<T> &v) { return Sum(v,0,v.size()-1); }
template<class T> inline ll sz(T &v){ return (ll)v.size(); }
inline ll CEIL(ll a,ll b){ return (a<0) ? -(-a/b) : (a+b-1)/b; }
inline ll FLOOR(ll a,ll b){ return -CEIL(-a,b); }

template<ll MOD> struct mll_{
	ll val;
	mll_(ll v = 0): val(v % MOD){ if (val < 0) val += MOD; }
	mll_ operator - () const { return -val; }
	mll_ operator + (const mll_ &b) const { return val + b.val; }
	mll_ operator - (const mll_ &b) const { return val - b.val; }
	mll_ operator * (const mll_ &b) const { return val * b.val; }
	mll_ operator / (const mll_ &b) const { return mll_(*this) /= b; }
	mll_ operator + (ll b) const { return *this + mll_(b); }
	mll_ operator - (ll b) const { return *this - mll_(b); }
	mll_ operator * (ll b) const { return *this * mll_(b); }
	friend mll_ operator + (ll a,const mll_ &b) { return b + a; }
	friend mll_ operator - (ll a,const mll_ &b) { return -b + a; }
	friend mll_ operator * (ll a,const mll_ &b) { return b * a; }
	friend mll_ operator / (ll a,const mll_ &b) { return mll_(a)/b; }
	mll_ &operator += (const mll_ &b) { val=(val+b.val)%MOD; return *this; }
	mll_ &operator -= (const mll_ &b) { val=(val+MOD-b.val)%MOD; return *this; }
	mll_ &operator *= (const mll_ &b) { val=(val*b.val)%MOD; return *this; }
	mll_ &operator /= (const mll_ &b) {
		ll c=b.val,d=MOD,u=1,v=0;
		while (d){
			ll t = c / d;
			c -= t * d; swap(c,d);
			u -= t * v; swap(u,v);
		}
		val = val * u % MOD;
		if (val < 0) val += MOD;
		return *this;
	}
	mll_ &operator += (ll b) { return *this += mll_(b); }
	mll_ &operator -= (ll b) { return *this -= mll_(b); }
	mll_ &operator *= (ll b) { return *this *= mll_(b); }
	mll_ &operator /= (ll b) { return *this /= mll_(b); }
	bool operator == (const mll_ &b) { return val == b.val; }
	bool operator != (const mll_ &b) { return val != b.val; }
	bool operator == (ll b) { return *this == mll_(b); }
	bool operator != (ll b) { return *this != mll_(b); }
	friend bool operator == (ll a,const mll_ &b) { return mll_(a) == b.val; }
	friend bool operator != (ll a,const mll_ &b) { return mll_(a) != b.val; }
	friend ostream &operator << (ostream &os,const mll_ &a) { return os << a.val; }
	friend istream &operator >> (istream &is,mll_ &a) { return is >> a.val; }
	static mll_ Combination(ll a,ll b){
		chmin(b,a-b);
		if (b<0) return mll_(0);
		mll_ c = 1;
		rep(i,0,b-1) c *= a-i;
		rep(i,0,b-1) c /= i+1;
		return c;
	}
};
using mll = mll_<998244353LL>;
using vmll    = std::vector<mll>;
using vvmll   = std::vector<vmll>;
using vvvmll  = std::vector<vvmll>;
using vvvvmll = std::vector<vvvmll>;

//vector用テンプレート
template<class T> inline vector<T>& operator+=(vector<T> &a,const vector<T> &b){ for (ll i=0; i<(ll)a.size(); i++) a[i]+=b[i];  return a; }
template<class T> inline vector<T>& operator-=(vector<T> &a,const vector<T> &b){ for (ll i=0; i<(ll)a.size(); i++) a[i]-=b[i];  return a; }
template<class T> inline vector<T>& operator*=(vector<T> &a,const vector<T> &b){ for (ll i=0; i<(ll)a.size(); i++) a[i]*=b[i];  return a; }
template<class T> inline vector<T>& operator/=(vector<T> &a,const vector<T> &b){ for (ll i=0; i<(ll)a.size(); i++) a[i]/=b[i];  return a; }
template<class T> inline vector<T>& operator%=(vector<T> &a,const vector<T> &b){ for (ll i=0; i<(ll)a.size(); i++) a[i]%=b[i];  return a; }
template<class T,class S> inline vector<T>& operator+=(vector<T> &a,S b){ for (T &e: a) e+=b;  return a; }
template<class T,class S> inline vector<T>& operator-=(vector<T> &a,S b){ for (T &e: a) e-=b;  return a; }
template<class T,class S> inline vector<T>& operator*=(vector<T> &a,S b){ for (T &e: a) e*=b;  return a; }
template<class T,class S> inline vector<T>& operator/=(vector<T> &a,S b){ for (T &e: a) e/=b;  return a; }
template<class T,class S> inline vector<T>& operator%=(vector<T> &a,S b){ for (T &e: a) e%=b;  return a; }
template<class T,class S> inline vector<T> operator+(const vector<T> &a,S b){ vector<T> c=a; return c+=b; }
template<class T,class S> inline vector<T> operator-(const vector<T> &a,S b){ vector<T> c=a; return c-=b; }
template<class T,class S> inline vector<T> operator*(const vector<T> &a,S b){ vector<T> c=a; return c*=b; }
template<class T,class S> inline vector<T> operator/(const vector<T> &a,S b){ vector<T> c=a; return c/=b; }
template<class T,class S> inline vector<T> operator%(const vector<T> &a,S b){ vector<T> c=a; return c%=b; }
template<class T,class S> inline vector<T> operator-(S b,const vector<T> &a){ vector<T> c=-a; return c+=b; }
template<class T> inline vector<T> operator-(const vector<T> &a){ vector<T> c=a; return c*=(-1); }
template<class T> inline ostream &operator<<(ostream &os,const vector<T> &a){ for (ll i=0; i<(ll)a.size(); i++) os<<(i>0?" ":"")<<a[i];  return os; }

//pair用テンプレート
using   pll=pair<ll,ll>;
using  vpll=vector< pll>;
using vvpll=vector<vpll>;
template<class T,class S> inline pair<T,S>& operator+=(pair<T,S> &a,const pair<T,S> &b){ a.first+=b.first; a.second+=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator-=(pair<T,S> &a,const pair<T,S> &b){ a.first-=b.first; a.second-=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator*=(pair<T,S> &a,const pair<T,S> &b){ a.first*=b.first; a.second*=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator/=(pair<T,S> &a,const pair<T,S> &b){ a.first/=b.first; a.second/=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator%=(pair<T,S> &a,const pair<T,S> &b){ a.first%=b.first; a.second%=b.second; return a; }
template<class T,class S,class R> inline pair<T,S>& operator+=(pair<T,S> &a,R b){ a.first+=b; a.second+=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator-=(pair<T,S> &a,R b){ a.first-=b; a.second-=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator*=(pair<T,S> &a,R b){ a.first*=b; a.second*=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator/=(pair<T,S> &a,R b){ a.first/=b; a.second/=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator%=(pair<T,S> &a,R b){ a.first%=b; a.second%=b; return a; }
template<class T,class S,class R> inline pair<T,S> operator+(const pair<T,S> &a,R b){ pair<T,S> c=a; return c+=b; }
template<class T,class S,class R> inline pair<T,S> operator-(const pair<T,S> &a,R b){ pair<T,S> c=a; return c-=b; }
template<class T,class S,class R> inline pair<T,S> operator*(const pair<T,S> &a,R b){ pair<T,S> c=a; return c*=b; }
template<class T,class S,class R> inline pair<T,S> operator/(const pair<T,S> &a,R b){ pair<T,S> c=a; return c/=b; }
template<class T,class S,class R> inline pair<T,S> operator%(const pair<T,S> &a,R b){ pair<T,S> c=a; return c%=b; }
template<class T,class S,class R> inline pair<T,S> operator-(R b,const pair<T,S> &a){ pair<T,S> c=-a; return c+=b; }
template<class T,class S> inline pair<T,S> operator-(const pair<T,S> &a){ pair<T,S> c=a; return c*=(-1); }
template<class T,class S> inline ostream &operator<<(ostream &os,const pair<T,S> &a){ return os << a.first << ' ' << a.second; }

#if 0
#include <atcoder/all>
using namespace atcoder;
#endif

inline ll MSB(ll a){
	for(ll o=63,x=-1;;){
		ll m=(o+x)/2;
		if(a<(1LL<<m))o=m; else x=m;
		if(o-x==1)return x;
	}
}
inline ll Upper2N(ll s) { return 1LL<<(MSB(s)+1); }//s<2^nなる最小の2^n
inline ll Bitcount(ll s){ return bitset<64>(s).count(); }
inline vll Bit2Idx(ll s){vll v; for(ll i=0;s;s>>=1,i++) if(s&1)v.push_back(i); return v;}
inline ll Bit(ll s, ll i){ return (s>>i)&1; } //sの第ibit i=0-63
[[nodiscard]] inline ll BitOn(ll s, ll i){ return s|(1LL<<i); } //sの第ibitON i=0-63
[[nodiscard]] inline ll BitOff(ll s, ll i){ return s&~(1LL<<i); } //sの第ibitOFF i=0-63
[[nodiscard]] inline ll BitCut(ll s, ll i){ return s & ((1LL<<++i)-1); }//sの第0～第ibitを抽出


template<class T> struct Dubling{
	vvll next; //!< next[v][i]:vの2^i個先
	vector<vector<T>> dist; //dist[v][i]:vから2^i個先までの距離
	ll N, B;
	Dubling(): N(0), B(0) {}
	Dubling(const vll &nxt, const vector<T> &d, ll nextTimesMax){ Init(nxt, d, nextTimesMax); }
	void Init(const vll &nxt, const vector<T> &d, ll nextTimesMax){
		N = (ll)nxt.size();
		B = MSB(nextTimesMax) + 1;
		next.resize(N, vll(B, INF));
		dist.resize(N, vll(B));
		REP(v, N) next[v][0] = nxt[v];
		REP(v, N) dist[v][0] = d[v];
		REPS(i, 1, B-1) REP(v, N) next[v][i] = next_(next_(v, i-1), i-1);
		REPS(i, 1, B-1) REP(v, N){
			ll u = next[v][i-1];
			dist[v][i] = dist[v][i-1] + dist_(u, i-1);
		}
	}
	pair<ll, T> Times(ll v, ll times){ //!< times個先  times=0も可
		T d = 0;
		DEPS(i, 0, MSB(times)){
			if ((times>>i)&1){
				d +=dist_(v, i);
				v = next_(v, i);
			}
		}
		return pair<ll, T>(v, d);
	}
	ll TimesPow2(ll v, ll i) { return next[v][i]; }  //!< 2^i個先
	ll next_(ll v, ll i){ return (v==INF) ? INF : next[v][i]; }
	T  dist_(ll v, ll i){ return (v==INF) ?   0 : dist[v][i]; }
};



void solve()
{
	ll n,x,m;  cin >> n >> x >> m;

	vll nx(m);
	rep(i,0,m-1){
		nx[i]=(i*i)%m;
	}

	Dubling<ll> dbl(nx,nx,n+10);
	pll e=dbl.Times(x,n-1);
	ll dist=e.second;
	ll ans=dist+x;
	cout << ans << '\n';

}


int main(){
#if 1
	solve();
#else
	ll t;  cin >> t;
	rep(i, 0, t-1){
		solve();
	}
#endif
	return 0;
}
