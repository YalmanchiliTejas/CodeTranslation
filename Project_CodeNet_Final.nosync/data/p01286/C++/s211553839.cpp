#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
template< typename flow_t >
struct Dinic {
  const flow_t INF;

  struct edge {
    int to;
    flow_t cap;
    int rev;
    bool isrev;
  };

  vector< vector< edge > > graph;
  vector< int > min_cost, iter;

  Dinic(int V) : INF(numeric_limits< flow_t >::max()), graph(V) {}

  void add_edge(int from, int to, flow_t cap) {
    graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(), false});
    graph[to].emplace_back((edge) {from, 0, (int) graph[from].size() - 1, true});
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

int main(void){
    int H,W,C,M,nw,nc,nm,i,j,k;
    while(cin >> H >> W >> C >> M >> nw >> nc >> nm){
        if(H==-1)break;
        Dinic< int > g(2*(H+W+C+M)+10);
        //Warrior
        for(int to=1;to<=W;to++){
            cin >> j;
            for(k=0;k<j;k++){
                int from;
                cin >> from;
                g.add_edge(from,to+H,1);
            }
        }
        for(i=1;i<=W;i++)g.add_edge(i+H,i+H+W,1);
        //cleric
        for(int to=1;to<=C;to++){
            cin >> j;
            for(k=0;k<j;k++){
                int from;
                cin >> from;
                g.add_edge(from+H+W,to+H+2*W,1);
            }
        }
        for(i=1;i<=C;i++)g.add_edge(i+H+2*W,i+H+2*W+C,1);
        //mage
        for(int to=1;to<=M;to++){
            cin >> j;
            for(k=0;k<j;k++){
                int from;
                cin >> from;
                g.add_edge(from+H+2*W+C,to+H+2*W+2*C,1);
            }
        }
        for(i=1;i<=M;i++)g.add_edge(H+2*W+2*C+i,H+2*W+2*C+M+1,1);//tailのedge
        
        for(i=1;i<=H;i++)g.add_edge(0,i,1);//最初のedge
        for(i=1;i<=H;i++)g.add_edge(i,H+2*W+2*C+M+2,1);//任意の勇者からwarriorを迂回するedge
        g.add_edge(H+2*W+2*C+M+2,H+2*W+2*C+M+3,nw);//warriorスルーできる数
        for(i=1;i<=C;i++)g.add_edge(H+2*W+2*C+M+3,H+2*W+i,1);//warrior迂回した後のedge
        for(i=1;i<=W;i++)g.add_edge(H+W+i,H+2*W+2*C+M+4,1);//clericを迂回するedge
        g.add_edge(H+2*W+2*C+M+4,H+2*W+2*C+M+5,nc);//clericスルーできる数
        for(i=1;i<=M;i++)g.add_edge(H+2*W+2*C+M+5,H+2*W+2*C+i,1);//迂回したあとのedge
        for(i=1;i<=C;i++)g.add_edge(H+2*W+C+i,H+2*W+2*C+M+6,1);//mageを迂回
        g.add_edge(H+2*W+2*C+M+6,H+2*W+2*C+M+1,nm);
        cout << g.max_flow(0,H+2*W+2*C+M+1) << endl;
    }
    return 0;
}

