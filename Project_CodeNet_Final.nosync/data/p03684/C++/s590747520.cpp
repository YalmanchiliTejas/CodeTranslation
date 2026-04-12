#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <functional>
#include <utility>
#include <queue>
#include <vector>
#include <string>
#include <stack>
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
typedef long long int ll;
const ll  MOD = 1000000007;
typedef pair<ll,ll> P;
const ll INF = 100100100100100100;
const ll V_MAX = 114514;
const ll E_MAX = 224514;
ll par[V_MAX];//oya
ll rnk[V_MAX];//hukasa

struct edge{ ll u,v,cost;};
edge es[E_MAX];
ll V,E;

void init(ll n){
  rep(i,n){
    par[i] = i;
    rnk[i] = 0;
  }
}

ll find(ll x){
  if(par[x] == x){
    return x;
  }
  else{
    return par[x] = find(par[x]);
  }
}

void unite(ll x,ll y){
  x = find(x);
  y = find(y);
  if(x == y) return;

  if(rnk[x] < rnk[y]){
    par[x] = y;
  }
  else{
    par[y] = x;
    if(rnk[x] == rnk[y]) rnk[x]++;
  }
}

bool same(ll x , ll y){
  return find(x) == find(y);
}


bool comp(const edge& e1, const edge& e2){
  return e1.cost < e2.cost;
}

ll kruskal(){
  sort(es,es+E,comp);
  init(V);
  ll res = 0;
  rep(i,E){
    edge e = es[i];
    if(!same(e.u,e.v)){
      unite(e.u,e.v);
      res += e.cost;
    }
  }
  return res;
}

int main(){
  cin >> V;
  P x[100100],y[100100];
  rep(i,V){
    cin >> x[i].first >> y[i].first;
    x[i].second = i;
    y[i].second = i;
  }
  sort(x,x+V);
  sort(y,y+V);
  rep(i,V){
    cerr << x[i].first << " " << x[i].second << endl;
  }
  rep(i,V){
    cerr << y[i].first << " " << y[i].second << endl;
  }
  rep(i,V-1){
    P a = x[i];
    P b = x[i+1];
    edge tmp;
    tmp.u = a.second;
    tmp.v = b.second;
    tmp.cost = (b.first - a.first);
    es[i] = tmp;
  }
  rep(i,V-1){
    P a = y[i];
    P b = y[i+1];
    edge tmp;
    tmp.u = a.second;
    tmp.v = b.second;
    tmp.cost = (b.first - a.first);
    es[i+V-1] = tmp;
  }
  rep(i,(V-1)*2){
    cerr << es[i].u << " " << es[i].v << " " << es[i].cost << endl;
  }
  E = (V-1)*2;
  ll ans = kruskal();
  cout << ans << endl;
}
