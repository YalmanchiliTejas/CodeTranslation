/**
 * @brief ユーザ定義リテラル
 * @author えびちゃん
 */

#ifndef H_int_literals
#define H_int_literals

#include <cstddef>
#include <cstdint>

constexpr intmax_t  operator ""_jd(unsigned long long n) { return n; }
constexpr uintmax_t operator ""_ju(unsigned long long n) { return n; }
constexpr size_t    operator ""_zu(unsigned long long n) { return n; }
constexpr ptrdiff_t operator ""_td(unsigned long long n) { return n; }

#endif  /* !defined(H_int_literals) */

/**
 * @brief ラムダ式の再帰
 * @author えびちゃん
 */

#ifndef H_make_fix_point
#define H_make_fix_point

#include <utility>

template <typename Fn>
class fix_point: Fn {
public:
  explicit constexpr fix_point(Fn&& f) noexcept: Fn(std::forward<Fn>(f)) {}

  template <typename... Args>
  constexpr decltype(auto) operator ()(Args&&... args) const {
    return Fn::operator ()(*this, std::forward<Args>(args)...);
  }
};

template <typename Fn>
static inline constexpr decltype(auto) make_fix_point(Fn&& f) noexcept {
  return fix_point<Fn>{std::forward<Fn>(f)};
}

#endif  /* !defined(H_make_fix_point) */

#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>

int main() {
  size_t n;
  scanf("%zu", &n);

  char buf[524288];
  scanf("%s", buf);
  std::string s = buf;

  std::vector<int> p(1_zu << n);
  for (auto& pi: p) scanf("%d", &pi), --pi;

  std::vector<int> res(1_zu << n);
  make_fix_point([&](auto& dfs, std::vector<int> const& cur, size_t dep, size_t k) -> void {
      if (cur.size() == 1) {
        res[k] = cur[0];
        return;
      }
      // for (size_t i = 0; i < cur.size(); ++i)
      //   fprintf(stderr, "%d%c", cur[i], i+1<cur.size()? ' ': '\n');
      {
        std::vector<int> next;
        next.reserve(cur.size()/2);
        for (size_t i = 0; i < cur.size(); i += 2) {
          int x, y;
          std::tie(x, y) = std::minmax(cur[i], cur[i+1]);
          next.push_back((s[y-x-1] == '1')? y: x);
        }
        dfs(next, dep + 1, k);
      }
      {
        std::vector<int> next;
        next.reserve(cur.size()/2);
        for (size_t i = 1; i < cur.size(); i += 2) {
          int x, y;
          std::tie(x, y) = std::minmax(cur[i], cur[(i+1)%cur.size()]);
          next.push_back((s[y-x-1] == '1')? y: x);
        }
        dfs(next, dep + 1, 1_zu << dep | k);
      }
  })(p, 0, 0);

  for (auto ri: res) printf("%d\n", ri+1);
}

