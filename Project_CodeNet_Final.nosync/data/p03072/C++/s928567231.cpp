#include<iostream>
#include<vector>
#include<algorithm>

int main() {
  unsigned N;
  std::cin >> N;
  std::vector<int> H(N);
  for (unsigned i = 0; i < N; ++i) { std::cin >> H[i]; }
  int cur_max = 0;
  int ans = 0;
  for (unsigned i = 0; i < N; ++i) {
    if (cur_max <= H[i]) { ++ans; }
    cur_max = std::max(cur_max, H[i]);
  }
  std::cout << ans << std::endl;
  return 0;
}