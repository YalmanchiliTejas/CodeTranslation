#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#include <chrono>
#include <random>
#include <time.h>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
#define MAX_V 400010
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
#define N 500000
ll MOD=1e9+7;
ll dp[2000000];

struct road{
    int s,t,x;
};
ll used[N];
//遅延評価
template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree
{
  using F = function< Monoid(Monoid, Monoid) >;
  using G = function< Monoid(Monoid, OperatorMonoid) >;
  using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;
  using P = function< OperatorMonoid(OperatorMonoid, int) >;

  int sz;
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  const F f;
  const G g;
  const H h;
  const P p;
  const Monoid M1;
  const OperatorMonoid OM0;


  LazySegmentTree(int n, const F f, const G g, const H h, const P p,
                  const Monoid &M1, const OperatorMonoid OM0)
      : f(f), g(g), h(h), p(p), M1(M1), OM0(OM0)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  void set(int k, const Monoid &x)
  {
    data[k + sz] = x;
  }

  void build()
  {
    for(int k = sz - 1; k > 0; k--) {
      data[k] = f(data[2 * k + 0], data[2 * k + 1]);
    }
  }

  void propagate(int k, int len)
  {
    if(lazy[k] != OM0) {
      if(k < sz) {
        lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
        lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      }
      data[k] = g(data[k], p(lazy[k], len));
      lazy[k] = OM0;
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x, int k, int l, int r)
  {
    propagate(k, r - l);
    if(r <= a || b <= l) {
      return data[k];
    } else if(a <= l && r <= b) {
      lazy[k] = h(lazy[k], x);
      propagate(k, r - l);
      return data[k];
    } else {
      return data[k] = f(update(a, b, x, 2 * k + 0, l, (l + r) >> 1),
                         update(a, b, x, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x)
  {
    return update(a, b, x, 1, 0, sz);
  }


  Monoid query(int a, int b, int k, int l, int r)
  {
    propagate(k, r - l);
    if(r <= a || b <= l) {
      return M1;
    } else if(a <= l && r <= b) {
      return data[k];
    } else {
      return f(query(a, b, 2 * k + 0, l, (l + r) >> 1),
               query(a, b, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid query(int a, int b)
  {
    return query(a, b, 1, 0, sz);
  }

  Monoid operator[](const int &k)
  {
    return query(k, k + 1);
  }
};
auto f=[](ll a,ll b){return a+b;};
auto g=[](ll a,ll b){return a*b;};
auto h=[](ll a,ll b){return min(a,b);};
auto p=[](ll a,ll b){return a;};
//例
//区間add　区間min
//LazySegmentTree<ll> seg(n,h,f,f,p,INF,0);
//区間add 区間sum
//LazySegmentTree<ll> seg(n,f,f,f,g,0,0);


//LazySegmentTree(n,f,g,h,p,M1,OM0) 
//サイズnで初期化
//fは二つの区間の要素をマージする二項演算
//gは要素と作用素をマージする二項演算(第三因数は区間の長さ)
//hは作用素同士をマージする二項演算
//p(value,length)は作用素を下におろした時の演算
//M1はモノイドの単位元
//OM0は作用素の単位元
//update(a,b,x) 区間[a,b)に作用素 x を作用
//query(a,b) 区間[a,b) の値
main(){
    int n=in();
    ll v[N];
    rep(i,n)v[i]=lin();
    ll ans=0;
    rep2(i,1,n-2){
        ll now=0;
        rep2(j,0,(n-1)/i-1){
            if((n-1)%i==0&&j*i>=n-1-j*i)break;
            now=now+v[j*i]+v[n-1-j*i];
            ans=max(ans,now);
        }
    }
    cout<<ans;
}

