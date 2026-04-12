#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  multiset<int> S;
  for (int i = 0; i < N; i++) {
    auto it = S.lower_bound(A.at(i));
    if (it != S.begin()) S.erase(--it);
    S.insert(A.at(i));
  }
  cout << S.size() << "\n";
}