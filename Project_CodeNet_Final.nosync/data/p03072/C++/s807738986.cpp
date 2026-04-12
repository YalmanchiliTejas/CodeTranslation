#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) cin >> H.at(i);

  int mx = 0, cnt = 0;
  for (int i = 0; i < N; i++) if (H.at(i) >= mx) cnt++, mx = H.at(i);

  cout << cnt << "\n";
}