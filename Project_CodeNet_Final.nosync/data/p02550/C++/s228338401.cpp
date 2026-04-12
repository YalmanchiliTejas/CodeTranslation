#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N;
  int X, M;
  cin >> N >> X >> M;
  
  if (N <= M) {
    long long sum = 0;
    for (long long i = 0, A = X; i < N; i++) {
      sum += A;
      A = A * A % M;
    }
    cout << sum << endl;
    return 0;
  }
  
  vector<bool> used(M, false);
  int pre = 0, period = 0, last = -1;
  long long sum = 0;
  for (long long i = 0, A = X; i < N; i++) {
    if (used[A]) {
      pre = i;
      last = A;
      break;
    }
    sum += A;
    used[A] = true;
    A = A * A % M;
  }
  
  long long sum2 = 0;
  if (last != -1) {
    for (long long i = 1, A = last;; i++) {
      sum2 += A;
      A = A * A % M;
      if (A == last) {
        period = i;
        break;
      }
    }
  }
  
  if (period) sum += sum2 * ((N - pre) / period);
  
  for (long long i = 0, A = last; i < (period ? (N - pre) % period : 0); i++) {
    sum += A;
    A = A * A % M;
  }
  
  cout << sum << endl;
  
  return 0;
}