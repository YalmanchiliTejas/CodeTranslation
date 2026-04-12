#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

constexpr int64_t kMod = 1e9+7;
int64_t Modinv(int64_t a, int64_t m) {
  int64_t b = m, u = 1, v = 0;
  while (b) {
    int64_t t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

int main() {
  int64_t N;
  cin >> N;
  
  int64_t sum = 0;
  int64_t square_sum = 0;
  for (int64_t n = 0; n < N; ++n) {
    int64_t A;
    cin >> A;
    (sum += A) %= kMod;
    (square_sum += A * A) %= kMod;
  }
  int64_t sum_square = (sum * sum) % kMod;
  int64_t res = ((sum_square - square_sum) %kMod * Modinv(2, kMod)) % kMod;
  if (res < 0) res += kMod;
  cout << res << endl;
  
  return 0;
}
