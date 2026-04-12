#include <bits/stdc++.h>
using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef priority_queue<int> PQGI; //大きい順
typedef priority_queue<int, VI, greater<int>> PQLI;
typedef priority_queue<PII> PQGP;
typedef priority_queue<PII, VPII, greater<PII>> PQLP;
//priority_queue<T,vector<T>,decltype(f)> pq{f};

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EB emplace_back
#define EF emplace_front
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define SORTR(c) sort((c).rbegin(), (c).rend())
#define LB lower_bound
#define UB upper_bound
#define NEXP next_permutation
#define FI first
#define SE second
#define Vmin(a) *min_element((a).begin(),(a).end())
#define Vmax(a) *max_element((a).begin(),(a).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define FORR(i,a,b) for(int i = (b-1);i>=(a);i--)
#define REPR(i,n) FORR(i,0,n)
#define CFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define CREP(i,n)  CFOR(i,0,n)
#define CFORR(i,a,b) for(int i = (b);i>=(a);i--)
#define CREPR(i,n) CFORR(i,0,n)
#define BFOR(bit,a,b) for(int bit = (a); bit < (1<<(b)); ++bit)
#define BREP(bit,n) BFOR(bit,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int INF = INT_MAX/2;
const LL LINF = LLONG_MAX/3;
const int RINF = INT_MIN/2;
const LL RLINF = LLONG_MIN/3;
const LL MOD = 1e9+7;
const LL MODD = 998244353;
const int MAX = 510000;

inline bool Eq(double a, double b) { return fabs(b - a) < EPS; }

//other
//-------------------------------------------
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define COUT(x) cout << (x) << endl
#define COUT2(x,y) cout << (x) << " " << (y) << endl
#define COUT3(x,y,z) cout << (x) << " " << (y) << " " << (z) << endl
#define PR(x) cout << (x)
#define ENDL cout << endl
#define SPACE cout << " "
#define BC(x) __builtin_popcountll(x)

VI dx = {1,0,-1,0,1,1,-1,-1};
VI dy = {0,1,0,-1,1,-1,1,-1};

LL Gcd(LL a, LL b) {return __gcd(a,b);}
LL Lcm(LL a, LL b) {return a/Gcd(a,b)*b;}

LL ModPow(LL A, LL N, LL M=MOD){
  LL res = 1;
  while(N>0){
    if(N&1) res = res * A % M;
    A = A * A % M;
    N >>= 1;
  }
  return res;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}

template<typename T>
struct SegmentTree{
  using OP = function<T(T,T)>;

  int n, defn;
  vector<T> node;
  T t;
  OP op;

  SegmentTree(int n_, T t, OP op) : t(t),op(op){
    n = 1;
    defn = n_;
    while(n < n_) n<<=1;
    node.assign(2*n,t);
  }

  void init(int n_){
    n = 1;
    defn = n_;
    while(n < n_) n<<=1;
    node.assign(2*n,t);
  }

  void set(int k,T x){
    node.at(k+n) = x;
  }

  void build(){
    for(int k = n - 1; k > 0; k--){
      node.at(k) = op(node.at(2*k),node.at(2*k+1));
    }
  }

  void update(int k, T x){
    k += n;
    node.at(k) = x;
    while(k >>= 1){
      node.at(k) = op(node.at(2*k),node.at(2*k+1));
    }
  }

  void update(int l, int r, T x){
    FOR(k,l,r) update(k,x);
  }

  T at(int k){
    return node.at(k+n);
  }

  void add(int k, T a){
    T x = at(k)+a;
    update(k,x);
  }

  T query(int a, int b){
    if(a==0 && b==defn) return all_query();
    T L = t, R = t;
    for(a += n, b += n; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = op(L, node.at(a++));
      if(b & 1) R = op(node.at(--b), R);
    }
    return op(L, R);
  }

  T all_query() { return node.at(1); }

  template<typename C>
  int findR(int a, int b, C &check){
    return findR(a,b,check,1,0,n);
  }
  template<typename C>
  int findR(int a, int b, C &check, int k, int l, int r){
    if(!check(node.at(k))||r<=a||b<=l) return -1;
    if(k >= n) return k-n;
    int rv = findR(a,b,check,2*k+1,(l+r)/2,r);
    if(rv != -1) return rv;
    return findR(a,b,check,2*k,l,(l+r)/2);
  }

  template<typename C>
  int findL(int a, int b, C &check){
    return findL(a,b,check,1,0,n);
  }
  template<typename C>
  int findL(int a, int b, C &check, int k, int l, int r){
    if(!check(node.at(k))||r<=a||b<=l) return -1;
    if(k >= n) return k-n;
    int lv = findL(a,b,check,2*k,l,(l+r)/2);
    if(lv != -1) return lv;
    return findL(a,b,check,2*k+1,(l+r)/2,r);
  }

  template<typename C>
  int max_right(int l, C &check){
    if(l == defn) return defn;
    l += n;
    T tm = t;
    do{
      while(l%2 == 0) l >>= 1;
      if(!check(op(tm, node.at(l)))){
        while(l < n){
          l *= 2;
          if(check(op(tm, node.at(l)))){
            tm = op(tm, node.at(l));
            l++;
          }
        }
        return l - n;
      }
      tm = op(tm, node.at(l));
      l++;
    }while((l&-l) != l);
    return defn;
  }

  template<typename C>
  int max_left(int r, C &check){
    if(r == 0) return 0;
    r += n;
    T tm = t;
    do{
      r--;
      while(r>1 && (r%2)) r >>= 1;
      if(!check(op(node.at(r), tm))){
        while(r < n){
          r = 2*r + 1;
          if(check(op(node.at(r), tm))){
            tm = op(node.at(r), tm);
            r--;
          }
        }
        return r + 1 - n;
      }
      tm = op(node.at(r), tm);
    }while((r&-r) != r);
    return 0;
  }
};

int main() {

  // cin.tie(0);
  // ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, Q;
  cin >> N >> Q;

  SegmentTree<int> seg(
    N,
    0,
    [](int a, int b){return max(a,b);}
  );

  REP(i,N){
    int A;
    cin >> A;
    seg.set(i,A);
  }
  seg.build();

  REP(q,Q){
    int T;
    cin >> T;
    if(T == 1){
      int x, v;
      cin >> x >> v;
      x--;
      seg.update(x,v);
    }
    if(T == 2){
      int l, r;
      cin >> l >> r;
      l--;
      COUT(seg.query(l,r));
    }
    if(T == 3){
      int x,v;
      cin >> x >> v;
      x--;
      auto f = [&](int a){return a<v;};
      COUT(seg.max_right(x,f)+1);
    }
  }

  return 0;
}