#include<iostream>
#include<algorithm>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int const MAXN = 1e5;
int const INF = 1e9+1;
int tmp[MAXN];

int main() {
  int N; std::cin >> N;
  std::fill_n(tmp, N, -1);
  for(int i = 0; i < N; ++i) {
    int A; std::cin >> A;
    auto it = std::partition_point(tmp, tmp+N, [&](int x){ return x >= A; });
    *it = A;
  }
  int ans = std::partition_point(tmp, tmp+N,
              [&](int x) { return x > -1; }) - tmp;
  fin(ans);
  return 0;
}
