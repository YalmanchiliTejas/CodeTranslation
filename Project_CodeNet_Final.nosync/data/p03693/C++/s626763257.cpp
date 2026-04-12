#include <bits/stdc++.h>
using namespace std;

int main() {
  int R,G,B,n;
  cin >> R >> G >> B;
  n = 10 * G + B;
  
  if (n % 4 == 0) {
    cout << "YES" << endl;
  }
  else cout << "NO" << endl; 
}