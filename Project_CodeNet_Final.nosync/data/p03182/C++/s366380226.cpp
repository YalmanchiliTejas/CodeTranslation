#include <bits/stdc++.h>
using namespace std;using ll=int_fast64_t;using ld=long double;const ll INF=1LL<<60,MOD=1e9+7;//998244353
void solve();int main(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(10);solve();}
#define SELECTOR(_1,_2,_3,_4,SELECT,...) SELECT
#define rep(...) SELECTOR(__VA_ARGS__,_rep2,_rep1,_rep0)(__VA_ARGS__)
#define _rep0(i,n) for(ll i=0;i<n;++i)
#define _rep1(i,k,n) for(ll i=k;i<n;++i)
#define _rep2(i,k,n,d) for(ll i=k;d>0?i<n:i>n;i+=d)
#define foreach(a,A) for(auto &a:A)
#define endl "\n"
template<class T> vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<class... Ts> auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<class T> inline bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

template<class T, class E>
class LazySegmentTree{
  ll n = 1, logn = 0;
  function<T(T, T)> dot; T unit; function<E(E, E)> compose; E identity; function<T(E, T)> act; vector<T> tree; vector<E> lazy;
  constexpr void ascend(ll i){while(i >>= 1) tree[i] = act(lazy[i], dot(tree[i << 1], tree[i << 1 | 1]));}
  constexpr void descend(ll i){
    rep(k, logn, 0, -1){
      ll p = i >> k;
      E f = lazy[p];
      tree[p << 1] = act(f, tree[p << 1]); lazy[p << 1] = compose(f, lazy[p << 1]);
      tree[p << 1 | 1] = act(f, tree[p << 1 | 1]); lazy[p << 1 | 1] = compose(f, lazy[p << 1 | 1]);
      lazy[p] = identity;
    }
  }
public:
  constexpr LazySegmentTree(const vector<T> &A, function<T(T, T)> dot, T unit ,function<E(E, E)> compose, E identity ,function<T(E, T)> act)
  : dot(dot), unit(unit), compose(compose), identity(identity), act(act) {
    while(n < A.size()){n <<= 1; logn++;}
    tree.resize(2 * n, unit);
    lazy.resize(2 * n, identity);
    rep(i, A.size()) tree[n + i] = A[i];
    rep(i, n - 1, 0, -1) tree[i] = dot(tree[i << 1], tree[i << 1 | 1]);
  }
  constexpr void range_act(ll l, ll r, E f){
    l += n; r += n;
    // propagation isn't necessary if monoid action is commutative
    descend(l); descend(r - 1);
    ll l0 = l, r0 = r;
    while(l < r){
      if(l & 1){tree[l] = act(f, tree[l]); lazy[l] = compose(f, lazy[l]);l++;}
      if(r & 1){r--; tree[r] = act(f, tree[r]); lazy[r] = compose(f, lazy[r]);}
      l >>= 1; r >>= 1;
    }
    ascend(l0); ascend(r0 - 1);
  }
  constexpr T sum(ll l, ll r){
    descend(l += n); descend((r += n) - 1);
    T l_val = unit, r_val = unit;
    while(l < r){
      if(l & 1) l_val = dot(l_val, tree[l++]);
      if(r & 1) r_val = dot(tree[--r], r_val);
      l >>= 1; r >>= 1;
    }
    return dot(l_val, r_val);
  }
};


void solve(){
  ll n,m; cin>>n>>m;
  vector<vector<pair<ll, ll>>> R(n);
  rep(_,m){
    ll l,r,a; cin>>l>>r>>a;
    R[--r].emplace_back(--l,a);
  }
  function<ll(ll,ll)> dot=[](ll a,ll b){return max(a,b);};
  ll e=0; // 全て0ならば0なので、scoreが負になることはない
  function<ll(ll,ll)> comp=[](ll f,ll g){return g+f;};
  ll id=0;
  function<ll(ll,ll)> act=[](ll f,ll a){return f+a;};
  LazySegmentTree<ll,ll> dp(vector<ll>(n,0),dot,e,comp,id,act);
  rep(r,n){
    ll opt=dp.sum(0,r);
    dp.range_act(r,r+1,opt);
    foreach(p,R[r]){
      ll l,a; tie(l,a)=p;
      dp.range_act(l,r+1,a);
    }
  }
  cout<<dp.sum(0,n)<<"\n";
}