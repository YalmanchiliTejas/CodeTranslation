// Author: Tyler Wang

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdlib>
#include <deque>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;

template <typename T>
constexpr int countl_zero(T x) noexcept {  // C++20
  if (sizeof(T) <= sizeof(unsigned)) {
    return __builtin_clz(x) - (std::numeric_limits<unsigned>::digits -
                               std::numeric_limits<T>::digits);
  } else if (sizeof(T) <= sizeof(unsigned long)) {
    return __builtin_clzl(x) - (std::numeric_limits<unsigned long>::digits -
                                std::numeric_limits<T>::digits);
  } else {
    return __builtin_clzll(x) -
           (std::numeric_limits<unsigned long long>::digits -
            std::numeric_limits<T>::digits);
  }
}

template <typename T>
constexpr T bit_width(T x) noexcept {  // C++20
  return (T)(std::numeric_limits<T>::digits - countl_zero(x));
}

template <typename T>
constexpr T bit_ceil(T x) noexcept {  // C++20
  return (T)(x <= 1 ? 1 : (T)1 << bit_width((T)(x - 1)));
}

template <typename T, typename Join, typename NodeUpdate>
class lazy_seg_tree {
 public:
  lazy_seg_tree(int n, const T& val = T(), const Join& join = Join(),
                const NodeUpdate& node_update = NodeUpdate())
      : join_(join),
        node_update_(node_update),
        n_(n),
        has_lazy_(bit_ceil((unsigned)n_), false),
        lazy_(has_lazy_.size()),
        data_(2 * lazy_.size(), val) {
    init(1, 0, n_ - 1);
  }

  lazy_seg_tree(const std::vector<T>& data, const Join& join = Join(),
                const NodeUpdate& node_update = NodeUpdate())
      : join_(join),
        node_update_(node_update),
        n_((int)data.size()),
        has_lazy_(bit_ceil((unsigned)n_), false),
        lazy_(has_lazy_.size()),
        data_(2 * lazy_.size()) {
    init(1, 0, n_ - 1, data);
  }

  int size() const { return n_; }

  void update(int pos, const T& val) { return update(pos, pos, val); }

  // Updates the closed range [first, last] with val.
  void update(int first, int last, const T& val) {
    assert(first <= last);
    return update(1, 0, n_ - 1, first, last, val);
  }

  T get(int pos) { return get(pos, pos); }

  // Queries the closed range [first, last].
  T get(int first, int last) {
    assert(first <= last);
    return get(1, 0, n_ - 1, first, last);
  }

  template <typename Contains>
  int find(T val, Contains contains) {
    if (!contains(data_[1], val)) {
      return n_;
    }
    int node = 1, low = 0, high = n_ - 1;
    while (low < high) {
      push(node, low, high);
      int mid = (low + high) >> 1;
      if (contains(data_[node], val)) {
        node = 2 * node;
        high = mid;
      } else {
        node = 2 * node + 1;
        low = mid + 1;
      }
    }
    return low;
  }

  friend std::ostream& operator<<(std::ostream& os, lazy_seg_tree tree) {
    os << '{';
    for (int i = 0; i < tree.size(); ++i) {
      if (i != 0) {
        os << ", ";
      }
      os << tree.get(i);
    }
    return os << '}';
  }

 private:
  Join join_;
  NodeUpdate node_update_;
  int n_;
  std::vector<bool> has_lazy_;
  std::vector<T> lazy_;
  std::vector<T> data_;

  void init(int node, int low, int high) {
    if (low == high) {
      return;
    }
    int mid = (low + high) >> 1;
    init(2 * node, low, mid);
    init(2 * node + 1, mid + 1, high);
    data_[node] = join_(data_[2 * node], data_[2 * node + 1]);
  }

  void init(int node, int low, int high, const std::vector<T>& data) {
    if (low == high) {
      data_[node] = data[low];
      return;
    }
    int mid = (low + high) >> 1;
    init(2 * node, low, mid, data);
    init(2 * node + 1, mid + 1, high, data);
    data_[node] = join_(data_[2 * node], data_[2 * node + 1]);
  }

  void update_node(int node, int low, int high, const T& val) {
    node_update_(data_[node], high - low + 1, val);
    if (low == high) {
      return;
    }
    if (has_lazy_[node]) {
      node_update_(lazy_[node], 1, val);
    } else {
      has_lazy_[node] = true;
      lazy_[node] = val;
    }
  }

  void push(int node, int low, int high) {
    if (!has_lazy_[node]) {
      return;
    }
    int mid = (low + high) >> 1;
    update_node(2 * node, low, mid, lazy_[node]);
    update_node(2 * node + 1, mid + 1, high, lazy_[node]);
    has_lazy_[node] = false;
  }

  void update(int node, int low, int high, int first, int last, const T& val) {
    if (first <= low && high <= last) {
      update_node(node, low, high, val);
      return;
    }
    push(node, low, high);
    int mid = (low + high) >> 1;
    if (first <= mid) {
      update(2 * node, low, mid, first, last, val);
    }
    if (mid < last) {
      update(2 * node + 1, mid + 1, high, first, last, val);
    }
    data_[node] = join_(data_[2 * node], data_[2 * node + 1]);
  }

  T get(int node, int low, int high, int first, int last) {
    if (first <= low && high <= last) {
      return data_[node];
    }
    push(node, low, high);
    int mid = (low + high) >> 1;
    if (last <= mid) {
      return get(2 * node, low, mid, first, last);
    }
    if (mid < first) {
      return get(2 * node + 1, mid + 1, high, first, last);
    }
    return join_(get(2 * node, low, mid, first, last),
                 get(2 * node + 1, mid + 1, high, first, last));
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.precision(12);
  std::cerr.precision(12);
  std::mt19937 rng((std::uint_fast32_t)std::chrono::high_resolution_clock::now()
                       .time_since_epoch()
                       .count());
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> la(n);
  for (int i = 0; i < m; ++i) {
    int l, r, a;
    cin >> l >> r >> a;
    --l, --r;
    la[r].emplace_back(l, a);
  }
  auto join = [](long long a, long long b) { return max(a, b); };
  auto update = [](long long& a, int, long long val) { a += val; };
  lazy_seg_tree<long long, decltype(join), decltype(update)> tree(n + 1, 0,
                                                                  join, update);
  for (int r = 0; r < n; ++r) {
    tree.update(r + 1, tree.get(0, r));
    for (auto& p : la[r]) {
      int l = p.first, a = p.second;
      tree.update(l + 1, r + 1, a);
    }
  }
  cout << tree.get(0, n) << '\n';
  return 0;
}