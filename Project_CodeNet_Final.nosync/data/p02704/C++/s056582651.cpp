#include <cstdint>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

std::vector<std::vector<int>> solve(std::vector<int> s, std::vector<int> t,
                                    std::vector<int> u, std::vector<int> v) {

  // s[i] == u[i] なら、i 行目には少なくとも一つ u[i] がある必要がある。
  // s[i] != u[i] なら、i 行目は全て u[i] である必要がある。
  // t[j] と v[j] に関しても同様のことが成り立つ。
  // 基本的には 0 で埋めておき、必要な箇所に 1 を割り当てる方針で解く。

  size_t n = s.size();

  // 未確定な箇所を -1 で初期化しておく。-1 は最後に 0 にする。
  std::vector<std::vector<int>> res(n, std::vector<int>(n, -1));

  auto validate = [&](auto& res) {
    // 未確定な箇所を 0 で埋めて返す。
    for (size_t i = 0; i < n; ++i)
      for (size_t j = 0; j < n; ++j)
        if (res[i][j] == -1) res[i][j] = 0;

    // 以下では、論理積を 0 にしたい行・列の条件を無視して構築するため。
    // ついでに全部の条件についても確認する。
    for (size_t i = 0; i < n; ++i) {
      int or_i = 0, and_i = 1;
      for (size_t j = 0; j < n; ++j) {
        or_i |= res[i][j];
        and_i &= res[i][j];
      }
      if (((s[i] == 0)? and_i: or_i) != u[i]) return res.clear(), res;
    }
    for (size_t j = 0; j < n; ++j) {
      int or_j = 0, and_j = 1;
      for (size_t i = 0; i < n; ++i) {
        or_j |= res[i][j];
        and_j &= res[i][j];
      }
      if (((t[j] == 0)? and_j: or_j) != v[j]) return res.clear(), res;
    }

    return res;
  };

  std::vector<size_t> u1, v1;  // 論理和を 1 にしたい添字（1 を入れる必要がある）
  std::vector<size_t> u0, v0;  // 論理積を 0 にしたい添字（必要に応じて 1 を許容する）

  for (size_t i = 0; i < n; ++i) {
    if (s[i] == u[i]) {
      ((u[i] == 0)? u0: u1).push_back(i);
    } else {
      for (size_t j = 0; j < n; ++j) res[i][j] = u[i];
    }
  }

  for (size_t j = 0; j < n; ++j) {
    if (t[j] == v[j]) {
      ((v[j] == 0)? v0: v1).push_back(j);
    } else if (v[j] == 1) {
      for (size_t i = 0; i < n; ++i) {
        if (!(res[i][j] == -1 || res[i][j] == v[j])) return {};
        res[i][j] = v[j];
      }
    }
  }

  // 論理和を 1 にしたい行・列について、適切な箇所に 1 を入れたい。
  // もし、そうしたい行・列がなければ、特にすることはなし。
  if (u1.empty() && v1.empty()) return validate(res);

  // 1 を入れてもいい行と 1 を入れてもいい列が存在するなら、その共通部分を
  // 1 にすることで条件を満たせる。
  if (std::count(u.begin(), u.end(), 1) && std::count(v.begin(), v.end(), 1)) {
    for (size_t i = 0; i < n; ++i)
      for (size_t j = 0; j < n; ++j)
        if (u[i] == 1 && v[j] == 1) {
          if (res[i][j] == 0) return {};
          res[i][j] = 1;
        }
    return validate(res);
  }

  // あとは、u1 と v1 のうちちょうど一つが empty() な場合のみを考えればよい。
  // 簡単のため、v1.empty() とする。
  auto transpose = [&] {
    std::swap(s, t), std::swap(u, v), std::swap(u0, v0), std::swap(u1, v1);
    for (size_t i = 0; i < n; ++i)
      for (size_t j = 0; j < i; ++j)
        std::swap(res[i][j], res[j][i]);
  };
  bool transposed = !v1.empty();
  if (!v1.empty()) transpose();

  // 1 を許容する列がなければ不可能。
  if (v0.empty()) return {};

  // 1 を許容する列が 1 つしかないのに、全ての行が 1 を要求するとこわれる。
  if (u1.size() == n && v0.size() == 1) return {};

  // そうでないなら、v0 をうまく使って埋めることができる。
  size_t j = v0[0];
  for (auto i: u1) {
    if (res[i][j] == 0) return {};
    res[i][j] = 1;
    j = v0.back();  // v0[1] だと u1.size() < n && v0.size() == 1 でこわれる。
  }

  if (transposed) transpose();
  return validate(res);
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

  std::vector<std::vector<uintmax_t>> res(n, std::vector<uintmax_t>(n, 0));
  for (int k = 0; k < 64; ++k) {
    std::vector<int> uk(n), vk(n);
    for (size_t i = 0; i < n; ++i) {
      uk[i] = u[i] >> k & 1;
      vk[i] = v[i] >> k & 1;
    }
    auto cur = solve(s, t, uk, vk);
    if (cur.empty()) return puts("-1"), 0;
    for (size_t i = 0; i < n; ++i)
      for (size_t j = 0; j < n; ++j)
        res[i][j] |= uintmax_t(cur[i][j]) << k;
  }

  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < n; ++j)
      printf("%ju%c", res[i][j], j+1<n? ' ': '\n');
}
