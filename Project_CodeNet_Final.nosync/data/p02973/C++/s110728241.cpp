#include <algorithm>
#include <iostream>

constexpr int MAX_N = 100000;
int N;
int A[MAX_N];
int C[MAX_N];

bool CanDraw(int num_colors) {
  for (int i = 0; i < num_colors; ++i) {
    C[i] = -1;
  }
  for (int i = 0; i < N; ++i) {
    int pos = std::lower_bound(C, C + num_colors, A[i]) - C - 1;
    if (pos == -1) {
      return false;
    } else {
      C[pos] = A[i];
    }
  }
  return true;
}

int main() {
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }
  int min = 0, max = N;
  while (min < max) {
    int mid = (min + max) / 2;
    if (CanDraw(mid)) {
      max = mid;
    } else {
      min = mid + 1;
    }
  }
  std::cout << min << std::endl;
  return 0;
}