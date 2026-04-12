#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <cstdint>
#include <vector>

/**
 * Calcurate Comb(n, k) in mod p.
 * This creates factorial/inverse cache table.
 * see https://drken1215.hatenablog.com/entry/2018/06/08/210000 in detail.
 */
class ModComb {
public:
  /**
   * \param p prime number
   * \param k max number for table
   */
  ModComb(uint64_t p, uint64_t k);

  uint64_t factorial(uint64_t n) const;
  uint64_t inverse(uint64_t n) const;
  uint64_t factorial_inverse(uint64_t n) const;

  uint64_t combination(uint64_t n, uint64_t k) const;

private:
  const uint64_t p_, k_;
  // table for n!
  std::vector<uint64_t> factorial_;
  // table for n^(-1)
  std::vector<uint64_t> inverse_;
  // table for (n!)^(-1)
  std::vector<uint64_t> factorial_inverse_;
};

ModComb::ModComb(uint64_t p, uint64_t k)
    : p_(p), k_(k)
{
  if(p < k) {
    throw std::runtime_error("p < k (must k <= p");
  }

  factorial_.resize(k_ + 1);
  inverse_.resize(k_ + 1);
  factorial_inverse_.resize(k_ + 1);

  factorial_[0] = factorial_[1] = 1;
  inverse_[0] = inverse_[1] = 1;
  factorial_inverse_[0] = factorial_inverse_[1] = 1;
  for(uint64_t i=2; i<=k_; i++) {
    factorial_[i] = (i * factorial_[i-1]) % p_;
    int64_t a = - (p_/i) * inverse_[p_ % i];
    while(a<0) {
      a += p_;
    }
    inverse_[i] = a % p_;
    factorial_inverse_[i] = (inverse_[i] * factorial_inverse_[i-1]) % p_;
  }
}

uint64_t ModComb::factorial(uint64_t n) const
{
  if(k_ < n) {
    throw std::runtime_error("too large n (must n <= k)");
  }
  return factorial_[n];
}

uint64_t ModComb::inverse(uint64_t n) const
{
  if(k_ < n) {
    throw std::runtime_error("too large n (must n <= k)");
  }
  return inverse_[n];
}

uint64_t ModComb::factorial_inverse(uint64_t n) const
{
  if(k_ < n) {
    throw std::runtime_error("too large n (must n <= k)");
  }
  return factorial_inverse_[n];
}

uint64_t ModComb::combination(uint64_t n, uint64_t k) const
{
  if(n < k) {
    throw std::runtime_error("error: n < k (must k < n)");
  }
  if(k_ < n) {
    throw std::runtime_error("too large n (must n < p_)");
  }

  return (((factorial_[n] * factorial_inverse_[n-k]) % p_) * factorial_inverse_[k]) % p_;
}

int main()
{
  const uint64_t mod = std::pow(10, 9) + 7;
  ModComb mc(mod, 2 * std::pow(10, 5));
  uint64_t N, M, K;
  std::cin >> N >> M >> K;

  uint64_t ret = 0;
  for(uint64_t i=0; i<N; i++) {
    for(uint64_t j=0; j<M; j++) {
      uint64_t tmp = ((i + j) * (N-i) * (M-j)) % mod;
      if(i * j != 0) {
        tmp *= 2;
      }
      // std::cout << "i: " << i << " j: " << j << " tmp: " << tmp << std::endl;
      ret += tmp;
      ret %= mod;
    }
  }

  ret *= mc.combination(M*N - 2, K - 2);
  ret %= mod;

  std::cout << std::fixed << ret << std::endl;

  return 0;
}
