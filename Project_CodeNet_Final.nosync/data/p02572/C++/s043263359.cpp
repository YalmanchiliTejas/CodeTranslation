#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for (int i = 0; i < (a); i++)
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
typedef long long ll;
template<typename T>istream& operator>>(istream&i,vector<T>&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const vector<T>&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const vector<T>&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.first>>v.second;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.first<<","<<v.second;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const vector<T>&a){ll res(0);for(auto&&x:a)res+=x;return res;}

#ifdef _DEBUG
inline void dump() { cerr << endl; }
template <typename Head> void dump(Head &&head) {
  cerr << head;
  dump();
}
template <typename Head, typename... Tail>
void dump(Head &&head, Tail &&... tail) {
  cerr << head << ", ";
  dump(forward<Tail>(tail)...);
}
#define dbg(...)                                                               \
  do {                                                                         \
    cerr << __LINE__ << ":\t" << #__VA_ARGS__ << " = ";                        \
    dump(__VA_ARGS__);                                                         \
  } while (false)
#else
#define dump(...)
#define dbg(...)
#endif

template <typename T> struct edge {
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
template <typename T> using Edges = vector<edge<T>>;
template <typename T> using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template <typename T> using Matrix = vector<vector<T>>;

const ll LINF = 1LL << 60;
const int INF = 1001001001;

/////////////////////////////////////////////////////////////////////

const ll mod = 1000000007;

struct mint {
  ll x;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x); }
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
  mint operator+(const mint a) const { return mint(*this)+=a; }
  mint operator-(const mint a) const { return mint(*this)-=a; }
  mint operator*(const mint a) const { return mint(*this)*=a; }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  mint inv() const { return pow(mod-2); }
  mint& operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this)/=a; }
  bool operator==(const mint a) const { return x == a.x; }
  bool operator!=(const mint a) const { return x != a.x; }
  friend ostream &operator<<(ostream &os, const mint &p) { return os << p.x; }
  friend istream &operator>>(istream &is, mint &a) {
    ll t;
    is >> t;
    a = mint(t);
    return (is);
  }
};

int main() {
  ll n; cin>>n;
  vector<ll> a(n); cin>>a;

  mint sum = 0;
  mint ans = 0;
  rep(i, n) {
    ans += sum * a[i];
    sum += a[i];
  }
  cout << ans << endl;

  return 0;
}
