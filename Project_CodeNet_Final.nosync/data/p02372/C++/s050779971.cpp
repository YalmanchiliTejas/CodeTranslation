// ???????????????
#include<vector>
#include<tuple>
#include<algorithm>
// ???
typedef int Weight;
// ?????????
class Tree {
public:
  explicit Tree(int n);
  int size() const;
  void join(int u, int v, Weight w);
  Weight diameter() const;
  Weight height(int root) const;
  const std::vector<Weight> height() const;
  Weight height_dfs(int u, int v, std::vector<std::vector<Weight>>& cost) const;
private:
  struct Edge {int from, to; Weight weight;};
  struct Farthest {int vertex; Weight cost;};
  const Farthest farthest(int current, int previous) const;
  std::vector<std::vector<Edge>> edge_;
};
// ?????????????????????
Tree::Tree(int n) : edge_(n) {}
// ????????°
int Tree::size() const {return edge_.size();}
// ????????????
void Tree::join(int u, int v, Weight w) {
  edge_[u].push_back({u, v, w});
  edge_[v].push_back({v, u, w});
}
// ???????????¨?????¢
const Tree::Farthest Tree::farthest(int current, int previous) const {
  Farthest result({current, 0});
  for(const auto& e: edge_[current]) {
    if(e.to == previous) continue;
    auto f = farthest(e.to, e.from);
    f.cost += e.weight;
    if(result.cost < f.cost) result = f;
  }
  return result;
}
// ??´???
Weight Tree::diameter() const {
  int v = farthest(0, 0).vertex;
  return farthest(v, v).cost;
}
// ?????????????????????????????§????????¢
//   ?????????farthest????????¢???????????¨????????????
Weight Tree::height(int root) const {return farthest(root, root).cost;}
// ?????????????????????????????§????????¢
//   memo[v][e]: ??????v?????????e????????£?????¨????????????????????§????????¢
const std::vector<Weight> Tree::height() const {
  std::vector<std::vector<Weight>> memo(size());
  for(int v = 0; v < size(); ++v) for(int e = 0; e < edge_[v].size(); ++e) memo[v].push_back(-1);
  for(int v = 0; v < size(); ++v) for(int e = 0; e < edge_[v].size(); ++e) if(memo[v][e] == -1) height_dfs(v, e, memo);
  std::vector<Weight> result(size(), 0);
  for(int v = 0; v < size(); ++v) for(int e = 0; e < edge_[v].size(); ++e) result[v] = std::max(result[v], memo[v][e]);
  return result;
}
Weight Tree::height_dfs(int v, int e, std::vector<std::vector<Weight>>& memo) const {
  if(memo[v][e] != -1) return memo[v][e];
  memo[v][e] = edge_[v][e].weight;
  int next_v = edge_[v][e].to;
  for(int next_e = 0; next_e < edge_[next_v].size(); ++next_e)
    if(edge_[next_v][next_e].to != v)
      memo[v][e] = std::max(memo[v][e], edge_[v][e].weight + height_dfs(next_v, next_e, memo));
  return memo[v][e];
}

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  Tree t(n);
  for(int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    t.join(u, v, w);
  }
  for(const auto& i: t.height()) cout << i << endl;
}