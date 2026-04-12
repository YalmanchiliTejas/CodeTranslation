#include <bits/stdc++.h>
using namespace std;

int main () {
  int a, b, c;
  cin >> a >> b >> c;
  int total = a * 100 + b * 10 + c;
  if (total %4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
    
}