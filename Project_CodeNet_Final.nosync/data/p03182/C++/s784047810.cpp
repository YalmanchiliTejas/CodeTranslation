#include "bits/stdc++.h"
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
#define REP(i, N) REPS(i, 0, (N)-1)
#define DEPS(i, S, E) for (ll i = (E); i >= (S); i--)
#define DEP(i, N) DEPS(i, 0, (N)-1)
#define EACH(e, v) for (auto&& e : v)

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
template<class T> inline T POW(T a, ll n){ T r=1; for (; n>0; n>>=1, a*=a){ if (n&1)r*=a; } return r; }
inline ll POW(int a, ll n){ return POW((ll)a, n); }
inline ll MSB(ll a){for(ll o=63,x=-1;;){ll m=(o+x)/2; if(a<(1LL<<m))o=m; else x=m; if(o-x==1)return x;}}
inline ll CEIL(ll a, ll b){ return (a+b-1)/b; }
ll Gcd(ll a, ll b){ return (b==0) ? a : Gcd(b, a%b); }
ll Lcm(ll a, ll b){ return a * b / Gcd(a, b); }
inline vll Mask2Idx(ll m){vll v; for(ll i=0;m;m>>=1,i++) if(m&1)v.push_back(i); return move(v);}
inline ll MaskNum(ll m){ for (ll c=0;; m>>=1){ c+=m&1; if (!m)return c; } }
inline ll Bit(ll s, ll i){ return (s>>i)&1; } //sの第ibit i=0-63
inline ll BitOn(ll s, ll i){ return s|(1LL<<i); } //sの第ibitON i=0-63
inline ll BitOff(ll s, ll i){ return s&~(1LL<<i); } //sの第ibitOFF i=0-63

template<class T=ll> inline vector<T> cinv(ll N){ vector<T> v(N); REP(i, N)cin>>v[i]; return move(v);}
template<class T=ll, class S=ll> inline vector<pair<T, S>> cinv2(ll N){
	vector<pair<T, S>> v(N); REP(i,N){cin>>v[i].first>>v[i].second;} return move(v); }
template<class T=ll,class S=ll,class R=ll> inline vector<tuple<T, S, R>> cinv3(ll N){
	vector<tuple<T,S,R>> v(N); REP(i,N){cin>>get<0>(v[i])>>get<1>(v[i])>>get<2>(v[i]);} return move(v);}
template<class T=ll,class S=ll,class R=ll,class Q=ll> inline vector<tuple<T,S,R,Q>> cinv4(ll N){
	vector<tuple<T,S,R,Q>> v(N); REP(i,N){cin>>get<0>(v[i])>>get<1>(v[i])>>get<2>(v[i])>>get<3>(v[i]);} return move(v);}
template<class T> inline void coutv(vector<T> &v, char deli=' '){
	ll N=(ll)v.size(); REP(i,N){cout << v[i] << ((i==N-1)?'\n':deli);} }
template<class T> void bye(T a){cout << a << '\n'; exit(0);}

#if defined(_DEBUG)
template<class T> void Dump(vector<T> &v){
	REP(i, (ll)v.size()) { cerr << ((i==0)?"[":" ") << setw(5) << v[i]; }  cerr << "]";
}
void Dump(vll &v){
	REP(i, (ll)v.size()) {
		cerr << ((i==0)?"[":" ") << setw(4);
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

struct mll{
	static ll MOD;
	ll val;
	mll(ll v = 0): val(v % MOD){ if (val < 0) val += MOD; }
	mll operator - () const { return -val; }
	mll operator + (const mll &b) const { return val + b.val; }
	mll operator - (const mll &b) const { return val - b.val; }
	mll operator * (const mll &b) const { return val * b.val; }
	mll operator / (const mll &b) const { return mll(*this) /= b; }
	mll operator + (ll b) const { return *this + mll(b); }
	mll operator - (ll b) const { return *this - mll(b); }
	mll operator * (ll b) const { return *this * mll(b); }
	friend mll operator + (ll a, const mll &b) { return b + a; }
	friend mll operator - (ll a, const mll &b) { return -b + a; }
	friend mll operator * (ll a, const mll &b) { return b * a; }
	friend mll operator / (ll a, const mll &b) { return mll(a)/b; }
	mll &operator += (const mll &b) { val=(val+b.val)%MOD; return *this; }
	mll &operator -= (const mll &b) { val=(val+MOD-b.val)%MOD; return *this; }
	mll &operator *= (const mll &b) { val=(val*b.val)%MOD; return *this; }
	mll &operator /= (const mll &b) {
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
	mll &operator += (ll b) { return *this += mll(b); }
	mll &operator -= (ll b) { return *this -= mll(b); }
	mll &operator *= (ll b) { return *this *= mll(b); }
	mll &operator /= (ll b) { return *this /= mll(b); }
	bool operator == (const mll &b) { return val == b.val; }
	bool operator != (const mll &b) { return val != b.val; }
	bool operator == (ll b) { return *this == mll(b); }
	bool operator != (ll b) { return *this != mll(b); }
	friend bool operator == (ll a, const mll &b) { return mll(a) == b.val; }
	friend bool operator != (ll a, const mll &b) { return mll(a) != b.val; }
	friend ostream &operator << (ostream &os, const mll &a) { return os << a.val; }
	friend istream &operator >> (istream &is, mll &a) { return is >> a.val; }
	static mll Combination(ll a, ll b){
		chmin(b, a-b);
		if (b<0) return mll(0);
		mll c = 1;
		REP(i, b) c *= a-i;
		REP(i, b) c /= i+1;
		return c;
	}
};
ll mll::MOD = 1000000007LL;// 998244353LL;//1000000007LL;
using vmll = std::vector<mll>;
using vvmll = std::vector<vmll>;
using vvvmll = std::vector<vvmll>;
using vvvvmll = std::vector<vvvmll>;
using vvvvvmll = std::vector<vvvvmll>;




template <typename T, typename E>
struct SegmentTree{
	using F = function<T(T, T)>;
	using G = function<T(T, E)>;
	using H = function<E(E, E)>;
	ll n=0, height=0;
	F f; //!< データ同士の合成関数
	G g; //!< 作用関数
	H h; //!< 作用素同士の合成関数
	T ti; //!< データの単位元 実際の単位元をセットしないとだめ
	E ei; //!< 作用素の単位元 if文で「何もしない」を実現するため、使わない値なら何でもOK
	vector<T> dat;
	vector<E> laz;
	SegmentTree(F f, G g, H h, T ti, E ei):
		f(f), g(g), h(h), ti(ti), ei(ei){}

	void init(ll n_){
		n=1; height=0;
		while (n<n_) n<<=1, height++;
		dat.assign(2*n, ti);
		laz.assign(2*n, ei);
	}
	void build(const vector<T> &v){
		ll n_=(ll)v.size();
		init(n_);
		for (ll i=0; i<n_; i++) dat[n+i]=v[i];
		for (ll i=n-1; i; i--)
			dat[i]=f(dat[(i<<1)|0], dat[(i<<1)|1]);
	}
	inline T reflect(ll k){
		return laz[k]==ei?dat[k]:g(dat[k], laz[k]);
	}
	inline void eval(ll k){
		if (laz[k]==ei) return;
		laz[(k<<1)|0]=h(laz[(k<<1)|0], laz[k]);
		laz[(k<<1)|1]=h(laz[(k<<1)|1], laz[k]);
		dat[k]=reflect(k);
		laz[k]=ei;
	}
	inline void thrust(ll k){
		for (ll i=height; i; i--) eval(k>>i);
	}
	inline void recalc(ll k){
		while (k>>=1)
			dat[k]=f(reflect((k<<1)|0), reflect((k<<1)|1));
	}
	void update(ll a, ll b, E x){
		thrust(a+=n);
		thrust(b+=n-1);
		for (ll l=a, r=b+1; l<r; l>>=1, r>>=1){
			if (l&1) laz[l]=h(laz[l], x), l++;
			if (r&1) --r, laz[r]=h(laz[r], x);
		}
		recalc(a);
		recalc(b);
	}
	void set_val(ll a, T x){ //配列[a]にxをセット aは0-origin
		thrust(a+=n);
		dat[a]=x; laz[a]=ei;
		recalc(a);
	}
	T query(ll a, ll b){ //区間[a,b)の値を得る
		thrust(a+=n);
		thrust(b+=n-1);
		T vl=ti, vr=ti;
		for (ll l=a, r=b+1; l<r; l>>=1, r>>=1) {
			if (l&1) vl=f(vl, reflect(l++));
			if (r&1) vr=f(reflect(--r), vr);
		}
		return f(vl, vr);
	}
	void Dump(ll w=5){
		REP(i, n) for (ll k=i+n, m=0, p=0; k>0; p=m, m+=k%2, k/=2){
			if (!m) cerr << ( (k<n) ?" ┬ ":"");
			else    cerr << ((m&&!p)?" ┘ ":"");
			if (!m) cerr << setw(w) << dat[k] << " /" << setw(w) << laz[k];
			if (k==1) cerr << '\n';
		}
	}
};


void solve()
{
	ll N, M; cin >> N >> M;
	auto lra = cinv3(M);
	EACH(e, lra){
		get<0>(e)--;
		get<1>(e)--;
	}
	sort(lra.begin(), lra.end(),
		[](auto &a, auto &b){return get<1>(a) < get<1>(b); }
	);

	SegmentTree<ll, ll>sgt(
		[](ll x, ll y){ return max(x, y); },//区間合成
		[](ll x, ll y){ return x + y; },//作用
		[](ll x, ll y){ return x + y; },//作用素の合成
		-INF, 0);
	vll initvals(N+1, 0);
	sgt.build(initvals);
	//sgt.Dump();

	ll lraIdx = 0;
	REPS(i, 0, N-1){
		//if (i > 0){
			ll val = sgt.query(0, i+1);
			//sgt.Dump();
			sgt.set_val(i+1, val);
			//sgt.Dump();
		//}
		while (lraIdx < M){
			ll l, r, a; tie(l,r,a) = lra[lraIdx];
			if (r != i) break;

			sgt.update(l+1, i+1+1, a);//lからiの区間に一律aを足す
			//sgt.Dump();
			lraIdx++;
		}
	}
	//sgt.Dump();

	ll ans = sgt.query(0, N+1);
	cout << ans << '\n';

#if 0
	vll v ={3,5,0,1,4,0,1};
	SegmentTree<ll, ll> sgt(
		[](ll i, ll j){ return max(i, j); },//区間合成
		[](ll i, ll j){ return j; },//作用
		[](ll i, ll j){ return max(i, j); },//作用素の合成
		0, //データの単位元
		0); //作用素の単位元

	sgt.build(v);
	sgt.Dump(); cout << '\n';
	sgt.set_val(0, 7);
	sgt.Dump(); cout << '\n';
	sgt.update(3, 5, 2);
	sgt.Dump(); cout << '\n';

	sgt.update(2, 7, 3);
	sgt.Dump(); cout << '\n';

	cout << sgt.query(2, 3) << '\n';
	sgt.Dump(); cout << '\n';
	cout << sgt.query(4, 6) << '\n';
	sgt.Dump(); cout << '\n';
	cout << sgt.query(5, 6) << '\n';
	sgt.Dump(); cout << '\n';
	cout << sgt.query(3, 4) << '\n';
	//sgt.DumpRaw(); cout << '\n';
	cout << sgt.query(4, 5) << '\n';
	//sgt.DumpRaw(); cout << '\n';
	cout << sgt.query(5, 6) << '\n';
	//sgt.DumpRaw(); cout << '\n';
	cout << sgt.query(6, 7) << '\n';
	//sgt.DumpRaw(); cout << '\n';
	cout << sgt.query(7, 8) << '\n';
	sgt.Dump(); cout << '\n';
#endif

#if 0
	//一点更新版segtreeの使用例。後でライブラリに書いておく
	SegmentTree<ll> sgt(v, 0,
		[](ll i, ll j){return max(i,j);}
	);
	sgt.Dump(2);
	sgt.Set(5, 7);
	sgt.Dump(2);
	ll x = sgt[5];
	sgt.Set(7, x*2);
	sgt.Dump(2);
#endif

	///////////////////////////////セグメントツリー書き途中////////
	/*
	区間更新一点取得、遅延伝搬セグメントツリーが完成した。
	次は、
	遅延伝搬セグメントツリーの題材として、
	EDPCのW-Intervalsをやる。
	設計まで完了。_memo.txtを参照。
	*/
}


int main(){
	solve();
	return 0;
}
