#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;
#define REP(i,n) for(int i=0;i<(int)n;++i)
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){
os << "(" << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator << (ostream& os, const vector<T> v){
for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
string num2bit(ll num, ll len){
  string bit = "";
  REP(i, len){
  bit += char('0'+(num>>i & 1));
  }
  return bit;
}

struct segment{
  ll l, r, a;
};

template< typename Monoid, typename OperatorMonoid, typename F, typename G, typename H  >
struct LazySegmentTree {
  //using F = function< Monoid(Monoid, Monoid) >;
  //using G = function< Monoid(Monoid, OperatorMonoid) >;
  //using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;

  int sz, height;
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  const F f;
  const G g;
  const H h;
  const Monoid M1;
  const OperatorMonoid OM0;


  // n: サイズ
  // f: 二つの区間をマージする二項演算
  // g: 要素と作用素をマージする二項演算
  // h: 作用素同士をマージする二項演算
  // M1: モノイドの単位元
  // OM0: 作用素の単位元

  // 初期化を忘れない！x を初期値とすると
  // REP(i, n) seg[i].set(x);
  // seg.build();

  // 初期化なしだとM1で初期化される

  LazySegmentTree(int n, const F f, const G g, const H h,
                  const Monoid &M1, const OperatorMonoid OM0)
      : f(f), g(g), h(h), M1(M1), OM0(OM0) {
    sz = 1;
    height = 0;
    while(sz < n) sz <<= 1, height++;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  void set(int k, const Monoid &x) {
    data[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      data[k] = f(data[2 * k + 0], data[2 * k + 1]);
    }
  }

  inline void propagate(int k) {
    if(lazy[k] != OM0) {
      lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
      lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      data[k] = reflect(k);
      lazy[k] = OM0;
    }
  }

  inline Monoid reflect(int k) {
    return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
  }

  inline void recalc(int k) {
    while(k >>= 1) data[k] = f(reflect(2 * k + 0), reflect(2 * k + 1));
  }

  inline void thrust(int k) {
    for(int i = height; i > 0; i--) propagate(k >> i);
  }

  void update(int a, int b, const OperatorMonoid &x) {
    thrust(a += sz);
    thrust(b += sz - 1);
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) lazy[l] = h(lazy[l], x), ++l;
      if(r & 1) --r, lazy[r] = h(lazy[r], x);
    }
    recalc(a);
    recalc(b);
  }

  Monoid query(int a, int b) {
    thrust(a += sz);
    thrust(b += sz - 1);
    Monoid L = M1, R = M1;
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = f(L, reflect(l++));
      if(r & 1) R = f(reflect(--r), R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) {
    return query(k, k + 1);
  }

  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a < sz) {
      propagate(a);
      Monoid nxt = type ? f(reflect(2 * a + type), M) : f(M, reflect(2 * a + type));
      if(check(nxt)) a = 2 * a + type;
      else M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }

  template< typename C >
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if(a <= 0) {
      if(check(f(L, reflect(1)))) return find_subtree(1, check, L, false);
      return -1;
    }
    thrust(a + sz);
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        Monoid nxt = f(L, reflect(a));
        if(check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }


  template< typename C >
  int find_last(int b, const C &check) {
    Monoid R = M1;
    if(b >= sz) {
      if(check(f(reflect(1), R))) return find_subtree(1, check, R, true);
      return -1;
    }
    thrust(b + sz - 1);
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        Monoid nxt = f(reflect(--b), R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, M;
  cin >> N >> M;

  vector<vector<segment>> S(N);
  REP(i, M){
    ll l, r, a;
    cin >> l >> r >> a;
    l--, r--;
    S[r].push_back((segment){l, r, a});
  }

  auto f = [](ll x, ll y){return max(x, y);};
  auto g = [](ll x, ll a){return x+a;};
  auto h = [](ll a, ll b){return a+b;};
  ll M1 = (1ll<<60);
  ll OM0 = 0;
  LazySegmentTree<ll, ll, decltype(f), decltype(g), decltype(h)> seg(N+1, f, g, h, -M1, OM0);
  REP(i, N+1) seg.set(i, 0);
  seg.build();

  for(int i=1;i<=N;i++){
    ll wa = 0;
    for(auto x: S[i-1]){
      wa += x.a;
    }
    wa += seg.query(0, i);
    seg.update(i, i+1, wa);

    for(auto x: S[i-1]){
      seg.update(x.l+1, i, x.a);
    }
  }

  //REP(i, N+1) cout << seg[i] << " ";
  //cout << endl;

  ll ma = -M1;
  REP(i, N+1) chmax(ma, seg[i]);
  cout << ma << endl;
  return 0;
}