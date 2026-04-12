#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

constexpr int64_t kMod = 1e9+7;

int main() {
  int64_t N;
  cin >> N;
  
  vector<int64_t> nums(N);
  vector<int64_t> sums(N+1);
  for (int64_t n = 0; n < N; ++n) {
    cin >> nums[n];
    sums[n+1] = sums[n] + nums[n];
  }
  int64_t sum = 0;
  for (int64_t n = 0; n < N-1; ++n) {
    (sum += ((sums.back() - sums[n+1]) % kMod) * nums[n]) %= kMod;
  }
  cout << sum << endl;
  
  return 0;
}
