#line 1 "F.cpp"
#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <set>
#include <string>
#include <vector>

#line 1 "~/git/library/utility/literals.cpp"



/**
 * @brief ユーザ定義リテラル
 * @author えびちゃん
 */

#include <cstddef>
#line 11 "~/git/library/utility/literals.cpp"

constexpr intmax_t  operator ""_jd(unsigned long long n) { return n; }
constexpr uintmax_t operator ""_ju(unsigned long long n) { return n; }
constexpr size_t    operator ""_zu(unsigned long long n) { return n; }
constexpr ptrdiff_t operator ""_td(unsigned long long n) { return n; }


#line 1 "~/git/library/utility/make/vector.cpp"
/**
 * @brief 多次元 vector の作成
 * @author えびちゃん
 */

#ifndef H_make_vector
#define H_make_vector

#line 10 "~/git/library/utility/make/vector.cpp"
#include <type_traits>
#line 12 "~/git/library/utility/make/vector.cpp"

namespace detail {
  template <typename Tp, size_t Nb>
  auto make_vector(std::vector<size_t>& sizes, Tp const& x) {
    if constexpr (Nb == 1) {
      return std::vector(sizes[0], x);
    } else {
      size_t size = sizes[Nb-1];
      sizes.pop_back();
      return std::vector(size, make_vector<Tp, Nb-1>(sizes, x));
    }
  }
}  // detail::

template <typename Tp, size_t Nb>
auto make_vector(size_t const(&sizes)[Nb], Tp const& x = Tp()) {
  std::vector<size_t> s(Nb);
  for (size_t i = 0; i < Nb; ++i) s[i] = sizes[Nb-i-1];
  return detail::make_vector<Tp, Nb>(s, x);
}

#endif  /* !defined(H_make_vector) */
#line 10 "F.cpp"

std::vector<std::vector<int>> f(std::vector<int> const& s, std::vector<int> const& t,
                                std::vector<int> const& u, std::vector<int> const& v) {

  size_t n = s.size();
  auto res = make_vector({n, n}, 0);
  size_t u_all0 = 0, u_all1 = 0;
  size_t v_all0 = 0, v_all1 = 0;
  std::vector<size_t> uu, vv;

  if (n == 1) {
    if (u[0] != v[0]) return {};
    res[0][0] = u[0];
    return res;
  }

  for (size_t i = 0; i < n; ++i) {
    if (s[i] != u[i]) {
      ++((u[i] == 0)? u_all0: u_all1);
    } else if (u[i] == 0) {
      uu.push_back(i);
    }
    if (t[i] != v[i]) {
      ++((v[i] == 0)? v_all0: v_all1);
    } else if (v[i] == 0) {
      vv.push_back(i);
    }
  }

  size_t u0 = std::count(u.begin(), u.end(), 0);
  size_t u1 = std::count(u.begin(), u.end(), 1);
  size_t v0 = std::count(v.begin(), v.end(), 0);
  size_t v1 = std::count(v.begin(), v.end(), 1);

  if ((u_all0 && v_all1) || (u_all1 && v_all0)) return {};
  if (u_all0 == n && v1 > 0) return {};
  if (u_all1 == n && v0 > 0) return {};
  if (v_all0 == n && u1 > 0) return {};
  if (v_all1 == n && u0 > 0) return {};

  for (size_t i = 0; i < n; ++i) {
    if (s[i] == u[i]) continue;
    for (size_t j = 0; j < n; ++j)
      res[i][j] = u[i];
  }

  for (size_t j = 0; j < n; ++j) {
    if (t[j] == v[j]) continue;
    for (size_t i = 0; i < n; ++i)
      res[i][j] = v[j];
  }

  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < n; ++j) {
      if (u[i] && v[j])
        res[i][j] = 1;
    }

  if (u1 && v1) return res;
  if (!u1 && !v1) return res;

  if (u1) {
    if (u1 == n && vv.size() < 2) return {};
    if (vv.empty()) return {};
    size_t c = vv[0];
    for (size_t i = 0; i < n; ++i) {
      if (s[i] == u[i] && u[i] == 1) {
        res[i][c] = 1;
        c = vv.back();
      }
    }
  }
  if (v1) {
    if (v1 == n && uu.size() < 2) return {};
    if (uu.empty()) return {};
    size_t r = uu[0];
    for (size_t j = 0; j < n; ++j) {
      if (t[j] == v[j] && v[j] == 1) {
        res[r][j] = 1;
        r = uu.back();
      }
    }
  }
  return res;
}

int main() {
  size_t n;
  scanf("%zu", &n);

  std::vector<int> s(n), t(n);
  std::vector<uintmax_t> u(n), v(n);

  for (auto& si: s) scanf("%d", &si);
  for (auto& ti: t) scanf("%d", &ti);
  for (auto& ui: u) scanf("%ju", &ui);
  for (auto& vi: v) scanf("%ju", &vi);

  auto res = make_vector({n, n}, 0_ju);
  for (int i = 0; i < 64; ++i) {
    std::vector<int> u1(n), v1(n);
    for (size_t j = 0; j < n; ++j) {
      u1[j] = u[j] >> i & 1;
      v1[j] = v[j] >> i & 1;
    }
    auto cur = f(s, t, u1, v1);
    if (cur.empty()) return puts("-1"), 0;
    for (size_t j = 0; j < n; ++j)
      for (size_t k = 0; k < n; ++k)
        res[j][k] |= uintmax_t(cur[j][k]) << i;
  }

  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < n; ++j)
      printf("%ju%c", res[i][j], j+1<n? ' ': '\n');
}
