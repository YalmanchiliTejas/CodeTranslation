/*
                  Charlotteまだ見てない人は見ような！！！！！！！

                  ／　 /:／　　　　　　　　　　　 　 ＼:ヽ　＼
  　　　　　　　 /　　／　　　　　　 　 　 　 　 　 　 　 ＼　　ヽ
  　　　　　＼__L 彡　　　　　　　　　　　　　　　　　　　 ヽ　　',
  　　　　　　　ﾌ /　　　/　　/　 /　　　,　　 　 　 　 ヽ　　', 　ｊ
  　　　　　　　ﾚ　　　 /　　/ 　/　 　 　 　 　 　 　 　 ', 　ヽ　j
  　　　 　 　 // 　 　 !　/_l＿/__ノ 　　{ ＼}　　　　 　 ',　　',/
  　　　　　　i ﾊ 　 　 {　从j　ﾊ　i　　　 ',　 ト-､}　 i i　 }　　jj
  　　　　　　( ﾊ　　　(　 川　ハ ﾊ　 !　 '　ﾊ　 ﾊ　j j　,' 　 八
  　　　 ＜＿,ｨ∧　　　斗芹ﾃミxハ ﾊ　 ﾚ　} /__ﾚﾚ　/ 　 ∧ ＼　ﾉ
  　　　 　 　 ∨　＼ 　ゝ　辷:ソ　　 　)　芹ﾚ心ヾレ′　/ ト--　´
  　　　＼ｰ‐'　ﾉ　　 ＼ゝ　　　　　　 　 　 ゞ:_ソ "/ 　／ 　ヽ
  　　　　 　 フ　　　　i八 " "　　　,　　　　　　　ム彡　　　　＼
  　　　　 　/　　/　　j　 ト　　　　　　 　 　 " "イト＜　 　 　 ＼＼
  　　　　 /　　/　　　j　/／ヽ､ 　 ∩　　 　 イ　{ {　　￣ フフへ ＼＼
  　　　　(　／　　　 ,/ / 　　i　＞――＜ニニニﾆ┐　 〃／: : ヽ　ヽヽ
  　　　　／　　ィT´/ /┌―　￣￣ /::: , ,)　 　 　 〃／／: : : : : :}　ヽヽ)
  　　　/ /　 ∧ヾi┌― { {￣　　　 ﾉ:::トﾟ<　 　 　 ∥//: : : : : : : : i　 ﾉ ﾉ
  . 　　( 人　 {:ヽヾi∨　∧V　　　 /:::/　､ヽ　　　 ∥/: : : : : : : : : :}　/
  　　　V　( ∧: :＼'∨　∧V　　 ﾉ:::/　 ∧ 〉＿__∥: : : : : :／: : : :ﾚ
  　　 　 　 /∧: : : : ∨　∧V┬ｲ:::ﾉ　 〈 TT　|　|{{: : : : ／: : : : : ∧　　 ﾉ
  　　　 　 (　ハ: : : : :∨'T∧Vi　i (　 　 V　!　!　{{: : ／ : : : : : : /　ｰ　ノ
  　　　　　V　ハ: : : : :∨ﾍ∧V　i ゝゝ　 i／⌒＼{／ : : : : : : : /ｰ― ´
  　　　　　 ∨　ヽ: : : : :∨ﾍ∧∨i　〉 〉 /　/二　 ): : : : : : : : :/

          (https://seesaawiki.jp/asciiart/d/Charlotte より)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ull = unsigned long long;
// #define int ll
// #define DEBUG 42
inline void nprint(){}
template <class Head, class... Tail>
inline void nprint(Head &&head, Tail &&... tail) {
    cout << head << endl;
    nprint(move(tail)...);
}
#ifdef DEBUG
  #define eprint(...) nprint(__VA_ARGS__)
#else
  #define eprint(...) if(0==1) cout << 1 << endl;
#endif
#define Yes(a) cout << (a ? "Yes" : "No") << endl
#define YES(a) cout << (a ? "YES" : "NO") << endl
#define POSSIBLE(a) cout << (a ? "POSSIBLE" : "IMPOSSIBLE") << endl
using cmp = complex<double>;
using vb = vector<bool>; using vvb = vector<vb>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
template<class T> using V = vector<T>;
template<class T> using VV = vector<V<T>>;
#define fi first
#define se second
#define maxs(x,y) (x=max<ll>(x,y))
#define mins(x,y) (x=min<ll>(x,y))
using pii = pair<int,int>; using pll = pair<ll,ll>;
#define FOR(i,a,b) for(ll i = (a); i < (ll)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORS(i,a,b) FOR(i,a,b+1)
#define REPS(i,n) REP(i,n+1)
#define RFOR(i,a,b) for(ll i = (ll)(b)-1;i >= a;--i)
#define RREP(i,n) RFOR(i,0,n)
#define RREPS(i,n) RREP(i,n+1)
#define RFORS(i,a,b) RFOR(i,a,b+1)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define PERM(c) sort(ALL(c)); for(bool cp = true;cp;cp = next_permutation(ALL(c)))
#define eb(val) emplace_back(val)
#define bitcnt(val) __builtin_popcountll(val)
constexpr double PI = acos((long double)-1);
constexpr int dx[] = {1,0,-1,0}; constexpr int dy[] = {0,1,0,-1};
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p){
  return s << "(" << p.first << ", " << p.second << ")";
}
template<class T> istream& operator>>(istream &is,vector<T> &st){
  for(size_t i=0;i<st.size();++i) is >> st[i];
  return is;
}
template<class T> istream& operator>>(istream &is,vector<vector<T>> &st){
  for(size_t i=0;i<st.size();++i) is >> st[i];
  return is;
}
template<class T> ostream& operator<<(ostream &os, const vector<T> &st){
  for(size_t i=0;i<st.size();++i){
    if(i==st.size()-1) os << st[i];
    else os << st[i] << " ";
  }
  return os;
}
template<class T> ostream& operator<<(ostream &os, const vector<vector<T>> &st){
  for(size_t i=0;i<st.size();++i){
    os << st[i];
    if(i!=st.size()-1) os << endl;
  }
  return os;
}
constexpr double EPS = 1e-10;
// constexpr ll MOD = 1E9+7;
constexpr ll MOD = 998244353;
template<ll Mod>
struct mod_int {
  static const ll mod = Mod;
  ll val;
  mod_int(long long sig = 0):val(sig%mod) { sig%=mod; if(sig<0) sig+=mod; }

  constexpr mod_int operator- () const {return val?mod-val:0;}
  constexpr mod_int &operator+=(const mod_int &that) { if ((val += that.val) >= mod) val -= mod; return *this; }
  constexpr mod_int &operator-=(const mod_int &that) { if ((val += mod - that.val) >= mod) val -= mod; return *this; }
  constexpr mod_int &operator*=(const mod_int &that) { val = (unsigned long long)val * that.val % mod; return *this; }
  // constexpr mod_int &operator/=(const mod_int &that) { return *this *= that.inverse(); }
  constexpr mod_int &operator/= (const mod_int& r) noexcept {
    long long a = r.val, b = Mod, u = 1, v = 0;
    while (b) {
      long long t = a / b;
      a -= t * b; swap(a, b);
      u -= t * v; swap(u, v);
    }
    val = val * u % Mod;
    if (val < 0) val += Mod;
    return *this;
  }
  constexpr mod_int operator+(const mod_int &that) const { return mod_int(*this) += that; }
  constexpr mod_int operator-(const mod_int &that) const { return mod_int(*this) -= that; }
  constexpr mod_int operator*(const mod_int &that) const { return mod_int(*this) *= that; }
  constexpr mod_int operator/(const mod_int &that) const { return mod_int(*this) /= that; }
  constexpr bool operator==(const mod_int &that) const noexcept{
    return this->val == that.val;
  }
  constexpr bool operator!=(const mod_int &that) const noexcept{
    return this->val != that.val;
  }
  friend constexpr ostream& operator << (ostream &os, const mod_int &x) noexcept {
    return os << x.val;
  }
  friend constexpr istream& operator >> (istream &is, mod_int& x) noexcept {
    return is >> x.val;
  }
  friend constexpr mod_int modpow(const mod_int &a, long long n) noexcept {
    if (n == 0) return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1) t = t * a;
    return t;
  }
};
using mint = mod_int<MOD>;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int n,s;
  cin >> n >> s;
  vi a(n);
  cin >> a;
  VV<mint> dp(n+1,V<mint>(s+1));
  dp[0][0] = 1;
  mint ans = 0;
  REP(i,n){
    REP(j,s+1){
      if(j==0 && a[i]<=s) dp[i+1][a[i]] = i+1;
      else if(j+a[i]<=s) dp[i+1][j+a[i]] += dp[i][j];
      dp[i+1][j] += dp[i][j];
    }
    ans += dp[i+1][s];
  }
  // eprint(dp);
  cout << ans << endl;
}
