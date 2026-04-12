#include <algorithm>
#include <cmath>
#include <climits>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main() {
  int N; std::cin >> N;
  std::vector<long long> A(N);
  for (int i = 0; i < N; ++i) std::cin >> A[i];

  sort(A.begin(), A.end());

  std::vector<long long> out1, out2;
  int start = 0;
  int end = N - 1;
  bool push_small = true;

  while (start != end) {
    if (push_small) {
      out1.push_back(A[start]);
      ++start;
    } else { // large one
      out1.push_back(A[end]);
      --end;
    }
    push_small = !push_small;
  }
  out1.insert(out1.begin(), A[start]);

  start = 0;
  end = N - 1;
  push_small = false;

  while (start != end) {
    if (push_small) {
      out2.push_back(A[start]);
      ++start;
    } else { // large one
      out2.push_back(A[end]);
      --end;
    }
    push_small = !push_small;
  }
  out2.insert(out2.begin(), A[start]);

  long long sum1 = 0;
  long long sum2 = 0;
  for (int i = 0; i < N-1; ++i) {
    sum1 += std::abs(out1[i]-out1[i+1]);
    sum2 += std::abs(out2[i]-out2[i+1]);
  }
  std::cout << std::max(sum1, sum2) << std::endl;
}
