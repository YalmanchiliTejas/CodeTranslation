#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <regex>
#include <numeric>

using namespace std;


/*--- Macro ---*/
#define rep(i, n) for(int i=0; i<(int)n; i++)
#define rep1(i, n) for(int i=1; i<(int)n; i++)
#define mp make_pair
#define pb push_back


/*---  Type ---*/
typedef long long ll;


/*--- Constants ---*/
template <typename T> const T INF = numeric_limits<T>::max() / 10;
const int MOD = (int)1e9 + 7;

// 4-direction
int dy4[] = {0,  1, -1,  0};
int dx4[] = {1,  0,  0, -1};

// 8-direction
int dy8[] = {0,  1,  1,  1,  0, -1, -1, -1};
int dx8[] = {1,  1,  0, -1, -1, -1,  0,  1};

// Floating
const double EPS = 1e-11;
#define EQ0(x) (abs(x) < EPS)
#define EQ(x, y) (abs(a-b) < EPS)

/**
  辺
  to: 辺の行き先
  cost: 辺の重み
  T: 重みの型
*/
template <typename T = int>
struct Edge {
  int to;
  T cost;
  Edge(int to, T cost) : to(to), cost(cost) {}
};

/**
  n: 頂点数
  graph: グラフ本体
*/
template <typename T = int>
class Graph {
  public:
    int n;
    vector<vector<Edge<T>>> graph;

    Graph(int n) {
      this->n = n;
      this->graph.assign(n, vector<Edge<T>>());
    }

    void addEdge(int from, int to, T cost) {
      this->graph[from].push_back(Edge<T>(to, cost));
    }
};

class P {
  public:
    int n;
    vector<bool> visited;
    int now;

    P(int n) {
      this->n = n;
      this->visited.resize(n);
      fill(this->visited.begin(), this->visited.end(), false);
      visited[0] = true;
      this->now = 0;
    }

    bool allVisited() {
      rep(i, this->n) {
        if(!visited[i]) {
          return false;
        }
      }
      return true;
    }

    P copy() {
      P cp = P(this->n);
      vector<bool> cvisited(this->n);
      rep(i, this->n) cvisited[i] = this->visited[i];
      cp.visited = cvisited;
      cp.now = this->now;
      return cp;
    }
};

int main() {
  int n, m;
  cin >> n >> m;
  Graph<int> g = Graph<int>(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    g.addEdge(a-1, b-1, 1);
    g.addEdge(b-1, a-1, 1);
  }

  queue<P> Q;
  Q.push(P(n));

  int ans = 0;
  while(!Q.empty()) {
    P p = Q.front(); Q.pop();
    if(p.allVisited()) {
      ans++;
      continue;
    }

    for(auto e : g.graph[p.now]) {
      if(p.visited[e.to]) continue;
      P cp = p.copy();
      cp.visited[e.to] = true;
      cp.now = e.to;
      Q.push(cp);
    }
  }

  cout << ans << endl;


  return 0;
}