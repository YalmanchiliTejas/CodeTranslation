
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>
#include <tuple>
#include <limits>

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
class lazy_propagation_segment_tree {
public:
  using value_type = typename T::value_type;
  using effector_type = typename T::effector_type;
  using value_operation = typename T::value_operation;
  using effector_operation = typename T::effector_operation;
  using merge_operation = typename T::merge_operation;

private:
  int size, height;
  const value_operation op1;
  const effector_operation op2;
  const merge_operation op3;
  std::vector<value_type> node;
  std::vector<effector_type> lazy;

  value_type reflect(int i, int l) const {
    if (lazy[i] == op2.identity) {
      return node[i];
    }
    else {
      return op3(node[i], lazy[i], l);
    }
  }

  void apply(int i, int l) {
    if (lazy[i] == op2.identity) {
      return;
    }
    if (i < size) {
      lazy[i << 1 | 0] = op2(lazy[i << 1 | 0], lazy[i]);
      lazy[i << 1 | 1] = op2(lazy[i << 1 | 1], lazy[i]);
    }
    node[i] = op3(node[i], lazy[i], l);
    lazy[i] = op2.identity;
  }
  void update() {
    for (int i = size - 1; i > 0; --i) {
      node[i] = op1(node[i << 1 | 0], node[i << 1 | 1]);
    }
  }

  void flush(int i) {
    for (int k = height; k >= 0; --k) {
      apply(i >> k, 1 << k);
    }
  }
  void lift(int i) {
    i >>= 1;
    int l = 1;
    while (i > 0) {
      node[i] = op1(reflect(i << 1 | 0, l), reflect(i << 1 | 1, l));
      i >>= 1;
      l <<= 1;
    }
  }

public:
  lazy_propagation_segment_tree(): op1(value_operation()), op2(effector_operation()), op3(merge_operation()) { }
  lazy_propagation_segment_tree(int size_, const value_type &initial_ = value_operation().identity):
    op1(value_operation()), op2(effector_operation()), op3(merge_operation())
  { init(size_, initial_); }
  lazy_propagation_segment_tree(const std::vector<value_type> &node_):
    op1(value_operation()), op2(effector_operation()), op3(merge_operation())
  { build(node_); }

  void init(int size_, const value_type &initial_ = value_operation().identity) {
    size = 1; 
    height = 0;
    while (size < size_) {
      size <<= 1;
      ++height;
    }
    node.assign(size << 1, op1.identity);
    lazy.assign(size << 1, op2.identity);
    if (initial_ != value_operation().identity) {
      update();
    }
  }
  void build(const std::vector<value_type> &node_) {
    init(node_.size());
    for (int i = 0; i < node_.size(); ++i) {
      node[i + size] = node_[i];
    }
    update();
  }

  void assign(int i, const value_type &x) {
    i += size;
    flush(i);
    node[i] = x;
    lift(i);
  }

  void modify(int l, int r, const effector_type &x) {
    flush(l + size);
    flush(r + size - 1);
    int tl = l + size, tr = r + size, k = 1;
    while (tl < tr) {
      if (tl & 1) {
        lazy[tl] = op2(lazy[tl], x);
        apply(tl, k);
        ++tl;
      }
      if (tr & 1) {
        --tr;
        lazy[tr] = op2(lazy[tr], x);
        apply(tr, k);
      }
      tl >>= 1;
      tr >>= 1;
      k <<= 1;
    }
    lift(l + size);
    lift(r + size - 1);
  }

  value_type fold(int l, int r) {
    flush(l + size);
    flush(r + size - 1);
    int tl = l + size, tr = r + size, k = 1;
    value_type resl = op1.identity, resr = op1.identity;
    while (tl < tr) {
      if (tl & 1) {
        apply(tl, k);
        resl = op1(resl, node[tl]);
        ++tl;
      }
      if (tr & 1) {
        --tr;
        apply(tr, k);
        resr = op1(node[tr], resr);
      }
      tl >>= 1;
      tr >>= 1;
      k <<= 1;
    }
    return op1(resl, resr);
  }

};

template <class T>
struct range_max_range_add {
  using value_type = T;
  using effector_type = T;
  struct value_operation {
    value_type identity = std::numeric_limits<T>::min();
    value_type operator () (const value_type &x, const value_type &y) const {
      return x > y ? x : y;
    }
  };
  struct effector_operation {
    effector_type identity = 0;
    effector_type operator () (const effector_type &x, const effector_type &y) const {
      return x + y;
    }
  };
  struct merge_operation {
    value_type operator () (const value_type &x, const effector_type &y, int l = 1) const {
      return x + y;
    }
  };
};

int main() {
  int N, M;
  std::cin >> N >> M;
  std::vector<std::vector<std::pair<int, int>>> query(N);
  for (int i: range(0, M)) {
    int l, r, a;
    std::cin >> l >> r >> a;
    --l; --r;
    query[r].emplace_back(l, a);
  }
  lazy_propagation_segment_tree<range_max_range_add<long long>> seg(N + 1);
  seg.assign(0, 0);
  for (int i: range(0, N)) {
    seg.assign(i + 1, seg.fold(0, i + 1));
    for (auto p: query[i]) {
      seg.modify(p.first + 1, i + 2, p.second);
    }
  }
  std::cout << seg.fold(0, N + 1) << '\n';
  return 0;
}
