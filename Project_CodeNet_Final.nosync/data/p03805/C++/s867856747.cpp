#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using Edges = std::vector<int>;

class Node {
 public:
  explicit Node(int id): id_(id) {}
  void addEdge(int edge) {
    edges_.push_back(edge);
  }
  const Edges& edges() const {return edges_;}
  int id() const {return id_;}
 private:
  int id_;
  Edges edges_;
};

class Graph {
  using GraphIndices = std::unordered_map<int, Node*>;
 public:
  Graph() = default;

  Node* find(int id) {
    return graph_.find(id)->second;
  }

  size_t size() const {
    return graph_.size();
  }

  GraphIndices::iterator begin() {return graph_.begin();}
  GraphIndices::iterator end() {return graph_.end();}
  
  void addNode(int id, int to) {
    auto from = graph_.find(id);
    Node* node = nullptr;
    if (graph_.end() == from) {
      node = new Node(id);
      graph_.insert({id, node});
    } else {
      node = from->second;
    }
    node->addEdge(to);
    if (id == 1) {
      start_ = node;
    }
    
    auto toNode = graph_.find(to);
    if (graph_.end() == toNode) {
      node = new Node(to);
      graph_.insert({to, node});
    } else {
      node = toNode->second;
    }
    node->addEdge(id);
  }
  
  Node* start() {return start_;}
 private:
  Node* start_;
  GraphIndices graph_;
};

using VisitedSet = std::unordered_set<int>;

void walk(int* route_count, Node* node, Graph* graph, VisitedSet* visited_set) {
  visited_set->insert(node->id());
  for (const auto &e: node->edges()) {
    if (visited_set->count(e) > 0) {
      continue;
    }
    auto copy = *visited_set;
    walk(route_count, graph->find(e), graph, &copy);
  }

  if (visited_set->size() == graph->size()) {
    (*route_count)++;
  }
}

int main() {
  int edgeCount = 0, vertCount = 0;
  scanf("%d %d", &vertCount, &edgeCount);
  Graph graph;

  for (int i = 0; i < edgeCount; i++) {
    int vertId = 0, toVertId = 0;
    scanf("%d %d", &vertId, &toVertId);
    graph.addNode(vertId, toVertId);
  }

  int find_routes = 0;
  VisitedSet visited_set;
  walk(&find_routes, graph.start(), &graph, &visited_set);
  printf("%d\n", find_routes);
  return 0;
}
