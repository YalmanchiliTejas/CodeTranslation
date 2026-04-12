#include <iostream>
#include <vector>
#include <cstdint>

int main() {
  std::int64_t N, X, M;
  std::cin >> N >> X >> M;
  std::vector<std::int64_t> A(M + 1);
  std::vector<int> index(M, -1);
  A[0] = X;
  index[A[0]] = 0;
  int end;
  for (end = 1; end <= M; ++end) {
    A[end] = A[end - 1] * A[end - 1] % M;
    if (index[A[end]] >= 0) break;
    index[A[end]] = end;
  }
  int begin = index[A[end]];
  if (N < begin) {
    std::int64_t sum = 0;
    for (int i = 0; i < N; ++i) {
      sum += A[i];
    }
    std::cout << sum << std::endl;
    return 0;
  }
  std::int64_t sum = 0, body = 0;
  for (int i = 0; i < begin; ++i) {
    sum += A[i];
  }
  for (int i = begin; i < end; ++i) {
    body += A[i];
  }
  const auto loops = (N - begin) / (end - begin);
  const auto remaining = N - begin - (end - begin) * loops;
  sum += body * loops;
  for (int i = begin; i < begin + remaining; ++i) {
    sum += A[i];
  }
  std::cout << sum << std::endl;
  return 0;
}
