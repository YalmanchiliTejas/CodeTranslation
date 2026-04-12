#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int c = 1, max_h = 1, h;
  for (int i = 0; i < n; ++i){
    cin >> h;
    if (i > 0 && max_h <= h) c++;
    max_h = max(h, max_h);
  }

  cout << c << endl;
  
  return 0;
}
