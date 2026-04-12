#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <cstdint>
#include <cmath>
#include <bitset>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

#define N_TIMES(i, n)     for ( uint64_t i = 0;     i <  n; ++i )
#define N_TIMES_REV(i, n) for (  int64_t i = n - 1; i >= 0; --i )

const uint64_t MOD = 1e+9 + 7;

class ModuloOps
{
private:
  std::vector<uint64_t> _fact, _fact_inv;

  void _calc_fact(uint64_t n)
  {
    for (uint64_t i = 2; i <= n; ++i) {
      _fact[i] = (_fact[i - 1] * i) % MOD;
      _fact_inv[i] = inv(_fact[i]);
    }
  }

public:
  ModuloOps(uint64_t n)
  {
    _fact = std::vector<uint64_t>(n + 1);
    _fact_inv = std::vector<uint64_t>(n + 1);

    _fact[0] = 1;
    _fact[1] = 1;
    _fact_inv[0] = 1;
    _fact_inv[1] = 1;

    _calc_fact(n);
  }

  uint64_t power(uint64_t x, uint64_t y) const
  {
    if (y <= 1) {
      return (y == 0) ? 1 : (x % MOD);
    }

    uint64_t w = power(x, y >> 1);
    uint64_t z = (w * w) % MOD;

    if (y % 2 == 1) {
      z = (x * z) % MOD;
    }

    return z;
  }

  uint64_t inv(uint64_t n) const { return power(n, MOD - 2); } 

  uint64_t fact(uint64_t n) const { return _fact[n]; }
  uint64_t fact_inv(uint64_t n) const { return _fact_inv[n]; }

  uint64_t perm(uint64_t n, uint64_t k) const {
    return (_fact[n] * _fact_inv[n - k]) % MOD;
  }

  uint64_t comb(uint64_t n, uint64_t k) const {
    return (perm(n, k) * _fact_inv[k]) % MOD;
  }

  uint64_t prem_rep(uint64_t k, uint64_t l) const
  {
    uint64_t x = _fact[k + l];
    x = (x * _fact_inv[k]) % MOD;
    x = (x * _fact_inv[l]) % MOD;
    return x;
  }

  uint64_t prem_rep(const std::vector<uint64_t> &a) const
  {
    uint64_t n = std::accumulate(a.begin(), a.end(), 0);
    uint64_t x = _fact[n];
    for (uint64_t y : a) {
      x = (x * _fact_inv[y]) % MOD;
    }
    return x;
  }

  uint64_t comb_rep(uint64_t n, uint64_t k) const {
    return comb(n + k - 1, k);
  }
};

int main(int argc, char **argv)
{
  uint64_t N, M, K;
  std::cin >> N >> M >> K;
  
  ModuloOps mod_ops(4 * 1e+5);
  
  uint64_t S = 0;
  
  N_TIMES(p, M) {
    uint64_t Nsq = (N * N) % MOD;
    uint64_t x = ((M - p) * Nsq) % MOD;
    S = (S + ((x * p) % MOD)) % MOD;
  }
  
  N_TIMES(q, N) {
    uint64_t Msq = (M * M) % MOD;
    uint64_t y = ((N - q) * Msq) % MOD;
    S = (S + ((y * q) % MOD)) % MOD;
  }
  
  std::cout << ((S * mod_ops.comb(N * M - 2, K - 2)) % MOD) << std::endl;
  
  return 0;
}