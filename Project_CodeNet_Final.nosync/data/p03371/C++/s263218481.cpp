#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int va, vb, vc, x ,y;
  cin >> va >> vb >> vc >> x >> y;
 
  int sum = INT_MAX;
 
  for (int i = 0; i < 100001; i++) {
    int su = i * 2 * vc + max(0, x-i) * va + max(0, y-i) * vb;
    if (sum > su) {
      sum = su;
    }
  } 
  cout << sum << endl;
}