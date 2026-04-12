#include <iostream>
#include <cstdint>
#include <vector>
#include <unordered_set>
#include <stack>
#include <cassert>

class history {
private:
  const std::vector<std::vector<std::int_fast32_t>>& m_graph;
  std::stack<std::int_fast32_t> m_stack;
  std::unordered_set<std::int_fast32_t> m_unordered_set;

public:
  history(const std::vector<std::vector<std::int_fast32_t>>& graph) :
    m_graph(graph),
    m_stack(),
    m_unordered_set() {
  }

  const std::vector<std::vector<std::int_fast32_t>>& graph() const {
    return this->m_graph;
  }

  std::size_t size() const {
    return this->m_stack.size();
  }

  bool empty() const {
    return this->size() == 0;
  }

  bool full() const {
    return this->size() == this->graph().size();
  }

  std::int_fast32_t pos() const {
    assert(!this->empty());
    return this->m_stack.top();
  }

  void visit(const std::int_fast32_t node) {
    assert(!this->full());
    this->m_stack.push(node);
    this->m_unordered_set.insert(node);
  }

  void back() {
    assert(!this->empty());
    const std::int_fast32_t pos = this->pos();
    this->m_stack.pop();
    this->m_unordered_set.erase(pos);
  }

  bool visited(const std::int_fast32_t node) const {
    return this->m_unordered_set.count(node) > 0;
  }
};

std::int_fast32_t dfs(history& history) {
  assert(!history.empty());

  if (history.full()) return 1;

  std::int_fast32_t result = 0;
  for (const std::int_fast32_t& to : history.graph()[history.pos()]) {
    if (history.visited(to)) continue;
    history.visit(to);
    result += dfs(history);
    history.back();
  }
  return result;
}

int main() {
  std::int_fast32_t n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::int_fast32_t>> graph(n);
  for (std::int_fast32_t i = 0; i < m; ++i) {
    std::int_fast32_t a, b;
    std::cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }

  history history(graph);
  history.visit(0);
  std::cout << dfs(history) << std::endl;

  return 0;
}