#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, S=0;
  for (int i=0; i<3; i++) {
    cin >> r;
    S+=r;
    S*=10;
  }
  S/=10;
  if (S%4==0) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}
