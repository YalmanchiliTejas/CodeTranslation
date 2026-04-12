#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<functional>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<ctime>
using namespace std;

#define mind(a,b) (a>b?b:a)
#define maxd(a,b) (a>b?a:b)
#define absd(x) (x<0?-(x):x)
#define pow2(x) ((x)*(x))
#define rep(i,n) for(int i=0; i<n; ++i)
#define repr(i,n) for(int i=n-1; i>=0; --i)
#define repl(i,s,n) for(int i=s; i<=n; ++i)
#define replr(i,s,n) for(int i=n; i>=s; --i)
#define repf(i,s,n,j) for(int i=s; i<=n; i+=j)
#define repe(e,obj) for(auto e : obj)

#define SP << " " <<
#define COL << " : " <<
#define COM << ", " <<
#define ARR << " -> " <<
#define PNT(STR) cout << STR << endl
#define POS(X,Y) "(" << X << ", " << Y << ")"
#define DEB(A) " (" << #A << ") " << A
#define DEBREP(i,n,val) for(int i=0; i<n; ++i) cout << val << " "; cout << endl
#define ALL(V) (V).begin(), (V).end()
#define INF 1000000007
#define INFLL 1000000000000000007LL
#define EPS 1e-9

typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define P_TYPE int
typedef pair<P_TYPE, P_TYPE> P;
typedef pair<P, P_TYPE> PI;
typedef pair<P_TYPE, P> IP;
typedef pair<P, P> PP;
typedef priority_queue<P, vector<P>, greater<P> > pvqueue;

#define N 4003

int parent[N];
int root(int x) {
  if(x != parent[x]) x = parent[x] = root(parent[x]);
  return x;
}
void unite(int x, int y) {
  int px = root(x), py = root(y);
  if(px < py) {
    parent[py] = px;
  } else {
    parent[px] = py;
  }
}

vector<P> g[N];
ll maxi[N][N];
void dfs(int s, int v, int prev, int cost) {
  maxi[s][v] = cost;
  rep(i, g[v].size()) {
    P &e = g[v][i];
    if(prev != e.first) {
      dfs(s, e.first, v, maxd(cost, e.second));
    }
  }
}

int main() {
  int n, m; cin >> n >> m;
  vector<IP> v;
  ll su = 0;
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    v.push_back(IP(c, P(a, b)));
  }
  sort(ALL(v));
  rep(i, n) parent[i+1] = i+1;
  rep(i, m) {
    IP &e = v[i];
    int a = e.second.first, b = e.second.second, c = e.first;
    if(root(a) != root(b)) {
      unite(a, b);
      su += c;
      g[a].push_back(P(b, c));
      g[b].push_back(P(a, c));
    }
  }
  rep(i, n) {
    dfs(i+1, i+1, -1, 0);
  }
  int q;cin >> q;
  rep(i, q) {
    int s, t; cin >> s >> t;
    cout << su - maxi[s][t] << endl;
  }
  return 0;
}
