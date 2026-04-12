#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 1e5;

int N;
int A[MAX_N];

int main() {
  cin >> N;

  for (int i{}; i < N; ++i)
    cin >> A[i];

  deque<int> d;
  for (int i{}; i < N; ++i) {
    int p = lower_bound(d.begin(), d.end(), A[i]) - d.begin();
    if (p == 0) {
      d.push_front(A[i]);
    } else {
      d[p-1] = A[i];
    }
  }
  int ans = d.size();

  cout << ans << endl;
  return 0;
}
