#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define all(x) x.begin(),x.end()


#include <type_traits>
#include <vector>
using i64 = long long;

template<class Iterator> class jter;
template<class Jter> class rev_jter;
template<class Jter, class F> class map_jter;

template<class Iterator>
class jter {

  Iterator b;
  Iterator e;

  public:

  using iterator = jter<Iterator>;
  using value_type = typename Iterator::value_type;
  using difference_type = std::ptrdiff_t;
  using pointer = value_type*;
  using reference = value_type&;
  using iterator_category = std::input_iterator_tag;

  jter() {}
  jter(Iterator b, Iterator e) : b(b), e(e) {}

  void next() { b++; }
  void prev() { --e; }
  value_type& front() { return *b; }
  value_type& back() { auto c = e; return *(--c); }
  bool isnone() const { return b == e; }

  jter begin() const { return *this; }
  jter end() const { return jter(); }
  jter& operator++() { next(); return *this; }
  value_type& operator*() { return front(); }
  bool operator!=(const jter& other) const { return !isnone(); }

  rev_jter<jter<Iterator>> rev() const { return rev_jter<jter<Iterator>>(*this); }
  template<class F>
    map_jter<jter<Iterator>, F> map(F f) const { return map_jter<jter<Iterator>, F>(*this, f); }
  std::vector<value_type> tovec() const { return std::vector<value_type>(this->begin(), this->end()); }

  template<class R, class F>
    R sum(R init, F f) const {
      for(const auto& x: *this) init = f(init, x);
      return init;
    }
};

template<class Jter>
class rev_jter {

  Jter j;

  public:

  using iterator = rev_jter<Jter>;
  using value_type = typename Jter::value_type;
  using difference_type = std::ptrdiff_t;
  using pointer = value_type*;
  using reference = value_type&;
  using iterator_category = std::input_iterator_tag;

  rev_jter() {}
  rev_jter(Jter j): j(j) {}

  void next() { j.prev(); }
  void prev() { j.next(); }
  value_type& front() { return j.back(); }
  value_type& back() { return j.front(); }
  bool isnone() const { return j.isnone(); }

  rev_jter begin() const { return *this; }
  rev_jter end() const { return rev_jter(); }
  rev_jter& operator++() { next(); return *this; }
  value_type& operator*() { return front(); }
  bool operator!=(const rev_jter& other) const { return !isnone(); }

  Jter rev() const { return j; }
  template<class F>
    map_jter<rev_jter, F> map(F f) const { return map_jter<rev_jter, F>(*this, f); }
  template<class R, class F>
    R sum(R init, F f) const {
      for(const auto& x: *this) init = f(init, x);
      return init;
    }
};

template<class Jter, class F>
class map_jter {

  Jter j;
  union _u {
    F f;
    bool isend;
    _u(): isend(true) {} 
    _u(F f): f(f) {}
  } u;

  public:

  using iterator = rev_jter<Jter>;
  using value_type = decltype(std::declval<F>()(std::declval<typename Jter::value_type>()));
  using difference_type = std::ptrdiff_t;
  using pointer = value_type*;
  using reference = value_type&;
  using iterator_category = std::input_iterator_tag;

  map_jter() {}
  map_jter(Jter j, F f): j(j), u(f) {}

  void next() { j.next(); }
  void prev() { j.prev(); }
  value_type front() { return u.f(j.front()); }
  value_type back() { return u.f(j.back()); }
  bool isnone() const { return j.isnone(); }

  map_jter begin() const { return *this; }
  map_jter end() const { return map_jter(); }
  map_jter& operator++() { next(); return *this; }
  value_type operator*() { return front(); }
  bool operator!=(const map_jter& other) const { return !isnone(); }

  Jter rev() const { return j; }
  template<class G>
    map_jter<map_jter, G> map(F f) const { return map_jter<map_jter, G>(*this, f); }
  std::vector<value_type> tovec() const { return std::vector<value_type>(this->begin(), this->end()); }
  template<class R, class G>
    R sum(R init, G g) const {
      for(const auto& x: *this) init = g(init, x);
      return init;
    }
};

class range {

  i64 b;
  i64 e;

  public:

  using iterator = range;
  using value_type = i64;
  using difference_type = std::ptrdiff_t;
  using pointer = value_type*;
  using reference = value_type&;
  using iterator_category = std::input_iterator_tag;

  range() {}
  range(i64 n) : b(0), e(n) {}
  range(i64 b, i64 e) : b(b), e(e) {}

  value_type next() { return b++; }
  value_type prev() { return --e; }
  value_type front() { return b; }
  value_type back() { return e - 1; }
  bool isnone() const { return b == e; }

  range begin() const { return *this; }
  range end() const { return range(); }
  range& operator++() { next(); return *this; }
  value_type operator*() { return front(); }
  bool operator!=(const range& other) const { return !isnone(); }

  rev_jter<range> rev() const { return rev_jter<range>(*this); }

  template<class F>
    map_jter<range, F> map(F f) const { return map_jter<range, F>(*this, f); }

  std::vector<value_type> tovec() const { return std::vector<value_type>(this->begin(), this->end()); }
  template<class R, class F>
    R sum(R init, F f) const {
      for(const auto& x: *this) init = f(init, x);
      return init; }
};

template<class Iterator>
jter<Iterator> jtr(Iterator b, Iterator e) { return jter<Iterator>(b, e); }

template<class V>
jter<typename V::iterator> jtr(V& v) { return jter<typename V::iterator>(begin(v), end(v)); }

template<class V>
jter<typename V::const_iterator> cjtr(const V& v) { return jter<typename V::const_iterator>(cbegin(v), cend(v)); }

template<class T, class Arg = i64>
T input(Arg dummy = Arg()) { T t; std::cin >> t; return t; }

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template<i64 M>
struct modint {
  i64 a;
  constexpr modint(const i64 x = 0) noexcept: a((x % M + M) % M) {}
  constexpr i64 value() const noexcept { return a; }
  constexpr modint pow(i64 r) const noexcept {
    modint ans(1);
    modint aa = *this;
    while(r) {
      if(r & 1) {
        ans *= aa;
      }
      aa *= aa;
      r >>= 1;
    }
    return ans;
  }
  constexpr modint& operator+=(const modint r) noexcept {
    a += r.a;
    if(a >= M) a -= M;
    return *this;
  }
  constexpr modint& operator=(const i64 r) {
    a = (r % M + M) % M;
    return *this;
  }
  constexpr modint& operator-=(const modint r) noexcept {
    a -= r.a;
    if(a < 0) a += M;
    return *this;
  }
  constexpr modint& operator*=(const modint r) noexcept {
    a = a * r.a % M;
    return *this;
  }
  constexpr modint& operator/=(modint r) noexcept {
    i64 ex = M - 2;
    while(ex) {
      if(ex & 1) {
        *this *= r;
      }
      r *= r;
      ex >>= 1;
    }
    return *this;
  }

  constexpr modint operator+(const modint r) const {
    return modint(*this) += r;
  }
  constexpr modint operator-(const modint r) const {
    return modint(*this) -= r;
  }
  constexpr modint operator*(const modint r) const {
    return modint(*this) *= r;
  }
  constexpr modint operator/(const modint r) const {
    return modint(*this) /= r;
  }
};

using fp = modint<(i64)1e9 + 7>;

int main() {
  i64 N, M, K;
  cin >> N >> M >> K;

  auto f = [](i64 a) { return range(1, a + 1).sum(fp(1), [](auto x, auto y) { return x * fp(y); }); };
  auto c = f(N * M - 2) / f(K - 2) / f(N * M - K);

  auto ans = fp(0);

  for(auto i: range(1, N)) {
    ans += fp(i) * fp(N - i) * fp(M) * fp(M);
  }

  for(auto i: range(1, M)) {
    ans += fp(i) * fp(M - i) * fp(N) * fp(N);
  }

  cout << (ans * c).value() << endl;
}
