#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  while (true) {
    int id, maxe = 0;
    for (int i = 0; i < 5; i++) {
      cin >> a >> b;
      if (a == 0 && b == 0) return 0;
      if (maxe < a + b) {
        maxe = a + b;
        id = i;
      }
    }
    cout << "ABCDE"[id] << " " << maxe << "\n";
  }
  return 0;
}

