
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>

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

template <uint32_t Modulus>
class modular {
public:
  using value_type = uint32_t;
  using max_type = uint64_t;

  static constexpr value_type mod = Modulus;
  static constexpr value_type mod_min = 1;
  static constexpr value_type mod_max = 2147483647;
  static_assert(mod >= mod_min, "invalid mod :: too small");
  static_assert(mod <= mod_max, "invalid mod :: too big");

  template <class T>
  static constexpr value_type normalize(T value_) {
    if (value_ < 0) {
      value_ = -value_;
      value_ %= mod;
      if (value_ == 0) return 0;
      return mod - value_;
    }
    return value_ % mod;
  }

private:
  value_type value;

public:
  constexpr modular(): value(0) { }
  template <class T>
  explicit constexpr modular(T value_): value(normalize(value_)) { }
  template <class T>
  explicit constexpr operator T() { return static_cast<T>(value); }

  constexpr value_type operator () () const { return value; }
  constexpr modular operator - () const { return modular(mod - value); }
  constexpr modular operator ~ () const { return inverse(); }

  constexpr value_type &extract() { return value; }
  constexpr modular inverse() const { return power(mod - 2); }
  constexpr modular power(max_type exp) const {
    modular res(1), mult(*this);
    while (exp > 0) {
      if (exp & 1) res *= mult;
      mult *= mult;
      exp >>= 1;
    }
    return res;
  }

  constexpr modular operator + (const modular &rhs) const { return modular(*this) += rhs; }
  constexpr modular& operator += (const modular &rhs) { 
    if ((value += rhs.value) >= mod) value -= mod; 
    return *this; 
  }

  constexpr modular operator - (const modular &rhs) const { return modular(*this) -= rhs; }
  constexpr modular& operator -= (const modular &rhs) { 
    if ((value += mod - rhs.value) >= mod) value -= mod; 
    return *this; 
  }

  constexpr modular operator * (const modular &rhs) const { return modular(*this) *= rhs; }
  constexpr modular& operator *= (const modular &rhs) { 
    value = (max_type) value * rhs.value % mod;
    return *this;
  }

  constexpr modular operator / (const modular &rhs) const { return modular(*this) /= rhs; }
  constexpr modular& operator /= (const modular &rhs) { return (*this) *= rhs.inverse(); }

  constexpr bool zero() const { return value == 0; }
  constexpr bool operator == (const modular &rhs) const { return value == rhs.value; }
  constexpr bool operator != (const modular &rhs) const { return value != rhs.value; }
  friend std::ostream& operator << (std::ostream &stream, const modular &rhs) {
    return stream << rhs.value;
  }

};

template <class T>
struct fix_point: private T {
  explicit constexpr fix_point(T &&func): T(std::forward<T>(func)) { }
  template <class... Args>
  constexpr decltype(auto) operator () (Args &&... args) const {
    return T::operator()(*this, std::forward<Args>(args)...);
  }
};

template <class T>
constexpr decltype(auto) make_fix_point(T &&func) {
  return fix_point<T>{std::forward<T>(func)};
}

using modint = modular<1000000007>;

int main() {
  int N;
  std::cin >> N;
  std::vector<int> H(N);
  for (int &x: H) {
    std::cin >> x;
  }
  auto ans = make_fix_point([&](auto dfs, int l, int r, int d) -> std::pair<modint, modint> {
    int min_height = *std::min_element(H.cbegin() + l, H.cbegin() + r);
    int height = min_height - d;
    int free = r - l;
    std::vector<std::pair<modint, modint>> up;
    {
      int right = r;
      while (right > l && H[right - 1] == min_height) {
        --right;
      }
      int left = l;
      for (int i: range(l, right)) {
        if (H[i] == min_height) {
          if (left < i) {
            up.emplace_back(dfs(left, i, min_height));
            free -= i - left;
          }
          left = i + 1;
        }
      }
      if (left < right) {
        up.emplace_back(dfs(left, right, min_height));
        free -= right - left;
      }
    }
    if (up.empty()) {
      return { modint(2).power(height), modint(2).power(r - l) - modint(2) };
    }
    modint alternate(1);
    for (auto p: up) {
      alternate *= p.first;
    }
    modint continuous = modint(2).power(free);
    for (auto p: up) {
      continuous *= p.first * modint(2) + p.second;
    }
    modint remove;

    return { modint(2).power(height) * alternate, continuous - modint(2) * alternate };
  })(0, N, 0);
  std::cout << ans.first + ans.second << '\n';
  return 0;
}
