#include <cassert>
#include <deque>
#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;
  std::vector<long long> A(N);
  for (int i = 0; i < N; ++i)
    std::cin >> A[i];

  std::deque<long long> dque;
  for (int i = 0; i < N; ++i) {
    int p = std::lower_bound(dque.begin(), dque.end(), A[i]) - dque.begin();
    if (p == 0)
      dque.push_front(A[i]);
    else
      dque[p - 1] = A[i];
  }
  std::cout << dque.size() << std::endl;

  return 0;
}
