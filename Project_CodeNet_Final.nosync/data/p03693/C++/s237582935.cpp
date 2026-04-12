#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C, D, E;
  cin >> A >> B >> C;
  D = 10 * B + C;
  E = D % 4;
  if(E == 0) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}
