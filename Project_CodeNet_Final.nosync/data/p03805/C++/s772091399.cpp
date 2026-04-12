#include <algorithm>
#include <array>
#include <bitset>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15);
  }
} initializer;

template<typename T> istream& operator>>(istream &s, vector<T> &v) {
  for (T &t : v) s >> t;
  return s;
}

template<typename T> ostream& operator<<(ostream &s, const vector<T> &v) {
  for (const T &t : v) s << t << endl;
  return s;
}

template<typename T> T min(vector<T>& v) {return *min_element(v.begin(), v.end());}

template<typename T> T max(vector<T>& v) {return *max_element(v.begin(), v.end());}

template<typename T> int min_element(vector<T>& v) {return min_element(v.begin(), v.end()) - v.begin();}

template<typename T> int max_element(vector<T>& v) {return max_element(v.begin(), v.end()) - v.begin();}

template<typename T> void sort(vector<T>& v) {sort(v.begin(), v.end());}

template<typename T, typename Function> void sort(vector<T>& v, Function func) {sort(v.begin(), v.end(), func);}

template<typename T> void rsort(vector<T>& v) {sort(v.rbegin(), v.rend());}

template<typename T> void reverse(vector<T>& v) {reverse(v.begin(), v.end());}

template<typename T> void unique(vector<T>& v) {v.erase(unique(v.begin(), v.end()), v.end());}

template<typename T> void nth_element(vector<T>& v, int n) {nth_element(v.begin(), v.begin() + n, v.end());}

template<typename T> bool next_permutation(vector<T>& v) {return next_permutation(v.begin(), v.end());}

template<typename T> int find(vector<T>& v, T t) {return find(v.begin(), v.end(), t) - v.begin();}

template<typename T> int in(vector<T> v, T t) {return find(v, t) != int(v.size());}

template<typename T> int lower_bound(vector<T>& v, T t) {return lower_bound(v.begin(), v.end(), t) - v.begin();}

template<typename T> int upper_bound(vector<T>& v, T t) {return upper_bound(v.begin(), v.end(), t) - v.begin();}

template<typename T> T accumulate(const vector<T>& v, function<T(T, T)> func = plus<T>()) {return accumulate(v.begin(), v.end(), T(), func);}

template<typename T> void adjacent_difference(vector<T>& v) {adjacent_difference(v.begin(), v.end(), v.begin());}

template<typename T> void adjacent_difference(vector<T>& v, vector<T>& u) {adjacent_difference(v.begin(), v.end(), u.begin());}

template<typename T> void partial_sum(vector<T>& v, vector<T>& u) {partial_sum(v.begin(), v.end(), u.begin());}

template<typename T> T inner_product(vector<T>& v, vector<T>& u) {return inner_product(v.begin(), v.end(), u.begin(), T(0));}

template<typename T> int count(const vector<T>& v, T t) {return count(v.begin(), v.end(), t);}

template<typename T, typename Function> int count_if(const vector<T>& v, Function func) {return count_if(v.begin(), v.end(), func);}

template<typename T, typename Function> void remove_if(vector<T>& v, Function func) {v.erase(remove_if(v.begin(), v.end(), func), v.end());}

template<typename T, typename Function> bool all_of(vector<T> v, Function func) {return all_of(v.begin(), v.end(), func);}

template<typename T, typename Function> bool any_of(vector<T> v, Function func) {return any_of(v.begin(), v.end(), func);}

template<typename T, typename Function> bool none_of(vector<T> v, Function func) {return none_of(v.begin(), v.end(), func);}

template<typename T> vector<T> subvector(vector<T>& v, int a, int b) {return vector<T>(v.begin() + a, v.begin() + b);}

template<typename T> int kinds(const vector<T>& v) {return set<T>(v.begin(), v.end()).size();}

template<typename T> void iota(vector<T>& v, T t = 0) {iota(v.begin(), v.end(), t);}

template<typename T> bool is_sorted(const vector<T>& v) {return is_sorted(v.begin(), v.end());}

class Permutation {
private:
  int id;
  vector<int> perm;

public:
  Permutation(int n) : id(0), perm(n) {
    iota(perm);
  }

  vector<int> operator*() {
    return perm;
  }

  bool operator!=(const Permutation& itr) const {
    return id != itr.id;
  }

  void operator++() {
    id = next_permutation(perm) ? id + 1 : -1;
  }

  Permutation& begin() {
    return *this;
  }

  Permutation& end();

  static Permutation makeEnd() {
    Permutation p(0);
    p.id = -1;
    return p;
  }
};

Permutation permutation_end = Permutation::makeEnd();

Permutation& Permutation::end() {
  return permutation_end;
}

template<typename Edge> class Graph {
public:
  using EdgeType = Edge;
  virtual int size() const = 0;
  template<typename... Args> void addEdge(int from, int to, Args...) {
    (void)from;
    (void)to;
  }
  template<typename... Args> void addUndirectedEdge(int from, int to, Args...) {
    (void)from;
    (void)to;
  }

  vector<pair<int, Edge>> getAllEdges() const {
    vector<pair<int, Edge>> res;
    for (int i = 0; i < size(); ++i) {
      for (const auto& edge : getEdges(i)) {
        res.emplace_back(i, edge);
      }
    }
    return res;
  }

  virtual vector<Edge> getEdges(int from) const = 0;
  virtual Edge getEdge(int from, int to) const = 0;
  virtual bool hasEdge(int from, int to) const = 0;

  int getDegree(int v) const {
    return getEdges(v).size();
  }

  vector<int> getIndegree() const {
    vector<int> degree(size());
    for (const auto& edge : getAllEdges()) ++degree[edge.second.to];
    return degree;
  }
};

template<typename Edge> class AdjacencyList : public Graph<Edge> {
protected:
  vector<vector<Edge>> graph;

public:
  AdjacencyList(int n) : graph(n) {}

  int size() const {
    return graph.size();
  }
  
  template<typename... Args> void addEdge(int from, int to, Args... args) {
    graph[from].emplace_back(to, args...);
  }

  template<typename... Args> void addUndirectedEdge(int from, int to, Args... args) {
    addEdge(from, to, args...);
    addEdge(to, from, args...);
  }

  vector<Edge> getEdges(int from) const {
    return graph[from];
  }

  Edge getEdge(int from, int to) const {
    Edge res;
    for (const auto& edge : graph[from]) {
      if (edge.to == to) res = edge;
    }
    return res;
  }

  bool hasEdge(int from, int to) const {
    for (const auto& edge : graph[from]) {
      if (edge.to == to) return true;
    }
    return false;
  }

  vector<Edge>& operator[](int v) {
    return graph[v];
  }
};

struct Edge {
  using CostType = int;
  const static int cost = 1;
  int to;
  Edge(int to = -1) : to(to) {}
  bool isNone() const {return to == -1;}
};

template<typename Cost> struct WeightedEdge : public Edge {
  using CostType = Cost;
  Cost cost;
  WeightedEdge(int to = -1, Cost cost = 0) : Edge(to), cost(cost) {}
};

template<typename Capacity> struct ResidualEdge : public Edge {
  using CapacityType = Capacity;
  Capacity cap;
  int rev;
  ResidualEdge(int to = -1, Capacity cap = 0) : Edge(to), cap(cap) {}
  ResidualEdge reverse(int from) const {return ResidualEdge(from, 0);}
};

template<typename Capacity, typename Cost> struct WeightedResidualEdge : public ResidualEdge<Capacity> {
  Cost cost;
  WeightedResidualEdge(int to = -1, Capacity cap = 0, Cost cost = 0) : ResidualEdge<Capacity>(to, cap), cost(cost) {}
  WeightedResidualEdge reverse(int from) const {return WeightedResidualEdge(from, 0, -cost);}
};

int main() {
  int n, m, r = 0;
  cin >> n >> m;
  AdjacencyList<Edge> graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    graph.addUndirectedEdge(a - 1, b - 1);
  }
  for (const auto& perm : Permutation(n - 1)) {
    bool f = true;
    if (!graph.hasEdge(0, perm[0] + 1)) f = false;
    for (int i = 0; i < n - 2; ++i) {
      if (!graph.hasEdge(perm[i] + 1, perm[i + 1] + 1)) f = false;
    }
    if (f) ++r;
  }
  cout << r << endl;
}

