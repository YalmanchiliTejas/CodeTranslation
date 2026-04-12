#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;

  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }

  int answer = 1;

  for (int i = 1; i < N; i++) {
    bool flg = true;
    for (int j = 0; j < i; j++) {
      if (H[i] < H[j]) {
        flg = false;
        break;
      }
    }
    if (flg) {
      answer++;
    }
  }

  cout << answer << endl;

}