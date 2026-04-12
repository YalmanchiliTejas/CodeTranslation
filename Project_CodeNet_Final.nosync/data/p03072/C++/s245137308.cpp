#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int H[100];
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }

  int m = 0, count = 0;
  for (int i = 0; i < N; i++) {
    if (H[i] >= m) {
      count++;
      m = H[i];
    }
  }
  cout << count << endl;
  return 0;
}