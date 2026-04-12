#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  deque<int> dq;
  for (int i = 0; i < N; i++) {
    int idx = lower_bound(dq.begin(), dq.end(), A.at(i)) - dq.begin();
    if (idx == 0) dq.push_front(A.at(i));
    else dq.at(idx - 1) = A.at(i);
  }
  cout << dq.size() << endl;
}