#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;

template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) {
  return a < b && (a = b, true);
}

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) {
  return a > b && (a = b, true);
}

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e : t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

template< typename flow_t >
struct Dinic {
  const flow_t INF;

  struct edge {
    int to;
    flow_t cap;
    int rev;
    bool isrev;
    int idx;
  };

  vector< vector< edge > > graph;
  vector< int > min_cost, iter;

  Dinic(int V) : INF(numeric_limits< flow_t >::max()), graph(V) {}

  void add_edge(int from, int to, flow_t cap, int idx = -1) {
    graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(), false, idx});
    graph[to].emplace_back((edge) {from, 0, (int) graph[from].size() - 1, true, idx});
  }

  bool bfs(int s, int t) {
    min_cost.assign(graph.size(), -1);
    queue< int > que;
    min_cost[s] = 0;
    que.push(s);
    while(!que.empty() && min_cost[t] == -1) {
      int p = que.front();
      que.pop();
      for(auto &e : graph[p]) {
        if(e.cap > 0 && min_cost[e.to] == -1) {
          min_cost[e.to] = min_cost[p] + 1;
          que.push(e.to);
        }
      }
    }
    return min_cost[t] != -1;
  }

  flow_t dfs(int idx, const int t, flow_t flow) {
    if(idx == t)
      return flow;
    for(int &i = iter[idx]; i < graph[idx].size(); i++) {
      edge &e = graph[idx][i];
      if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
        flow_t d = dfs(e.to, t, min(flow, e.cap));
        if(d > 0) {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  flow_t max_flow(int s, int t) {
    flow_t flow = 0;
    while(bfs(s, t)) {
      iter.assign(graph.size(), 0);
      flow_t f = 0;
      while((f = dfs(s, t, INF)) > 0) flow += f;
    }
    return flow;
  }

  void output() {
    for(int i = 0; i < graph.size(); i++) {
      for(auto &e : graph[i]) {
        if(e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << (&rev_e) << " " << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
      }
    }
  }
};

template< typename flow_t, template< typename > class F >
struct MaxFlowLowerBound {
  F< flow_t > flow;
  vector< flow_t > in, up;
  typename F< flow_t >::edge *latte, *malta;
  int X, Y, V;
  flow_t sum;

  MaxFlowLowerBound(int V) : V(V), flow(V + 2), X(V), Y(V + 1), sum(0), in(V) {}

  void add_edge(int from, int to, flow_t low, flow_t high) {
    assert(from != to);
    flow.add_edge(from, to, high - low, up.size());
    in[from] -= low;
    in[to] += low;
    up.emplace_back(high);
  }

  void build() {
    for(int i = 0; i < V; i++) {
      if(in[i] > 0) {
        flow.add_edge(X, i, in[i]);
        sum += in[i];
      } else if(in[i] < 0) {
        flow.add_edge(i, Y, -in[i]);
      }
    }
  }

  bool can_flow(int s, int t) {
    assert(s != t);
    flow.add_edge(t, s, flow.INF);
    latte = &flow.graph[t].back();
    malta = &flow.graph[s].back();
    return can_flow();
  }

  bool can_flow() {
    build();
    auto ret = flow.max_flow(X, Y);
    return ret >= sum;
  }

  flow_t max_flow(int s, int t) {
    if(can_flow(s, t)) {
      return flow.max_flow(s, t);
    } else {
      return -1;
    }
  }

  flow_t min_flow(int s, int t) {
    if(can_flow(s, t)) {
      auto ret = flow.INF - latte->cap;
      latte->cap = malta->cap = 0;
      return ret - flow.max_flow(t, s);
    } else {
      return -1;
    }
  }

  void output(int M) {
    vector< flow_t > ans(M);
    for(int i = 0; i < flow.graph.size(); i++) {
      for(auto &e : flow.graph[i]) {
        if(!e.isrev && ~e.idx) ans[e.idx] = up[e.idx] - e.cap;
      }
    }
    for(auto &p : ans) cout << p << endl;
  }
};

int main() {
  int N, M;
  while(cin >> N >> M, N) {
    vector< int > U(M), V(M);
    for(int i = 0; i < M; i++) {
      cin >> U[i] >> V[i];
      --U[i], --V[i];
    }
    auto check = [&](int low, int high) {
      MaxFlowLowerBound< int, Dinic > flow(N + M + 2);
      int S = N + M, T = N + M + 1;
      for(int i = 0; i < M; i++) {
        flow.add_edge(S, i, 1, 1);
        flow.add_edge(i, M + U[i], 0, 1);
        flow.add_edge(i, M + V[i], 0, 1);
      }
      for(int i = 0; i < N; i++) {
        flow.add_edge(M + i, T, low, high);
      }
      return flow.can_flow(S, T);
    };

    int p = 0, q = N;
    int l = 0;
    for(int r = 0; r <= N; r++) {
      while(l <= r && check(l, r)) {
        p = l, q = r;
        ++l;
      }
    }
    cout << p << " " << q << endl;
  }
}

