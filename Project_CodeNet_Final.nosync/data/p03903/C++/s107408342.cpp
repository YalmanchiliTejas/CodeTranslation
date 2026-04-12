
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>
#include <tuple>

template <class T, class U>
inline bool chmin(T& lhs, const U& rhs) {
  if (lhs > rhs) {
    lhs = rhs;
    return true;
  }
  return false;
}

template <class T, class U>
inline bool chmax(T& lhs, const U& rhs) {
  if (lhs < rhs) {
    lhs = rhs;
    return true;
  }
  return false;
}

// [l, r) from l to r
struct range {
  struct itr {
    int i;
    constexpr itr(int i_): i(i_) { }
    constexpr void operator ++ () { ++i; }
    constexpr int operator * () const { return i; }
    constexpr bool operator != (itr x) const { return i != x.i; }
  };
  const itr l, r;
  constexpr range(int l_, int r_): l(l_), r(std::max(l_, r_)) { }
  constexpr itr begin() const { return l; }
  constexpr itr end() const { return r; }
};

// [l, r) from r to l
struct revrange {
  struct itr {
    int i;
    constexpr itr(int i_): i(i_) { }
    constexpr void operator ++ () { --i; }
    constexpr int operator * () const { return i; }
    constexpr bool operator != (itr x) const { return i != x.i; }
  };
  const itr r, l;
  constexpr revrange(int l_, int r_): l(l_ - 1), r(std::max(l_, r_) - 1) { }
  constexpr itr begin() const { return r; }
  constexpr itr end() const { return l; }
};

template <class T>
class partially_persistent_union_find {
public:
  using value_type = T;

private:
  int size;
  value_type last_query;
  const value_type inf;
  std::vector<int> parent;
  std::vector<value_type> updated;
  std::vector<std::pair<value_type, int>> component;
  std::vector<std::vector<std::pair<value_type, int>>> history;

public:
  partially_persistent_union_find(): inf(std::numeric_limits<value_type>::max()) { }
  partially_persistent_union_find(int size_): 
    inf(std::numeric_limits<value_type>::max())
  { init(size_);}

  void init(int size_) {
    size = size_;
    last_query = std::numeric_limits<value_type>::min();
    parent.assign(size_, 1);
    updated.assign(size_, inf);
    component.assign(1, { last_query, size_ });
    history.assign(size_, { { last_query, 1 } });
  }

  int find_parent(int i, const value_type &t) const {
    if (updated[i] > t) {
      return i;
    }
    else {
      return find_parent(parent[i], t);
    }
  }

  int count_components(const value_type &t) const {
    return (--std::upper_bound(component.begin(), component.end(), std::make_pair(t, size))) -> second;
  }
  int component_size(int i, const value_type &t) const {
    i = find_parent(i, t);
    return (--std::upper_bound(history[i].begin(), history[i].end(), std::make_pair(t, size))) -> second;
  }
  bool same_component(int i, int j, const value_type &t) const {
    return find_parent(i, t) == find_parent(j, t);
  }

  value_type united(int i, int j) const {
    if (!same_component(i, j, last_query)) {
      return inf;
    }
    int ok = last_query, ng = -1;
    while (ok - ng > 1) {
      int md = (ok + ng) / 2;
      (same_component(i, j, md) ? ok : ng) = md;
    }
    return ok;
  }

  bool unite(int i, int j, const value_type &t) {
    i = find_parent(i, last_query);
    j = find_parent(j, last_query);
    last_query = t;
    if (i == j) {
      return false;
    }
    if (parent[i] < parent[j]) {
      std::swap(i, j);
    }
    parent[i] += parent[j];
    parent[j] = i;
    updated[j] = last_query;
    int tmp = component.back().second;
    component.emplace_back(last_query, tmp - 1);
    history[i].emplace_back(last_query, parent[i]);
    return true;
  }

};

int main() {
  int N, M, Q, a, b, c;
  scanf("%d %d", &N, &M);
  std::vector<std::tuple<int, int, int>> edges;
  while (M--) {
    scanf("%d %d %d", &a, &b, &c);
    edges.emplace_back(c, a - 1, b - 1);
  }
  std::sort(edges.begin(), edges.end());
  partially_persistent_union_find<int> dsu(N);
  long long sum = 0;
  for (auto e: edges) {
    std::tie(c, a, b) = e;
    if (dsu.unite(a, b, c)) {
      sum += c;
    }
  }
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d %d", &a, &b);
    printf("%lld\n", sum - dsu.united(a - 1, b - 1));
  }
  return 0;
}
