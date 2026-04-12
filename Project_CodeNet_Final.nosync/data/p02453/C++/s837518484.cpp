#include <iostream>
using namespace std;

int lower_bound(int *A, int N, int key) {
  int left = 0;
  int right = N;

  while (left < right) {
    int mid = (left + right) / 2;
    if (key <= A[mid]) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

int main() {
  int N;
  cin >> N;

  int A[100010];
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int k;
    cin >> k;
    int ans = lower_bound(A, N, k);
    cout << ans << endl;
  }

  return 0;
}

