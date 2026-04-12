#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define RREP(i,n) for(int i = n - 1; i >= 0; i--)

#define ALL(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define UNIQUE(v) do{sort(v.begin(), v.end()); v.erase( unique(v.begin(), v.end()), v.end() );} while(0)


#define y0 y3487465
#define y1 y8687969

#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;


// Minimum Spanning Tree Kruskal O(E log V)
// 1. init E, V
// 2. kruskal() returns the sum of costs

const int MAX_E = 200000;
const int MAX_V = 100000;

struct edge { ll u, v, cost; };
bool comp(const edge& e1, const edge& e2) {
  return e1.cost < e2.cost; 
}

int par[MAX_V];
int rk[MAX_V];

void init(int n){
  REP(i,n){
    par[i] = i;
    rk[i] = 0;
  }
}

int find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x==y) return;
  if(rk[x] < rk[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(rk[x] == rk[y]) rk[x]++;
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}

edge es[MAX_E];
int V, E;

ll kruskal() {
  sort(es, es + E, comp);
  init(V);
  ll res = 0;
  for(int i = 0; i < E; i++) {
    edge e = es[i];
    if (!same(e.u, e.v)) {
      unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}


ll N;
const ll MAX_N = 100000;
ll x[MAX_N], y[MAX_N];

int main(){
  cin >> N;
  REP(i, N) cin >> x[i] >> y[i];
  vpll xs, ys;
  V = N;
  E = 2 * N - 2;
  REP(i, N) {
    xs.pb(pll(x[i], i));
    ys.pb(pll(y[i], i));
  }

  sort(ALL(xs));
  sort(ALL(ys));

  REP(i, N - 1) {
    es[i] = edge{xs[i].S, xs[i + 1].S, xs[i + 1].F - xs[i].F};
    es[N - 1 + i] = edge{ys[i].S, ys[i + 1].S, ys[i + 1].F - ys[i].F};
  }

  cout << kruskal() << endl;

  return 0;
}
