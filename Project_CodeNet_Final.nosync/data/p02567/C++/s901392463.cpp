#line 1 "main.cpp"

/**
 * @title Template
 */

#include <iostream>
#include <algorithm>
#include <utility>
#include <numeric>
#include <vector>
#include <array>
#include <cassert>

#line 2 "/Users/kodamankod/Desktop/cpp_programming/Library/other/chmin_chmax.cpp"

template <class T, class U>
constexpr bool chmin(T &lhs, const U &rhs) {
  if (lhs > rhs) { lhs = rhs; return true; }
  return false;
}

template <class T, class U>
constexpr bool chmax(T &lhs, const U &rhs) {
  if (lhs < rhs) { lhs = rhs; return true; }
  return false;
}

/**
 * @title Chmin/Chmax
 */
#line 2 "/Users/kodamankod/Desktop/cpp_programming/Library/other/range.cpp"

#line 4 "/Users/kodamankod/Desktop/cpp_programming/Library/other/range.cpp"

class range {
public:
  class iterator {
  private:
    int64_t M_position;

  public:
    constexpr iterator(int64_t position) noexcept: M_position(position) { }
    constexpr void operator ++ () noexcept { ++M_position; }
    constexpr bool operator != (iterator other) const noexcept { return M_position != other.M_position; }
    constexpr int64_t operator * () const noexcept { return M_position; }

  };

  class reverse_iterator {
  private:
    int64_t M_position;
  
  public:
    constexpr reverse_iterator(int64_t position) noexcept: M_position(position) { }
    constexpr void operator ++ () noexcept { --M_position; }
    constexpr bool operator != (reverse_iterator other) const noexcept { return M_position != other.M_position; }
    constexpr int64_t operator * () const noexcept { return M_position; }

  };
  
private:
  const iterator M_first, M_last;

public:
  constexpr range(int64_t first, int64_t last) noexcept: M_first(first), M_last(std::max(first, last)) { }
  constexpr iterator begin() const noexcept { return M_first; }
  constexpr iterator end() const noexcept { return M_last; }
  constexpr reverse_iterator rbegin() const noexcept { return reverse_iterator(*M_last - 1); } 
  constexpr reverse_iterator rend() const noexcept { return reverse_iterator(*M_first - 1); } 

};

/**
 * @title Range
 */
#line 2 "/Users/kodamankod/Desktop/cpp_programming/Library/other/rev.cpp"

#include <type_traits>
#include <iterator>
#line 6 "/Users/kodamankod/Desktop/cpp_programming/Library/other/rev.cpp"

template <class T>
class rev_impl {
public:
  using iterator = decltype(std::rbegin(std::declval<T>()));

private:
  const iterator M_begin;
  const iterator M_end;

public:
  constexpr rev_impl(T &&cont) noexcept: M_begin(std::rbegin(cont)), M_end(std::rend(cont)) { }
  constexpr iterator begin() const noexcept { return M_begin; }
  constexpr iterator end() const noexcept { return M_end; }

};

template <class T>
constexpr decltype(auto) rev(T &&cont) {
  return rev_impl<T>(std::forward<T>(cont));
}

/**
 * @title Reverser
 */
#line 2 "/Users/kodamankod/Desktop/cpp_programming/Library/container/segment_tree.cpp"

#line 2 "/Users/kodamankod/Desktop/cpp_programming/Library/other/monoid.cpp"

#include <type_traits>
#line 5 "/Users/kodamankod/Desktop/cpp_programming/Library/other/monoid.cpp"
#include <stdexcept>

template <class T, class = void>
class has_identity: public std::false_type { };

template <class T>
class has_identity<T, typename std::conditional<false, decltype(T::identity()), void>::type>: public std::true_type { };

template <class T>
constexpr typename std::enable_if<has_identity<T>::value, typename T::type>::type empty_exception() {
  return T::identity();
}
template <class T>
[[noreturn]] typename std::enable_if<!has_identity<T>::value, typename T::type>::type empty_exception() {
  throw std::runtime_error("type T has no identity");
}

template <class T, bool HasIdentity>
class fixed_monoid_impl: public T {
public:
  using type = typename T::type;

  static constexpr type convert(const type &value) { return value; }
  static constexpr type revert(const type &value) { return value; }

  template <class Mapping, class Value, class... Args>
  static constexpr void operate(Mapping &&func, Value &value, const type &op, Args&&... args) {
    value = func(value, op, std::forward<Args>(args)...);
  }
  template <class Constraint>
  static constexpr bool satisfies(Constraint &&func, const type &value) {
    return func(value);
  }
};

template <class T>
class fixed_monoid_impl<T, false>: private T {
public:
  class type {
  public:
    typename T::type value;
    bool state;
  
    explicit constexpr type(): value(typename T::type { }), state(false) { }
    explicit constexpr type(const typename T::type &value): value(value), state(true) { }
  };

  static constexpr type convert(const typename T::type &value) { return type(value); }
  static constexpr typename T::type revert(const type &value) { 
    if (!value.state) throw std::runtime_error("attempted to revert identity to non-monoid"); 
    return value.value; 
  }

  static constexpr type identity() { return type(); }
  static constexpr type operation(const type &v1, const type &v2) {
    if (!v1.state) return v2;
    if (!v2.state) return v1;
    return type(T::operation(v1.value, v2.value));
  }

  template <class Mapping, class Value, class... Args>
  static constexpr void operate(Mapping &&func, Value &value, const type &op, Args&&... args) {
    if (!op.state) return;
    value = func(value, op.value, std::forward<Args>(args)...);
  }
  template <class Constraint>
  static constexpr bool satisfies(Constraint &&func, const type &value) {
    if (!value.state) return false;
    return func(value.value);
  }
};

template <class T>
using fixed_monoid = fixed_monoid_impl<T, has_identity<T>::value>;

/**
 * @title Monoid Utility
 */
#line 4 "/Users/kodamankod/Desktop/cpp_programming/Library/container/segment_tree.cpp"

#include <cstddef>
#line 10 "/Users/kodamankod/Desktop/cpp_programming/Library/container/segment_tree.cpp"
#include <type_traits>
#line 12 "/Users/kodamankod/Desktop/cpp_programming/Library/container/segment_tree.cpp"

template <class Monoid>
class segment_tree {
public:
  using structure    = Monoid;
  using value_monoid = typename Monoid::value_structure;
  using value_type   = typename Monoid::value_structure::type;
  using size_type    = size_t;

private:
  using fixed_value_monoid = fixed_monoid<value_monoid>;
  using fixed_value_type   = typename fixed_value_monoid::type;

  std::vector<fixed_value_type> M_tree;

  void M_fix_change(const size_type index) {
    M_tree[index] = fixed_value_monoid::operation(M_tree[index << 1 | 0], M_tree[index << 1 | 1]);
  }

public:
  segment_tree() = default;
  explicit segment_tree(const size_type size) { initialize(size); }
  template <class InputIterator>
  explicit segment_tree(InputIterator first, InputIterator last) { construct(first, last); }

  void initialize(const size_type size) {
    clear();
    M_tree.assign(size << 1, fixed_value_monoid::identity());
  }

  template <class InputIterator>
  void construct(InputIterator first, InputIterator last) {
    clear();
    const size_type size = std::distance(first, last);
    M_tree.reserve(size << 1);
    M_tree.assign(size, fixed_value_monoid::identity());
    std::transform(first, last, std::back_inserter(M_tree), [&](const value_type &value) {
      return fixed_value_monoid::convert(value);
    });
    for (size_type index = size - 1; index != 0; --index) {
      M_fix_change(index);
    }
  }

  void assign(size_type index, const value_type &value) {
    assert(index < size());
    index += size();
    M_tree[index] = fixed_value_monoid::convert(value);
    while (index != 1) {
      index >>= 1;
      M_fix_change(index);
    } 
  }

  value_type at(const size_type index) const { 
    assert(index < size());
    return fixed_value_monoid::revert(M_tree[index + size()]);
  }

  value_type fold(size_type first, size_type last) const {
    assert(first <= last);
    assert(last <= size());
    first += size();
    last += size();
    fixed_value_type fold_l = fixed_value_monoid::identity();
    fixed_value_type fold_r = fixed_value_monoid::identity();
    while (first != last) {
      if (first & 1) {
        fold_l = fixed_value_monoid::operation(fold_l, M_tree[first]);
        ++first;
      }
      if (last & 1) {
        --last;
        fold_r = fixed_value_monoid::operation(M_tree[last], fold_r);      
      }
      first >>= 1;
      last >>= 1;
    }
    return fixed_value_monoid::revert(fixed_value_monoid::operation(fold_l, fold_r));
  }

  template <bool ToRight = true, class Constraint, std::enable_if_t<ToRight>* = nullptr> 
  size_type satisfies(const size_type left, Constraint &&func) const {
    assert(left <= size());
    if (fixed_value_monoid::satisfies(std::forward<Constraint>(func), 
      fixed_value_monoid::identity())) return left;
    size_type first = left + size();
    size_type last = 2 * size();
    const size_type last_c = last;
    fixed_value_type fold = fixed_value_monoid::identity();
    const auto try_merge = [&](const size_type index) {
      fixed_value_type tmp = fixed_value_monoid::operation(fold, M_tree[index]);
      if (fixed_value_monoid::satisfies(std::forward<Constraint>(func), tmp)) return true;
      fold = std::move(tmp);
      return false;
    };
    const auto subtree = [&](size_type index) {
      while (index < size()) {
        index <<= 1;
        if (!try_merge(index)) ++index;
      }
      return index - size() + 1;
    };
    size_type story = 0;
    while (first < last) {
      if (first & 1) {
        if (try_merge(first)) return subtree(first);
        ++first;
      }
      first >>= 1;
      last >>= 1;
      ++story;
    }
    while (story--) {
      last = last_c >> story;
      if (last & 1) {
        --last;
        if (try_merge(last)) return subtree(last);
      }
    }
    return size() + 1;
  }

  template <bool ToRight = true, class Constraint, std::enable_if_t<!ToRight>* = nullptr> 
  size_type satisfies(const size_type right, Constraint &&func) const {
    assert(right <= size());
    if (fixed_value_monoid::satisfies(std::forward<Constraint>(func), 
      fixed_value_monoid::identity())) return right;
    size_type first = size();
    size_type last = right + size();
    const size_type first_c = last;
    fixed_value_type fold = fixed_value_monoid::identity();
    const auto try_merge = [&](const size_type index) {
      fixed_value_type tmp = fixed_value_monoid::operation(M_tree[index], fold);
      if (fixed_value_monoid::satisfies(std::forward<Constraint>(func), tmp)) return true;
      fold = std::move(tmp);
      return false;
    };
    const auto subtree = [&](size_type index) {
      while (index < size()) {
        index <<= 1;
        if (try_merge(index + 1)) ++index;
      }
      return index - size();
    };
    size_type story = 0;
    while (first < last) {
      if (last & 1) {
        --last;
        if (try_merge(last)) return subtree(last);
      }
      first >>= 1;
      last >>= 1;
      ++story;
    }
    while (story--) {
      first = first_c >> story;
      if (first & 1) {
        if (try_merge(first)) return subtree(first);
        ++first;
      }
    }
    return size_type(-1);
  }

  void clear() {
    M_tree.clear();
    M_tree.shrink_to_fit();
  }
  size_type size() const { 
    return M_tree.size() >> 1;
  }
};

/**
 * @title Segment Tree
 */
#line 18 "main.cpp"

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

constexpr i32 inf32 = (i32(1) << 30) - 1;
constexpr i64 inf64 = (i64(1) << 62) - 1;

struct st_monoid {
  struct value_structure {
    using type = i32;
    static type identity() { return -inf32; }
    static type operation(const type& v1, const type& v2) { 
      return std::max(v1, v2);
    }
  };
};

int main() {
  size_t N, Q;
  std::cin >> N >> Q;
  std::vector<i32> A(N);
  for (auto &x: A) {
    std::cin >> x;
  }
  segment_tree<st_monoid> seg(A.begin(), A.end());
  while (Q--) {
    size_t type;
    std::cin >> type;
    if (type == 1) {
      size_t x;
      i32 v;
      std::cin >> x >> v;
      seg.assign(x - 1, v);
    }
    else if (type == 2) {
      size_t l, r;
      std::cin >> l >> r;
      std::cout << seg.fold(l - 1, r) << '\n';
    }
    else {
      size_t x; 
      i32 v;
      std::cin >> x >> v;
      std::cout << seg.satisfies(x - 1, [&](i32 a) { return a >= v; }) << '\n';
    }
  }
  return 0;
}
