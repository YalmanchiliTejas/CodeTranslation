#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int e[12];
  for (int i = 0; i < 12; i++) {
    cin >> e[i];
  }
  sort(e, e + 12);

  bool yes = true;
  for (int i = 0; i < 12; i += 4) {
    yes &= e[i] == e[i + 1] && e[i + 1] == e[i + 2] && e[i + 2] == e[i + 3];
  }

  cout << (yes ? "yes" : "no") << endl;

  return 0;
}
