#include <bits/stdc++.h>
using namespace std;
#define null NULL
#define mp make_pair
#define pb(a) push_back(a)
#define sz(a) ((int)(a).size())
#define all(a) a.begin() , a.end()
#define fi first
#define se second
#define relaxMin(a , b) (a) = min((a),(b))
#define relaxMax(a , b) (a) = max((a),(b))
#define SQR(a) ((a)*(a))
#define PI 3.14159265358979323846
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

const int MAXN = 100010;
const ll oo = 1E18;

// Modular operations
const int MOD = 1E9 + 7;

int Add(int a, int b, int m = MOD){
  a += b;
  if(a >= m) a -= m;
  return a;
}

int Sub(int a, int b, int m = MOD){
  a -= b;
  if(a < 0) a += m;
  return a;
}

int AddTo(int& to, int w, int m = MOD){
  to += w;
  if(to >= m) to -= m;
  return to;
}

int SubTo(int& to, int w, int m = MOD){
  to -= w;
  if(to < 0) to += m;
  return to;
}

int Mult(int a, int b, int m = MOD){
  return (a * 1LL * b) % m;
}
// </end>

int n, m, s, t;
vector<pii> fo[MAXN];

ll sp_st[MAXN], sp_ts[MAXN];
ll* _sp;
struct Compare{
  bool operator()(const int& f, const int& s) const{
    return mp(_sp[f], f) < mp(_sp[s], s);
  }
};

void Djikstra(int start, ll* sp){
  _sp = sp;
  fill(sp, sp + n, oo);

  set<int, Compare> nal;
  sp[start] = 0;
  nal.insert(start);

  while(!nal.empty()){
    int vr = *nal.begin();
    nal.erase(vr);

    for(const auto& e : fo[vr]){
      int to = e.fi;
      ll cost = e.se + sp[vr];
      if(cost < sp[to]){
        nal.erase(to);
        sp[to] = cost;
        nal.insert(to);
      }
    }
  }
}

// Num paths
ll SP;

bool OnSp(int f, int t, int d){
  return sp_st[f] + sp_ts[t] + d == SP;
}

int path_st[MAXN], path_ts[MAXN];

// TopSort
bool seen[MAXN];
vi ord;

void Dfs(int vr){
  seen[vr] = true;
  for(const auto& e : fo[vr]){
    int to = e.fi;
    int d = e.se;
    if(!seen[to] && OnSp(vr, to, d))
      Dfs(to);
  }
  ord.pb(vr);
}

// Interval Intersect
bool Intersect(ll a, ll b,
               ll c, ll d){
  if(b <= c) return false;
  if(d <= a) return false;
  return true;
}

int main(){
  scanf("%d%d", &n, &m);
  scanf("%d%d", &s, &t);
  --s, --t;
  for(int i = 0;i < m;++i){
    int u, v, d;
    scanf("%d%d%d", &u, &v, &d);
    --u, --v;
    fo[u].pb(mp(v, d));
    fo[v].pb(mp(u, d));
  }

  Djikstra(s, sp_st);
  Djikstra(t, sp_ts);
  SP = sp_st[t];

  // TopSort
  for(int i = 0;i < n;++i)
    if(!seen[i]) Dfs(i);
  reverse(all(ord));

  // path_st
  for(int i = 0;i < sz(ord);++i){
    int vr = ord[i];
    if(vr == s) AddTo(path_st[vr], 1);
    for(const auto& e : fo[vr])
      if(OnSp(vr, e.fi, e.se))
        AddTo(path_st[e.fi], path_st[vr]);
  }

  // path_ts
  for(int i = sz(ord) - 1;i >= 0;--i){
    int vr = ord[i];
    if(vr == t) AddTo(path_ts[vr], 1);
    for(const auto& e : fo[vr])
      if(OnSp(e.fi, vr, e.se))
        AddTo(path_ts[e.fi], path_ts[vr]);
  }

  // answer
  int total = Mult(path_st[t], path_st[t]);

  // Vertex
  for(int i = 0;i < n;++i)
    if(SP == sp_st[i] + sp_ts[i] && sp_st[i] == sp_ts[i]){
      int bad = Mult(path_st[i], path_ts[i]);
      SubTo(total, Mult(bad, bad));
    }

  // Edge
  for(int i = 0;i < n;++i)
    for(const auto& e : fo[i]){
      int x = i;
      int y = e.fi;
      int d = e.se;
      if(OnSp(x, y, d)){
        if(Intersect(sp_st[x], sp_st[y],
                     sp_ts[y], sp_ts[x])){
          int bad1 = Mult(path_st[x], path_ts[y]);
          int bad2 = Mult(path_ts[y], path_st[x]);
          SubTo(total, Mult(bad1, bad2));
        }
      }
    }

  printf("%d\n", total);

  return 0;
}
