#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, max, ans = 1;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) cin >> H.at(i);
  max = H.at(0);
  for (int i = 1; i < N; i++) {
    if (max > H.at(i)) continue;
    max = H.at(i);
    ans++;
  }
  cout << ans << endl;
}