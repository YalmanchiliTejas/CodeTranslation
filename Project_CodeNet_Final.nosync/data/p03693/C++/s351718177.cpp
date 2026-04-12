#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,c;
  cin >> a >> b >> c;
  a *= 100;
  b *= 10;
  int t = a+b+c;
  if (t%4 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}