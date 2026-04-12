#include <iostream>
#include <assert.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#include <unordered_set>
using namespace std;
constexpr int64_t MOD = 1e9 + 7;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int32_t N;
  cin >> N;
  vector<int64_t> A(N);
  int64_t sum = 0;
  for (auto& a : A) {
    cin >> a;
    sum += a;
    sum %= MOD;
  }
  int64_t res = 0;
  for (int i = 0; i < N; i++) {
    sum -= A[i];
    if (sum < 0) sum += MOD;
    res += ((A[i] * sum) % MOD);
    res %= MOD;
  }



  cout << res << endl;
  
  return 0;
}
