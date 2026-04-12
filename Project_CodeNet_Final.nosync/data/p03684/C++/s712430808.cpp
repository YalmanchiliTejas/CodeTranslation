#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>
#define typeof(x) __typeof__(x)
#define int long long int
#define mod(x) ((x % MOD) + MOD) % MOD
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);--i)

#define ALL(c) (c).begin(),(c).end()
#define SZ(c) (int)((c).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define SORT(c) sort(ALL(c))
#define LB(c,x) (int)(lower_bound(ALL(c),x)-(c).begin())
#define UB(c,x) (int)(upper_bound(ALL(c),x)-(c).begin())
#define COUNT(c,x) UB(c,x)-LB(c,x)
#define UNIQUE(c) SORT(c); (c).erase(unique(ALL(c)),(c).end());
#define PB push_back
#define MP make_pair
#define vec vector

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;

using namespace std;

typedef pair<int,int> P;
struct edge {
  int to, cost;
};

const int INF = 1e18;
const int MOD = 1e9+7;

template<typename T> ostream& operator << (ostream& s, const vector<T>& v) {
  int len = v.size();
  s << "[";
  for (int i = 0; i < len; i++) {
    s << v[i]; if (i < len - 1) s << " ";
  }
  s << "]";
  return s;
}


int prim(const vector< vector<edge> >& G)
{
  int sum = 0;
  vector<bool> used(G.size(), false);
  priority_queue<P, vector<P>, greater<P> > que;
  que.push(P(0, 0));
  while (!que.empty()) {
    int cost = que.top().first;
    int from = que.top().second;
    que.pop();
    if (used[from]) continue;
    used[from] = true;
    sum += cost;
    for (int i = 0; i < G[from].size(); i++) {
      edge e = G[from][i];
      if (!used[e.to]) {
        que.push(P(e.cost, e.to));
      }
    }
  }
  return sum;
}

void add_edge(vector< vector<edge> >& G, int u, int v, int c) {
  G[u].push_back((edge){ v, c });
  G[v].push_back((edge){ u, c });
}


signed main()
{
  int N; cin >> N;
  vec< pair<int,int> > x(N), y(N);
  rep(i, 0, N) {
    int a, b; cin >> a >> b;
    x[i] = MP(a, i);
    y[i] = MP(b, i);
  }
  SORT(x); SORT(y);

  vec< vec<edge> > G(N, vec<edge>());
  rep(i, 0, N-1) {
    int dist = abs(x[i+1].first - x[i].first);
    int u = x[i].second, v = x[i+1].second;
    add_edge(G, u, v, dist);
    add_edge(G, v, u, dist);
  }
  rep(i, 0, N-1) {
    int dist = abs(y[i+1].first - y[i].first);
    int u = y[i].second, v = y[i+1].second;
    add_edge(G, u, v, dist);
    add_edge(G, v, u, dist);
  }

  cout << prim(G) << endl;

  return 0;
}
