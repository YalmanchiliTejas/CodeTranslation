#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  
  int count = 1;
  bool b;
  for (int i = 1; i < N; i++) {
    b = true;
    for (int k = 0; k < i; k++) {
      if (H.at(i) < H.at(k)) {
        b = false;
        break;
      }
    }
    if (b == true) {
      count++;
    }
  }
  cout << count << endl;
}