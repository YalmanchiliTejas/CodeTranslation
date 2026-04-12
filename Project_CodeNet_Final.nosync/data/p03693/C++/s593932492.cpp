#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  int b;
  int c;
  cin >> a;
  cin >> b;
  cin >> c;
  
  if ((b * 10 + c) % 4 == 0) {
    cout << "YES" << endl;
  }
  
  else {
    cout << "NO" << endl;
  }
}

