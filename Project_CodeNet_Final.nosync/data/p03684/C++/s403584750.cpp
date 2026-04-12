#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

struct UnionFind{
  std::vector<int> parent;
  UnionFind(int N) : parent(N) { for(int i = 0; i < N; ++i){ this->Root(i) = i; } }

  int& Root(int id){
    if(this->parent[id] == id){ return this->parent[id]; }
    else{ return this->parent[id] = this->Root(this->parent[id]); }
  }
  int Find(int id){ return this->Root(id); }

  bool Unite(int lhs, int rhs){
    if(this->Root(lhs) != this->Root(rhs)){ this->parent[this->Root(rhs)] = this->Root(lhs); return true; }
    return false;
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

  UnionFind unionFind(N);
  long long int sumCost = 0;

  for(auto it = cost.begin(), end = cost.end(); it != end; ++it){
    if(unionFind.Find(it->left) != unionFind.Find(it->right)){
      unionFind.Unite(it->left, it->right);
      sumCost += it->cost;
    }
  }

  std::cout << sumCost << std::endl;

  return 0;
}

