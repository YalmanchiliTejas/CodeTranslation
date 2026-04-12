#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;
#define REP(i,n) for(int i=0;i<(int)n;++i)
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){
os << "(" << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator << (ostream& os, const vector<T> v){
for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
string num2bit(ll num, ll len){
    string bit = "";
    REP(i, len){
    bit += char('0'+(num>>i & 1));
    }
    return bit;
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
    if(idx == t) return flow;
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
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
      }
    }
  }
};


template< typename flow_t, template< typename > class F >
struct MaxFlowLowerBound {
  int V;
  F< flow_t > flow;
  int X, Y;
  vector< flow_t > in, up;
  typename F< flow_t >::edge *latte, *malta;
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


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ull> S(N), T(N), U(N), V(N);
    REP(i, N) cin >> S[i];
    REP(i, N) cin >> T[i];
    REP(i, N) cin >> U[i];
    REP(i, N) cin >> V[i];

    vector<vector<ull>> res(N, vector<ull>(N, 0));

    bool ok = true;
    ull base = 1;
    REP(t, 64){
        MaxFlowLowerBound<ll, Dinic> F(2*N+2);

        REP(i, N){
            REP(j, N){
                F.add_edge(i, N+j, 0, 1);
            }
        }

        REP(i, N){
            ll ub, lb;
            ll bin = (U[i]>>t & 1);

            if(S[i] == 0 and bin == 0) lb = 0, ub = N-1;
            if(S[i] == 0 and bin == 1) lb = N, ub = N;
            if(S[i] == 1 and bin == 0) lb = 0, ub = 0;
            if(S[i] == 1 and bin == 1) lb = 1, ub = N;

            F.add_edge(2*N, i, lb, ub);
        }

        REP(i, N){
            ll ub, lb;
            ll bin = (V[i]>>t & 1);

            if(T[i] == 0 and bin == 0) lb = 0, ub = N-1;
            if(T[i] == 0 and bin == 1) lb = N, ub = N;
            if(T[i] == 1 and bin == 0) lb = 0, ub = 0;
            if(T[i] == 1 and bin == 1) lb = 1, ub = N;

            F.add_edge(i+N, 2*N+1, lb, ub);
        }

        if(F.min_flow(2*N, 2*N+1) == -1) ok = false;

        //vector<vector<ll>> tmp(N, vector<ll>(N, 0));

        REP(i, N){
            for(auto e: F.flow.graph[i]){
                if(N <= e.to and e.to < 2*N){
                    ll val = 1-e.cap;
                    //tmp[i][e.to-N] = val;
                    res[i][e.to-N] += base * val;
                }
            }
        }

        //dump(t)
        
        /*
        REP(i, N){
            REP(j, N){
                cout << tmp[i][j] << " ";
            }
            cout << endl;
        }
        */

        base *= 2;
    }

    if(ok){
        REP(i, N){
            REP(j, N){
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }else{
        cout << -1 << endl;
    }

    return 0;
}