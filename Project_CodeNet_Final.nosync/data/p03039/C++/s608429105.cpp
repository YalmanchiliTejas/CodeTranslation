#include <bits/stdc++.h>

template <typename InputIterator>
typename InputIterator::value_type summation(InputIterator first,
                                             InputIterator last) {
  return std::accumulate(first, last, typename InputIterator::value_type());
}
template <typename T>
std::istream &operator>>(std::istream &stream, std::vector<T> &v);
template <typename T1, typename T2>
std::istream &operator>>(std::istream &stream, std::pair<T1, T2> &p);
template <typename T>
std::istream &operator>>(std::istream &stream, std::vector<T> &v) {
  for (auto &i : v) {
    stream >> i;
  }
  return stream;
}
template <typename T1, typename T2>
std::istream &operator>>(std::istream &stream, std::pair<T1, T2> &p) {
  stream >> p.first >> p.second;
  return stream;
}

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long COM(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  const int64_t mod = 1000000007;
  int64_t n, m, k;
  std::cin >> n >> m >> k;
  if (n == 1) {
    std::swap(n, m);
  }

  int64_t sum = 0;
  for (int64_t i = 0; i < n; i++) {
    sum += (n - i - 1) * (n - i) / 2;
    sum %= mod;
  }
  int64_t cost = sum;
  int64_t count = n * n;
  count %= mod;
  for (int64_t i = 1; i < m; i++) {
    auto tmp = sum * 2 * i;
    tmp %= mod;
    tmp += count * i * (i + 1) / 2;
    tmp %= mod;

    cost += tmp;
    cost %= mod;

    cost += sum;
    cost %= mod;
    // 新しい列で完結するやつを追加.
  }
  COMinit();
  std::cout << (cost * COM(n * m - 2, k - 2)) % mod << std::endl;
  return 0;
}