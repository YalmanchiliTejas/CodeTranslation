#include "bits/stdc++.h"

#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i, x, n) for(int i = x; i >= n; i--)
#define rrep(i, n) RREP(i,n,0)
#define pb push_back
#pragma GCC optimize ("-O3")

using namespace std;

#define DEBUG_IS_VALID

#ifdef DEBUG_IS_VALID
#define DEB 1 
#else
#define DEB 0
#endif
#define DUMPOUT cout
#define dump(...) if(DEB) DUMPOUT<<"  "<<#__VA_ARGS__<<" :["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl<<"    "; if(DEB) dump_func(__VA_ARGS__)
template<typename T1,typename T2>ostream& operator << (ostream& os, pair<T1,T2> p){cout << "(" << p.first << ", " << p.second << ")"; return os;}
template<typename T>ostream& operator << (ostream& os, vector<T>& vec) { os << "{"; for (int i = 0; i<vec.size(); i++) os << vec[i] << (i + 1 == vec.size() ? "" : ", "); os << "}"; return os; }
template<typename T>ostream& operator << (ostream& os, set<T>& st){cout << "{"; for(auto itr = st.begin(); itr != st.end(); itr++) cout << *itr << (next(itr)!=st.end() ? ", " : ""); cout << "}"; return os;}
template<typename T1,typename T2>ostream& operator << (ostream& os, map<T1,T2> mp){cout << "{"; for(auto itr = mp.begin(); itr != mp.end(); itr++) cout << "(" << (itr->first) << ", " << (itr->second) << ")" << (next(itr)!=mp.end() ? "," : ""); cout << "}"; return os; }

void dump_func(){DUMPOUT << endl;}
template <class Head, class... Tail>void dump_func(Head&& head, Tail&&... tail){ DUMPOUT << head; if (sizeof...(Tail) == 0) { DUMPOUT << " "; } else { DUMPOUT << ", "; } dump_func(std::move(tail)...);}
template<class T> inline bool chmax(T& a,T const& b){if(a>=b) return false; a=b; return true;}
template<class T> inline bool chmin(T& a,T const& b){if(a<=b) return false; a=b; return true;}
void _main();
int main(){ cin.tie(0); ios::sync_with_stdio(false); _main(); return 0;}

using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

const int mod=1e9+7,INF=1<<29;
const double EPS=1e-12,PI=3.1415926535897932384626;
const ll lmod = 1e9+7,LINF=1LL<<59; 

template<int MOD> struct ModInt {
    static const int Mod = MOD; unsigned x; ModInt() : x(0) { }
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const { long long a = x, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return ModInt(u); }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ostream& operator<<(ostream& st, const ModInt<MOD> a) { st << a.get(); return st; };
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
    ModInt<MOD> r = 1; while (k) { if (k & 1) r *= a; a *= a; k >>= 1; } return r; }
template<typename T, int FAC_MAX> struct Comb { vector<T> fac, ifac;
    Comb(){fac.resize(FAC_MAX,1);ifac.resize(FAC_MAX,1); for(int i = 1; i < FAC_MAX; i++)fac[i]=fac[i-1]*i;
        ifac[FAC_MAX-1]=T(1)/fac[FAC_MAX-1];for(int i = FAC_MAX-2; i >= 1; i--)ifac[i]=ifac[i+1]*T(i+1);}
    T aPb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b]; }
    T aCb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b] * ifac[b]; }
    T nHk(int n, int k) { if (n == 0 && k == 0) return T(1); if (n <= 0 || k < 0) return 0;
        return aCb(n + k - 1, k); }}; // nHk = (n+k-1)Ck : n is separator

using mint =  ModInt<int(1e9+7)>;
using vm = vector<mint>;

using vd = vector<double>;

template <class Monoid> class SegmentTree{
  private:
    using T = typename Monoid::type;
    int sz, N;
    vector<T> dat;
  public:
    SegmentTree(const vector<T> &vec){
      sz = vec.size(); N = 1; while(N<sz) N<<=1;
      dat.resize(2*N);
      fill(dat.begin(),dat.end(),Monoid::id());
      copy(vec.begin(),vec.end(),dat.begin()+N-1);
      for(int i=N-2;i>=0;i--) dat[i]=Monoid::op(dat[2*i+1],dat[2*i+2]);
    }
    SegmentTree(const int n){
      sz = n; N = 1; while(N<n) N<<=1;
      dat.resize(2*N);
      fill(dat.begin(),dat.end(),Monoid::id());
      for(int i=N-2;i>=0;i--) dat[i]=Monoid::op(dat[2*i+1],dat[2*i+2]);
    }
    void update(int i,T val){
      assert(0<=i && i<sz);
      dat[i+=N-1] = val;
      while(i>0){
        i=(i-1)/2;
        dat[i]=Monoid::op(dat[2*i+1],dat[2*i+2]);
      }
      return;
    }
    T query(int a,int b){ // op[a,b)
      return query(a,b,0,0,N);}
    T query(int a,int b,int k,int l,int r){
      assert(0<=l && l<=r && r<2*N);
      if(r<=a || b<=l) return Monoid::id();
      else if(a<=l && r<=b) return dat[k];
      else{
        T lval=query(a,b,2*k+1,l,(l+r)/2);
        T rval=query(a,b,2*k+2,(l+r)/2,r);
        return Monoid::op(lval,rval);
      }
    }
};

struct RMQ{
  using type = ll;
  static type id(){return -LINF;}
  static type op(const type &a ,const type &b){return max(a,b);}
};
 

struct Mat {
  vector<vector<ll>> v;
  Mat(int n):v(n,vector<ll>(n)){};
  Mat(const vector<vector<ll>>& v):v(v){};
};
Mat mulmat(Mat& a,Mat& b) {
  int n = a.v.size();
	ll mo2=4*lmod*lmod;
	int x,y,z; Mat r(n);
	rep(x,n) rep(y,n) r.v[x][y]=0;
	rep(x,n) rep(z,n) rep(y,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
		if(r.v[x][y]>mo2) r.v[x][y] -= mo2;
	}
	rep(x,n) rep(y,n) r.v[x][y]%=lmod;
	return r;
}

Mat powmat(ll p,Mat a) {
  int n = a.v.size();
	int i,x,y; Mat r(n);
	rep(x,n) rep(y,n) r.v[x][y]=0;
	rep(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a);
		a=mulmat(a,a);
		p>>=1;
	}
	return r;
}


void _main(){
  string K; cin >> K ;
  int D; cin >> D ;
  int N = K.size();
  vector<vm> dp1(N+1,vm(D)),dp2(N+1,vm(D)); // equal, less
  dp1[0][0] = 1;
  rep(i,N){
    int num = int(K[i]-'0');
    rep(j,D){
      rep(d,num) dp2[i+1][(j+d)%D] += dp1[i][j];
      dp1[i+1][(j+num)%D] += dp1[i][j];
      rep(d,10) dp2[i+1][(j+d)%D] += dp2[i][j];
    }
  }
  mint ans = 0;
  cout << dp1[N][0]+dp2[N][0]-mint(1) << endl;
}