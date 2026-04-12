#include "bits/stdc++.h"
#include <random>
using namespace std;
using ll    =long long;    using dd   =double;        using pll    =pair<ll, ll>;  using tll    =tuple<ll,ll,ll>;
using vll   =vector<ll>;   using vdd  =vector<dd>;    using vpll   =vector<pll>;   using vtll   =vector<tll>;
using vvll  =vector<vll>;  using vvdd =vector<vdd>;   using vvpll  =vector<vpll>;  using vvtll  =vector<vtll>;
using vvvll =vector<vvll>; using vvvdd=vector<vvdd>;  using vvvpll =vector<vvpll>; using vvvtll =vector<vvtll>;
using vvvvll=vector<vvvll>;using vvvvdd=vector<vvvdd>;using vvvvpll=vector<vvvpll>;using vvvvtll=vector<vvvtll>;

constexpr ll INF = 1LL << 60;
constexpr dd EPS = 1e-11;

//cin,cout高速化のおまじない＋桁数指定
struct Fast{
	Fast(){
		cin.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(std::numeric_limits<double>::max_digits10);
	}
} fast;

#define REPS(i, S, E) for (ll i = (S); i <= (E); i++)
#define rep(i, S, E) REPS(i, S, E)
#define REP(i, N) REPS(i, 0, (N)-1)
#define DEPS(i, S, E) for (ll i = (E); i >= (S); i--)
#define dep(i, E, S) DEPS(i, S, E)
#define DEP(i, N) DEPS(i, 0, (N)-1)
#define EACH(e, v) for (auto&& e : v)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }
template<class T> inline T MaxE(vector<T>&v,ll S,ll E){T m=v[S]; REPS(i,S,E)chmax(m,v[i]); return m;}//v[S]～v[E]の最大値
template<class T> inline T MinE(vector<T>&v,ll S,ll E){T m=v[S]; REPS(i,S,E)chmin(m,v[i]); return m;}//v[S]～v[E]の最小値
template<class T> inline T MaxE(vector<T> &v, ll N) { return MaxE(v, 0, N - 1); } //先頭N個中の最大値
template<class T> inline T MinE(vector<T> &v, ll N) { return MinE(v, 0, N - 1); }
template<class T> inline T MaxE(vector<T> &v) { return MaxE(v, (ll)v.size()); }
template<class T> inline T MinE(vector<T> &v) { return MinE(v, (ll)v.size()); }
template<class T> inline ll MaxI(vector<T>&v,ll S,ll E){ll m=S; REPS(i,S,E){if(v[i]>v[m])m=i;} return m;}
template<class T> inline ll MinI(vector<T>&v,ll S,ll E){ll m=S; REPS(i,S,E){if(v[i]<v[m])m=i;} return m;}
template<class T> inline ll MaxI(vector<T> &v, ll N) { return MaxI(v, 0, N - 1); }
template<class T> inline ll MinI(vector<T> &v, ll N) { return MinI(v, 0, N - 1); }
template<class T> inline ll MaxI(vector<T> &v) { return MaxI(v, (ll)v.size()); }
template<class T> inline ll MinI(vector<T> &v) { return MinI(v, (ll)v.size()); }
template<class T> inline T Sum(vector<T> &v, ll S,ll E){ T s=v[S]; REPS(i,S+1,E)s+=v[i]; return s; }
template<class T> inline T Sum(vector<T> &v, ll N) { return Sum(v, 0, N - 1); }
template<class T> inline T Sum(vector<T> &v) { return Sum(v, v.size()); }
template<class T> inline ll sz(T &v){ return (ll)v.size(); }
template<class T> inline T POW(T a, ll n){ T r=1; for (; n>0; n>>=1, a*=a){ if (n&1)r*=a; } return r; }
inline ll POW(int a, ll n){ return POW((ll)a, n); }
inline ll MSB(ll a){for(ll o=63,x=-1;;){ll m=(o+x)/2; if(a<(1LL<<m))o=m; else x=m; if(o-x==1)return x;}}
inline ll CEIL(ll a, ll b){ return (a+b-1)/b; }
ll Gcd(ll a, ll b){ return (b==0) ? a : Gcd(b, a%b); }
ll Lcm(ll a, ll b){ return a * b / Gcd(a, b); }
inline vll Bit2Idx(ll m){vll v; for(ll i=0;m;m>>=1,i++) if(m&1)v.push_back(i); return move(v);}
inline ll BitNum(ll m){ for (ll c=0;; m>>=1){ c+=m&1; if (!m)return c; } }
inline ll Bit(ll s, ll i){ return (s>>i)&1; } //sの第ibit i=0-63
[[nodiscard]] inline ll BitOn(ll s, ll i){ return s|(1LL<<i); } //sの第ibitON i=0-63
[[nodiscard]] inline ll BitOff(ll s, ll i){ return s&~(1LL<<i); } //sの第ibitOFF i=0-63
[[nodiscard]] inline ll BitCut(ll s, ll i){ return s & (1LL<<++i)-1; }//sの第0～第ibitを抽出
template<class T> inline ll UnderNumOf(vector<T> &v, T x){ //sort済vのx以下の個数を得る
	return upper_bound(v.begin(), v.end(), x) - v.begin(); }
template<class T, class Pr> inline ll UnderNumOf(vector<T> &v, T x, Pr pred){ //x以下個数
	return upper_bound(v.begin(), v.end(), x, pred) - v.begin(); }
template<class T> inline ll OverNumOf(vector<T> &v, T x){ //sort済vのx以上の個数を得る
	return (ll)v.size() - (lower_bound(v.begin(), v.end(), x) - v.begin()); }
template<class T, class Pr> inline ll OverNumOf(vector<T> &v, T x, Pr pred){ //x以上の個数
	return (ll)v.size() - (lower_bound(v.begin(), v.end(), x, pred) - v.begin()); }

template<class T=ll> inline vector<T> cinv(ll N){ vector<T> v(N); REP(i, N)cin>>v[i]; return move(v);}
template<class T=ll, class S=ll> inline vector<pair<T, S>> cinv2(ll N){
	vector<pair<T, S>> v(N); REP(i,N){cin>>v[i].first>>v[i].second;} return move(v); }
template<class T=ll,class S=ll,class R=ll> inline vector<tuple<T, S, R>> cinv3(ll N){
	vector<tuple<T,S,R>> v(N); REP(i,N){cin>>get<0>(v[i])>>get<1>(v[i])>>get<2>(v[i]);} return move(v);}
template<class T=ll,class S=ll,class R=ll,class Q=ll> inline vector<tuple<T,S,R,Q>> cinv4(ll N){
	vector<tuple<T,S,R,Q>> v(N); REP(i,N){cin>>get<0>(v[i])>>get<1>(v[i])>>get<2>(v[i])>>get<3>(v[i]);} return move(v);}
template<class T=ll> inline vector<vector<T>> cinvv(ll N, ll M){
	vector<vector<T>> vv(N); REP(i, N) vv[i] = cinv(M); return move(vv);}
template<class T> inline void coutv(vector<T> &v, char deli=' '){
	ll N=(ll)v.size(); REP(i,N){cout << v[i] << ((i==N-1)?'\n':deli);} }
template<class T> void bye(T a){cout << a << '\n'; exit(0);}

#if defined(_DEBUG)
ll dumpW = 5;
template<class T> void Dump(vector<T> &v){
	REP(i, (ll)v.size()) { cerr << ((i==0)?"[":" ") << setw(dumpW) << v[i]; }  cerr << "]";
}
void Dump(vll &v){
	REP(i, (ll)v.size()) {
		cerr << ((i==0)?"[":" ") << setw(dumpW);
		if       (v[i] == INF) cerr << "INF";
		else if (v[i] == -INF) cerr << "-INF";
		else                   cerr << v[i];
	}  cerr << "]";
}
template<class T> void Dump(vector<vector<T>> &v){
	ll N=(ll)v.size();  string d[2][2]={{" ", "["},  {"\n", "]\n"}};
	REP(i, N) { cerr << d[0][i==0];  Dump(v[i]);  cerr << d[1][i==N-1]; }
}
template<class T> void Dump(vector<vector<vector<T>>> &v){
	ll N=(ll)v.size();  string d[2]={"  <", "[ <"};
	REP(i, N) { cerr << d[i==0] << i << ">\n"; Dump(v[i]); }  cerr << "]\n";
}
template<class T> void Dump(vector<vector<vector<vector<T>>>> &v){
	ll N=(ll)v.size();  string d[2]={"  ---<", "[ ---<"};
	REP(i, N) { cerr << d[i==0] << i << ">---\n"; Dump(v[i]); }  cerr << "]\n";
}
template<class T> void Dump(vector<vector<vector<vector<vector<T>>>>> &v){
	ll N=(ll)v.size();  string d[2]={"  ======<", "[ ======<"};
	REP(i, N) { cerr << d[i==0] << i << ">======\n"; Dump(v[i]); }  cerr << "]\n";
}
#else
template<class T> void Dump(vector<T> &v){}
template<class T> void Dump(vector<vector<T>> &v){}
template<class T> void Dump(vector<vector<vector<T>>> &v){}
template<class T> void Dump(vector<vector<vector<vector<T>>>> &v){}
template<class T> void Dump(vector<vector<vector<vector<vector<T>>>>> &v){}
#endif

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
	friend mll_ operator + (ll a, const mll_ &b) { return b + a; }
	friend mll_ operator - (ll a, const mll_ &b) { return -b + a; }
	friend mll_ operator * (ll a, const mll_ &b) { return b * a; }
	friend mll_ operator / (ll a, const mll_ &b) { return mll_(a)/b; }
	mll_ &operator += (const mll_ &b) { val=(val+b.val)%MOD; return *this; }
	mll_ &operator -= (const mll_ &b) { val=(val+MOD-b.val)%MOD; return *this; }
	mll_ &operator *= (const mll_ &b) { val=(val*b.val)%MOD; return *this; }
	mll_ &operator /= (const mll_ &b) {
		ll c=b.val, d=MOD, u=1, v=0;
		while (d){
			ll t = c / d;
			c -= t * d; swap(c, d);
			u -= t * v; swap(u, v);
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
	friend bool operator == (ll a, const mll_ &b) { return mll_(a) == b.val; }
	friend bool operator != (ll a, const mll_ &b) { return mll_(a) != b.val; }
	friend ostream &operator << (ostream &os, const mll_ &a) { return os << a.val; }
	friend istream &operator >> (istream &is, mll_ &a) { return is >> a.val; }
	static mll_ Combination(ll a, ll b){
		chmin(b, a-b);
		if (b<0) return mll_(0);
		mll_ c = 1;
		REP(i, b) c *= a-i;
		REP(i, b) c /= i+1;
		return c;
	}
};
using mll = mll_<998244353LL>; //1000000007LL;// 998244353LL;
using vmll = std::vector<mll>;
using vvmll = std::vector<vmll>;
using vvvmll = std::vector<vvmll>;
using vvvvmll = std::vector<vvvmll>;
using vvvvvmll = std::vector<vvvvmll>;


using ull = unsigned long long;

void calc(){
	ll N=1;
	vector<ull> S = cinv<ull>(N);
	vector<ull> T = cinv<ull>(N);
	vector<ull> U = cinv<ull>(N);
	vector<ull> V = cinv<ull>(N);
	if (U[0] != V[0]) bye(-1);
	cout << U[0] << '\n';
}

void solve()
{
	ll N;  cin >> N;
	if (N==1) {
		calc();
		return;
	}
	vector<ull> S = cinv<ull>(N);
	vector<ull> T = cinv<ull>(N);
	vector<ull> U = cinv<ull>(N);
	vector<ull> V = cinv<ull>(N);
	vector<vector<ull>> ans(N, vector<ull>(N));

	rep(b, 0, 63){
		vll u(N);
		bool u0=false, u1=false, u2=false, u3=false;
		ll uc0=0, uc1=0, uc2=0, uc3=0;
		rep(i, 0, N-1){
			if (S[i]==0){
				if (Bit(U[i], b)==1) { u[i]=1; u1=true; uc1++; }
				else                 { u[i]=2; u2=true; uc2++; }
			}
			else if (S[i]==1){
				if (Bit(U[i], b)==0) { u[i]=0; u0=true; uc0++; }
				else                 { u[i]=3; u3=true; uc3++; }
			}
		}
		vll v(N);
		bool v0=false, v1=false, v2=false, v3=false;
		ll vc0=0, vc1=0, vc2=0, vc3=0;
		rep(j, 0, N-1){
			if (T[j]==0){
				if (Bit(V[j], b)==1) { v[j]=1; v1=true; vc1++; }
				else                 { v[j]=2; v2=true; vc2++; }
			}
			else if (T[j]==1){
				if (Bit(V[j], b)==0) { v[j]=0; v0=true; vc0++; }
				else                 { v[j]=3; v3=true; vc3++; }
			}
		}

		///// 全面0/1の時
		if (u0==false && u2==false && u3==false){//全面1
			if (v0==true || v2==true) bye(-1);
			rep(i, 0, N-1)rep(j, 0, N-1) ans[i][j] = BitOn (ans[i][j], b);
		}
		else if (u1==false && u2==false && u3==false){//全面0
			if (v1==true || v3==true) bye(-1);
			rep(i, 0, N-1)rep(j, 0, N-1) ans[i][j] = BitOff(ans[i][j], b);
		}
		else if (v0==false && v2==false && v3==false){//全面1
			if (u0==true || u2==true) bye(-1);
			rep(i, 0, N-1)rep(j, 0, N-1) ans[i][j] = BitOn (ans[i][j], b);
		}
		else if (v1==false && v2==false && v3==false){//全面0
			if (u1==true || u3==true) bye(-1);
			rep(i, 0, N-1)rep(j, 0, N-1) ans[i][j] = BitOff(ans[i][j], b);
		}
		///// 片辺はN-1個0/1、もう片辺は全部2/3の時
		else if (uc1==N-1 && u0==false && (v0==false && v1==false) ){//uがN-1個1
			if (u3==true && vc2==N) bye(-1);
			rep(i, 0, N-1){
				if (u[i]==1) rep(j, 0, N-1) ans[i][j] = BitOn (ans[i][j], b);
				else{
					ll c=0;
					rep(j, 0, N-1){
						if (v[j]==2 || c>0) ans[i][j] = BitOff(ans[i][j], b);
						else                ans[i][j] = BitOn (ans[i][j], b);
						if (v[j]==3) c++;
					}
				}
			}
		}
		else if (uc0==N-1 && u1==false && (v0==false && v1==false) ){//uがN-1個0
			if (u2==true && vc3==N) bye(-1);
			rep(i, 0, N-1){
				if (u[i]==0) rep(j, 0, N-1) ans[i][j] = BitOff(ans[i][j], b);
				else{
					ll c=0;
					rep(j, 0, N-1){
						if (v[j]==3 || c>0) ans[i][j] = BitOn (ans[i][j], b);
						else                ans[i][j] = BitOff(ans[i][j], b);
						if (v[j]==2) c++;
					}
				}
			}
		}
		else if (vc1==N-1 && v0==false && (u0==false && u1==false) ){//vがN-1個1
			if (v3==true && uc2==N) bye(-1);
			rep(j, 0, N-1){
				if (v[j]==1) rep(i, 0, N-1) ans[i][j] = BitOn (ans[i][j], b);
				else{
					ll c=0;
					rep(i, 0, N-1){
						if (u[i]==2 || c>0) ans[i][j] = BitOff(ans[i][j], b);
						else                ans[i][j] = BitOn (ans[i][j], b);
						if (u[i]==3) c++;
					}
				}
			}
		}
		else if (vc0==N-1 && v1==false && (u0==false && u1==false) ){//vがN-1個0
			if (v2==true && uc3==N) bye(-1);
			rep(j, 0, N-1){
				if (v[j]==0) rep(i, 0, N-1) ans[i][j] = BitOff(ans[i][j], b);
				else{
					ll c=0;
					rep(i, 0, N-1){
						if (u[i]==3 || c>0) ans[i][j] = BitOn (ans[i][j], b);
						else                ans[i][j] = BitOff(ans[i][j], b);
						if (u[i]==2) c++;
					}
				}
			}
		}
		//uが全部2or3の時
		else if (u0==false && u1==false){
			rep(j, 0, N-1){
				if (v[j]==0){
					rep(ii, 0, N-1){
						ans[ii][j] = BitOff(ans[ii][j], b);
					}
				}
				else if (v[j] == 1){
					rep(ii, 0, N-1){
						ans[ii][j] = BitOn(ans[ii][j], b);
					}
				}
				else{
					rep(ii, 0, N-1){
						if ((ii+j)%2==0) ans[ii][j] = BitOff(ans[ii][j], b);
						else             ans[ii][j] = BitOn (ans[ii][j], b);
					}
				}
			}
		}
		//tが全部2or3の時
		else if (v0==false && v1==false){
			rep(i, 0, N-1){
				if (u[i]==0){
					rep(jj, 0, N-1){
						ans[i][jj] = BitOff(ans[i][jj], b);
					}
				}
				else if (u[i] == 1){
					rep(jj, 0, N-1){
						ans[i][jj] = BitOn (ans[i][jj], b);
					}
				}
				else{
					rep(jj, 0, N-1){
						if ((i+jj)%2==0) ans[i][jj] = BitOff(ans[i][jj], b);
						else             ans[i][jj] = BitOn (ans[i][jj], b);
					}
				}
			}
		}
		//uに0も1もある
		else if (u0==true && u1==true) bye(-1);
		//vに0も1もある
		else if (v0==true && v1==true) bye(-1);
		//uに0のみ
		else if (u0==true){
			if (v1==true) bye(-1);
			else if (v0==true){
				rep(i, 0, N-1)rep(j, 0, N-1){
					if (u[i]==0 || v[j]==0){
						ans[i][j] = BitOff(ans[i][j], b);
					}
					else{
						ans[i][j] = BitOn (ans[i][j], b);
					}
				}
			}
			else bye(-1);
		}
		//uに1のみ
		else if (u1==true){
			if (v0==true) bye(-1);
			else if (v1==true){
				rep(i, 0, N-1)rep(j, 0, N-1){
					if (u[i]==1 || v[j]==1){
						ans[i][j] = BitOn (ans[i][j], b);
					}
					else{
						ans[i][j] = BitOff(ans[i][j], b);
					}
				}
			}
		}
	}

	rep(i, 0, N-1){
		coutv(ans[i]);
	}
}


int main(){
#if 1
	solve();
#else
	ll t;  cin >> t;
	rep(i, 0, t-1) solve();
#endif
	return 0;
}
