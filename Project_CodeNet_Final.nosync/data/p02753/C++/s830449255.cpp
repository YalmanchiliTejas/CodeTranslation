#include <bits/stdc++.h>
#define rep(var,cnt) for(int (var)=0; (var)<(int)(cnt); ++(var))
#define Rep(var,init,cnt) for(int (var)=(init); (var)<(int)(cnt); ++(var))
#define REP(var,init,cnt) for(int (var)=(init); (var)<=(int)(cnt); ++(var))
#define ran(var,vec) for(auto &(var):(vec))
#define bet(min,var,max) (min)<=(var)&&(var)<=(max)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define SORT(v) sort(all(v))
#define RSORT(v) sort(rall(v))
#define SUM(v) accumulate(all(v),(int)0)
#define tget(tp,idx) get<idx>(tp)
#define TF(flag) ((flag)?1:0)
#define YN(flag) cout<<(flag?"YES":"NO")<<endl;
#define Yn(flag) cout<<(flag?"Yes":"No")<<endl;
#define yn(flag) cout<<(flag?"yes":"no")<<endl;
#define Cout(v) cout<<(v)
#define COUT(v) cout<<(v)<<endl
#define pre(var) cout<<fixed<<setprecision(var);
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using ti = tuple<int,int,int>;
using tl = tuple<ll,ll,ll>;

template<typename T>
using vec = vector<T>;
template<typename T>
using mat = vector<vec<T>>;
template<typename T>
using cub = vector<mat<T>>;
template<typename T>
using val = valarray<T>;

template<typename T>
using pq = priority_queue<T>;
template<typename T>
using rpq = priority_queue<T,vec<T>,greater<T>>;

template<typename T>
struct Edge{
  int to; T cost;
  Edge(int to,T cost) : to(to),cost(cost){}
};

using UWGraph = vector<vector<int>>;
template<typename T>
using WGraph = vector<vector<Edge<T>>>;
enum DIRECT{UnDirected=0, Directed=1};

void EdgeAdd(UWGraph &Graph, int a, int b, DIRECT isDirected){
  --a, --b;
  switch(isDirected){
    case UnDirected :
      Graph[b].emplace_back(a);
    case Directed   :
      Graph[a].emplace_back(b);
      break;
  }
}
template<typename T>
void EdgeAdd(WGraph<T> &Graph, int a, int b, T c, DIRECT isDirected){
  --a, --b;
  switch(isDirected){
    case UnDirected :
      Graph[b].emplace_back(Edge<T>(a,c));
    case Directed   :
      Graph[a].emplace_back(Edge<T>(b,c));
      break;
  }
}

template<typename T1,typename T2>
ostream &operator<<(ostream &os, const pair<T1,T2> &p){
  os<<p.first<<" "<<p.second;
  return os;
}

template<typename T1,typename T2>
istream &operator>>(istream &is, pair<T1,T2> &p){
  is>>p.first>>p.second;
  return is;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v){
  for(int i=0; i<(int)v.size(); ++i){
    os<<v[i]<<" ";
  }
  return os;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v){
  for(T &in:v) is>>in;
  return is;
}

template<typename T>
ostream &operator<<(ostream &os, const valarray<T> &v){
  for(int i=0; i<(int)v.size(); ++i){
    os<<v[i]<<" ";
  }
  return os;
}

template<typename T>
istream &operator>>(istream &is, valarray<T> &v){
  for(T &in:v) is>>in;
  return is;
}

template<typename T>
bool chmax(T &a,T b){if(a<b){a=b;return true;}else{return false;}};

template<typename T>
bool chmin(T &a,T b){if(a>b){a=b;return true;}else{return false;}};

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

template<typename T>
T gcd(T a,T b){if(a<b){a^=b;b^=a;a^=b;} return b?gcd(b,a%b):a;}
template<typename T>
T lcm(T a,T b){return a/gcd(a,b)*b;}

void MAIN(void);

int main(void){
  cin.tie(0);
  ios::sync_with_stdio(0);
  //pre(10);
  MAIN();
}
// Usual Template End ===================

// Template End =========================

constexpr int MOD=1e9+7;
using mint = ModInt<MOD>;
locale LOCATE=locale::classic();

void MAIN(void){
  string S; cin>>S;
  Yn((S[0]!=S[1])||(S[1]!=S[2]));
}












