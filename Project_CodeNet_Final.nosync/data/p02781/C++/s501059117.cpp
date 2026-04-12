#include "bits/stdc++.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

using LL = long long;
using VLL = std::vector<LL>;
using VVLL = std::vector<VLL>;
using VVVLL = std::vector<VVLL>;
using LD = long double;
using VLD = std::vector<LD>;
using VVLD = std::vector<VLD>;
using VVVLD = std::vector<VVLD>;
using BL = bool;
using VBL = std::vector<BL>;
using VVBL = std::vector<VBL>;
using VVVBL = std::vector<VVBL>;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }
template<class T> void bye(T a){cout << a << '\n'; exit(0);} 

//template<class T=LL> inline vector<T> cinv(LL N){ vector<T> v(N); REP(i, N)cin>>v[i]; return move(v);}
//template<class T=LL> inline vector<T> cinv(LL N){ vector<T> v(N); REP(i, N)cin>>v[i]; return move(v);}
#define REP(i,n) for(LL (i)=0;(i)<(n);(i)++)
#define REPM(i,n,m) for(LL (i)=m;(i)<(n);(i)++)
#define ALL(v) v.begin(), v.end()
#define PRINTLN(v) {LL i=0; for(auto (a): v ){   cerr <<setw(2) <<i << " : "<<  a << endl; i++;}}
//#define PRLLSP(v) for(auto (a): v ) {cerr << a << " ";} cerr << endl


template<class T> 
void PRINTSP(vector<T> v, size_t w=3){
  for(auto (a): v ) {cerr <<setw(w)<< a << " ";} cerr << endl;
} 


struct mll{
  static LL MOD;
  LL val;
  mll(LL v = 0): val(v % MOD){ if (val < 0) val += MOD; }
  mll operator - () const { return -val; }
  mll operator + (const mll &b) const { return val + b.val; }
  mll operator - (const mll &b) const { return val - b.val; }
  mll operator * (const mll &b) const { return val * b.val; }
  mll operator / (const mll &b) const { return mll(*this) /= b; }
  mll operator + (LL b) const { return *this + mll(b); }
  mll operator - (LL b) const { return *this - mll(b); }
  mll operator * (LL b) const { return *this * mll(b); }
  friend mll operator + (LL a, const mll &b) { return b + a; }
  friend mll operator - (LL a, const mll &b) { return -b + a; }
  friend mll operator * (LL a, const mll &b) { return b * a; }
  mll &operator += (const mll &b) { val=(val+b.val)%MOD; return *this; }
  mll &operator -= (const mll &b) { val=(val+MOD-b.val)%MOD; return *this; }
  mll &operator *= (const mll &b) { val=(val*b.val)%MOD; return *this; }
  mll &operator /= (const mll &b) {
    LL c=b.val, d=MOD, u=1, v=0;
    while (d){
      LL t = c / d;
      c -= t * d; swap(c, d);
      u -= t * v; swap(u, v);
    }
    val = val * u % MOD;
    if (val < 0) val += MOD;
    return *this;
  }
  mll &operator += (LL b) { return *this += mll(b); }
  mll &operator -= (LL b) { return *this -= mll(b); }
  mll &operator *= (LL b) { return *this *= mll(b); }
  mll &operator /= (LL b) { return *this /= mll(b); }
  bool operator == (const mll &b) { return val == b.val; }
  bool operator != (const mll &b) { return val != b.val; }
  bool operator == (LL b) { return *this == mll(b); }
  bool operator != (LL b) { return *this != mll(b); }
  friend bool operator == (LL a, const mll &b) { return mll(a) == b.val; }
  friend bool operator != (LL a, const mll &b) { return mll(a) != b.val; }
  friend ostream &operator << (ostream &os, const mll &a) { return os << a.val; }
  friend istream &operator >> (istream &is, mll &a) { return is >> a.val; }
  static mll Combination(LL a, LL b){
    chmin(b, a-b);
    if (b<0) return mll(0);
    mll c = 1;
    REP(i, b) c *= a-i;
    REP(i, b) c /= i+1;
    return c;
  }
  static mll Kumiawase(LL a, LL b){
    chmin(b, a-b);
    if (b<0) return mll(0);
    return Junretu(a,b)/Kaijou(b);
  }
  static mll Kaijou(LL a){
    if (a<0)  return mll(0);
    mll c = 1;
    for(LL i=1;i<=a;i++){
      c *= i;
    }
    return c;
  }
  static mll Junretu(LL a, LL b){
    if(a<b){
      return mll(0);
    }
    mll c = 1;
    for(LL i=a;i>a-b;i--){
      c *= i;
    }

    return c;
  }
  static mll _Junretu(LL a, LL b){
    if(a<b){
      return mll(0);
    }
    return Kaijou(a)/(Kaijou(a-b));
  }
  LL get(){
    return val;
  }
};
LL mll::MOD = (LL)(1e9 + 7);// 998244353LL;//(LL)(1e9 + 7);
using vmll = std::vector<mll>;
using vvmll = std::vector<vmll>;
using vvvmll = std::vector<vvmll>;
using vvvvmll = std::vector<vvvmll>;

// a^n mod を計算する
LL modpow(LL a, LL n, LL mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

template<typename TTT>
vector<LL> arg_sort(vector<TTT> A, bool ascend = true) {
  vector<LL> index(A.size());
  iota(index.begin(), index.end(), 0);
  if (ascend) {
    std::sort(index.begin(), index.end(), [&A](TTT i1, TTT i2) {
      return A[i1] < A[i2];
      });
  }
  else {
    std::sort(index.begin(), index.end(), [&A](TTT i1, TTT i2) {
      return A[i1] > A[i2];
      });
  }

  return index;
}

template<typename _Iterator, typename _Compare>
LL num_of_ika(_Iterator _first, _Iterator _last, _Compare key){
  return (LL)(upper_bound(_first,_last,key)-_first);
}
template<typename _Iterator, typename _Compare>
LL num_of_ookii(_Iterator _first, _Iterator _last, _Compare key){
  return (LL)(_last-upper_bound(_first,_last,key));
}
template<typename _Iterator, typename _Compare>
LL num_of_chisai(_Iterator _first, _Iterator _last, _Compare key){
  return (LL)(lower_bound(_first,_last,key) - _first);
}
template<typename _Iterator, typename _Compare>
LL num_of_ijou(_Iterator _first, _Iterator _last, _Compare key){
  return (LL)(_last-lower_bound(_first,_last,key));
}
template<typename _Iterator, typename _Compare>
LL num_of_onaji(_Iterator _first, _Iterator _last, _Compare key){
  return (LL)(upper_bound(_first,_last,key)-lower_bound(_first,_last,key));
}

struct UnionFindTree {
private:
  vector<LL> UFT;
public:
  UnionFindTree(LL N) {
    UFT.resize(N);
    for (LL i = 0; i < N; i++) {
      UFT[i] = -1; 
    }
  }

  LL root(LL i) { 
    if (UFT[i] < 0) {
      return i;
    }
    else {
      LL j = root(UFT[i]);
      UFT[i] = j;
      return j;
    }
  }

  bool same(LL i, LL j) {
    return (root(i) == root(j));
  }

  bool unite(LL i, LL j)
  {
    if(same(i,j)){
      return false;
    }

    LL root_i = root(i);
    LL root_j = root(j);
    if (root_i != root_j) {
      if (size(root_i) < size(root_j)) {
        swap(root_i, root_j);
      }
      UFT[root_i] += UFT[root_j];
      UFT[root_j] = root_i;
    }
    return true;
  }

  LL size(LL i) {
    return -UFT[root(i)];
  }

  LL get_root_num() {
    set<LL> roots;
    for (LL i = 0; i < (LL)UFT.size(); ++i) {
      roots.insert(root(i));
    }
    return (LL)roots.size();
  }

  map<LL, vector<LL>> get_root_child() {
    map<LL, vector<LL>> a;
    for (LL i = 0; i < (LL)UFT.size(); ++i) {
      LL j = root(i);
      a[j].push_back(i);
    }
    return a;
  }

  void print() { 
    for (LL i = 0; i < (LL)UFT.size(); ++i) {
      cerr << root(i) << " ";
    }
    cerr << endl;
  }
};



#define cmax(a,b) {if(a<b){a=b;}}
#define cmin(a,b) {if(a>b){a=b;}}
#define EACH(a,A) for(auto a: A)
//#define cmax(a,b) a = (a>b ? a:b)
//#define cmin(a,b) a = (a<b ? a:b) 
//cin,cout高速化のおまじない＋桁数指定
inline VLL cinvll(LL N, LL minus = 0){
  VLL A(N);
  REP(i,N){
    cin >> A[i];
    A[i] -= minus;
  }
  return move(A);
}
inline VVLL zerosll(LL H, LL W, LL val=0){
  VVLL A(H,VLL(W,val));
  return move(A);
}
inline VVVLL zerosll3(LL H, LL W,LL C, LL val=0){
  VVVLL A(H,VVLL(W,VLL(C,val)));
  return move(A);
}


#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)

// vector
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec) is >> x;
    return is;
}
// pair
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {

  for (LL i = 0; i < (LL)vec.size(); i++) {
    //os << setw(3) <<i <<" : "<< setw(5) << vec[i] << endl;
    os << setw(5) << vec[i];
  } 
  os << endl;
  return os;
    
#if 0    
    os << "{";
    for (LL i = 0; i < (LL)vec.size(); i++) {
        os << vec[i] << (i + 1 == (LL)vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
#endif
}
// map
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var) {
    os << "{";
    repi(itr, map_var) {
        os << *itr;
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// set
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var) {
    os << "{";
    repi(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    
    return os;
}

#define DUMPOUT cerr
#define DUMPCOLOR ("\033[36m")

void dump_func() {
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
    DUMPOUT << DUMPCOLOR;
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
    DUMPOUT << "\033[m";
}
#ifdef DEBUG_
#define DEB
#define dump(...)                                                              \
    DUMPOUT << DUMPCOLOR                                                      \
            << "" << string(#__VA_ARGS__) << ": "                            \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]"        \
            << endl                                                            \
            << "\033[m"                                                        \
            << "",                                                         \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif

struct Fast{
  Fast(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(std::numeric_limits<double>::max_digits10);
  }
} fast;

#if 0 
LL GCD(LL m, LL n) {

  if (m < n) {
    swap(m, n);
  }

  while (n != 0) {
    LL n_new = m % n;
    m = n;
    n = n_new;
  }

  return m;

}

VLL B;
VVLL T;
LL cnt=0;
void dfs(LL me,LL oya){

  for(LL i=0;i<T[me].size();i++){
    LL ko = T[me][i];
    if(ko==oya){
      continue;
    }
    cnt += min(B[me],B[ko]);
    dfs(ko,me);
  }

}
#endif


bool isPrime(LL N)
{
  if (N < 2) {
    return false;
  }
  else if (N == 2) {
    return true;
  }
  else if (N % 2 == 0) {
    return false;
  }

  LD sqrtNum = sqrt(N);
  for (LL i = 3; i <= sqrtNum; i += 2)
  {
    if (N % i == 0)
    {
      return false;
    }
  }
  return true;
}


#if 0
VLL A;
LL N,M;
// index が条件を満たすかどうか
bool isOK(LL X) {

  LL cnt=0;
  REP(i,N){
    LL hidari=A[i];
    auto it = lower_bound(ALL(A),X-hidari);
    cnt += A.end()-it;
  }
  dump(cnt);
  if(cnt>=M){
    return true;
  }
  else{
    return false;
  }
}
// 汎用的な二分探索のテンプレ
LL binary_search() {
  LL ng = 1e10+1 ;
  LL ok = 0;

  /* ok と ng のどちらが大きいかわからないことを考慮 */
  while (abs(ok - ng) > 1) {
      LL mid = (ok + ng) / 2;

      if (isOK(mid)) ok = mid;
      else ng = mid;
  }
  return ok;
}

map< LL, LL > prime_factor(LL n) {
  map< LL,LL > ret;
  for(LL i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

LL GCD(LL m, LL n) { 
  if (m < n) {
    swap(m, n);
  }

  while (n != 0) {
    LL n_new = m % n;
    m = n;
    n = n_new;
  }
  return m;
}
LL LCM(LL x, LL y) { 
  return x / GCD(x, y) * y; 
}


#endif

struct Furui{
  LL n;
  VLL f;
  VLL prime;

  Furui(LL n=1):n(n),f(n+1){
    f[0]=-1;
    f[1]=-1;
    for( LL i=2;i<=n;i++){
      if(f[i]){
        continue;
      }
      prime.push_back(i);
      for(LL j=i;j<=n; j+=i){
        if(f[j]==0){
          f[j] = i;
        }
      }
    }
  }
  bool isPrime(LL x){
    if(x<=1){
      return false;
    }
    return (f[x]==x);
  }
  VLL factorList(LL x){
    VLL res;
    if( x>=2 and x<=n){
      while( x!=1){
        res.push_back(f[x]);
        x /=f[x];
      }
    }
    return res;
  }
  vector<pair<LL,LL>> factor(LL x){
    VLL factors = factorList(x);
    vector<pair<LL,LL>> P;
    if(factors.size()==0){
      return P;
    }
    P.emplace_back(factors[0],0);
    for(auto p : factors){
      if(P.back().first==p){
        P.back().second++;
      }else{
        P.emplace_back(p,1);
      }
    }
    return P;
  }
};

template< typename T >
struct edge {
  int src, to;
  T cost;
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};
template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

template< typename T >
void warshall_floyd(Matrix< T > &g, T INF) {
  for(int k = 0; k < g.size(); k++) {
    for(int i = 0; i < g.size(); i++) {
      for(int j = 0; j < g.size(); j++) {
        if(g[i][k] == INF || g[k][j] == INF) continue;
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
}

template< typename T >
T kruskal(Edges< T > &edges, LL V) {
  sort(begin(edges), end(edges), [](const edge< T > &a, const edge< T > &b) {
    return (a.cost < b.cost);
  });
  UnionFindTree tree(V);
  T ret = 0;
  for(auto &e : edges) {
    if(tree.unite(e.src, e.to)) ret += e.cost;
  }
  return (ret);
}



map< LL, LL > prime_factor(LL n) {
  map< LL,LL > ret;
  for(LL i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}


#if 0
VLL A;
VLL B;
  
bool isOK(LL X) {


  LL cnt=0;
  REP(i,N){
    LL hidari=A[i];
    auto it = lower_bound(ALL(A),X-hidari);
    cnt += A.end()-it;
  }
  dump(cnt);
  if(cnt>=M){
    return true;
  }
  else{
    return false;
  }
}
// 汎用的な二分探索のテンプレ
LL binary_search() {
  LL ng = 0 ;
  LL ok = 100000;

  /* ok と ng のどちらが大きいかわからないことを考慮 */
  while (abs(ok - ng) > 1) {
      LL mid = (ok + ng) / 2;

      if (isOK(mid)) ok = mid;
      else ng = mid;
  }
  return ok;
}

void funcE()
{
  LL H,N;
  cin >>H >> N;
  VLL A;
  VLL B;
  A.resize(N);
  B.resize(N);
  REP(i,N){
    cin >> A[i];
    cin >> B[i];
  }
  dump(H,N);
  dump(A);
  dump(B);
}
#endif
LL powll(LL a,LL b){
  LL c = 1LL;
  REP(i,b){
    c *= a;
  }
  return c;
}

LL knapsack(vector<LL> v,vector<LL> w,LL W) {
  LL N = (LL)v.size();
  vector<LL> dp(W+1,0);
  for (LL i=0; i<N; ++i){
    for (LL j=w[i]; j<=W; ++j){
      dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
    }
  }

  return dp[W];
}


#if 0 

LL H,W;
VVLL M;
VVLL V;
LL sx;
LL sy;
LL gx;
LL gy;

void MeiroDFS(LL y,LL x){

  if(V[y][x]==1){
    return;
  }
  V[y][x]=1;

  if(y>0 and M[y-1][x]==0){
    dfs(y-1,x);
  }
  if(x>0 and M[y][x-1]==0){
    dfs(y,x-1);
  }
  if(y+1<H and M[y+1][x]==0){
    dfs(y+1,x);
  }
  if(x+1<W and M[y][x+1]==0){
    dfs(y,x+1);
  }

}

LL H,W;
VVLL M;
VVLL V;
LL sx;
LL sy;
LL gx;
LL gy;
void MeiroBFS(LL y,LL x){

  queue<tuple<LL,LL,LL>> Q;
  Q.emplace(y,x,0);
  V[y][x]=0;

  LL cnt=0;
  while(not Q.empty()){
    tuple<LL,LL,LL> q = Q.front();
    Q.pop();
    y = get<0>(q);
    x = get<1>(q);
    cnt = get<2>(q);
    if(y>0 and M[y-1][x]==0 and V[y-1][x]==-1){
      V[y-1][x]=cnt+1;
      Q.emplace(y-1,x,cnt+1);
    }
    if(x>0 and M[y][x-1]==0 and V[y][x-1]==-1){
      V[y][x-1]=cnt+1;
      Q.emplace(y,x-1,cnt+1);
    }
    if(y+1<H and M[y+1][x]==0 and V[y+1][x]==-1){
      V[y+1][x]=cnt+1;
      Q.emplace(y+1,x,cnt+1);
    }
    if(x+1<W and M[y][x+1]==0 and V[y][x+1]==-1){
      V[y][x+1]=cnt+1;
      Q.emplace(y,x+1,cnt+1);
    }
  }



}
#endif

template <typename T> vector<T> dijkstra(WeightedGraph<T> &g, int s)
{
  const auto INF = numeric_limits<T>::max();
  vector<T> dist(g.size(), INF);

  using Pi = pair<T, int>;
  priority_queue<Pi, vector<Pi>, greater<Pi>> que;
  dist[s] = 0;
  que.emplace(dist[s], s);
  while(!que.empty()) {
    T cost;
    int idx;
    tie(cost, idx) = que.top();
    que.pop();
    if(dist[idx] < cost)
      continue;
    for(auto &e : g[idx]) {
      auto next_cost = cost + e.cost;
      if(dist[e.to] <= next_cost)
        continue;
      dist[e.to] = next_cost;
      que.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}

template <typename T> struct BinaryIndexedTree {
  vector<T> data;

  BinaryIndexedTree(int sz = 10) { data.assign(++sz, 0); }

  T sum(int k)
  {
    T ret = 0;
    for(++k; k > 0; k -= k & -k)
      ret += data[k];
    return (ret);
  }

  void add(int k, T x)
  {
    for(++k; k < data.size(); k += k & -k)
      data[k] += x;
  }
  void resize(int sz) { data.assign(++sz, 0); }
};


bool isKaibun2(string S){
  LL N = (LL)S.length();
  REP(i,(LL)(N/2)){
    if(S[i]!= S[N-1-i])  {
      return false;
    }
  }
  return true;
}

LL Combination(LL a, LL b){
    chmin(b, a-b);
    if (b<0) return 0;
    LL c = 1;
    REP(i, b) c *= a-i;
    REP(i, b) c /= i+1;
    return c;
  }

struct IntegralImage{
  VVLL I; 
  LL H;
  LL W;
  IntegralImage(VVLL M){
    I = M;
    H = M.size();
    W = M[0].size();
    // check
    bool isOK=true;
    REP(i,H){
      if(I[i].size()!=W){
        isOK=false;
      }
    }
    if(not isOK){
      cerr << "shape error :";
      REP(i,H){
        cerr << I[i].size() << " ";
      }
      cerr << endl;
      throw 0;
    }

    REP(i,H){
      REP(j,W-1){
        I[i][j+1] += I[i][j];
      }
    }
    REP(j,W){
      REP(i,H-1){
        I[i+1][j] += I[i][j];
      }
    }
  }
  LL get_sum( LL y, LL h, LL x, LL w){
    if(y<0 or x<0 or h<0 or w<0 or y+h>=H or x+w>=W){
      fprintf(stderr,"H=%lld, W=%lld, y=%lld, h=%lld, x=%lld, w=%lld\n",H,W,y,h,x,w);
      throw 1;
    }
    LL a1 = I[y+h][x+w];
    LL a2 = 0;
    if(y>0){
      a2 = I[y-1][x+w];
    }            
    LL a3 = 0;
    if(x>0){
      a3 = I[y+h][x-1];
    }            
    LL a4 = 0;
    if(y>0 && x>0){
      a4 = I[y-1][x-1];
    }
    return (a1 + a4 - a2 -a3);
  }
  void print( ){
    REP(i,(LL)I.size()){
      PRINTSP(I[i]);
    }  
  }
};

bool isKaibun(string S){
  bool ok = true;
  LL N = (LL)S.length();
  REP(i,N){
    if(S[i]!=S[N-i-1]){
      ok = false;
      break;
    }
  }
  return ok;
}

void func()
{
  LL K;
  string S;
  cin >> S;
  cin >>K;
  //K=5;
  dump(S,K);
  LL N = S.length();
  VVVLL dp = zerosll3(N+1,5,2);
  dp[0][0][0]=1;
  REP(i,N){
    REP(j,4){
      REP(k,2){
        dump(i,j,k);
        LL a = (LL)S[i]-(LL)'0';
        REP(d,10){
          LL ni = i+1;
          LL nj = j;    
          LL nk = k;
          
          if(d>0){
            nj +=1;
          }
          if(nj>K){
            continue;
          }
          if(k==0){          
            if(d>a){
              continue;
            }
            if(d<a){
              nk=1;
            }
          }
          dp[ni][nj][nk] += dp[i][j][k];
        }
      }
    } 
  }
dump(dp);
  bye(dp[N][K][0]+dp[N][K][1]);
  return ;
}
int main()
{
  // funcD();
  func();
  return 0;
}
