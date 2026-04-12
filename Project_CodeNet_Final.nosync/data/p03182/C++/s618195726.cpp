#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
const ll INF = 1e17;
using P = pair<ll,ll>;

template<typename T, typename E, typename F, typename G, typename H>
class LazySegmentTree {
  int n, height;
  F f; G g; H h; const T ti; const E ei;
  vector<T> dat; vector<E> laz; vector<int> highest;

  void propagate(int k) {
    if(laz[k] != ei) {
      laz[2*k] = h(laz[2*k],laz[k]); laz[2*k+1] = h(laz[2*k+1],laz[k]);
      dat[k] = g(dat[k],laz[k],n/highest[k]);
      laz[k] = ei;
    }
  }
  inline void recalc(int k) {
    while(k >>= 1) dat[k] = f(g(dat[2*k],laz[2*k],n/highest[2*k]),g(dat[2*k+1],laz[2*k+1],n/highest[2*k+1]));
  }
  inline void thrust(int k) {
    for(int i = height; i > 0; i--) propagate(k >> i);
  }
public:
  LazySegmentTree(int _n, F f, G g, H h, T ti, E ei): f(f), g(g), h(h), ti(ti), ei(ei) {
    n = 1; height = 0;
    while(n < _n) n <<= 1, height++;
    dat.assign(2*n,ti); laz.assign(2*n,ei); highest.assign(2*n,0);
    int c = 1;
    for(int i = 1; i < 2*n; i++) {
      if(c*2 <= i) c <<= 1;
      highest[i] = c;
    }
  }
  void set(int k, T x) {
    dat[k+n] = x;
  }
  void build() {
    for(int i = n-1; i >= 0; i--) {
      dat[i] = f(dat[2*i],dat[2*i+1]);
    }
  }
  void update(int a, int b, const E x) {
    thrust(a += n); thrust(b += n-1);
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) laz[l] = h(laz[l],x), ++l;
      if(r & 1) --r, laz[r] = h(laz[r],x);
    }
    recalc(a); recalc(b);
  }
  T query(int a, int b) {
    thrust(a += n); thrust(b += n-1);
    T l = ti, r = ti; b++;
    while(a < b) {
      if(a & 1) l = f(l,g(dat[a],laz[a],n/highest[a])), a++;
      if(b & 1) b--, r = f(g(dat[b],laz[b],n/highest[b]),r);
      a >>= 1; b >>= 1;
    }
    return f(l,r);
  }
};

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<P>> add(n+1), del(n+1); 
  rep(i,m) {
    int l, r; ll a;
    cin >> l >> r >> a;
    add[l].push_back(P(l,a));
    del[r].push_back(P(l,-a));
  } 
  auto f = [](ll a, ll b){return max(a,b);};
  auto g = [](ll a, ll b, int l){return a+b;};
  auto h = [](ll a, ll b){return a+b;};
  LazySegmentTree<ll,ll,decltype(f),decltype(g),decltype(h)> lst(n+1,f,g,h,-INF,0);
  rep(i,n+1) lst.set(i,0);
  lst.build();
  for(int i = 1; i <= n; i++) {
    for(auto k : add[i]) lst.update(0,k.first,k.second);
    lst.update(i,i+1,lst.query(0,i));
    for(auto k : del[i]) lst.update(0,k.first,k.second);
  }
  cout << lst.query(0,n+1) << endl; 
  return 0;
}