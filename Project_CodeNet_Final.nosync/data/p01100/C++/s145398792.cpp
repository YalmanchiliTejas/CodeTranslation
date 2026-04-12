#include<bits/stdc++.h>
#define X first
#define Y second
#define pb emplace_back
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define EFOR(i,a,b) for(int (i)=(a);i<=(b);++(i))
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef ll LL;
typedef pii PII;
typedef pll PLL;
template<class T> using vv=vector<vector<T>>;
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
const ll MOD=1e9+7;

//
// Dinic's maximum flow
// 
// Description:
//   Given a directed network G = (V, E) with edge capacity c: E->R.
//   The algorithm finds a maximum flow. 
//
// Algorithm:
//   Dinic's blocking flow algorithm.
//
// Complexity:
//   O(n^2 m), but very fast in practice.
//   In particular, for a unit capacity graph, 
//   it runs in O(m min{m^{1/2}, n^{2/3}}).
// 
// Verified:
//   SPOJ FASTFLOW
//
// Reference:
//   E. A. Dinic (1970):
//   Algorithm for solution of a problem of maximum flow in networks with power estimation.
//   Soviet Mathematics Doklady, vol. 11, pp. 1277-1280.
//
//   B. H. Korte and J. Vygen (2008):
//   Combinatorial Optimization: Theory and Algorithms.
//   Springer Berlin Heidelberg. 
//

const long long INF = (1ll << 50);
struct graph {
  typedef long long flow_type;
  struct edge {
    int src, dst;
    flow_type capacity, flow;
    size_t rev;
  };
  int n;
  vector<vector<edge>> adj;
  graph(int n) : n(n), adj(n) { }

  void add_edge(int src, int dst, flow_type capacity) {
    adj[src].push_back({src, dst, capacity, 0, adj[dst].size()});
    adj[dst].push_back({dst, src, 0, 0, adj[src].size()-1});
  }
  flow_type max_flow(int s, int t) {
    vector<int> level(n), iter(n);
    function<int(void)> levelize = [&]() { // foward levelize
      level.assign(n, -1); level[s] = 0;
      queue<int> Q; Q.push(s);
      while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u == t) break;
        for (auto &e: adj[u]) {
          if (e.capacity > e.flow && level[e.dst] < 0) {
            Q.push(e.dst);
            level[e.dst] = level[u] + 1;
          }
        }
      }
      return level[t];
    };
    function<flow_type(int, flow_type)> augment = [&](int u, flow_type cur) {
      if (u == t) return cur;
      for (int &i = iter[u]; i < adj[u].size(); ++i) {
        edge &e = adj[u][i], &r = adj[e.dst][e.rev];
        if (e.capacity > e.flow && level[u] < level[e.dst]) {
          flow_type f = augment(e.dst, min(cur, e.capacity - e.flow));
          if (f > 0) {
            e.flow += f;
            r.flow -= f;
            return f;
          }
        }
      }
      return flow_type(0);
    };

    flow_type flow = 0;
    while (levelize() >= 0) {
      fill(all(iter), 0);
      for (flow_type f; (f = augment(s, INF)) > 0; )
        flow += f;
    }
    return flow;
  }
};

int N;
int M;
int S;
int T;
int U[114514];
int V[114514];

bool check(int lim) {
  graph g(T+1);
  rep(i, M) {
    g.add_edge(S, N+i, 1);
    g.add_edge(N+i, U[i], 1);
    g.add_edge(N+i, V[i], 1);
  }

  rep(i, N) {
    g.add_edge(i, T, lim);
  }
  return g.max_flow(S, T) >= M;
}

bool check2(int dlim, int lim) {
  int P = T+1;
  int Q = T+2;
  graph g(T+3);
  rep(i, M) {
    g.add_edge(S, N+i, 1);
    g.add_edge(N+i, U[i], 1);
    g.add_edge(N+i, V[i], 1);
  }

  LL dsum = 0;
  rep(i, N) {
    g.add_edge(i, T, lim - dlim);
    g.add_edge(i, Q, dlim);
    g.add_edge(P, T, dlim);
    dsum += dlim;
  }
  auto a = g.max_flow(P, Q);
  auto b = g.max_flow(P, T);
  auto c = g.max_flow(S, Q);
  if (a+b != dsum || a+c != dsum) return false;

  auto d = g.max_flow(S, T);
  return b+d >= M;
}

int main() {
  while (1) {
    scanf("%d%d", &N, &M);
    if ((N|M) == 0) return 0;

    S = N+M;
    T = N+M+1;
    rep(i, M) {
      scanf("%d%d", &U[i], &V[i]);
      --U[i];
      --V[i];
    }

    int low = 0;
    int high = M+1;
    while (high - low > 1) {
      int mid = (high+low)/2;
      if (check(mid)) high = mid;
      else low = mid;
    }

    int low2 = -1;
    int high2 = high+1;
    while (high2 - low2 > 1) {
      int mid = (high2+low2)/2;
      if (check2(mid, high)) low2 = mid;
      else high2 = mid;
    }
    printf("%d %d\n", low2, high);
  }
}

