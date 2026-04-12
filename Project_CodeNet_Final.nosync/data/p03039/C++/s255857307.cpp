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
・ModInt
[備考] Mod演算のための構造体
[使用例]
modint M;                   // 剰余系MOD(1e9+7)における演算ができる
ModInt<mod> N;              // 剰余系modにおける演算ができる
*/

template< int MODULO > struct ModInt {
  using uint32 = uint_fast32_t;
  using uint64 = uint_fast64_t;
  uint64 x; ModInt() : x(0) {}
  ModInt(uint64 y) : x(set(y % MODULO + MODULO)) {}
  static uint64 set(const uint64 &y) { return (y < MODULO) ? y : y - MODULO; }
  static ModInt make(const uint64 &y) { ModInt ret = y; return ret; }
  ModInt operator+(const ModInt &m) const { return make(set(x + m.x)); }
  ModInt operator-(const ModInt &m) const { return make(set(x + MODULO - m.x)); }
  ModInt operator*(const ModInt &m) const { return make(x * m.x % MODULO); }
  ModInt operator/(const ModInt &m) const { return make(x) * ~make(m.x); }
  ModInt &operator+=(const ModInt &m) { return *this = *this + m; }
  ModInt &operator-=(const ModInt &m) { return *this = *this - m; }
  ModInt &operator*=(const ModInt &m) { return *this = *this * m; }
  ModInt &operator/=(const ModInt &m) { return *this = *this / m; }
  ModInt &operator^=(const uint64 &y) { return *this = *this ^ y; }
  ModInt operator~ () const { return *this ^ (MODULO - 2); }
  ModInt operator- () const { return make(set(MODULO - x)); }
  ModInt operator! () const { init(uint32(*this)); return fact[uint32(*this)]; }
  ModInt operator& () const { init(uint32(*this)); return finv[uint32(*this)]; }
  ModInt operator++() { return *this = make(set(x + 1)); }
  ModInt operator--() { return *this = make(set(x + MODULO - 1)); }
  bool operator==(const ModInt &m) const { return x == m.x; }
  bool operator!=(const ModInt &m) const { return x != m.x; }
  bool operator< (const ModInt &m) const { return x <  m.x; }
  bool operator<=(const ModInt &m) const { return x <= m.x; }
  bool operator> (const ModInt &m) const { return x >  m.x; }
  bool operator>=(const ModInt &m) const { return x >= m.x; }
  explicit operator   bool() const { return x; }
  explicit operator uint64() const { return x; }
  ModInt operator^(uint64 y) const {
    uint64 t = x, u = 1;
    while (y) { if (y & 1) (u *= t) %= MODULO; (t *= t) %= MODULO; y >>= 1; }
    return make(u);
  }
  friend ostream &operator<<(ostream &os, const ModInt< MODULO > &m) { return os << m.x; }
  friend istream &operator>>(istream &is, ModInt< MODULO > &m) { uint64 y; is >> y; m = make(y); return is; }
  static vector< ModInt > fact, finv, invs;
  static void init(uint32 n) {
    uint32 m = fact.size();
    if (n < m) return;
    fact.resize(n + 1, 1);
    finv.resize(n + 1, 1);
    invs.resize(n + 1, 1);
    if (m == 0) m = 1;
    for (uint32 i = m; i <= n; ++i) fact[i] = fact[i - 1] * ModInt(i);
    finv[n] = ModInt(1) / fact[n];
    for (uint32 i = n; i >= m; --i) finv[i - 1] = finv[i] * make(i);
    for (uint32 i = m; i <= n; ++i) invs[i] = finv[i] * fact[i - 1];
  }
  static ModInt C(uint64 n, uint64 r) {
    if (r == 0) return make(1);
    if (r <  0) return make(0);
    if (n <  0) return make(r & 1 ? MODULO - 1 : 1) * C(-n + r - 1, r);
    if (n == 0 || n < r) return make(0);
    init(n);
    return fact[n] * finv[n - r] * finv[r];
  }
  static ModInt P(uint64 n, uint64 r) {
    if (n < r || r < 0) return make(0);
    init(n);
    return fact[n] * finv[n - r];
  }
  static ModInt H(uint64 n, uint64 r) {
    if (n < 0 || r < 0) return make(0);
    if (!n && !r) return make(1);
    init(n + r - 1);
    return C(n + r - 1, r);
  }
  static ModInt montmort(uint32 n) {
    ModInt res;
    init(n);
    for (uint32 k = 2; k <= n; ++k) {
      if (k & 1) res -= finv[k];
      else res += finv[k];
    }
    return res *= fact[n];
  }
  static ModInt LagrangePolynomial(vector<ModInt> &y, ModInt t) {
    uint32 n = y.size() - 1;
    if (t.x <= n) return y[t.x];
    init(n + 1);
    ModInt res, num(1);
    for (uint32 i = 0; i <= n; ++i) num *= t - make(i);
    for (uint32 i = 0; i <= n; ++i) {
      ModInt tmp = y[i] * num / (t - make(i)) * finv[i] * finv[n - i];
      if ((n - i) & 1) res -= tmp;
      else res += tmp;
    }
    return res;
  }
};
template< int MODULO >
vector<ModInt< MODULO >> ModInt< MODULO >::fact = vector<ModInt< MODULO >>();
template< int MODULO >
vector<ModInt< MODULO >> ModInt< MODULO >::finv = vector<ModInt< MODULO >>();
template< int MODULO >
vector<ModInt< MODULO >> ModInt< MODULO >::invs = vector<ModInt< MODULO >>();
using modint = ModInt< MOD >;

signed main() {

    SS(ll, N, M, K);

    modint res = 0;

    vector<ll> stair(1, 0);
    for (int i = 0; i < 200200; ++i) {
        stair.emplace_back((stair[i] + i + 1) % MOD);
    }

    {   // K = 2のときを数える
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                ll whole = (stair[j + 1] + stair[M - j] - 1) % MOD;
                ll parti = stair[M - 1 - j];
                // debug(i, j, whole, parti);
                // 下に列が存在
                if (i != N - 1) {
                    res += whole * (N - 1 - i);
                    res += M * stair[N - 2 - i];
                }
                res += parti;
            }
        }
    }

    res *= modint::C(N * M - 2, K - 2);

    print(res);

}