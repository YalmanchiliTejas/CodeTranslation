#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define rep(val,cnt) for(int (val)=0;(val)<(cnt);++(val))
#define all(v) (v).begin(),(v).end()
using namespace std;

using ull  = unsigned long long;
using pint = pair<int,int>;
using tint = tuple<int,int,int>;

void Main(void);
signed main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Main();
}

template<typename T>
struct edge{T to,cost;};

template<typename T>
class Graph{
  public :
  vector<vector<edge<T>>> graph;

  void add(int from,T to,int cost){
    graph[from].emplace_back((edge<T>){to,cost});
  }
  T prim(void){
    using Pi = pair<T,int>;
    T total=0;
    vector<bool> used(graph.size(),false);
    priority_queue<Pi,vector<Pi>,greater<Pi>> que;
    que.emplace(0,0);
    while(!que.empty()){
      auto p=que.top(); que.pop();
      if(used[p.second]) continue;
      used[p.second]=true;
      total+=p.first;
      for(auto &e : graph[p.second]) que.emplace(e.cost,e.to);
    }
    return total;
  }
};

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

template< typename T >
struct Combination {
  vector< T > _fact, _rfact, _inv;

  Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {
    _fact[0] = _rfact[sz] = _inv[0] = 1;
    for(int i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;
    _rfact[sz] /= _fact[sz];
    for(int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);
    for(int i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];
  }

  inline T fact(int k) const { return _fact[k]; }

  inline T rfact(int k) const { return _rfact[k]; }

  inline T inv(int k) const { return _inv[k]; }

  T P(int n, int r) const {
    if(r < 0 || n < r) return 0;
    return fact(n) * rfact(n - r);
  }

  T C(int p, int q) const {
    if(q < 0 || p < q) return 0;
    return fact(p) * rfact(q) * rfact(p - q);
  }

  T H(int n, int r) const {
    if(n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};

const int MOD=1e9+7;
using mint=ModInt<MOD>;

// ---------------------------------------------------------------
// Code from Here
// ---------------------------------------------------------------
void Main(void){
  int N,M,K; cin>>N>>M>>K;
  Combination<mint> X(N*M);
  mint ans=0;
  for(int d=1;d<N;++d) ans+=X.C(N*M-2,K-2)*d*(N-d)*M*M;
  for(int d=1;d<M;++d) ans+=X.C(N*M-2,K-2)*d*(M-d)*N*N;
  cout<<ans<<endl;
}