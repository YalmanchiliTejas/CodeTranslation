#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0,i##_max=(N);i<i##_max;++i)
#define repp(i,l,r) for(int i=(l),i##_max=(r);i<i##_max;++i)
#define per(i,N) for(int i=(N)-1;i>=0;--i)
#define perr(i,l,r) for(int i=r-1,i##_min(l);i>=i##_min;--i)
#define all(arr) (arr).begin(), (arr).end()
#define SP << " " <<
#define SPF << " "
#define SPEEDUP cin.tie(0);ios::sync_with_stdio(false);
#define MAX_I INT_MAX //1e9
#define MIN_I INT_MIN //-1e9
#define MAX_UI UINT_MAX //1e9
#define MAX_LL LLONG_MAX //1e18
#define MIN_LL LLONG_MIN //-1e18
#define MAX_ULL ULLONG_MAX //1e19
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<char,char> PCC;
typedef pair<ll,ll> PLL;
typedef pair<char,int> PCI;
typedef pair<int,char> PIC;
typedef pair<ll,int> PLI;
typedef pair<int,ll> PIL; 
typedef pair<ll,char> PLC; 
typedef pair<char,ll> PCL; 

inline void YesNo(bool b){ cout << (b?"Yes" : "No") << endl;}
inline void YESNO(bool b){ cout << (b?"YES" : "NO") << endl;}
inline void Yay(bool b){ cout << (b?"Yay!" : ":(") << endl;}

template<int MOD> struct Fp {
    ll val;
    constexpr Fp(ll v = 0) noexcept : val(v % MOD) {
        if (val < 0) v += MOD;
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
    friend constexpr istream& operator >> (istream &is, Fp<MOD>& x) noexcept {
        return is >> x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};


//const int MOD = 998244353;
//const int MOD = 1e6 + 3;
const int MOD = 1e9 + 7;
const int N_MAX = 1e5+5;
//mint:mod演算のための型
using mint = Fp<MOD>;
//型変換
#define MINT (mint)

//mod MOD上での階乗
mint fact[N_MAX];
mint finv[N_MAX];
void init(){
  fact[0] = fact[1] = MINT 1;
  finv[0] = finv[1] = MINT 1;
  for(int i = 2; i < N_MAX; i++){
    fact[i] = fact[i-1] * i;
    finv[i] = finv[i-1] / i;
  }
}

//mod MOD上での逆元
inline mint inv(mint n){
  return MINT 1/n;
}

//二項係数の計算(mod MOD上)
inline mint COM(int n, int k){
  if(n<k) return 0;
  if(k<0) return 0;
  return fact[n]/(fact[k]*fact[n-k]);
}

inline mint PER(int n, int k){
  if(n<k) return 0;
  if(k<0) return 0;
  return fact[n]*finv[n-k];
}

int main(void){
  SPEEDUP
  cout << setprecision(15);
  init();
  int N,A,B,C,D;cin >> N >> A >> B >> C >> D;
  //i人以下のグルプのみでj人使っている場合の数
  vector<vector<mint> > dp(B+1,vector<mint>(N+1,0));
  vector<mint> invpow(D+1);
  rep(i,B+1) dp[i][0] = 1;

  repp(i,A,B+1){
    invpow[0] = 1;
    rep(k,D) invpow[k+1] = invpow[k]/fact[i];
    rep(j,N+1){
      dp[i][j] = dp[i-1][j];
      repp(k,C,D+1){
        if(i*k > j) break;
        dp[i][j] += dp[i-1][j-i*k] * PER(N-j+i*k,i*k)*invpow[k]*finv[k];
      }
    }
  }
  cout << dp[B][N] << endl;
  return 0;
} 

