#include <bits/stdc++.h>
using namespace std;
int main(){
  int k, h, b;
  cin >> k >> h >> b;
  cout << (((10 * h + b) % 4 == 0) ? "YES" : "NO") << endl;
  return 0;
}