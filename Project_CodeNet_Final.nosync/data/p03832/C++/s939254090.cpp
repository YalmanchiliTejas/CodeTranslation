#define STOPIT
#include <bits/stdc++.h>
#define loop(n) for (int ngtkana_is_a_genius = 0; ngtkana_is_a_genius < int(n); ngtkana_is_a_genius++)
#define rep(i, begin, end) for (int i = int(begin); (i) < int(end); i++)
#define all(v) v.begin(), v.end()
#define rand(l, r) std::uniform_int_distribution<>(l, r)(mt)
using lint = long long;
auto mt = std::mt19937_64(std::random_device{}());
auto cmn = [](auto& a, auto b){ if (a > b) {a = b; return true;} return false; };
auto cmx = [](auto& a, auto b){ if (a < b) {a = b; return true;} return false; };
void debug_impl() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_impl(Head head, Tail... tail) { std::cerr << " " << head; debug_impl(tail...); }
#ifndef STOPIT
#define debug(...)\
  do {\
    std::cerr << std::boolalpha << "[" << #__VA_ARGS__ << "]:";\
    debug_impl(__VA_ARGS__);\
    std::cerr << std::noboolalpha;\
  } while (false)
#else
#define debug(...) 0;
#endif

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; std::swap(a, m);
    u -= t * v; std::swap(u, v);
  }
  assert(m == 1);
  return u;
}
template <typename T>
class modular {
  private:
    int value;
  public:
    constexpr modular() = default;
    constexpr modular(const modular&) = default;
    constexpr modular(modular&&) = default;
    modular& operator=(const modular&) = default;
    modular& operator=(modular&&) = default;

    template <typename U>
    modular (const U& x) {value = normalize(x);}

    template <typename U>
    static auto normalize(const U& x) {
      int v = static_cast<int>(-mod() <= x && x < mod() ? x : x % mod());
      if (v < 0) v += mod();
      return v;
    }

    auto const& operator()() const { return value; }
    template <typename U>
    explicit operator U() const { return static_cast<U>(value); }
    constexpr static auto mod() { return T::value; }

    auto& operator+=(const modular& other) {
      if ((value += other.value) >= mod()) value -= mod();
      return *this;
    }
    auto& operator-=(const modular& other) {
      if ((value -= other.value) < 0) value += mod();
      return *this;
    }
    template <typename U>
    auto& operator+=(const U& other) {return *this += modular(other); }
    template <typename U>
    auto& operator-=(const U& other) {return *this -= modular(other); }
    auto operator-() const { return modular(-value); }
    auto& operator++() {return *this += 1;}
    auto& operator--() {return *this -= 1;}
    auto  operator++(int) {modular result(*this); operator++(); return result;}
    auto  operator--(int) {modular result(*this); operator--(); return result;}

    template <typename U = T>
    auto& operator*=(const modular& rhs) {
      value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
      return *this;
    }
    auto& operator/=(const modular& other) {
      return *this *= modular(inverse(other.value, mod()));
    }
};
template <typename T> struct is_modular : std::false_type {};
template <typename T> struct is_modular <modular<T>> : std::true_type{};
template <typename T> constexpr bool is_modular_v = is_modular<T>::value;

template <typename T> bool operator==(const modular<T>& lhs, const modular<T>& rhs) { return lhs() == rhs(); }
template <typename T, typename U> bool operator==(const modular<T>& lhs, U rhs) { return lhs == modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const modular<T>& rhs) { return modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const modular<T>& lhs, const modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> modular<T> operator+(const modular<T>& lhs, const modular<T>& rhs) { return modular<T>(lhs) += rhs; }
template <typename T, typename U> modular<T> operator+(const modular<T>& lhs, U rhs) { return modular<T>(lhs) += rhs; }
template <typename T, typename U> modular<T> operator+(U lhs, const modular<T>& rhs) { return modular<T>(lhs) += rhs; }

template <typename T> modular<T> operator-(const modular<T>& lhs, const modular<T>& rhs) { return modular<T>(lhs) -= rhs; }
template <typename T, typename U> modular<T> operator-(const modular<T>& lhs, U rhs) { return modular<T>(lhs) -= rhs; }
template <typename T, typename U> modular<T> operator-(U lhs, const modular<T>& rhs) { return modular<T>(lhs) -= rhs; }

template <typename T> modular<T> operator*(const modular<T>& lhs, const modular<T>& rhs) { return modular<T>(lhs) *= rhs; }
template <typename T, typename U> modular<T> operator*(const modular<T>& lhs, U rhs) { return modular<T>(lhs) *= rhs; }
template <typename T, typename U> modular<T> operator*(U lhs, const modular<T>& rhs) { return modular<T>(lhs) *= rhs; }

template <typename T> modular<T> operator/(const modular<T>& lhs, const modular<T>& rhs) { return modular<T>(lhs) /= rhs; }
template <typename T, typename U> modular<T> operator/(const modular<T>& lhs, U rhs) { return modular<T>(lhs) /= rhs; }
template <typename T, typename U> modular<T> operator/(U lhs, const modular<T>& rhs) { return modular<T>(lhs) /= rhs; }

template<typename T, typename U>
modular<T> power (const modular<T>& a, U b) {
  assert(b >= 0);
  modular<T> x = a, ret = 1;
  for (; b > 0; b /= 2) {
    if (b % 2 == 1) ret *= x;
    x *= x;
  }
  return ret;
}

template <typename T>
std::string to_string(const modular<T>& a) {
  return std::to_string(a());
}
template <typename T>
auto operator<<(std::ostream& os, const T& a)
  -> std::enable_if_t<is_modular_v<T>, std::ostream&>{
    return os << a();
  }
template <typename T>
auto operator>>(std::istream& is, T& a)
  -> std::enable_if_t<is_modular_v<T>, std::istream&> {
  long long x; is >> x;
  a = T(x);
  return is;
}

// using mod_type = int;

// struct variable_mod { static mod_type value; };
// mod_type variable_mod::value;
// mod_type& mod = variable_mod::value;
// using mint = modular< variable_mod >;

constexpr int mod = 1'000'000'007;
using mint = modular<std::integral_constant<std::decay_t<decltype(mod)>, mod>>;

template < typename Container, typename Value = typename Container::value_type, std::enable_if_t<!std::is_same< Container, std::string >::value, std::nullptr_t> = nullptr>
std::istream& operator>> (std::istream& is, Container& v)
  { for (auto & x : v) { is >> x; } return is; }

template < typename Container, typename Value = typename Container::value_type, std::enable_if_t<!std::is_same< Container, std::string >::value, std::nullptr_t> = nullptr >
std::ostream& operator<< (std::ostream& os, Container const& v) {
 os << "{";
  for (auto it = v.begin(); it != v.end(); it++)
    {os << (it != v.begin() ? "," : "") << *it;}
  return os << "}";
}

template < template < typename ... > class Tuple,  typename... Args, std::size_t ... Inds, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::istream& tuple_input_impl(std::istream& os, Tuple<Args...>& tuple, std::integer_sequence<std::size_t, Inds...>)
  { (void)std::initializer_list<int>{((void)(os >> std::get< Inds >(tuple)), 0)...}; return os; }
template < template < typename ... > class Tuple,  typename... Args, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::istream& operator>> (std::istream& os, Tuple<Args...>& tuple)
  { return tuple_input_impl(os, tuple, std::index_sequence_for<Args...>()); }

template < template < typename ... > class Tuple,  typename... Args, std::size_t ... Inds, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::ostream& tuple_output_impl(std::ostream& os, const Tuple<Args...>& tuple, std::integer_sequence<std::size_t, Inds...>)
  { os << "("; (void)std::initializer_list<int>{((void)(os << (Inds > 0 ? "," : "") << std::get< Inds >(tuple)), 0)...}; return os << ")"; }
template < template < typename ... > class Tuple,  typename... Args, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::ostream& operator<< (std::ostream& os, const Tuple<Args...>& tuple)
 { return tuple_output_impl(os, tuple, std::index_sequence_for<Args...>()); }

template < typename Value >
class factorials {
    std::vector< Value > fact, finv;

  public:
    factorials()=default;

    void build(int n) {
      fact.resize(n), finv.resize(n);
      fact.at(0) = 1;
      for (int i = 1; i < n; i++) fact.at(i) = fact.at(i - 1) * Value(i);
      finv.at(n - 1) = Value(1) / fact.at(n - 1);
      for (int i = n - 2; i >= 0; i--) finv.at(i) = finv.at(i + 1) * Value(i + 1);
    }
    auto operator()  (int i) const {return fact.at(i);}
    auto inv         (int i) const {return finv.at(i);}
    auto binom(int i, int j) const {
      assert(0 <= i);
      if (j < 0 ||i < j) return Value(0);
      return fact.at(i) * finv.at(j) * finv.at(i - j);
    }
    auto deal(int i, int j) const
      { return binom(i + j - 1, j - 1); }
};

int main() {
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  int n, A, B, C, D;
  std::cin >> n >> A >> B >> C >> D;
  factorials< mint > fact;
  fact.build(n+1);
  std::vector< mint > dp(n+1,0);
  dp.at(0) = 1;
  rep(sz,A,B+1) {
    for (int i = n; i >= 0; i--) {
      mint& crr = dp.at(i);
      if (i - C*sz < 0) continue;
      int D_ = std::min(D, i / sz);
      rep(m,C,D_+1) {
        int k = i - m*sz;
        debug(k,i);
        mint now = dp.at(k) * fact.inv(m) * power(fact.inv(sz), m);
        crr += now;
      }
    }
    {
      mint coeff = 1;
      auto tmp_dp = dp;
      rep(i,1,n+1) {
        coeff *= i;
        tmp_dp.at(i) *= coeff;
      }
      debug(tmp_dp);
    }
  }
  mint coeff = 1;
  rep(i,1,n+1) {
    coeff *= i;
    dp.at(i) *= coeff;
  }
  debug(dp);
  mint ans = dp.at(n);
  std::cout << ans << std::endl;
  return 0;
}