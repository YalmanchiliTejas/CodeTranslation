#include <bits/stdc++.h>
using namespace std;
#define Int long long
//#define int long long
//TEMPLATE START---------------8<---------------8<---------------8<---------------8<---------------//
typedef long long ll;       typedef long double ld;  typedef pair<int,int> pii; typedef pair<ll,ll> pll;  typedef vector<int> vi;   typedef vector<ll> vl;
typedef vector<string> vst; typedef vector<bool> vb; typedef vector<ld> vld;    typedef vector<pii> vpii; typedef vector<pll> vpll; typedef vector<vector<int> > vvi;
const int INF = (0x7FFFFFFFL); const ll INFF = (0x7FFFFFFFFFFFFFFFL); const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int MOD = 1e9 + 7;       const int MODD = 998244353;            const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const double PI = acos(-1.0);  const double EPS = 1e-9;               const string Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int dx[9] = { 1, 0, -1,  0,  1, -1, -1, 1, 0 };
int dy[9] = { 0, 1,  0, -1, -1, -1,  1, 1, 0 };
#define ln '\n'
#define scnaf scanf
#define sacnf scanf
#define sancf scanf
#define SS(type, ...)type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T& t){cin >> t;}template<typename First, typename...Rest> void MACRO_VAR_Scan(First& first, Rest&...rest){cin >> first;MACRO_VAR_Scan(rest...);}
#define SV(type,c,n) vector<type> c(n);for(auto& i:c)cin >> i;
#define SVV(type,c,n,m) vector<vector<type>> c(n,vector<type>(m));for(auto& r:c)for(auto& i:r)cin >> i;
template<class T,class U>ostream &operator<<(ostream &o,const pair<T,U>&j){o<<"{"<<j.first<<", "<<j.second<<"}";return o;}
template<class T,class U>ostream &operator<<(ostream &o,const map<T,U>&j){o<<"{";for(auto t=j.begin();t!=j.end();++t)o<<(t!=j.begin()?", ":"")<<*t;o<<"}";return o;}
template<class T>ostream &operator<<(ostream &o,const set<T>&j){o<<"{";for(auto t=j.begin();t!=j.end();++t)o<<(t!=j.begin()?", ":"")<<*t;o<<"}";return o;}
template<class T>ostream &operator<<(ostream &o,const vector<T>&j){o<<"{";for(int i=0;i<(int)j.size();++i)o<<(i>0?", ":"")<<j[i];o<<"}";return o;}
inline int print(void){cout << endl; return 0;}
template<class Head> int print(Head&& head){cout << head;print();return 0;} template<class Head,class... Tail> int print(Head&& head,Tail&&... tail){cout<<head<<" ";print(forward<Tail>(tail)...);return 0;}
inline int debug(void){cerr << endl; return 0;}
template<class Head> int debug(Head&& head){cerr << head;debug();return 0;} template<class Head,class... Tail> int debug(Head&& head,Tail&&... tail){cerr<<head<<" ";debug(forward<Tail>(tail)...);return 0;}
template<typename T> void PA(T &a){int ASIZE=sizeof(a)/sizeof(a[0]);for(int ii=0;ii<ASIZE;++ii){cout<<a[ii]<<" \n"[ii==ASIZE-1];}}
template<typename T> void PV(T &v){int VSIZE=v.size();for(int ii=0;ii<VSIZE;++ii){cout<<v[ii]<<" \n"[ii==VSIZE-1];}}
#define ER(x)  cerr << #x << " = " << (x) << endl;
#define ERV(v) {cerr << #v << " : ";for(const auto& xxx : v){cerr << xxx << " ";}cerr << "\n";}
inline int YES(bool x){cout<<((x)?"YES":"NO")<<endl;return 0;} inline int Yes(bool x){cout<<((x)?"Yes":"No")<<endl;return 0;}  inline int yes(bool x){cout<<((x)?"yes":"no")<<endl;return 0;}
inline int yES(bool x){cout<<((x)?"yES":"nO")<<endl;return 0;} inline int Yay(bool x){cout<<((x)?"Yay!":":(")<<endl;return 0;}
template<typename A,typename B> void sankou(bool x,A a,B b){cout<<((x)?(a):(b))<<endl;}
#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define _RREP(i,n) RREPI(i,n,0)
#define RREPI(i,a,b) for(ll i=ll(a);i>=ll(b);--i)
#define RREP(...) _overload3(__VA_ARGS__,RREPI,_RREP,)(__VA_ARGS__)
#define EACH(e,v) for(auto& e : v)
#define PERM(v) sort((v).begin(),(v).end());for(bool c##p=1;c##p;c##p=next_permutation((v).begin(),(v).end()))
#define ADD(a,b) a=(a+ll(b))%MOD
#define MUL(a,b) a=(a*ll(b))%MOD
inline ll MOP(ll x,ll n,ll m=MOD){ll r=1;while(n>0){if(n&1)(r*=x)%=m;(x*=x)%=m;n>>=1;}return r;}
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}inline ll lcm(ll a,ll b){return a*b/gcd(a,b);}inline ll POW(ll a,ll b){ll c=1ll;do{if(b&1)c*=1ll*a;a*=1ll*a;}while(b>>=1);return c;}
template<typename T,typename A,typename B> inline bool between(T x,A a,B b) {return ((a<=x)&&(x<b));}template<class T> inline T sqr(T x){return x*x;}
template<typename A,typename B> inline bool chmax(A &a,const B &b){if(a<b){a=b;return 1;}return 0;}
template<typename A,typename B> inline bool chmin(A &a,const B &b){if(a>b){a=b;return 1;}return 0;}
#define tmax(x,y,z) max((x),max((y),(z)))
#define tmin(x,y,z) min((x),min((y),(z)))
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define SORT(v) sort((v).begin(),(v).end())
#define RSORT(v) sort((v).rbegin(),(v).rend())
#define EXIST(s,e) (find((s).begin(),(s).end(),(e))!=(s).end())
#define EXISTST(s,c) (((s).find(c))!=string::npos)
#define POSL(x,val) (lower_bound(x.begin(),x.end(),val)-x.begin())
#define POSU(x,val) (upper_bound(x.begin(),x.end(),val)-x.begin())
#define GEQ(x,val) (int)(x).size() - POSL((x),(val))
#define GREATER(x,val) (int)(x).size() - POSU((x),(val))
#define LEQ(x,val) POSU((x),(val))
#define LESS(x,val) POSL((x),(val))
#define SZV(a) int((a).size())
#define SZA(a) sizeof(a)/sizeof(a[0])
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define MEMINF(a) memset(a,0x3f,sizeof(a))
#define FILL(a,b) memset(a,b,sizeof(a))
#define UNIQUE(v) sort((v).begin(),(v).end());(v).erase(unique((v).begin(),(v).end()),(v).end())
struct abracadabra{
  abracadabra(){
    cin.tie(0); ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(5);
  };
} ABRACADABRA;

//TEMPLATE END---------------8<---------------8<---------------8<---------------8<---------------//

/*
・セグメント木
  >         build O(N)
  > query, update O(logN)
[備考] 結合律, 単位元を持つ二項演算を, 任意の区間に関してlogNで行うデータ構造
[使用例]
SegmentTree<int> seg_sum(N, [](int a, int b){ return a+b; }, 0 );       // 区間和
SegmentTree<int> seg_min(N, [](int a, int b){ return min(a,b); }, INF); // 区間min
seg_min.set(k,x);     // 要素kに値xを設定
seg_min.build();      // 上のセグメントに値を設定
seg_min.update(k,x);  // 要素kを値xに変更
seg_min.add(k,x);     // 要素kに値xを加算
seg_min.query(l,r);   // 区間[l,r)に対する二項演算の結果を返す
*/

template<typename T> struct SegmentTree {

  using F = function< T(T,T) >;

  vector< T > seg;

  int size;       // データの数以上の最小の2冪, 最下段のデータの個数
  const F func;
  const T M1;

  SegmentTree(int n, const F f, const T &M) : func(f), M1(M) {
    size = 1; while (size < n) size *= 2;
    seg.resize(2 * size - 1, M1);
  }

  void set(int k, T x) {
    seg[k + size - 1] = x;
  }

  void build() {
    for (int i = size - 2; i >= 0; --i) {
      // iの子は, (2*i+1, 2*i+2)
      seg[i] = func(seg[2*i+1], seg[2*i+2]);
    }
  }

  void update(int k, T x) {
    // kをseg内の添字に対応させる <- (size - 1)を足す
    k += size - 1;
    seg[k] = x;
    while (k > 0) {
      k = (k - 1) / 2;
      seg[k] = func(seg[2*k+1], seg[2*k+2]);
    }
  }

  void add(int k, T x) {
    // kをseg内の添字に対応させる <- (size - 1)を足す
    k += size - 1;
    seg[k] += x;
    while (k > 0) {
      k = (k - 1) / 2;
      seg[k] = func(seg[2*k+1], seg[2*k+2]);
    }
  }

  T query(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = size;
    if (r <= a || l >= b) return M1;
    if (l >= a && r <= b) return seg[k];
    T f_l = query(a, b, 2*k+1, l, (l+r)/2);
    T f_r = query(a, b, 2*k+2, (l+r)/2, r);
    return func(f_l, f_r);
  }

  void debug() {
    for (int i = 0; i < 2 * size - 1; ++i) {
      cerr << seg[i] << " \n"[i==2*size-2];
    }
  }

};

/*
・座標圧縮
  > O(NlogN)
[備考] 各数字の対応関係が欲しいときは, 引数にmapを入れてコメントアウトを外す.
[使用例]
1. 引数にmapを入れない場合
vl com = compress(v);
2. 引数にmapを入れる場合
map<ll,int> rev;
vl com = compress(v, rev);
*/

// template<typename T> vector<T> compress(vector<T> ord, map<T,int> &rev) {
template<typename T> vector<T> compress(vector<T> ord) { map<T,int> rev;
  vector<T> com = ord;
  sort(com.begin(), com.end());
  com.erase(unique(com.begin(), com.end()), com.end());
  for (int i = 0; i < com.size(); ++i) rev[com[i]] = i;
  vector<T> ret; for (auto& e : ord) ret.emplace_back(rev[e]);
  return ret;
}

signed main() {

    SS(int, N);
    SV(int, A, N);

    vi com = compress(A);

    SegmentTree<int> seg(N, [](int a, int b){ return max(a,b); }, 0);

    REP(i, N) {
        int bef = seg.query(com[i], N);
        seg.update(com[i], bef + 1);
    }

    print(seg.query(0, N));

}