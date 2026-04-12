#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  int head = 0;
  while (Q--) {
    int c, k;
    cin >> c >> k;
    if (c == 0) { // show
      cout << (head + k - 1) % N + 1 << endl;
    } else { // swap
      head = (head + k) % N;
    }
  }
}

