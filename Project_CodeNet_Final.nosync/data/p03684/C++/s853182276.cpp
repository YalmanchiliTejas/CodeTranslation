#include <iostream>
#include <vector>
#include <algorithm>

class DisjointSet {
 public:
  std::vector<unsigned> parent;
  std::vector<unsigned> rank;
  DisjointSet(unsigned size)
      : parent(size),
        rank(size, 0u) {
    for (unsigned i = 0; i < size; ++i) { parent[i] = i; }
  }
  unsigned find(unsigned index) {
    if (parent[index] != index) { return parent[index] = find(parent[index]); }
    else { return index; }
  }
  void merge(unsigned index_a, unsigned index_b) {
    auto parent_a = find(index_a);
    auto parent_b = find(index_b);
    if (parent_a == parent_b) { return; }
    if (rank[parent_a] < rank[parent_b]) { parent[parent_a] = parent_b; }
    else if (rank[parent_b] < rank[parent_b]) { parent[parent_b] = parent_a; }
    else {
      ++rank[parent_a];
      parent[parent_b] = parent_a;
    }
  }
};

int main() {
  unsigned N;
  std::cin >> N;
  using pu = std::pair<std::pair<unsigned, unsigned>, unsigned>;
  std::vector<pu> town(N);
  DisjointSet disjointSet(N);
  for (unsigned i = 0; i < N; ++i) {
    std::cin >> town[i].first.first >> town[i].first.second;
    town[i].second = i;
  }
  std::sort(town.begin(), town.end(),
            [](pu i, pu j) -> bool {
              return i.first.first < j.first.first
                  || (i.first.first == j.first.first && i.first.second < j.first.second);
            });
  for (unsigned i = 0; i < N - 1; ++i) {
    if (town[i].first == town[i + 1].first) {
      disjointSet.merge(town[i].second, town[i + 1].second);
    }
  }
  std::vector<pu> horiz(N - 1);
  for (unsigned i = 0; i < N - 1; ++i) {
    horiz[i].second = town[i + 1].first.first - town[i].first.first;
    horiz[i].first.first = town[i].second;
    horiz[i].first.second = town[i + 1].second;
  }
  std::sort(horiz.begin(), horiz.end(), [](pu i, pu j) -> bool { return i.second < j.second; });
  std::sort(town.begin(), town.end(),
            [](pu i, pu j) -> bool {
              return i.first.second < j.first.second
                  || (i.first.second == j.first.second && i.first.first < j.first.first);
            });
  std::vector<pu> vert(N - 1);
  for (unsigned i = 0; i < N - 1; ++i) {
    vert[i].second = town[i + 1].first.second - town[i].first.second;
    vert[i].first.first = town[i].second;
    vert[i].first.second = town[i + 1].second;
  }
  std::sort(vert.begin(), vert.end(), [](pu i, pu j) -> bool { return i.second < j.second; });
  unsigned long long cost = 0;
  auto ph = horiz.begin();
  auto pv = vert.begin();
  while (ph < horiz.end() || pv < vert.end()) {
    if (ph < horiz.end() && (pv >= vert.end() || ph->second < pv->second)) {
      if (disjointSet.find(ph->first.first) != disjointSet.find(ph->first.second)) {
        cost += ph->second;
        disjointSet.merge(ph->first.first, ph->first.second);
      }
      ++ph;
    } else {
      if (disjointSet.find(pv->first.first) != disjointSet.find(pv->first.second)) {
        cost += pv->second;
        disjointSet.merge(pv->first.first, pv->first.second);
      }
      ++pv;
    }
  }
  std::cout << cost;
  return 0;
}