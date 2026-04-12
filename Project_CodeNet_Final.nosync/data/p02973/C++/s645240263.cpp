#include<iostream>
#include<deque>
#include<algorithm>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int const MAXN = 1e5;
int const INF = 1e9+1;

int main() {
  int N; std::cin >> N;
  std::deque<int> tmp(N, INF);
  for(int i = 0; i < N; ++i) {
    int A; std::cin >> A;
    auto it = std::lower_bound(tmp.begin(), tmp.end(), A);
    if(it != tmp.begin()) *(it-1) = A;
    else tmp.push_front(A);
  }
  int ans = std::lower_bound(tmp.begin(), tmp.end(), INF) - tmp.begin();
  fin(ans);
  return 0;
}
