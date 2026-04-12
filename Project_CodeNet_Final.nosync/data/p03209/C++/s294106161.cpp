#include <iostream>
#include <vector>

using namespace std;

long len(long N) {
  if (N == 0) return 1;
  return 3 + 2 * len(N-1);
}

long pat(long N) {
  if (N == 0) return 1;
  return 1 + 2 * pat(N-1);
}

long calc(long N, long X, vector<long> len_vec, vector<long> pat_vec) {
  if (X == 0) return 0;
  if (X == len_vec[N]) {
    return pat_vec[N];
  }
  if (X <= len_vec[N-1] + 1) {
    return calc(N-1, X-1, len_vec, pat_vec);
  }
  X = X - 1 - len_vec[N-1] - 1;
  long ans = pat_vec[N-1] + 1;
  if (X == 0) {
    return ans;
  }
  return ans + calc(N-1, X, len_vec, pat_vec);
}

int main(void) {
  long N, X;
  cin >> N >> X;

  vector<long> len_vec;
  vector<long> pat_vec;

  for (long i = 0; i <= 50; i++) {
    len_vec.push_back(len(i));
    pat_vec.push_back(pat(i));
  }

  long ans = calc(N, X, len_vec, pat_vec);

  cout << ans << endl;

  return 0;
}
