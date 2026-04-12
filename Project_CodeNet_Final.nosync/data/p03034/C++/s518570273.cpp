#include <iostream>
#include <cstdint>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

LL gcd(LL a, LL b) {
  if( b == 0 ) { return a; }
  return gcd(b, a % b);
}

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

template <LL MOD=1000000007> class MODLL {
public:
  LL x;
  MODLL(const LL _x) : x(_x % MOD) {};
  MODLL operator+(const MODLL rhs) const { return MODLL(*this) += rhs; }
  MODLL operator-(const MODLL rhs) const { return MODLL(*this) -= rhs; }
  MODLL operator*(const MODLL rhs) const { return MODLL(*this) *= rhs; }
  MODLL operator/(const MODLL rhs) const { return MODLL(*this) /= rhs; }
  MODLL& operator+=(const MODLL rhs) { x += rhs.x; x %= MOD; return *this; }
  MODLL& operator-=(const MODLL rhs) { x -= rhs.x; x %= MOD; if(x<0) x += MOD; return *this; }
  MODLL& operator*=(const MODLL rhs) { x *= rhs.x; x %= MOD; return *this; }
  MODLL inv() const {
    if(x == 0) { throw "does not have inverse"; }
    LL a = x, b = MOD, u = 1, v = 0;
    while (b) {
      long long t = a / b;
      a -= t * b; swap(a, b);
      u -= t * v; swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return MODLL(u);
  }
  MODLL& operator/=(const MODLL rhs) { (*this) *= rhs.inv(); return *this; }
  MODLL pow(ULL n) const {
    MODLL res = 1;
    MODLL a = x;
    while (n > 0) {
      if (n & 1) res *= a;
      a = a * a;
      n >>= 1;
    }
    return res;
  }
};

typedef MODLL<> ML;


void test() {
  {
    ML x = 3;
    assert(x.pow(45).x == 644897553);
  }
  {
    for(int i=1; i<13; i++) {
      MODLL<13> x = i;
      assert( (x.inv().x * i) % 13 == 1 );
    }
  }
}


int main() {
  LL N;
  std::cin >> N;
  std::vector<LL> s(N);
  for(LL i=0; i<N; i++) {
    std::cin >> s[i];
  }

  LL ans = 0;
  for(LL c = 1; c < N; c++) {
    LL score = 0;
    for(LL k=1; N-1-k*c > 0; k++) {
      LL A = N-1-k*c;
      LL B = A - c;
      if(B <= 0) break;
      LL left = k*c;
      LL right = N-1-k*c;
      if(left >= right && ((N-1)-left) % c == 0) continue;
      if(left >= right && right % c == 0) continue;
      score += s[left];
      score += s[right];
      ans = std::max(ans, score);
    }
  }

  std::cout << ans << std::endl;
  return 0;
}

