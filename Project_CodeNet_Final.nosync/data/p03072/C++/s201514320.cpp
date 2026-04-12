#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for (int i = 0; i < N; i++) cin >> vec.at(i);

  int A = 0;
  int ans = 1;

  for (int i = 1; i < N; i++) {
    A = max(A, vec.at(i - 1));
    if (vec.at(i) >= A) ans++;
  }

  cout << ans << endl;
}