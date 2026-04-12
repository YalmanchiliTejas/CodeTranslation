#include <iostream>
#include <string>
#include <tuple>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <assert.h>

using namespace std;

class Edge {
public:
  Edge()
    : src(-1), dest(-1) {}
  Edge(int src_, int dest_)
    : src(src_), dest(dest_) {}
  Edge(const Edge& other)
    : src(other.src), dest(other.dest) {}
  
  void print() {
    cout << "(" << src << ", " << dest << ")" << endl;
  }

  Edge rev() {
    return Edge(dest, src);
  }
  
  bool operator==(const Edge& other) const {
    return src == other.src && dest == other.dest;
  }
  
  bool operator<(const Edge& other) const {
    return (dest < other.dest) || (dest == other.dest && src < other.src);
  }

  int src;
  int dest;
};

class Graph {
public:
  Graph(int n)
    : num_of_nodes(n) {
  }

  void add_edge(int src, int dest) {
    edges.insert(Edge(src, dest));
  }
  
  int num_of_nodes;
  set<Edge> edges;

  int num_of_one_stroke();
  void add_targets(set<int>& reached, int node, queue<tuple<set<int>, int>>& targets) {
    for (Edge e : edges) {
      if (e.src == node) {
	set<int> new_reached = reached;
	new_reached.insert(node);
	targets.push(make_tuple(new_reached, e.dest));
      } 
      if (e.dest == node) {
	set<int> new_reached = reached;
	new_reached.insert(node);
	targets.push(make_tuple(new_reached, e.src));
      }
    }
  }
};

int Graph::num_of_one_stroke()
{
  int n = 0;
  queue<tuple<set<int>, int>> targets;
  targets.push(make_tuple(set<int>(), 0));
  while (!targets.empty()) {
    auto pair = targets.front(); 
    set<int> reached = get<0>(pair);
    int node = get<1>(pair);
    targets.pop();
    if (reached.find(node) != reached.end()) {
      continue;
    }
    if (reached.size() + 1 == num_of_nodes) {
      n++;
    } else {
      add_targets(reached, node, targets);
    }
  }
  return n;
}

int main()
{
  int n, m;
  cin >> n >> m;

  Graph g(n);
  for (int i = 0; i < m; i++) {
    int src, dest;
    cin >> src >> dest;
    g.add_edge(src - 1, dest - 1);
  }

  cout << g.num_of_one_stroke() << endl;
  
  return 0;
}
