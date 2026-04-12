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
  std::vector<int64_t> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];
  int64_t sum = 0;
  for(int i = 0; i < N; ++i) sum += a[i];
  std::sort(a.begin(), a.end());
  if(a.back() < N) fin(0);

  int64_t sum2 = 0;
  for(int i = 0; i <= N; ++i) {
    for(auto& v: a) v %= N+1;
    std::sort(a.begin(), a.end());
    if(a.back() == N-1) {
      int64_t cur = 0;
      for(int64_t v: a) cur += v;
      if(cur < sum) sum2 = std::max(sum2, cur);
    }
    for(auto& v: a) ++v;
  }
  fin(sum - sum2);
  return 0;
}
