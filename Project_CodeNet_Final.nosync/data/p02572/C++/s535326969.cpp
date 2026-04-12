#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cstdint>
#include <unordered_set>
#include <ctime>
#include <numeric>
#include <cstdint>

using u64 = std::uint_fast64_t;
#include <cstdint>

template <std::uint_fast64_t Modulus> class modint {

public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
	*this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};

void solve(void){

  int n;
  std::cin >> n;
  
  std::vector<u64> A(n);
  
  modint<1000000007> total = 0;
  modint<1000000007> ret = 0;
  for(int i=0; i<n; i++){
    std::cin >> A[i];
    total+= A[i];

    ret += (total - A[i]) * A[i];
    //std::cout << A[i] << " " << total.a << " " << ret.a << std::endl;
  }
  std::cout << ret.a << std::endl;
  
  return;
}
int main(void){
  solve();
  return 0;
}



