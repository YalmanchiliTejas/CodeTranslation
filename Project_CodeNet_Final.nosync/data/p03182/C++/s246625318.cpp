// includes
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <climits>
#include <bitset>
#include <list>

// macros
#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())

using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1e9 + 7;

// solve
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}

ll dp[200001];
template<typename T, typename E>
struct LazySegmentTree_ {
  function<T(T, T)> f;
  function<E(E, E)> h;
  function<T(T, E, int)> p;
  int n;
  T def;
  E l_def;
  vector<T> vec;
  vector<E> lazy;
  LazySegmentTree_(){}
  LazySegmentTree_(int n_, function<T(T, T)> f_, T def_,
      function<E(E, E)> h_, E l_def_, function<T(T, E, int)> p_, vector<T> v=vector<T>()){
    f = f_;
    h = h_;
    p = p_;
    def = def_;
    l_def = l_def_;

    // initialize vector
    n = 1;
    while(n < n_){
      n *= 2;
    }
    vec = vector<T>(2*n-1, def);
    lazy = vector<E>(2*n-1, l_def);

    // initialize segment tree
    for(int i = 0; i < v.size(); i++){
      vec[i + n - 1] = v[i];
    }
    for(int i = n - 2; i >= 0; i--){
      vec[i] = f(vec[2*i+1], vec[2*i+2]);
    }
  }
  void eval(int k, int len){
    if(lazy[k] != l_def){
      if(k < n - 1){
        lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);
        lazy[2*k+2] = h(lazy[2*k+2], lazy[k]);
      }
      vec[k] = p(vec[k], lazy[k], len);
      lazy[k] = l_def;
    }
  }
  E update(int a, int b, const E &val, int k, int l, int r){
    eval(k, r - l);
    if(r <= a || b <= l){
      return vec[k];
    }else if(a <= l && r <= b){
      lazy[k] = h(lazy[k], val);
      eval(k, r - l);
      return vec[k];
    }else{
      return vec[k] = f(update(a, b, val, 2*k+1, l, (l+r)/2),
          update(a, b, val, 2*k+2, (l+r)/2, r));
    }
  }
  E update(int a, int b, E val){
    return update(a, b, val, 0, 0, n);
  }
  // [l, r) -> [a, b) (at k)
  T query(int a, int b, int k, int l, int r){
    eval(k, r - l);
    if(r <= a || b <= l)return def;
    if(a <= l && r <= b)return vec[k];
    T ld = query(a, b, 2*k+1, l, (l+r)/2);
    T rd = query(a, b, 2*k+2, (l+r)/2, r);
    return f(ld, rd);
  }
  T query(int a, int b){
    return query(a, b, 0, 0, n);
  }
};

template<typename T, typename E>
using LazySegmentTree = struct LazySegmentTree_<T, E>;
using LazySegmentTreeI = LazySegmentTree<int, int>;

int main(int argc, char const* argv[])
{
  int n, m;
  cin >> n >> m;
  vector<vector<Pl> > vec(n);
  rep(i, m){
    int l, r;
    ll b;
    cin >> l >> r >> b;
    l--; r--;
    vec[r].pb(mk(b, l));
  }
  LazySegmentTree<ll, ll> seg = LazySegmentTree<ll, ll>(n, [](ll a, ll b){return max(a, b);},
      0, [](ll a, ll b){return a + b;}, 0, [](ll a, ll b, int c){return a + b;}, vector<ll>());
  rep(i, n){
    seg.update(i, i+1, seg.query(0, i));
    for(auto p: vec[i]){
      seg.update(p.second, i+1, p.first);
    }
  }
  cout << max((ll)0, seg.query(0, n)) << endl;
	return 0;
}
