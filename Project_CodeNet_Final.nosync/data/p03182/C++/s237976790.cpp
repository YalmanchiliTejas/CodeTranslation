#include <bits/stdc++.h>
using namespace std;using ll=int_fast64_t;using ld=long double;using pll=pair<ll,ll>;using pld=pair<ld,ld>;
const ll INF=1LL<<60;void solve();int main(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(10);solve();}
#define foreach(i,a) for(auto &i:a)
#define SELECTOR(_1,_2,_3,_4,SELECT,...) SELECT
#define rep(...) SELECTOR(__VA_ARGS__,_rep2,_rep1,_rep0)(__VA_ARGS__)
#define _rep0(i,n) for(ll i=0;i<n;++i)
#define _rep1(i,k,n) for(ll i=k;i<n;++i)
#define _rep2(i,k,n,d) for(ll i=k;d!=0&&d>0?i<n:i>n;i+=d)
template<class T> vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<class... Ts> auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<class T> inline bool chmax(T &a,const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a,const T &b){if(a>b){a=b; return 1;} return 0;}
template<class T> void contout(const T &v){for(auto it=v.begin();it!=v.end();++it,cout<<(it!=v.end()?" ":"\n"))cout<<*it;}

template<class T,class E>
class SegmentTree{
  using F=function<T(T,T)>;
  using G=function<E(E,E)>;
  using H=function<T(E,T)>;
private:
  ll n=1;
  F dot;
  T e;
  G comp;
  E id;
  H act;
  vector<T> node;
  vector<E> lazy;
  constexpr inline void propagate(ll i){
    if(lazy[i]==id) return;
    if(i<=n-1){
      lazy[2*i]=comp(lazy[2*i],lazy[i]);
      lazy[2*i+1]=comp(lazy[2*i+1],lazy[i]);
    }
    node[i]=act(lazy[i],node[i]);
    lazy[i]=id;
  }
  void ancestors_propagate(ll i){
    if(i==1) return;
    ancestors_propagate(i>>=1);
    propagate(i);
  }
  constexpr inline void update_ancestors(ll i){
    while(i!=1){
      propagate(i+1-2*(i%2));
      i>>=1;
      node[i]=dot(node[2*i],node[2*i+1]);
    }
  }
public:
  constexpr SegmentTree(const vector<T> &A,F dot,T e,G comp,E id,H act)
  :dot(dot),e(e),comp(comp),id(id),act(act){
    while(n<A.size()) n<<=1;
    node.resize(2*n,e);
    lazy.resize(2*n,id);
    rep(i,A.size()) node[n+i]=A[i];
    for(ll i=n-1;i>0;--i) node[i]=dot(node[2*i],node[2*i+1]);
  }
  constexpr void update(ll i,T c){
    ancestors_propagate(i+=n);
    propagate(i);
    node[i]=c;
    update_ancestors(i);
  }
  constexpr void add(ll l,ll r,E f){
    vector<ll> range,low(2);
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
      if(l%2==1){
        if(!low[0]) low[0]=l;
        range.push_back(l++);
      }
      if(r%2==1){
        range.push_back(--r);
        if(!low[1]) low[1]=r;
      }
    }
    for(ll i:low) if(i) ancestors_propagate(i);
    for(ll i:range) lazy[i]=comp(lazy[i],f);
    for(ll i:low) if(i){
      propagate(i);
      update_ancestors(i);
    }
  }
  constexpr T sum(ll l,ll r){
    T vl=e, vr=e;
    pair<bool,bool> low;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
      if(l%2==1){
        if(!low.first){
          ancestors_propagate(l);
          low.first=true;
        }
        propagate(l);
        vl=dot(vl,node[l]);
        l++;
      }
      if(r%2==1){
        r--;
        if(!low.second){
          ancestors_propagate(r);
          low.second=true;
        }
        propagate(r);
        vr=dot(node[r],vr);
      }
    }
    return dot(vl,vr);
  }
};

void solve(){
  ll n,m; cin>>n>>m;
  vector<vector<pll>> R(n);
  rep(_,m){
    ll l,r,a; cin>>l>>r>>a;
    R[--r].emplace_back(--l,a);
  }
  function<ll(ll,ll)> dot=[](ll a,ll b){return max(a,b);};
  ll e=0; // 全て0ならば0なので、scoreが負になることはない
  function<ll(ll,ll)> comp=[](ll f,ll g){return g+f;};
  ll id=0;
  function<ll(ll,ll)> act=[](ll f,ll a){return f+a;};
  SegmentTree<ll,ll> dp(vector<ll>(n,0),dot,e,comp,id,act);
  rep(r,n){
    ll opt=dp.sum(0,r);
    dp.update(r,opt);
    foreach(p,R[r]){
      ll l,a; tie(l,a)=p;
      dp.add(l,r+1,a);
    }
  }
  cout<<dp.sum(0,n)<<"\n";
}