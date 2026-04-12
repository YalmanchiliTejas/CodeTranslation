#include <bits/stdc++.h>

using namespace std;

#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define INF 1000000000
#define INFL (1LL << 60)
#define MOD 1000000007
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define ll long long int
#define P pair<ll, ll>

struct point {int x, y, ind;};
struct edge {int from, to, cost;};

int p[200001];
int r[200001];

void init(int n){
  REP(i, n){
    p[i] = i;
    r[i] = 0;
  }
  return;
}

int find(int x){
  return (p[x] == x ? x : p[x] = find(p[x]));
}

void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return;
  if(r[x] < r[y]) p[x] = y;
  else{
    p[y] = x;
    if(r[x] == r[y]) r[x]++;
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}

bool px(point p1, point p2){
  return p1.x < p2.x;
}

bool py(point p1, point p2){
  return p1.y < p2.y;
}

bool ec(edge e1, edge e2){
  return e1.cost < e2.cost;
}

int main(){
  int n;
  cin >> n;
  point p[n];
  REP(i, n){
    int x, y;
    cin >> x >> y;
    p[i] = {x, y, (int)i};
  }
  sort(p, p+n, px);
  vector<edge> v;
  REP(i, n-1){
    v.pb({p[i].ind, p[i+1].ind, p[i+1].x - p[i].x});
  }
  sort(p, p+n, py);
  REP(i, n-1){
    v.pb({p[i].ind, p[i+1].ind, p[i+1].y - p[i].y});
  }
  ll ans = 0;
  sort(ALL(v), ec);
  init(n);
  REP(i, v.size()){
    if(!same(v[i].from, v[i].to)){
      ans += v[i].cost;
      unite(v[i].from, v[i].to);
    }
  }
  cout << ans << endl;
	return 0;
}