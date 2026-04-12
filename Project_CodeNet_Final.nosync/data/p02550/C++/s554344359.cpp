#include "bits/stdc++.h"
using namespace std;
//#include "atcoder/all"
//using namespace atcoder;
#define int long long
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define RREP(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define FOR(i, s, n) for (int i = s; i < (int)n; ++i)
#define RFOR(i, s, n) for (int i = (int)n - 1; i >= s; --i)
#define ALL(a) a.begin(), a.end()
#define IN(a, x, b) (a <= x && x < b)
template<class T>istream&operator >>(istream&is,vector<T>&vec){for(T&x:vec)is>>x;return is;}
template<class T>inline void out(T t){cout << t << "\n";}
template<class T,class... Ts>inline void out(T t,Ts... ts){cout << t << " ";out(ts...);}
template<class T>inline bool CHMIN(T&a,T b){if(a > b){a = b;return true;}return false;}
template<class T>inline bool CHMAX(T&a,T b){if(a < b){a = b;return true;}return false;}
constexpr int INF = 1e18;

template<int MOD> struct Fp {
	long long val;
	constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
		if (val < 0) val += MOD;
	}
	constexpr int getmod() { return MOD; }
	constexpr Fp operator - () const noexcept {
		return val ? MOD - val : 0;
	}
	constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
	constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
	constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
	constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
	constexpr Fp& operator += (const Fp& r) noexcept {
		val += r.val;
		if (val >= MOD) val -= MOD;
		return *this;
	}
	constexpr Fp& operator -= (const Fp& r) noexcept {
		val -= r.val;
		if (val < 0) val += MOD;
		return *this;
	}
	constexpr Fp& operator *= (const Fp& r) noexcept {
		val = val * r.val % MOD;
		return *this;
	}
	constexpr Fp& operator /= (const Fp& r) noexcept {
		long long a = r.val, b = MOD, u = 1, v = 0;
		while (b) {
			long long t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		val = val * u % MOD;
		if (val < 0) val += MOD;
		return *this;
	}
	constexpr bool operator == (const Fp& r) const noexcept {
		return this->val == r.val;
	}
	constexpr bool operator != (const Fp& r) const noexcept {
		return this->val != r.val;
	}
	friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
		return os << x.val;
	}
	friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
		if (n == 0) return 1;
		auto t = modpow(a, n / 2);
		t = t * t;
		if (n & 1) t = t * a;
		return t;
	}
};
 

template<class T> struct BiCoef {
	vector<T> fact_, inv_, finv_;
	constexpr BiCoef() {}
	constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
		init(n);
	}
	constexpr void init(int n) noexcept {
		fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
		int MOD = fact_[0].getmod();
		for(int i = 2; i < n; i++){
			fact_[i] = fact_[i-1] * i;
			inv_[i] = -inv_[MOD%i] * (MOD/i);
			finv_[i] = finv_[i-1] * inv_[i];
		}
	}
	constexpr T com(int n, int k) const noexcept {
		if (n < k || n < 0 || k < 0) return 0;
		return fact_[n] * finv_[k] * finv_[n-k];
	}
	constexpr T P(int n, int k) const noexcept {
		if (n < k || n < 0 || k < 0) return 0;
		return fact_[n] * finv_[n-k];
	}
	constexpr T fact(int n) const noexcept {
		if (n < 0) return 0;
		return fact_[n];
	}
	constexpr T inv(int n) const noexcept {
		if (n < 0) return 0;
		return inv_[n];
	}
	constexpr T finv(int n) const noexcept {
		if (n < 0) return 0;
		return finv_[n];
	}
};
 
// const int MOD = 1000000007;
const int MOD = 998244353;
using mint = Fp<MOD>;
BiCoef<mint> bc;
// bc.init(500050);

template <typename T>
struct SegmentTree{
  using F = function<T(T,T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;

  SegmentTree(){}
  SegmentTree(F f,T ti):f(f),ti(ti){}

  void init(int n_){
	n=1;
	while(n<n_) n<<=1;
	dat.assign(n<<1,ti);
  }

  void build(const vector<T> &v){
	int n_=v.size();
	init(n_);
	for(int i=0;i<n_;i++) dat[n+i]=v[i];
	for(int i=n-1;i;i--)
	  dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }

  void set_val(int k,T x){
	dat[k+=n]=x;
	while(k>>=1)
	  dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
  }

  T query(int a,int b){
	if(a>=b) return ti;
	T vl=ti,vr=ti;
	for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
	  if(l&1) vl=f(vl,dat[l++]);
	  if(r&1) vr=f(dat[--r],vr);
	}
	return f(vl,vr);
  }

  template<typename C>
  int find(int st,C &check,T &acc,int k,int l,int r){
	if(l+1==r){
	  acc=f(acc,dat[k]);
	  return check(acc)?k-n:-1;
	}
	int m=(l+r)>>1;
	if(m<=st) return find(st,check,acc,(k<<1)|1,m,r);
	if(st<=l&&!check(f(acc,dat[k]))){
	  acc=f(acc,dat[k]);
	  return -1;
	}
	int vl=find(st,check,acc,(k<<1)|0,l,m);
	if(~vl) return vl;
	return find(st,check,acc,(k<<1)|1,m,r);
  }

  template<typename C>
  int find(int st,C &check){
	T acc=ti;
	return find(st,check,acc,1,0,n);
  }
  //アウトの条件を渡す
};

signed main(){
	int N, X, M;
	cin >> N >> X >> M;
	int g = gcd(X, M);
	int mul = X;
	int loop = 0;
	vector<int>cnt;
	set<int>st;
	do{
		cnt.emplace_back(mul);
		st.insert(mul);
		mul *= mul;
		mul %= M;
		//out(mul);
	}while(st.find(mul) == st.end());
	if(mul == 0) {
		out(accumulate(ALL(cnt), 0ll));
		return 0;
	}
	if(N < cnt.size()) {
		int ans = 0;
		REP(i, N) ans += cnt[i];
		out(ans);
		return 0;
	}
	int ans = 0;
	int start = 0;
	while(1) {
		if(cnt[start] == mul) break;
		ans += cnt[start];
		start++;
		N--;
	}
	vector<int>v;
	FOR(i, start, cnt.size()) v.emplace_back(cnt[i]);
	ans += (N / v.size()) * accumulate(ALL(v), 0ll);
	REP(i, N % v.size()) ans += v[i];
	out(ans);
}