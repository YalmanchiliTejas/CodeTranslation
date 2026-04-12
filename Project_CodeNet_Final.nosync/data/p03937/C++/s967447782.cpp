//ue right > sita left OUT
#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  vector<int> R(x);
  vector<int> L(x);
  for (int i = 0; i < x; i++) {
    string s;
    cin >> s;
    bool b = true;
    for (int j = 0; j < y; j++) {
      if (s[j] == '#') {
        R[i] = j;
        if (b) {
          b = !b;
          L[i] = j;
        }
      }
    }
    
    if (i > 0 && R[i-1] > L[i]) {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << "Possible" << endl;
}