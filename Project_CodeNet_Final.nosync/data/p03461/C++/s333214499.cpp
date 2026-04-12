
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>
#include <array>
#include <queue>

template <class T, class U>
inline bool chmin(T &lhs, const U &rhs) {
  if (lhs > rhs) {
    lhs = rhs;
    return true;
  }
  return false;
}

template <class T, class U>
inline bool chmax(T &lhs, const U &rhs) {
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
  const itr l, r;
  constexpr revrange(int l_, int r_): l(l_ - 1), r(std::max(l_, r_) - 1) { }
  constexpr itr begin() const { return r; }
  constexpr itr end() const { return l; }
};

constexpr int inf = (1 << 30) - 1;
constexpr int d_max = 100;
constexpr int V = 2 * (d_max + 1);
constexpr int S = 0, T = V - 1;

int main() {
  int A, B;
  std::cin >> A >> B;
  std::vector<std::vector<int>> dist(A, std::vector<int>(B));
  for (auto &vec: dist) {
    for (auto &x: vec) {
      std::cin >> x;
    }
  }
  std::array<std::array<int, d_max + 1>, d_max + 1> cost{};
  for (int i: range(0, A)) {
    for (int j: range(0, B)) {
      for (int a: range(0, d_max + 1)) {
        for (int b: range(0, d_max + 1)) {
          chmax(cost[a][b], dist[i][j] - (i + 1) * a - (j + 1) * b);
        }
      }
    }
  }
  std::array<std::pair<int, int>, d_max> Xs{};
  std::array<std::pair<int, int>, d_max> Ys{};
  for (int i: range(0, d_max)) {
    Xs[i] = { i, i + 1 };
    Ys[i] = { V - i - 2, V - i - 1 };
  }
  auto calc = [&](int x, int y) {
    std::array<std::vector<std::pair<int, int>>, V> graph{};
    for (int i: range(0, d_max)) {
      graph[Xs[i].first].emplace_back(Xs[i].second, x);
      graph[Ys[i].first].emplace_back(Ys[i].second, y);
    }
    for (int i: range(0, d_max + 1)) {
      for (int j: range(0, d_max + 1)) {
        if (cost[i][j] <= d_max) {
          graph[i].emplace_back(V - j - 1, cost[i][j]);
        }
      }
    }
    std::array<int, V> length{};
    length.fill(inf);
    length[S] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;
    que.emplace(length[S], S);
    while (!que.empty()) {
      auto tmp = que.top();
      que.pop();
      int d = tmp.first;
      int v = tmp.second;
      if (d > length[v]) {
        continue;
      }
      for (auto e: graph[v]) {
        if (chmin(length[e.first], length[v] + e.second)) {
          que.emplace(length[e.first], e.first);
        }
      }
    }
    return length[T];
  };
  for (int i: range(0, A)) {
    for (int j: range(0, B)) {
      if (dist[i][j] != calc(i + 1, j + 1)) {
        std::cout << "Impossible\n";
        return 0;
      }
    }
  }
  std::cout << "Possible\n";
  int E = 2 * d_max;
  for (const auto &arr: cost) {
    for (auto x: arr) {
      if (x <= d_max) {
        ++E;
      }
    }
  }
  std::cout << V << ' ' << E << '\n';
  for (auto e: Xs) {
    std::cout << e.first + 1 << ' ' << e.second + 1 << " X\n";
  }
  for (auto e: Ys) {
    std::cout << e.first + 1 << ' ' << e.second + 1 << " Y\n";
  }
  for (int i: range(0, d_max + 1)) {
    for (int j: range(0, d_max + 1)) {
      if (cost[i][j] <= d_max) {
        std::cout << i + 1 << ' ' << V - j << ' ' << cost[i][j] << '\n';
      }
    }
  }
  std::cout << S + 1 << ' ' << T + 1 << '\n';
  return 0;
}
