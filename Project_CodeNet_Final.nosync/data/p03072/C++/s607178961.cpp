#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,c,d;
  c = 0;
  d = 0;
  cin >> a;
  for (int i=0; i<a; i++) {
    cin >> b;
    if (b >= c) {
      d++;
      c = b;
    }
  }
    cout << d << endl;
}