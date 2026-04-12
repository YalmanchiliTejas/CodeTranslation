#include <bits/stdc++.h>
using namespace std;

int abs(int x) {
  if(x >= 0) {
    return x;
  }
  else {
    return -1 * x;
  }
}

int main() {
  int A;
  cin >> A;
  if(A == 5) {
    cout << "YES" << endl;
  }
  else if(abs(A - 5) == 2) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}