#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
template< typename flow>
struct max_flow {
    struct edge {
        int to;
        flow cap;
        int rev; };
    int V;
    vector<vector<edge>> G;
    vector<int> itr, level;

    max_flow(int V) : V(V) { G.assign(V,vector<edge>()); }

    void add_edge(int from, int to, flow cap) {
        G[from].push_back((edge) {to, cap, (int) G[to].size()});
        G[to].push_back((edge) {from, 0, (int) G[from].size()-1});
    }

    void bfs(int s) {
        level.assign(V,-1);
        queue<int> q;
        level[s] = 0; q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for(auto &e: G[v]){
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    flow dfs(int v, int t, flow f) {
        if (v == t) return f;
        for (int& i = itr[v]; i < (int) G[v].size(); ++i) {
            edge& e = G[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                flow d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow run(int s, int t) {
        flow ret = 0, f;
        while (bfs(s), level[t] >= 0) {
            itr.assign(V,0);
            while ((f = dfs(s, t, INF)) > 0) ret += f;
        }
        return ret;
    }
};


template< typename flow_t, template< typename > class F >
struct MaxFlowLowerBound {
  F< flow_t > flow;
  int X, Y;
  flow_t low_sum;

  MaxFlowLowerBound(int V) : flow(V + 2), X(V), Y(V + 1), low_sum(0) {}

  void add_edge(int from, int to, flow_t low, flow_t high) {
    flow.add_edge(from, to, high - low);
    flow.add_edge(X, to, low);
    flow.add_edge(from, Y, low);
    low_sum += low;
  }

  flow_t run(int s, int t) {
    auto a = flow.run(X, Y);
    auto b = flow.run(s, Y);
    auto c = flow.run(X, t);
    auto d = flow.run(s, t);
    return b == c && a + b == low_sum ? b + d : -1;
  }
};


int u[10000], v[10000];

int main() {
    while(true) {
        int n, m;
        cin >> n >> m;
        if(n == 0) break;
        for(int i = 1; i <= m; i++) cin >> u[i] >> v[i];
        int ansmin = 0;
        int ansmax = 1e9;
        for(int mini = 0; mini <= n - 1; mini++) {
            int ok = n;
            int ng = max(0, mini - 1);
            while(ok - ng > 1) {
                int mid = (ok + ng) / 2;
                MaxFlowLowerBound<int, max_flow> graph(20001);
                for(int i = 1; i <= m; i++) {
                    graph.add_edge(0, n + i, 1, 1);
                    graph.add_edge(n + i, u[i], 0, 1);
                    graph.add_edge(n + i, v[i], 0, 1);
                }
                for(int i = 1; i <= n; i++) {
                    graph.add_edge(i, 1e4, mini, mid);
                }
                int val = graph.run(0, 1e4);
                //cerr << mini << " " << mid << " " << val << endl;
                if(val != -1) ok = mid;
                else ng = mid;
            }
            //cerr << "candidate: " << mini << " " << ok << endl;
                MaxFlowLowerBound<int, max_flow> graph(20001);
                for(int i = 1; i <= m; i++) {
                    graph.add_edge(0, n + i, 1, 1);
                    graph.add_edge(n + i, u[i], 0, 1);
                    graph.add_edge(n + i, v[i], 0, 1);
                }
                for(int i = 1; i <= n; i++) {
                    graph.add_edge(i, 1e4, mini, ok);
                }
                if(graph.run(0, 1e4) == -1) continue;
            if(ansmax - ansmin > ok - mini) {
                ansmax = ok;
                ansmin = mini;
            }
        }
        cout << ansmin << " " << ansmax << endl;
    }
    return 0;
}
