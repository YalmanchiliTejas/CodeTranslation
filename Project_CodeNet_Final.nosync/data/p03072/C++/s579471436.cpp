// This is free and unencumbered software released into the public domain.

// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.

// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all present and future rights to this
// software under copyright law.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

// For more information, please refer to <http://unlicense.org>

/****************/
/* template.hpp */
/****************/

#include <algorithm>
#include <cassert>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>

using std::cerr;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::swap;

struct BoolName : std::numpunct<char> {
  std::string t, f;
  BoolName(std::string t, std::string f) : t(t), f(f) {}
  std::string do_truename() const { return t; }
  std::string do_falsename() const { return f; }
};

void setBoolName(std::string t, std::string f) {
  cout.imbue(std::locale(cout.getloc(), new BoolName(t, f)));
}

struct Initializer {
  Initializer() {
    cout << std::fixed << std::setprecision(15) << std::boolalpha;
    setBoolName("Yes", "No");
  }
} initializer;

struct Input {
  bool eof;

  Input() : eof(false) {}

  operator char() {
    char v;
    this->eof = (std::scanf("%c", &v) != 1);
    return v;
  }

  operator int() {
    int v;
    this->eof = (std::scanf("%d", &v) != 1);
    return v;
  }

  operator long() {
    long v;
    this->eof = (std::scanf("%ld", &v) != 1);
    return v;
  }

  operator long long() {
    long long v;
    this->eof = (std::scanf("%lld", &v) != 1);
    return v;
  }

  operator unsigned int() {
    unsigned int v;
    this->eof = (std::scanf("%u", &v) != 1);
    return v;
  }

  operator unsigned long() {
    unsigned long v;
    this->eof = (std::scanf("%lu", &v) != 1);
    return v;
  }

  operator unsigned long long() {
    unsigned long long v;
    this->eof = (std::scanf("%llu", &v) != 1);
    return v;
  }

  operator double() {
    double v;
    this->eof = (std::scanf("%lf", &v) != 1);
    return v;
  }

  operator long double() {
    long double v;
    this->eof = (std::scanf("%Lf", &v) != 1);
    return v;
  }

  void ignore() const { getchar(); }
} in;

template <typename T> T abs(T a) { return a >= 0 ? a : -a; }

template <typename T> bool chmin(T &a, T b) {
  return a > b ? a = b, true : false;
}

template <typename T> bool chmax(T &a, T b) {
  return a < b ? a = b, true : false;
}

template <typename T, typename S> std::function<S(T)> cast() {
  return [](const T &t) { return static_cast<S>(t); };
}

class ZeroPadding {
public:
  ZeroPadding(int n) : n(n) {}

  int n;
};

std::ostream &operator<<(std::ostream &os, const ZeroPadding &z) {
  os << std::setw(z.n) << std::setfill('0');
  return os;
}

template <typename T> constexpr T inf() {
  return std::numeric_limits<T>::max() / 2 - 1;
}

/*************/
/* tuple.hpp */
/*************/

#include <tuple>

template <typename... T> class Tuple : public std::tuple<T...> {
public:
  Tuple(Input &in) : std::tuple<T...>() { (void)in; }
};

template <typename T, typename... S>
class Tuple<T, S...> : public std::tuple<T, S...> {
public:
  Tuple() : std::tuple<T, S...>() {}

  Tuple(T t, S... s) : std::tuple<T, S...>(t, s...) {}

  Tuple(const std::tuple<T, S...> &t) : std::tuple<T, S...>(t) {}

  Tuple(Input &in) {
    auto a = std::tuple<T>(in);
    std::tuple<S...> b = Tuple<S...>(in);
    std::tuple<T, S...> c = std::tuple_cat(a, b);
    *this = c;
  }

  template <int n> auto &get() { return std::get<n>(*this); }

  template <int n> const auto &get() const { return std::get<n>(*this); }
};

template <typename... T> Tuple<T...> makeTuple(const T &... args) {
  return Tuple<T...>(args...);
}

namespace std {
template <typename... T>
class tuple_size<Tuple<T...>>
    : public std::integral_constant<size_t, sizeof...(T)> {};
template <std::size_t I, typename... T> class tuple_element<I, Tuple<T...>> {
public:
  using type = tuple_element_t<I, std::tuple<T...>>;
};
} // namespace std

/*****************/
/* container.hpp */
/*****************/

#include <vector>

template <typename T> class Container : public T {
private:
  using S = typename T::value_type;
  using Itr = typename T::iterator;

public:
  Container() : T() {}

  Container(int n) : T(n) {}

  Container(int n, S s) : T(n, s) {}

  template <typename Itr> Container(Itr first, Itr last) : T(first, last) {}

  Container(const std::initializer_list<S> &v) : T(v) {}

  Container(int n, Input &in) {
    std::vector<S> v(n);
    for (auto &i : v) {
      i = in;
    }
    *this = Container<T>(v.begin(), v.end());
  }

  S max() const { return *max_element(this->begin(), this->end()); }

  template <typename Function> auto max(Function func) const {
    std::vector<std::pair<decltype(func(S())), S>> res;
    for (const auto &i : *this) {
      res.emplace_back(func(i), i);
    }
    return max_element(res.begin(), res.end())->second;
  }

  S min() const { return *min_element(this->begin(), this->end()); }

  Tuple<S, S> minmax() const {
    auto itrs = minmax_element(this->begin(), this->end());
    return Tuple<S, S>(*itrs.first, *itrs.second);
  }

  template <typename Function> auto min(Function func) const {
    std::vector<std::pair<decltype(func(S())), S>> res;
    for (const auto &i : *this) {
      res.emplace_back(func(i), i);
    }
    return min_element(res.begin(), res.end())->second;
  }

  int argmax() const {
    return max_element(this->begin(), this->end()) - this->begin();
  }

  int argmin() const {
    return min_element(this->begin(), this->end()) - this->begin();
  }

  bool contains(const S &a) const {
    return find(this->begin(), this->end(), a) != this->end();
  }

  int size() const { return T::size(); }

  std::pair<Itr, Itr> equal_range(const S &a) {
    return std::equal_range(this->begin(), this->end(), a);
  }

  template <typename Function> bool all_of(Function func) const {
    return std::all_of(this->begin(), this->end(), func);
  }

  template <typename Function> bool any_of(Function func) const {
    return std::any_of(this->begin(), this->end(), func);
  }

  template <typename Function> bool none_of(Function func) const {
    return std::none_of(this->begin(), this->end(), func);
  }

  int count(const S &s) const {
    return std::count(this->begin(), this->end(), s);
  }
};

/***********/
/* map.hpp */
/***********/

#include <map>

template <typename T, typename S> class Map : public Container<std::map<T, S>> {
public:
  Map() : Container<std::map<T, S>>() {}

  bool contains(const T &a) const { return this->find(a) != this->end(); }

  int count(const T &t) const { return this->count(t); }
};

/***************/
/* ordered.hpp */
/***************/

template <typename T> class Ordered {
public:
  template <typename V> bool operator==(const V &v) const {
    return !(static_cast<T>(v) < static_cast<const T &>(*this) ||
             static_cast<const T &>(*this) < static_cast<T>(v));
  }

  template <typename V> bool operator!=(const V &v) const {
    return static_cast<T>(v) < static_cast<const T &>(*this) ||
           static_cast<const T &>(*this) < static_cast<T>(v);
  }

  template <typename V> bool operator>(const V &v) const {
    return static_cast<T>(v) < static_cast<const T &>(*this);
  }

  template <typename V> bool operator<=(const V &v) const {
    return !(static_cast<T>(v) < static_cast<const T &>(*this));
  }

  template <typename V> bool operator>=(const V &v) const {
    return !(static_cast<const T &>(*this) < static_cast<T>(v));
  }
};

/**************/
/* vector.hpp */
/**************/

#include <numeric>

template <typename T>
class Vector : public Container<std::vector<T>>, public Ordered<Vector<T>> {
public:
  Vector() = default;

  Vector(const Vector<T> &v) = default;

  Vector(int n) : Container<std::vector<T>>(n) {}

  Vector(int n, T t) : Container<std::vector<T>>(n, t) {}

  template <typename Itr>
  Vector(Itr first, Itr last) : Container<std::vector<T>>(first, last) {}

  Vector(const std::initializer_list<T> &v) : Container<std::vector<T>>(v) {}

  Vector(int n, Input &in) : Container<std::vector<T>>(n, in) {}

  Vector operator+=(const Vector &v) {
    if (this->size() < v.size()) {
      this->resize(v.size());
    }
    for (int i = 0; i < v.size(); ++i) {
      (*this)[i] += v[i];
    }
    return *this;
  }

  Vector operator+=(const T &v) {
    for (auto &i : *this) {
      i += v;
    }
    return *this;
  }

  Vector operator-=(const Vector &v) {
    if (this->size() < v.size()) {
      this->resize(v.size());
    }
    for (int i = 0; i < v.size(); ++i) {
      (*this)[i] -= v[i];
    }
    return *this;
  }

  Vector operator-=(const T &v) {
    for (auto &i : *this) {
      i -= v;
    }
    return *this;
  }

  Vector operator*=(const Vector &v) {
    for (int i = 0; i < this->size(); ++i) {
      (*this)[i] *= v[i];
    }
    return *this;
  }

  Vector operator*=(const T &v) {
    for (auto &i : *this) {
      i *= v;
    }
    return *this;
  }

  Vector operator/=(const Vector &v) {
    for (int i = 0; i < this->size(); ++i) {
      (*this)[i] /= v[i];
    }
    return *this;
  }

  Vector operator/=(const T &v) {
    for (auto &i : *this) {
      i /= v;
    }
    return *this;
  }

  Vector operator%=(const Vector &v) {
    for (int i = 0; i < this->size(); ++i) {
      (*this)[i] %= v[i];
    }
    return *this;
  }

  Vector operator%=(const T &v) {
    for (auto &i : *this) {
      i %= v;
    }
    return *this;
  }

  Vector operator+(const Vector &v) const { return Vector(*this) += v; }

  Vector operator+(const T &v) const { return Vector(*this) += v; }

  Vector operator-(const Vector &v) const { return Vector(*this) -= v; }

  Vector operator-(const T &v) const { return Vector(*this) -= v; }

  Vector operator*(const Vector &v) const { return Vector(*this) *= v; }

  Vector operator*(const T &v) const { return Vector(*this) *= v; }

  Vector operator/(const Vector &v) const { return Vector(*this) /= v; }

  Vector operator/(const T &v) const { return Vector(*this) /= v; }

  Vector operator%(const Vector &v) const { return Vector(*this) %= v; }

  Vector operator%(const T &v) const { return Vector(*this) %= v; }

  bool operator<(const Vector &v) const {
    if (this->size() != v.size()) {
      return this->size() < v.size();
    }
    for (int i = 0; i < this->size(); ++i) {
      if ((*this)[i] != v[i]) {
        return (*this)[i] < v[i];
      }
    }
    return false;
  }

  Vector operator-() const { return *this * -1; }

  T inner_product(const Vector<T> &v) const {
    return std::inner_product(this->begin(), this->end(), v.begin(), T(0));
  }

  void output(std::string sep = "\n", std::string end = "\n") const {
    if (!this->empty()) {
      cout << (*this)[0];
    }
    for (int i = 1; i < this->size(); ++i) {
      cout << sep << (*this)[i];
    }
    cout << end;
  }

  Vector<T> partial_sort(int k, bool reverse = false) {
    if (!reverse) {
      std::partial_sort(this->begin(), this->begin() + k, this->end());
    } else {
      std::partial_sort(this->begin(), this->begin() + k, this->end(),
                        std::greater<T>());
    }
    return *this;
  }

  Vector<T> sort() {
    std::sort(this->begin(), this->end());
    return *this;
  }

  template <typename Function> Vector<T> sort(Function func) {
    std::sort(this->begin(), this->end(), func);
    return *this;
  }

  Vector<T> rsort() {
    std::sort(this->rbegin(), this->rend());
    return *this;
  }

  Vector<int> argsort() const {
    Vector<Tuple<T, int>> v;
    for (int i = 0; i < this->size(); ++i) {
      v.emplace_back((*this)[i], i);
    }
    v.sort();
    auto f = [](const Tuple<T, int> &t) { return t.template get<1>(); };
    return v.transform(f);
  }

  Vector<T> nth_element(int n, bool reverse = false) {
    if (!reverse) {
      std::nth_element(this->begin(), this->begin() + n, this->end());
    } else {
      std::nth_element(this->begin(), this->begin() + n, this->end(),
                       std::greater<T>());
    }
    return *this;
  }

  Vector<T> subvector(int a) const {
    return Vector<T>(this->begin(), this->begin() + a);
  }

  Vector<T> subvector(int a, int b) const {
    return Vector<T>(this->begin() + a, this->begin() + b);
  }

  template <typename Function> auto transform(Function func) const {
    Vector<decltype(func(T()))> res;
    std::transform(this->begin(), this->end(), std::back_inserter(res), func);
    return res;
  }

  Vector<T> partial_sum() const {
    Vector<T> res;
    std::partial_sum(this->begin(), this->end(), std::back_inserter(res));
    return res;
  }

  template <typename Function> Vector<T> partial_sum(Function func) const {
    Vector<T> res;
    std::partial_sum(this->begin(), this->end(), std::back_inserter(res), func);
    return res;
  }

  Vector<T> reverse() {
    std::reverse(this->begin(), this->end());
    return *this;
  }

  template <typename Function> int count_if(Function func) const {
    return std::count_if(this->begin(), this->end(), func);
  }

  Vector<T> adjacent_difference() const {
    Vector<T> res;
    std::adjacent_difference(this->begin(), this->end(),
                             std::back_inserter(res));
    return res;
  }

  T lower_bound(T t) const {
    return std::lower_bound(this->begin(), this->end(), t) - this->begin();
  }

  T upper_bound(T t) const {
    return std::upper_bound(this->begin(), this->end(), t) - this->begin();
  }

  T accumulate() const {
    return std::accumulate(this->begin(), this->end(), T(0));
  }

  template <typename S, typename Function>
  S accumulate(S n, Function func) const {
    return std::accumulate(this->begin(), this->end(), n, func);
  }

  template <typename Int> static Vector<T> makeVector(Int n) {
    return Vector<T>(n);
  }

  template <typename Int> static Vector<T> makeVector(Input &in, Int n) {
    return Vector<T>(n, in);
  }

  template <typename Int, typename... Ints>
  static auto makeVector(Input &in, Int n, Ints... ints) {
    Vector<decltype(makeVector(in, ints...))> res;
    for (int i = 0; i < n; ++i) {
      res.emplace_back(makeVector(in, ints...));
    }
    return res;
  }

  template <typename Int, typename... Ints>
  static auto makeVector(Int n, Ints... ints) {
    Vector<decltype(makeVector(ints...))> res;
    for (int i = 0; i < n; ++i) {
      res.emplace_back(makeVector(ints...));
    }
    return res;
  }

  Vector<T> unique() {
    this->erase(std::unique(this->begin(), this->end()), this->end());
    return *this;
  }

  bool next_permutation() {
    return std::next_permutation(this->begin(), this->end());
  }

  Vector<T> rotate(int n) {
    std::rotate(this->begin(), this->begin() + n, this->end());
    return *this;
  }

  Map<T, int> countAll() const {
    Map<T, int> res;
    for (const auto &i : *this) {
      ++res[i];
    }
    return res;
  }

  T matmul(const T &a) const {
    return this->transform([&](const T &i) { return i.inner_product(a); });
  }
};

template <typename T> Vector<T> iota(int n, T m = 0) {
  Vector<T> v(n);
  std::iota(v.begin(), v.end(), m);
  return v;
}

template <typename T, typename S> void read(Vector<T> &t, Vector<S> &s) {
  for (int i = 0; i < t.size(); ++i) {
    t[i] = T(in);
    s[i] = S(in);
  }
}

template <typename T, typename S, typename U>
void read(Vector<T> &t, Vector<S> &s, Vector<U> &u) {
  for (int i = 0; i < t.size(); ++i) {
    t[i] = T(in);
    s[i] = S(in);
    u[i] = U(in);
  }
}

template <typename T> Vector<T> operator+(const T &a, const Vector<T> &b) {
  return b + a;
}

template <typename T> Vector<T> operator-(const T &a, const Vector<T> &b) {
  return -b + a;
}

template <typename T> Vector<T> operator*(const T &a, const Vector<T> &b) {
  return b * a;
}

/************/
/* main.cpp */
/************/

int main() {
  int n(in);
  Vector<int> h(n, in);
  cout << (h.partial_sum([](int a, int b) { return max(a, b); }) - h).count(0)
       << endl;
}
