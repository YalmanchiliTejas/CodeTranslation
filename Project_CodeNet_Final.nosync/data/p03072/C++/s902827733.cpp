#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int H[N];
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    cin >> H[i];
    for (int j = i; j >= 0; j--) {
      if (H[i] < H[j]) {
        break;
      }
      if (j == 0) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}
