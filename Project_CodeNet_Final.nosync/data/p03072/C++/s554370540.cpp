#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  vector<int> MH(N);
  MH.at(0) = H.at(0);
  for (int i = 1; i < N; i++) {
    MH.at(i) = max(MH.at(i - 1), H.at(i));
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (H.at(i) == MH.at(i)) {
      ans++;
    }
  }
  cout << ans << endl;
}
