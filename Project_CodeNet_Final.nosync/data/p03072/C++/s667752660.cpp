#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++)
    cin >> H[i];
  int res = 1;
  for (int i = 1; i < N; i++) {
    bool flag = true;
    for (int j = 0; j < i; j++) {
      if (H[i] < H[j]) flag = false;
    }
    if (flag) res++;
  }
  cout << res << '\n';
  return 0;
}
