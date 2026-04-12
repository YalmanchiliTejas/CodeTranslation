#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N; std::cin >> N;
  std::vector<int64_t> s(N);
  for(int i = 0; i < N; ++i) std::cin >> s[i];
  int64_t ans = 0;
  for(int g = 1; g*2 <= N-2; ++g) {
    int64_t cur = 0;
    int l = g, r = N-1-g;
    while(l<r) {
      cur += s[l]+s[r];
      ans = std::max(ans, cur);
      l += g; r -= g;
    }
    if((N-1)%g != 0) while(r > g) {
      cur += s[l]+s[r];
      ans = std::max(ans, cur);
      l += g; r -= g;
    }
  }
  fin(ans);
  return 0;
}
