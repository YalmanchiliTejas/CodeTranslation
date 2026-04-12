#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;

  multiset<int> A;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    auto it = A.lower_bound(a);
    if (it != A.begin()) A.erase(--it);
    A.insert(a);
  }

  cout << A.size() << '\n';
  return 0;
}
