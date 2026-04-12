#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cinttypes>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N, K;
  cin >> N >> K;
  
  if (K == 0) {
    cout << 1LL * N * N << '\n';
    return 0;
  }
  
  int64_t result = 0;
  for (int B = K + 1; B <= N; ++B) {
    result += (B - K);
    
    int chunks = (N - B) / B;
    result += 1LL * chunks * (B - K);
    if (N % B != 0) {
      result += max(0, N % B - K + 1);
    }
  }
  
  cout << result << '\n';
  
  return 0;
}
