#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n, x, m;
  cin >> n >> x >> m;
  int64_t a = x;
  int64_t sum = 0;
  vector<int> seen(m, -1);
  vector<int> sequence;
  int loop_start = -1;
  for (int i = 0; i < n; ++i) {
    if (seen[a] == -1) {
      seen[a] = sequence.size();
    } else {
      loop_start = seen[a];
      break;
    }
    sequence.push_back(a);
    a = a * a % m;
  }
  for (int i = 0; i < loop_start; ++i) {
    sum += sequence[i];
  }
  if (loop_start != -1) {
    int64_t loop_sum = 0;
    int sequence_len = 0;
    for (int i = loop_start; i < (int) sequence.size(); ++i) {
      loop_sum += sequence[i];
      ++sequence_len;
    }
    int64_t left = n - loop_start;
    sum += loop_sum * (left / sequence_len);
    for (int i = 0; i < left % sequence_len; ++i) {
      sum += sequence[loop_start + i];
    }
  } else {
    assert((int) sequence.size() == n);
    for (int i = 0; i < n; ++i) {
      sum += sequence[i];
    }
  }
  cout << sum << '\n';
  return 0;
}