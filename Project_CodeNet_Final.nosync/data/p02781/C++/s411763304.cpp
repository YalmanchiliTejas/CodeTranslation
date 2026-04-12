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
inline ll bitcnt(ll val) { return __builtin_popcountll(val); }
constexpr double PI = acos((long double)-1);
constexpr int dx[] = {1,0,-1,0}; constexpr int dy[] = {0,1,0,-1};
template<typename Tail> auto type_vector(Tail&& tail){return tail;}
template<typename Head, typename... Tail> auto type_vector(Head&& head, Tail&&... tail){
  head = 0; return vector<decltype(type_vector(tail...))>(head);
}
template<typename Tail> auto make_vector(Tail&& tail){return tail;}
template<typename Head, typename... Tail> auto make_vector(Head&& head, Tail&&... tail){
  return vector<decltype(type_vector(tail...))>(head, make_vector(tail...));
}
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p){
  return s << "(" << p.first << ", " << p.second << ")";
}
template<class T> istream& operator>>(istream &is,vector<T> &st){
  for(size_t i=0;i<st.size();++i){is >> st[i];} return is;
}
template<class T> istream& operator>>(istream &is,vector<vector<T>> &st){
  for(size_t i=0;i<st.size();++i){is >> st[i];} return is;
}
template<class T> ostream& operator<<(ostream &os, const vector<T> &st){
  for(size_t i=0;i<st.size();++i) os << st[i] << (i!=st.size()-1?" ":"");
  return os;
}
template<> ostream& operator<<(ostream &os, const vector<string> &st){
  for(size_t i=0;i<st.size();++i) os << st[i] << (i!=st.size()-1?"\n":"");
  return os;
}
template<class T> ostream& operator<<(ostream &os, const vector<vector<T>> &st){
  for(size_t i=0;i<st.size();++i) os << st[i] << (i!=st.size()-1?"\n":"");
  return os;
}
constexpr double EPS = 1e-10;
// constexpr ll MOD = 1E9+7;
constexpr ll MOD = 998244353;
template<ll Mod>
struct mod_int {
  static const ll mod = Mod;
  ll val;
  mod_int(ll sig = 0) { sig%=mod; if(sig<0) sig+=mod; val = sig; }

  constexpr mod_int operator- () const {return val?mod-val:0;}
  constexpr mod_int &operator+=(const mod_int &that) { if ((val += that.val) >= mod) val -= mod; return *this; }
  constexpr mod_int &operator-=(const mod_int &that) { if ((val += mod - that.val) >= mod) val -= mod; return *this; }
  constexpr mod_int &operator*=(const mod_int &that) { val = (unsigned long long)val * that.val % mod; return *this; }
  constexpr mod_int &operator/= (const mod_int& r) noexcept {
    ll a = r.val, b = Mod, u = 1, v = 0;
    while (b) { ll t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }
    val = val * u % Mod; if (val < 0) val += Mod;
    return *this;
  }
  constexpr mod_int operator+(const mod_int &that) const { return mod_int(*this) += that; }
  constexpr mod_int operator-(const mod_int &that) const { return mod_int(*this) -= that; }
  constexpr mod_int operator*(const mod_int &that) const { return mod_int(*this) *= that; }
  constexpr mod_int operator/(const mod_int &that) const { return mod_int(*this) /= that; }
  constexpr bool operator==(const mod_int &that) const noexcept{ return this->val == that.val; }
  constexpr bool operator!=(const mod_int &that) const noexcept{ return this->val != that.val; }
  friend constexpr ostream& operator << (ostream &os, const mod_int &x) noexcept { return os << x.val; }
  friend constexpr istream& operator >> (istream &is, mod_int& x) noexcept { return is >> x.val; }
  friend constexpr mod_int power(const mod_int &a, long long n) noexcept {
    mod_int res = 1, r = a; for(;n>0;n>>=1,r*=r) res*=(n&1?r:1); return res;
  }
  static int sz;
  static vector<mod_int> fact, infact;
};
using mint = mod_int<MOD>;
template<> int mint::sz = 1;
template<> vector<mint> mint::fact(1,1);
template<> vector<mint> mint::infact(1,1);
mint comb(int n, int k){
  if(n+1>mint::sz){
    mint::fact.resize(n+1), mint::infact.resize(n+1);
    for(int i=mint::sz;i<n+1;++i){ mint::fact[i] = mint::fact[i-1]*i, mint::infact[i] = mint::infact[i-1]/i; }
    mint::sz = n+1;
  }
  if(k<0 || k>n) return 0;
  return mint::fact[n]*mint::infact[n-k]*mint::infact[k];
}
signed main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  string n;
  int k;
  cin >> n >> k;
  auto dp = make_vector(n.size()+1,k+2,2,mint(0));
  dp[0][0][1] = 1;
  REP(i,n.size())REP(j,k+1)REP(l,2){
    REP(x,10){
      if(l&&x>n[i]-'0') continue;
      dp[i+1][j+(x!=0)][l&&x==n[i]-'0'] += dp[i][j][l];
    }
  }
  cout << dp[n.size()][k][0] + dp[n.size()][k][1] << endl;
}
