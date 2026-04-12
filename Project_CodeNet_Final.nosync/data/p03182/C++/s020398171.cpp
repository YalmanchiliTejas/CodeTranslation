#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
#define int ll
using PII = pair<ll, ll>;
 
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
 
template<typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template<typename T> bool IN(T a, T b, T x) { return a<=x&&x<b; }
template<typename T> T ceil(T a, T b) { return a/b + !!(a%b); }
 
template<typename T> vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts) { 
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type
fill_v(T &t, const V &v) { t=v; }
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t, const V &v ) { for(auto &e:t) fill_v(e,v); }
 
template<class S,class T>
ostream &operator <<(ostream& out,const pair<S,T>& a){
  out<<'('<<a.first<<','<<a.second<<')'; return out;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& vec){
  for(T& x: vec) {is >> x;} return is;
}
template<class T>
ostream &operator <<(ostream& out,const vector<T>& a){
  out<<'['; for(T i: a) {out<<i<<',';} out<<']'; return out;
}
 
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}; // DRUL
const int INF = 1<<30;
const ll LLINF = 1LL<<60;
const int MOD = 1000000007;

template <typename T, typename E>
struct lazySegTree {
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  using P = function<E(E,int)>;
  F f; G g; H h; P p; T d1; E d0;
  int n;
  vector<T> dat;
  vector<E> lazy;

  lazySegTree(){}
  lazySegTree(int n_, F f_, G g_, H h_, 
    T d1_, E d0_, P p_=[](E a, int b){return a;})
    : f(f_), g(g_), h(h_), p(p_), d1(d1_), d0(d0_) 
  {
    n = 1; while(n < n_) n *= 2;
    dat.assign(n*2-1, d1);
    lazy.assign(n*2-1, d0);
  }
  void build(vector<T> v) {
    REP(i, v.size()) dat[i+n-1] = v[i];
    for(int i=n-2; i>=0; --i) dat[i] = f(dat[i*2+1], dat[i*2+2]);
  }

  // 区間の幅がlenの節点kについて遅延評価
  inline void eval(int len, int k) {
    if(lazy[k] == d0) return;
    if(k*2+1 < n*2-1) {
      lazy[2*k+1] = h(lazy[k*2+1], lazy[k]);
      lazy[2*k+2] = h(lazy[k*2+2], lazy[k]);
    }
    dat[k] = g(dat[k],p(lazy[k],len));
    lazy[k] = d0;
  }
  // [a, b)
  T update(int a, int b, E x, int k, int l, int r) {
    eval(r-l, k);
    if(b <= l || r <= a) return dat[k];
    if(a <= l && r <= b) {
      lazy[k] = h(lazy[k], x);
      return g(dat[k], p(lazy[k],r-l));
    }
    return dat[k] = f(update(a, b, x, 2*k+1, l, (l+r)/2),
                      update(a, b, x, 2*k+2, (l+r)/2, r));
  }
  T update(int a, int b, E x) { return update(a, b, x, 0, 0, n); }
  // [a, b)
  T query(int a, int b, int k, int l, int r) {
    eval(r-l, k);
    if(r <= a || b <= l) return d1;
    if(a <= l && r <= b) return dat[k];
    return f(query(a, b, 2*k+1, l, (l+r)/2), 
             query(a, b, 2*k+2, (l+r)/2, r));
  }
  T query(int a, int b) { return query(a, b, 0, 0, n); }
  // デバッグ出力
  void debug() {
    cout << "---------------------" << endl;
    int cnt = 0;
    for(int i=1; i<=n; i*=2) {
      REP(j, i) {
        cout << "(" << dat[cnt] << "," << lazy[cnt] << ") "; 
        cnt++;
      }
      cout << endl;
    }
    cout << "---------------------" << endl;
  }
};
/**
* 区間更新区間max d1=d0=INT_MAX f=max(a,b) g=h=(b==INT_MAX?a:b)\n
* 区間加算区間和  d1=d0=0 f=g=h=a+b p=a*b\n
* 区間加算区間min d1=d0=0 f=min(a,b) g=h=a+b\n
* 区間更新区間和  d1=d0=0 f=a+b g=h=(b==0?a:b) p=a*b\n
* 区間xor区間和   d1=d0=0 f=a+b g=(b>=1?b-a:a) h=a^b p=a*b
*/

signed main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  vector<vector<PII>> g(n);
  REP(i, m) {
    ll l, r, a;
    cin >> l >> r >> a;
    l--, r--;
    g[r].push_back({l, a});
  }

  auto f = [](ll a, ll b) {return max(a,b);};
  auto h = [](ll a, ll b) {return a+b;};
  lazySegTree<ll, ll> seg(n+2, f, h, h, 0, 0);

  REP(i, n) {
    ll now = 0;
    if(i) now = seg.query(0, i); 
    seg.update(i, i+1, now);
    for(auto p: g[i]) {
      seg.update(p.first, i+1, p.second);
    }
  }
  cout << seg.query(0, n+1) << endl;

  return 0;
}
