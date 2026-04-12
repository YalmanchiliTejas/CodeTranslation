#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

struct UnionFind{
  std::vector<int> parent;
  int& Root(int id){
    if(this->parent[id] == id){ return this->parent[id]; }
    else{ return this->parent[id] = this->Root(this->parent[id]); }
  }

  UnionFind(int N) : parent(N)
  {
    for(int i = 0; i < N; ++i){ this->Root(i) = i; }
  }

  void Union(int lhs, int rhs){
    if(this->Root(lhs) != this->Root(rhs)){ this->Root(this->Root(rhs)) = this->Root(lhs); }
  }

};

int main(void)
{
  int N;
  std::cin >> N;

  std::vector<std::pair<int, long long int> > x(N), y(N);
  for(int i = 0; i < N; ++i){
    long long int a, b;
    std::cin >> a >> b;
    x[i] = std::make_pair(i, a);
    y[i] = std::make_pair(i, b);
  }

  std::sort(x.begin(), x.end(), [](auto const& lhs, auto const& rhs){ return lhs.second < rhs.second; });
  std::sort(y.begin(), y.end(), [](auto const& lhs, auto const& rhs){ return lhs.second < rhs.second; });

  struct Cost{ long long int cost; int left; int right; };
  std::vector<Cost> cost((N-1)*2);
  for(int i = 0; i < N-1; ++i){
    cost[i*2] = {x[i+1].second-x[i].second, x[i].first, x[i+1].first};
    cost[i*2+1] = {y[i+1].second-y[i].second, y[i].first, y[i+1].first};
  }
  std::sort(cost.begin(), cost.end(), [](auto const& lhs, auto const& rhs){ return lhs.cost < rhs.cost; });

  std::vector<bool> checked(N, false);
  long long int sumCost = 0, sumCost2 = 0;
  UnionFind uf(N);

  for(auto it = cost.begin(), end = cost.end(); it != end; ++it){
    if(!checked[it->left] || !checked[it->right]){
      sumCost += it->cost;
      checked[it->left] = checked[it->right] = true;
    }
    if(uf.Root(it->left) != uf.Root(it->right)){
      uf.Union(it->left, it->right);
      sumCost2 += it->cost;
    }
  }

  std::cout << sumCost2 << std::endl;

  return 0;
}

