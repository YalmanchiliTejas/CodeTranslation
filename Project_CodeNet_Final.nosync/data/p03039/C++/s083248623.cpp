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

int64_t combination(const int64_t n, const int64_t k) {
  int64_t ans = 1;
  for (int64_t i = 0; i < k; i++) {
    ans *= n - i;
    ans /= i + 1;
  }
  return ans;
}

class combination_cache {
 private:
  explicit combination_cache(const int64_t p)
      : mod(p), max(1), fac(2, 1), finv(2, 1), inv(2, 1) {}
  ~combination_cache() = default;
  const int64_t mod;
  int64_t max;

 public:
  combination_cache(const combination_cache &) = delete;
  combination_cache &operator=(const combination_cache &) = delete;
  combination_cache(combination_cache &&) = delete;
  combination_cache &operator=(combination_cache &&) = delete;

  std::vector<int64_t> fac;
  std::vector<int64_t> finv;
  std::vector<int64_t> inv;

  static const combination_cache &get(const int64_t n, const int64_t p) {
    static combination_cache instance(p);

    assert(p == instance.mod);
    if (instance.max < n) {
      instance.fac.reserve(n + 1);
      instance.finv.reserve(n + 1);
      instance.inv.reserve(n + 1);
      for (int64_t i = instance.max + 1; i <= n; i++) {
        instance.fac.push_back(instance.fac[i - 1] * i % p);
        instance.inv.push_back(p - instance.inv[p % i] * (p / i) % p);
        instance.finv.push_back(instance.finv[i - 1] * instance.inv[i] % p);
      }
      instance.max = n;
    }
    return instance;
  }
};

int64_t combination(const int64_t n, const int64_t k, const int64_t p) {
  if (n < k || n < 0 || k < 0) {
    return 0;
  }
  const auto &cache = combination_cache::get(n, p);
  return cache.fac[n] * (cache.finv[k] * cache.finv[n - k] % p) % p;
}

int main() {
  const int64_t mod = 1000000007;
  int64_t n, m, k;
  std::cin >> n >> m >> k;
  int64_t cost = 0;

  for (int64_t i = 1; i < n; i++) {
    cost += (n - i) * i * m * m;
    cost %= mod;
  }
  for (int64_t i = 1; i < m; i++) {
    cost += (m - i) * i * n * n;
    cost %= mod;
  }

  std::cout << (cost * combination(n * m - 2, k - 2, mod)) % mod << std::endl;
  return 0;
}
