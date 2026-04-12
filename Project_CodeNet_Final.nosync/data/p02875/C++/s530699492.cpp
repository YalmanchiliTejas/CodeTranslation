#include <bits/stdc++.h>
#define whlie while
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define rep(i,N) for(int i = 0; i < (N); i++)
#define repr(i,N) for(int i = (N) - 1; i >= 0; i--)
#define rep1(i,N) for(int i = 1; i <= (N) ; i++)
#define repr1(i,N) for(int i = (N) ; i > 0 ; i--)
#define each(x,v) for(auto& x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define vrep(v,it) for(auto it = v.begin(); it != v.end(); it++)
#define vrepr(v,it) for(auto it = v.rbegin(); it != v.rend(); it++)
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
using namespace std; void solve();
using ll = long long; using vl = vector<ll>;
using vi = vector<int>; using vvi = vector< vector<int> >;
constexpr int inf = 1001001001;
constexpr ll infLL = (1LL << 61) - 1;
struct IoSetupNya {IoSetupNya() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); cerr << fixed << setprecision(7);} } iosetupnya;
template<typename T, typename U> inline bool amin(T &x, U y) { return (y < x) ? (x = y, true) : false; }
template<typename T, typename U> inline bool amax(T &x, U y) { return (x < y) ? (x = y, true) : false; }
template<typename T, typename U> ostream& operator <<(ostream& os, const pair<T, U> &p) { os << p.first << " " << p.second; return os; }
template<typename T, typename U> istream& operator >>(istream& is, pair<T, U> &p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator <<(ostream& os, const vector<T> &v) { int s = (int)v.size(); rep(i,s) os << (i ? " " : "") << v[i]; return os; }
template<typename T> istream& operator >>(istream& is, vector<T> &v) { for(auto &x : v) is >> x; return is; }
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
template<typename T>void die(T x){out(x); exit(0);}
#ifdef NyaanDebug
  #include "NyaanDebug.h"
  #define trc(...) do { cerr << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__);} while(0)
  #define trca(v,N) do { cerr << #v << " = "; array_out(v , N);cout << endl;} while(0)
#else
  #define trc(...)
  #define trca(...)
  int main(){solve();}
#endif
using P = pair<int,int>; using vp = vector<P>;
constexpr int MOD = /** 1000000007; //*/ 998244353;
////////////////

vector<ll> fac,finv,inv;
void COMinit(int MAX) {
  MAX++;
  fac.resize(MAX , 0);
  finv.resize(MAX , 0);
  inv.resize(MAX , 0);
  fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}
// nCk combination 
inline long long COM(int n,int k){
  if(n < k || k < 0 || n < 0) return 0;
  else return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// nPk permutation
inline long long PER(int n,int k){
  if (n < k || k < 0 || n < 0) return 0;
  else return (fac[n] * finv[n - k]) % MOD;
}
// nHk homogeneous polynomial
inline long long HGP(int n,int k){
  if(n == 0 && k == 0) return 1; //問題依存?
  else if(n < 1 || k < 0) return 0;
  else return fac[n + k - 1] * (finv[k] * finv[n - 1] % MOD) % MOD;
}

template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

using modint = ModInt< MOD >;

// 累積演算ライブラリ Accumulated Operation Library
template<typename T>
struct ACC{
  private:
    vector<T> Head,Tail;
    function<T(T,T)> f = [](T a,T b){return a + b;};
    function<T(T,T)> f_inv = [](T a,T b){return a - b;};
    T UNIT = 0;
  public:
    // Head[i]には[0 , i)の結果を代入する
    // Tail[i]には[i , N)の結果を代入する
    ACC(const vector<T> &v){
      int N = int(v.size());
      Head.resize(N + 1);
      Tail.resize(N + 1);
      Head[0] = Tail[N] = UNIT;
      for(int i = 0, j = N; i < N ; i++,j--){
        Head[i + 1] = f( Head[i] , v[i]);
        Tail[j - 1] = f( Tail[j] , v[j - 1]);
      }
    };
    // 半開区間[0 , k)の演算結果を返す
    T head(int k){ return Head[k]; }
    // 半開区間[k , N)の演算結果を返す
    T tail(int k){ return Tail[k]; }
    // 逆演算の存在するとき半開区間[l , r)の演算結果を返す
    T query(int l,int r){
      return f_inv(Head[r] , Head[l]);
    }
};

void solve(){
  inl(N);
  vl beki(N/2 + 10);
  COMinit(N / 2 + 10);
  beki[0] = 1;
  rep1(i , N / 2 + 2){
    beki[i] = beki[i - 1] * 2;
    if(beki[i] >= MOD) beki[i] -= MOD;
  }
  vector<modint> a(N / 2 + 1);
  rep(k , N / 2 + 1){
    a[k] = 1LL * beki[N/2 - k] * COM(N/2 , k) % MOD;
  }
  ACC<modint> ruiseki(a);
  
  modint dame = 0;
  //
  rep(x , N / 2 + 1){
    int y = N / 2 + 1 - x; // これ以上がダメ
    dame += a[x] * ruiseki.tail(y);
  }
  modint ans = modint(3).pow(N);
  ans -= dame; ans -= dame;
  out(ans);

}