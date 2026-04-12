#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  int res = 1;
  for (int i = 0; i < N; i++) cin >> H[i];
  for (int i = 1; i < N; i++) {
    bool can = true;
    for (int  j = 0; j < i; j++) {
      if (H[i] < H[j]) can = false;
    }
    if (can) res++;
  }
  cout << res << endl;
}
