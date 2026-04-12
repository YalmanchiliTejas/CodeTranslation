#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  int b;
  int c;
  cin >> a >> b >> c;
  if ((10 * b + c - 1) / 4 != (10 * b + c) / 4) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }  
}