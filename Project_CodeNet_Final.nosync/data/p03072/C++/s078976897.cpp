#include <bits/stdc++.h>

const int MAX_N = 20;

int main() {
  int N, H[MAX_N];
  std::cin >> N;
  for(int i = 0; i < N; ++i) {
    std::cin >> H[i];
  }

  int maxHeight = H[0], ans = 0;
  for(int i = 0; i < N; ++i) {
    if(maxHeight <= H[i]) ++ans;
    maxHeight = std::max(maxHeight, H[i]);
  }

  std::cout << ans << std::endl;
}
