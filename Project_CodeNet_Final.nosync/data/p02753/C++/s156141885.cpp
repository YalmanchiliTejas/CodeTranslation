/*
                  友利奈緒ぱわーでACしてくれ！！！！！！！！！！！！
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
const double PI = acos(-1), EPS = 1e-10;
constexpr ll MOD = 1E9+7;
// constexpr ll MOD = 998244353;
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
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  string s;
  cin >> s;
  set<char> st;
  REP(i,s.size()) st.insert(s[i]);
  Yes(st.size()==2);
}
