#include <iostream>#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int r, g, b;
  cin >> r >> g >> b;
  int S = 2 * g + b;
  if(S % 4 == 0)
    cout << "YES" << endl;
  if(S % 4 != 0)
    cout << "NO" << endl;
}